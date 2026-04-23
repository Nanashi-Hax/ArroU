@echo off

if "%DEVKITPRO_WIN%"=="" (
    echo [ERROR] DEVKITPRO_WIN is not set.
    exit /b 1
)

if not exist "%DEVKITPRO_WIN%" (
    echo [ERROR] DEVKITPRO_WIN path does not exist: %DEVKITPRO_WIN%
    exit /b 1
)

set DEVKITPRO=%DEVKITPRO_WIN%
set PRESET=%1

cmake --preset %PRESET%
if errorlevel 1 exit /b %errorlevel%

cmake --build --preset %PRESET%
exit /b %errorlevel%
