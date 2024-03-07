@echo off

set PROGRAM="%~1"

echo Test 1
echo This test checks that there are no arguments
%PROGRAM% > nul
if not errorlevel 1 goto err
echo No arguments
echo _________

echo Test 2
echo This test checks that there are not enough arguments
%PROGRAM% "test1.txt" "test1-out.txt" > nul
if not errorlevel 1 goto err
echo Not enough arguments
echo _________

echo Test 3
echo This test checks for argument count overflow
%PROGRAM% "test1.txt" "test1-out.txt" "123" "123" "123" > nul
if not errorlevel 1 goto err
echo Too much arguments
echo _________

echo Test 4
echo missing file test
%PROGRAM% "input.txt" "output.txt" "123" "1234" > nul
if not errorlevel 1 goto err
echo No such file
echo _________

echo Test 5 
echo (mama test) situation with multiple occurrences of the search string in the replacement string
%PROGRAM% "test2.txt" "test2-out.txt" "ma" "mama" > nul
if errorlevel 1 goto err
echo Test 5 passed
echo _________

echo Test 6 
echo default task-test check
%PROGRAM% "test1.txt" "test1-out.txt" "1231234" "zamena" > nul
if errorlevel 1 goto err
echo Test 6 passed
echo _________

echo Test 7 
echo dot-test check
%PROGRAM% "test7.txt" "test7-out.txt" "." "!" > nul
if errorlevel 1 goto err
echo Test 7 passed
echo _________

echo Test 8 
echo empty-file check
%PROGRAM% "test8.txt" "test8-out.txt" "." "!" > nul
if errorlevel 1 goto err
echo Test 8 passed
echo _________

echo Test 9 
echo new-line test
%PROGRAM% "test9.txt" "test9-out.txt" "." "!" > nul
if errorlevel 1 goto err
echo Test 9 passed
echo _________

echo All tests passed
exit /B 0

:err
echo Program testing failed
exit /B 1