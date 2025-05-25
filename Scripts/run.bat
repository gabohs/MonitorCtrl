@echo off

setlocal EnableDelayedExpansion

cd /d "%~dp0.."

call Scripts\utils\colors.bat

cls

set "path_to_main=build\bin\Debug\MonitorCtrl.exe"

echo %BLUE%Building the project...%RESET%
timeout /t 1 /nobreak >nul
cmake --build build

if exist "%path_to_main%" (
    echo %GREEN%Executable found%RESET%
    timeout /t 1 /nobreak >nul
    echo Running main.exe...
    timeout /t 1 /nobreak >nul
    start cmd /k "%path_to_main%"
) else (
    echo %RED%Couldn't find executable!%RESET% - Check the value of the path_to_main variable in run.bat
    echo %YELLOW%[INFO]%RESET%: Path to main is set to %path_to_main%
)
