@echo off

set PROGRAM="%~1"

echo Test 1 - This test checks that there are no arguments
%PROGRAM% > nul
if not ERRORLEVEL 1 goto err
echo No arguments
echo _________

echo Test 2 - This test checks that there are not enough arguments
%PROGRAM% "test1.txt" "test1-out.txt" > nul
if not ERRORLEVEL 1 goto err
echo Not enough arguments
echo _________

echo Test 3 - This test checks for argument count overflow
%PROGRAM% "test1.txt" "test1-out.txt" "123" "123" "123" > nul
if not ERRORLEVEL 1 goto err
echo Too much arguments
echo _________

echo Test 4 - missing file test
%PROGRAM% "input.txt" "output.txt" "123" "1234" > nul
if not ERRORLEVEL 1 goto err
echo No such file
echo _________

echo Test 5 - (mama test) situation with multiple occurrences of the search string in the replacement string
%PROGRAM% "test2.txt" "test2-out.txt" "ma" "mama" > nul
if ERRORLEVEL 1 goto err
echo Test 5 passed
echo _________

echo Test 6 - default task-test check
%PROGRAM% "test1.txt" "test1-out.txt" "1231234" "zamena" > nul
if ERRORLEVEL 1 goto err
echo Test 6 passed
echo _________

echo Test 7 - dot-test check
%PROGRAM% "test7.txt" "test7-out.txt" "." "!" > nul
if ERRORLEVEL 1 goto err
echo Test 7 passed
echo _________

echo Test 8 - empty-file check
%PROGRAM% "test8.txt" "test8-out.txt" "." "!" > nul
if ERRORLEVEL 1 goto err
echo Test 8 passed
echo _________

echo Test 9 - new-line test
%PROGRAM% "test9.txt" "test9-out.txt" "." "!" > nul
if ERRORLEVEL 1 goto err
echo Test 9 passed
echo _________

echo All tests passed
exit /B 0

:err
echo Program testing failed
exit /B 1