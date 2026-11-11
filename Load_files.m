% Automatically detect the directory where this startup.m file is located
startupFolder = fileparts(mfilename('fullpath'));

% Generate paths for the startup folder and ALL its subfolders, then add them
addpath(genpath(startupFolder));

% Print confirmation
disp(['Added startup folder and all subfolders to MATLAB path: ', startupFolder]);
clear startupFolder;

NBMS_Calibration;
open_system('NBMS_App.slx');