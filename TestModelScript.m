%% Programmatic Builder for 4.8Ah 3RC Dynamic Battery Cell Simulink Model
% V_init, Temp_C, and I_cell are all top-level Simulink block inputs.
% Uses ONLY basic Simulink library blocks (no Simscape or MATLAB Function blocks).

clear; clc;

%% ========================================================================
%  PART 1: INITIALIZE WORKSPACE LOOKUP TABLES & PARAMETERS
%  ========================================================================

% 1. Default Top-Level Constant Block Values (Editable directly in Simulink)
V_init_default = 3.2;  % Default value for V_init Constant block (V)
Temp_default   = 25.0;  % Default value for Temp_C Constant block (degC)

% 2. Cell Specifications & 3RC Partitioning
Q_nom_Ah     = 4.8;                 % Nominal Capacity (Ah)
Q_nom_As     = Q_nom_Ah * 3600;     % Nominal Capacity in Coulombs (A*s)
SOC_gain     = -100 / Q_nom_As;     % Coulomb counting gain (%/A*s)

% 3RC Resistance Split Weights (R0, R1, R2, R3 share of total DCIR)
w_R0 = 0.55; w_R1 = 0.15; w_R2 = 0.15; w_R3 = 0.15;

% 3RC Time Constants (seconds) & Inverse Gains (1/tau)
tau1 = 1.0;   tau2 = 15.0;  tau3 = 100.0;
inv_tau1 = 1 / tau1;
inv_tau2 = 1 / tau2;
inv_tau3 = 1 / tau3;

% 3. Breakpoints
SOC_bp_ocv   = 0:5:100;
Temp_bp_ocv  = [-20, -10, 0, 10, 25, 45, 55];

SOC_bp_dcir  = 0:10:100;
Temp_bp_dcir = [-20, -10, 0, 10, 25, 45, 60];

% 4. Digitized OCV & DCIR Tables
OCV_Dis_Table = [
    2.934, 2.929, 2.920, 2.900, 2.911, 2.903, 2.922;
    3.148, 3.135, 3.129, 3.118, 3.123, 3.121, 3.133;
    3.295, 3.294, 3.289, 3.281, 3.272, 3.266, 3.276;
    3.409, 3.409, 3.405, 3.400, 3.395, 3.386, 3.395;
    3.450, 3.452, 3.451, 3.451, 3.452, 3.449, 3.452;
    3.494, 3.501, 3.501, 3.499, 3.499, 3.490, 3.496;
    3.552, 3.559, 3.558, 3.557, 3.554, 3.546, 3.551;
    3.597, 3.607, 3.607, 3.606, 3.603, 3.593, 3.598;
    3.636, 3.640, 3.641, 3.642, 3.642, 3.642, 3.648;
    3.667, 3.672, 3.674, 3.676, 3.676, 3.679, 3.685;
    3.708, 3.715, 3.717, 3.718, 3.718, 3.721, 3.727;
    3.753, 3.756, 3.758, 3.759, 3.763, 3.766, 3.763;
    3.799, 3.803, 3.805, 3.807, 3.813, 3.812, 3.808;
    3.868, 3.872, 3.872, 3.870, 3.877, 3.874, 3.866;
    3.907, 3.909, 3.910, 3.910, 3.912, 3.911, 3.907;
    3.946, 3.949, 3.950, 3.950, 3.953, 3.952, 3.947;
    4.006, 4.008, 4.009, 4.009, 4.012, 4.011, 4.005;
    4.057, 4.059, 4.060, 4.060, 4.063, 4.063, 4.059;
    4.072, 4.075, 4.077, 4.077, 4.080, 4.080, 4.079;
    4.087, 4.091, 4.093, 4.094, 4.096, 4.096, 4.094;
    4.149, 4.159, 4.158, 4.161, 4.161, 4.158, 4.150
];

