@echo off
title MyCalc
echo MyCalc [Version 1.1.0]
echo (c) Wilson Corporation. All rights reserved.
echo ---------------------------------------------

:: Keep REPL loop running
:loop
gcc Input.c -o input.exe
input.exe
if exist exit_marker.txt (
    del /f /q exit_marker.txt
    goto cleanup
)

:: Compile dynamically generated win.h and Output.c
gcc Output.c -o output.exe
if %ERRORLEVEL% NEQ 0 goto loop

output.exe
goto loop

:: Cleanup files when exiting
:cleanup
exit