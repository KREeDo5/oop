@echo off

set PROGRAM="%~1"

rem Test 1 - тест на отсутствие аргументов
%PROGRAM% > nul
if %ERRORLEVEL%==1 (
    echo Test 1 passed - No arguments
    echo _________
) else (
    goto err
)

rem Test 2 - тест на недостаточное количество аргументов
%PROGRAM% "test1.txt" "test1-out.txt" > nul
if %ERRORLEVEL%==1 (
    echo Test 2 passed - Not enough arguments
    echo _________
) else (
    goto err
)

rem Test 3 - тест на переполнение аргументами
%PROGRAM% "test1.txt" "test1-out.txt" "123" "123" "123" > nul
if %ERRORLEVEL%==1 (
    echo Test 3 passed - Arguments overflow
    echo _________
) else (
    goto err
)

rem Test 4 - тест на ошибку открытия входного файла
%PROGRAM% "input.txt" "output.txt" "123" "1234" > nul
if %ERRORLEVEL%==2 (
    echo Test 4 passed - No such file 
    echo _________
) else (
    goto err
)

rem Test 6 - (мама тест) проверяет ситуацию с многократным вхождением искомой строки в строку-заменитель
%PROGRAM% "test2.txt" "test2-out.txt" "ma" "mama" > nul
if not (%ERRORLEVEL%) == (0) goto err
echo Test 6 passed (mama test)
echo _________

rem Test 7 - тест с возвратом при неудачном поиске
%PROGRAM% "test1.txt" "test1-out.txt" "1231234" "zamena" > nul
if not (%ERRORLEVEL%) == (0) goto err
fc "test1-out.txt" "test1-result.txt" > nul || goto err
echo Test 7 passed
echo _________

rem Test 8 - проверка "большого" текста
%PROGRAM% "test7.txt" "test7-out.txt" "." "!" > nul
if not (%ERRORLEVEL%) == (0) goto err
fc "test7-out.txt" "test7-result.txt" > nul || goto err
echo Test 8 passed
echo _________

rem Test 9 - проверка работы с пустым входным файлом
%PROGRAM% "test8.txt" "test8-out.txt" "." "!" > nul
if not (%ERRORLEVEL%) == (0) goto err
fc "test8-out.txt" "test8-result.txt" > nul || goto err
echo Test 9 passed
echo _________

rem Test 10 - проверка вывода каретки в конце файла на новую строку
%PROGRAM% "test9.txt" "test9-out.txt" "." "!" > nul
if not (%ERRORLEVEL%) == (0) goto err
fc "test9-out.txt" "test9-result.txt" > nul || goto err
echo Test 10 passed
echo _________

rem Test 11 - проверка ситуации ввода пустых аргументов строк
%PROGRAM% "test1.txt" "test11-out.txt" "" "" > nul
if not (%ERRORLEVEL%) == (0) goto err
fc "test11-out.txt" "test11-result.txt" > nul || goto err
echo Test 11 passed
echo _________

echo All tests passed
exit /B 0

:err
echo Program testing failed
exit /B 1