OCV_Chg_Table = [
    2.934, 2.929, 2.920, 2.900, 2.910, 2.903, 2.922;
    3.260, 3.274, 3.271, 3.271, 3.254, 3.238, 3.240;
    3.387, 3.399, 3.397, 3.397, 3.385, 3.362, 3.363;
    3.436, 3.442, 3.442, 3.441, 3.439, 3.429, 3.430;
    3.481, 3.491, 3.491, 3.493, 3.492, 3.479, 3.481;
    3.538, 3.547, 3.546, 3.547, 3.540, 3.534, 3.534;
    3.586, 3.592, 3.592, 3.593, 3.589, 3.582, 3.582;
    3.616, 3.621, 3.622, 3.624, 3.622, 3.622, 3.623;
    3.644, 3.650, 3.651, 3.653, 3.652, 3.653, 3.656;
    3.677, 3.683, 3.685, 3.687, 3.686, 3.688, 3.691;
    3.719, 3.726, 3.727, 3.730, 3.728, 3.731, 3.734;
    3.766, 3.772, 3.774, 3.777, 3.776, 3.777, 3.780;
    3.819, 3.837, 3.838, 3.840, 3.835, 3.829, 3.831;
    3.880, 3.886, 3.886, 3.887, 3.885, 3.883, 3.882;
    3.913, 3.918, 3.919, 3.920, 3.918, 3.917, 3.917;
    3.952, 3.958, 3.959, 3.960, 3.958, 3.958, 3.958;
    4.010, 4.017, 4.017, 4.019, 4.017, 4.016, 4.016;
    4.061, 4.066, 4.067, 4.068, 4.067, 4.067, 4.067;
    4.076, 4.080, 4.082, 4.083, 4.083, 4.083, 4.084;
    4.090, 4.096, 4.098, 4.100, 4.099, 4.098, 4.099;
    4.135, 4.137, 4.138, 4.141, 4.139, 4.143, 4.144
];

DCIR_Dis_Table = [
    0.4429, 0.4429, 0.1677, 0.1473, 0.1409, 0.1403, 0.1384, 0.1409, 0.1428, 0.1421, 0.1510;
    0.2169, 0.2169, 0.0906, 0.0755, 0.0721, 0.0709, 0.0713, 0.0732, 0.0738, 0.0709, 0.0772;
    0.1281, 0.1281, 0.0657, 0.0554, 0.0530, 0.0530, 0.0526, 0.0531, 0.0556, 0.0525, 0.0558;
    0.0808, 0.0808, 0.0453, 0.0396, 0.0389, 0.0387, 0.0385, 0.0396, 0.0407, 0.0380, 0.0417;
    0.1135, 0.0531, 0.0333, 0.0290, 0.0284, 0.0284, 0.0280, 0.0284, 0.0299, 0.0277, 0.0296;
    0.0885, 0.0407, 0.0269, 0.0233, 0.0227, 0.0229, 0.0219, 0.0228, 0.0239, 0.0210, 0.0234;
    0.0860, 0.0373, 0.0250, 0.0221, 0.0220, 0.0218, 0.0207, 0.0214, 0.0224, 0.0195, 0.0220
];

DCIR_Chg_Table = [
    0.1796, 0.1796, 0.1427, 0.2163, 0.2033, 0.2013, 0.2128, 0.2128, 0.2128, 0.2128, 0.2128;
    0.0883, 0.0883, 0.0672, 0.1006, 0.0948, 0.0949, 0.1067, 0.1035, 0.1035, 0.1035, 0.1035;
    0.0742, 0.0742, 0.0579, 0.0531, 0.0482, 0.0485, 0.0584, 0.0576, 0.0631, 0.0631, 0.0631;
    0.0554, 0.0554, 0.0407, 0.0412, 0.0380, 0.0390, 0.0386, 0.0389, 0.0429, 0.0402, 0.0402;
    0.0590, 0.0414, 0.0282, 0.0291, 0.0272, 0.0277, 0.0285, 0.0271, 0.0286, 0.0269, 0.0269;
    0.0479, 0.0358, 0.0221, 0.0233, 0.0215, 0.0217, 0.0218, 0.0212, 0.0220, 0.0195, 0.0195;
    0.0448, 0.0327, 0.0200, 0.0219, 0.0202, 0.0204, 0.0205, 0.0195, 0.0206, 0.0181, 0.0181
];

R0_Dis_Table = w_R0 .* DCIR_Dis_Table;
R1_Dis_Table = w_R1 .* DCIR_Dis_Table;
R2_Dis_Table = w_R2 .* DCIR_Dis_Table;
R3_Dis_Table = w_R3 .* DCIR_Dis_Table;

