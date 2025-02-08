@echo off
title MyCalc Wrapper
echo Starting MyCalc...
echo ---------------------------------------------

:: Start Run.bat in a new CMD process
start /wait cmd /c Run.bat

:: Wait for Run.bat to finish, then clean up
echo Cleaning up temporary files...
del /f /q input.exe output.exe win.h exit_marker.txt 2>nul
echo Cleanup complete. Goodbye!
pause