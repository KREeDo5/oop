@echo off

set PROGRAM="%~1"

echo Test 1 - test check count of arguments
%PROGRAM% > nul
if %ERRORLEVEL%==1 (
    echo Test 1 passed - No arguments
    echo _________
) else (
    goto err
)


echo All tests passed
exit /B 0

:err
echo Program testing failed
exit /B 1