R0_Chg_Table = w_R0 .* DCIR_Chg_Table;
R1_Chg_Table = w_R1 .* DCIR_Chg_Table;
R2_Chg_Table = w_R2 .* DCIR_Chg_Table;
R3_Chg_Table = w_R3 .* DCIR_Chg_Table;

% 5. Build Inverse 2-D Lookup Table: SOC = f(V_init, Temp_C) for Basic Simulink Block
% Allows V_init and Temp_C Constant blocks to dynamically set SOC_init inside Simulink!
V_bp_inv        = linspace(2.90, 4.16, 64); % Uniform voltage breakpoints [1x64]
SOC_Inv_Dis_Tbl = zeros(length(V_bp_inv), length(Temp_bp_ocv));
SOC_Inv_Chg_Tbl = zeros(length(V_bp_inv), length(Temp_bp_ocv));

for col = 1:length(Temp_bp_ocv)
    % Clamp voltage query points to each temperature column's min/max OCV
    v_col_dis = OCV_Dis_Table(:, col);
    v_q_dis   = min(max(V_bp_inv, min(v_col_dis)), max(v_col_dis));
    SOC_Inv_Dis_Tbl(:, col) = interp1(v_col_dis, SOC_bp_ocv, v_q_dis, 'linear');
    
    v_col_chg = OCV_Chg_Table(:, col);
    v_q_chg   = min(max(V_bp_inv, min(v_col_chg)), max(v_col_chg));
    SOC_Inv_Chg_Tbl(:, col) = interp1(v_col_chg, SOC_bp_ocv, v_q_chg, 'linear');
end

fprintf('Workspace Ready! V_init and Temp_C are now live Simulink Constant block inputs.\n');

% %% ========================================================================
% %  PART 2: PROGRAMMATICALLY BUILD THE SIMULINK MODEL (.slx)
% %  ========================================================================

