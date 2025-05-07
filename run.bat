@echo off
setlocal EnableDelayedExpansion

set "path_to_main=build\Debug\PassGen.exe"

:: --------------------------------------------------------------------------------------------------

cls

if exist build (
    echo build directory detected!
    set /p recreate_build_dir=RECREATE BUILD DIRECTORY {Y or N} 

    if /i "!recreate_build_dir!"=="Y" (
        del build
        timeout /t 2 /nobreak >nul
        echo Creating build directory...
        timeout /t 3 /nobreak >nul
        cmake -B build
    ) else if /i "!recreate_build_dir!"=="N" (
        echo Keeping existing build directory...
    ) else (
        echo Invalid input! Please enter Y or N.
        exit /b 1
    )
) else (
    echo build directory not detected!
    echo Creating build directory...
    timeout /t 3 /nobreak >nul
    cmake -B build
)

echo Building the project...
cmake --build build

if exist "%path_to_main%" (
    echo main.exe found!
    echo Running main.exe...
    timeout /t 3 /nobreak >nul
    start cmd /k "%path_to_main%"
) else (
    echo main.exe not found! Change the value of the path_to_main variable in run.bat
)

endlocal