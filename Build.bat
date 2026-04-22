@echo off

set "PRESET=%~1"
if "%PRESET%"=="" set "PRESET=windows"

cmake --preset %PRESET%
if errorlevel 1 exit /b %errorlevel%

cmake --build --preset %PRESET%
exit /b %errorlevel%