% modelName = 'Cell_3RC_Dynamic_Model';
% if bdIsLoaded(modelName)
%     close_system(modelName, 0);
% end
% new_system(modelName);
% open_system(modelName);
% 
% set_param(modelName, 'StopTime', '3600', 'Solver', 'ode45');
% 
% % --- 1. Top-Level Constant & Step Input Blocks ---
% % Current input: 0A rest for 10s, then +4.8A (1C discharge)
% add_block('simulink/Sources/Step', [modelName '/I_cell_Input'], ...
%     'Time', '10', 'Before', '0', 'After', '4.8', ...
%     'Position', [40, 150, 80, 180]);
% 
% % Temperature Constant block
% add_block('simulink/Sources/Constant', [modelName '/Temp_C_Input'], ...
%     'Value', 'Temp_default', ...
%     'Position', [40, 230, 80, 260]);
% 
% % Initial Cell Voltage Constant block
% add_block('simulink/Sources/Constant', [modelName '/V_init_Input'], ...
%     'Value', 'V_init_default', ...
%     'Position', [40, 310, 80, 340]);
% 
% % --- 2. Create the 3RC Battery Cell Subsystem ---
% subName = [modelName '/Battery_Cell_3RC'];
% add_block('simulink/Ports & Subsystems/Subsystem', subName, ...
%     'Position', [210, 130, 380, 360]);
% 
% delete_line(subName, 'In1/1', 'Out1/1');
% delete_block([subName '/In1']);
% delete_block([subName '/Out1']);
% 
% % Subsystem Inports & Outports
% add_block('simulink/Sources/In1', [subName '/I_cell'], 'Position', [40, 80, 70, 94]);
% add_block('simulink/Sources/In1', [subName '/Temp_C'], 'Position', [40, 230, 70, 244]);
% add_block('simulink/Sources/In1', [subName '/V_init'], 'Position', [40, 150, 70, 164]);
% 
% add_block('simulink/Sinks/Out1', [subName '/V_cell'], 'Position', [1080, 240, 1110, 254]);
% add_block('simulink/Sinks/Out1', [subName '/SOC_out'], 'Position', [1080, 80, 1110, 94]);
% 
% % --- 3. Dynamic SOC_init Lookup from V_init & Temp_C Constant Blocks ---
% add_block('simulink/Lookup Tables/2-D Lookup Table', [subName '/SOC_Init_Dis_LUT'], ...
%     'BreakpointsForDimension1', 'V_bp_inv', ...
%     'BreakpointsForDimension2', 'Temp_bp_ocv', ...
%     'Table', 'SOC_Inv_Dis_Tbl', ...
%     'Position', [140, 130, 200, 175]);
% 
% add_block('simulink/Lookup Tables/2-D Lookup Table', [subName '/SOC_Init_Chg_LUT'], ...
%     'BreakpointsForDimension1', 'V_bp_inv', ...
%     'BreakpointsForDimension2', 'Temp_bp_ocv', ...
%     'Table', 'SOC_Inv_Chg_Tbl', ...
%     'Position', [140, 195, 200, 240]);
% 
% add_block('simulink/Signal Routing/Switch', [subName '/SOC_Init_Switch'], ...
%     'Criteria', 'u2 >= Threshold', 'Threshold', '0', ...
%     'Position', [245, 165, 280, 205]);
% 
% add_line(subName, 'V_init/1', 'SOC_Init_Dis_LUT/1', 'autorouting', 'on');
% add_line(subName, 'Temp_C/1', 'SOC_Init_Dis_LUT/2', 'autorouting', 'on');
% add_line(subName, 'V_init/1', 'SOC_Init_Chg_LUT/1', 'autorouting', 'on');
% add_line(subName, 'Temp_C/1', 'SOC_Init_Chg_LUT/2', 'autorouting', 'on');
% 
% add_line(subName, 'SOC_Init_Dis_LUT/1', 'SOC_Init_Switch/1', 'autorouting', 'on');
% add_line(subName, 'I_cell/1', 'SOC_Init_Switch/2', 'autorouting', 'on');
% add_line(subName, 'SOC_Init_Chg_LUT/1', 'SOC_Init_Switch/3', 'autorouting', 'on');
% 
% % --- 4. Coulomb Counting (SOC Integrator with External Initial Condition) ---
% add_block('simulink/Math Operations/Gain', [subName '/SOC_Gain'], ...
%     'Gain', 'SOC_gain', 'Position', [180, 70, 240, 104]);
% 
% add_block('simulink/Continuous/Integrator', [subName '/SOC_Integrator'], ...
%     'InitialConditionSource', 'external', ...
%     'LimitOutput', 'on', 'UpperSaturationLimit', '100', 'LowerSaturationLimit', '0', ...
%     'Position', [330, 75, 365, 115]);
% 
% add_line(subName, 'I_cell/1', 'SOC_Gain/1', 'autorouting', 'on');
% add_line(subName, 'SOC_Gain/1', 'SOC_Integrator/1', 'autorouting', 'on');
% add_line(subName, 'SOC_Init_Switch/1', 'SOC_Integrator/2', 'autorouting', 'on'); % External IC!
% add_line(subName, 'SOC_Integrator/1', 'SOC_out/1', 'autorouting', 'on');
% 
% % --- 5. OCV 2-D Lookup Tables & Charge/Discharge Switch ---
% add_block('simulink/Lookup Tables/2-D Lookup Table', [subName '/OCV_Dis_LUT'], ...
%     'BreakpointsForDimension1', 'SOC_bp_ocv', ...
%     'BreakpointsForDimension2', 'Temp_bp_ocv', ...
%     'Table', 'OCV_Dis_Table', ...
%     'Position', [460, 160, 525, 210]);
% 
% add_block('simulink/Lookup Tables/2-D Lookup Table', [subName '/OCV_Chg_LUT'], ...
%     'BreakpointsForDimension1', 'SOC_bp_ocv', ...
%     'BreakpointsForDimension2', 'Temp_bp_ocv', ...
%     'Table', 'OCV_Chg_Table', ...
%     'Position', [460, 240, 525, 290]);
% 
% add_block('simulink/Signal Routing/Switch', [subName '/OCV_Switch'], ...
%     'Criteria', 'u2 >= Threshold', 'Threshold', '0', ...
%     'Position', [590, 205, 630, 245]);
% 
% add_line(subName, 'SOC_Integrator/1', 'OCV_Dis_LUT/1', 'autorouting', 'on');
% add_line(subName, 'Temp_C/1', 'OCV_Dis_LUT/2', 'autorouting', 'on');
% add_line(subName, 'SOC_Integrator/1', 'OCV_Chg_LUT/1', 'autorouting', 'on');
% add_line(subName, 'Temp_C/1', 'OCV_Chg_LUT/2', 'autorouting', 'on');
% 
% add_line(subName, 'OCV_Dis_LUT/1', 'OCV_Switch/1', 'autorouting', 'on');
% add_line(subName, 'I_cell/1', 'OCV_Switch/2', 'autorouting', 'on');
% add_line(subName, 'OCV_Chg_LUT/1', 'OCV_Switch/3', 'autorouting', 'on');
% 
% % --- 6. R0 Ohmic Branch ---
% add_block('simulink/Lookup Tables/2-D Lookup Table', [subName '/R0_Dis_LUT'], ...
%     'BreakpointsForDimension1', 'Temp_bp_dcir', ...
%     'BreakpointsForDimension2', 'SOC_bp_dcir', ...
%     'Table', 'R0_Dis_Table', ...
%     'Position', [460, 330, 525, 380]);
% 
% add_block('simulink/Lookup Tables/2-D Lookup Table', [subName '/R0_Chg_LUT'], ...
%     'BreakpointsForDimension1', 'Temp_bp_dcir', ...
%     'BreakpointsForDimension2', 'SOC_bp_dcir', ...
%     'Table', 'R0_Chg_Table', ...
%     'Position', [460, 410, 525, 460]);
% 
% add_block('simulink/Signal Routing/Switch', [subName '/R0_Switch'], ...
%     'Criteria', 'u2 >= Threshold', 'Threshold', '0', ...
%     'Position', [590, 375, 630, 415]);
% 
% add_block('simulink/Math Operations/Product', [subName '/V_R0_Prod'], ...
%     'Position', [690, 370, 720, 400]);
% 
% add_line(subName, 'Temp_C/1', 'R0_Dis_LUT/1', 'autorouting', 'on');
% add_line(subName, 'SOC_Integrator/1', 'R0_Dis_LUT/2', 'autorouting', 'on');
% add_line(subName, 'Temp_C/1', 'R0_Chg_LUT/1', 'autorouting', 'on');
% add_line(subName, 'SOC_Integrator/1', 'R0_Chg_LUT/2', 'autorouting', 'on');
% 
% add_line(subName, 'R0_Dis_LUT/1', 'R0_Switch/1', 'autorouting', 'on');
% add_line(subName, 'I_cell/1', 'R0_Switch/2', 'autorouting', 'on');
% add_line(subName, 'R0_Chg_LUT/1', 'R0_Switch/3', 'autorouting', 'on');
% 
% add_line(subName, 'I_cell/1', 'V_R0_Prod/1', 'autorouting', 'on');
% add_line(subName, 'R0_Switch/1', 'V_R0_Prod/2', 'autorouting', 'on');
% 
% % --- 7. Build 3 Dynamic RC Polarization Loops (k = 1, 2, 3) ---
% for k = 1:3
%     y_off = 500 + (k - 1) * 190;
%     rk_dis_name = sprintf('R%d_Dis_LUT', k);
%     rk_chg_name = sprintf('R%d_Chg_LUT', k);
%     sw_name     = sprintf('R%d_Switch', k);
%     prod_name   = sprintf('IR%d_Prod', k);
%     sum_name    = sprintf('RC%d_Sum', k);
%     gain_name   = sprintf('InvTau%d_Gain', k);
%     int_name    = sprintf('V_rc%d_Int', k);
% 
%     add_block('simulink/Lookup Tables/2-D Lookup Table', [subName '/' rk_dis_name], ...
%         'BreakpointsForDimension1', 'Temp_bp_dcir', ...
%         'BreakpointsForDimension2', 'SOC_bp_dcir', ...
%         'Table', sprintf('R%d_Dis_Table', k), ...
%         'Position', [460, y_off, 525, y_off+45]);
% 
%     add_block('simulink/Lookup Tables/2-D Lookup Table', [subName '/' rk_chg_name], ...
%         'BreakpointsForDimension1', 'Temp_bp_dcir', ...
%         'BreakpointsForDimension2', 'SOC_bp_dcir', ...
%         'Table', sprintf('R%d_Chg_Table', k), ...
%         'Position', [460, y_off+65, 525, y_off+110]);
% 
%     add_block('simulink/Signal Routing/Switch', [subName '/' sw_name], ...
%         'Criteria', 'u2 >= Threshold', 'Threshold', '0', ...
%         'Position', [590, y_off+35, 630, y_off+75]);
% 
%     add_block('simulink/Math Operations/Product', [subName '/' prod_name], ...
%         'Position', [690, y_off+30, 720, y_off+60]);
% 
%     add_block('simulink/Math Operations/Sum', [subName '/' sum_name], ...
%         'Inputs', '+-', 'Position', [770, y_off+35, 795, y_off+65]);
% 
%     add_block('simulink/Math Operations/Gain', [subName '/' gain_name], ...
%         'Gain', sprintf('inv_tau%d', k), ...
%         'Position', [835, y_off+35, 885, y_off+65]);
% 
%     add_block('simulink/Continuous/Integrator', [subName '/' int_name], ...
%         'InitialCondition', '0', ...
%         'Position', [925, y_off+35, 955, y_off+65]);
% 
%     add_line(subName, 'Temp_C/1', [rk_dis_name '/1'], 'autorouting', 'on');
%     add_line(subName, 'SOC_Integrator/1', [rk_dis_name '/2'], 'autorouting', 'on');
%     add_line(subName, 'Temp_C/1', [rk_chg_name '/1'], 'autorouting', 'on');
%     add_line(subName, 'SOC_Integrator/1', [rk_chg_name '/2'], 'autorouting', 'on');
% 
%     add_line(subName, [rk_dis_name '/1'], [sw_name '/1'], 'autorouting', 'on');
%     add_line(subName, 'I_cell/1', [sw_name '/2'], 'autorouting', 'on');
%     add_line(subName, [rk_chg_name '/1'], [sw_name '/3'], 'autorouting', 'on');
% 
%     add_line(subName, 'I_cell/1', [prod_name '/1'], 'autorouting', 'on');
%     add_line(subName, [sw_name '/1'], [prod_name '/2'], 'autorouting', 'on');
% 
%     add_line(subName, [prod_name '/1'], [sum_name '/1'], 'autorouting', 'on');
%     add_line(subName, [int_name '/1'], [sum_name '/2'], 'autorouting', 'on');
%     add_line(subName, [sum_name '/1'], [gain_name '/1'], 'autorouting', 'on');
%     add_line(subName, [gain_name '/1'], [int_name '/1'], 'autorouting', 'on');
% end
% 
% % --- 8. Final Terminal Voltage Summation (V_cell = V_OCV - V_R0 - V_rc1 - V_rc2 - V_rc3) ---
% add_block('simulink/Math Operations/Sum', [subName '/V_term_Sum'], ...
%     'Inputs', '+----', 'Position', [1005, 215, 1035, 285]);
% 
% add_line(subName, 'OCV_Switch/1', 'V_term_Sum/1', 'autorouting', 'on');
% add_line(subName, 'V_R0_Prod/1', 'V_term_Sum/2', 'autorouting', 'on');
% add_line(subName, 'V_rc1_Int/1', 'V_term_Sum/3', 'autorouting', 'on');
% add_line(subName, 'V_rc2_Int/1', 'V_term_Sum/4', 'autorouting', 'on');
% add_line(subName, 'V_rc3_Int/1', 'V_term_Sum/5', 'autorouting', 'on');
% 
% add_line(subName, 'V_term_Sum/1', 'V_cell/1', 'autorouting', 'on');
% 
% % --- 9. Connect Top-Level Constant & Step Blocks to Subsystem & Scopes ---
% add_block('simulink/Sinks/Scope', [modelName '/V_cell_Scope'], ...
%     'Position', [480, 175, 515, 215]);
% add_block('simulink/Sinks/Scope', [modelName '/SOC_Scope'], ...
%     'Position', [480, 285, 515, 325]);
% 
% add_line(modelName, 'I_cell_Input/1', 'Battery_Cell_3RC/1', 'autorouting', 'on');
% add_line(modelName, 'Temp_C_Input/1', 'Battery_Cell_3RC/2', 'autorouting', 'on');
% add_line(modelName, 'V_init_Input/1', 'Battery_Cell_3RC/3', 'autorouting', 'on');
% 
% add_line(modelName, 'Battery_Cell_3RC/1', 'V_cell_Scope/1', 'autorouting', 'on');
% add_line(modelName, 'Battery_Cell_3RC/2', 'SOC_Scope/1', 'autorouting', 'on');
% 
% save_system(modelName);
% fprintf('Successfully generated and opened "%s.slx"!\n', modelName);