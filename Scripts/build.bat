@echo off
setlocal EnableDelayedExpansion

cd /d "%~dp0.."

call Scripts\utils\colors.bat

cls

if exist build (
    echo %YELLOW%Build directory detected!%RESET%
    set /p recreate_build_dir=RECREATE BUILD DIRECTORY {Y or N} 

    if /i "!recreate_build_dir!"=="Y" (
        del build
        timeout /t 2 /nobreak >nul
        echo Creating build directory...
        timeout /t 3 /nobreak >nul
        cmake -B build
        echo Build folder created!
    ) else if /i "!recreate_build_dir!"=="N" (
        echo %GREEN%Keeping existing build directory...%RESET%
        timeout /t 2 /nobreak >nul
    ) else (
        echo Invalid input! Please enter Y or N.
        exit /b 1
    )
) else (
    echo %RED%build directory not detected!%RESET%
    timeout /t 3 /nobreak >nul
    echo %BLUE%Creating build directory...%RESET%
    timeout /t 3 /nobreak >nul
    cmake -B build
    echo Build folder created!
)


timeout /t 2 /nobreak >nul
echo Now execute run.bat to build and start the program! 

endlocal