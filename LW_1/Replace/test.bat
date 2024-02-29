@echo off

set PROGRAM="%~1"

echo Test 1
%PROGRAM% > nul
if not errorlevel 1 goto err
echo No arguments

echo Test 2
%PROGRAM% "test1.txt" "test1-out.txt" > nul
if not errorlevel 1 goto err
echo Not enough arguments

echo Test 3
%PROGRAM% "test1.txt" "test1-out.txt" "123" "123" "123" > nul
if not errorlevel 1 goto err
echo Too much arguments

echo All tests passed
exit /B 0

:err
echo Program testing failed
exit /B 1