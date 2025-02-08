@echo off
title MyCalc
echo MyCalc [Version 1.1.0]
echo (c) Wilson Corporation. All rights reserved.
echo ---------------------------------------------

:: Keep REPL loop running
:loop
gcc Input.c -o input.exe
input.exe
if %ERRORLEVEL% NEQ 0 goto loop

:: Compile dynamically generated win.h and Output.c
gcc Output.c -o output.exe
if %ERRORLEVEL% NEQ 0 goto loop

output.exe
goto loop

:: Cleanup files when CMD is closed
:cleanup
del /f /q input.exe output.exe win.h 2>nul
exit