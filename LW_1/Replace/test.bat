@echo off

set PROGRAM="%~1"

rem Test 1 - тест на отсутствие аргументов
%PROGRAM% > nul
if not ERRORLEVEL 1 goto err
echo Test 1 passed - No arguments
echo _________

rem Test 2 - тест на недостаточное количество аргументов
%PROGRAM% "test1.txt" "test1-out.txt" > nul
if not ERRORLEVEL 1 goto err
echo Test 2 passed - Not enough arguments
echo _________

rem Test 3 - тест на переполнение аргументами
%PROGRAM% "test1.txt" "test1-out.txt" "123" "123" "123" > nul
if not ERRORLEVEL 1 goto err
echo Test 3 passed - Arguments overflow
echo _________

rem Test 4 - тест на отсутствие входного файла
%PROGRAM% "input.txt" "output.txt" "123" "1234" > nul
if not ERRORLEVEL 2 goto err
echo Test 4 passed - No such file 
echo _________

rem Test 5 - (мама тест) проверяет ситуацию с многократным вхождением искомой строки в строку-заменитель
%PROGRAM% "test2.txt" "test2-out.txt" "ma" "mama" > nul
if not ERRORLEVEL 0 goto err
echo Test 5 passed (mama test)
echo _________

rem Test 6 - тест с возвратом при неудачном поиске
%PROGRAM% "test1.txt" "test1-out.txt" "1231234" "zamena" > nul
if not ERRORLEVEL 0 goto err
echo Test 6 passed
echo _________

rem Test 7 - проверка "большого" текста
%PROGRAM% "test7.txt" "test7-out.txt" "." "!" > nul
if not ERRORLEVEL 0 goto err
echo Test 7 passed
echo _________

rem Test 8 - проверка работы с пустым входным файлом
%PROGRAM% "test8.txt" "test8-out.txt" "." "!" > nul
if not ERRORLEVEL 0 goto err
echo Test 8 passed
echo _________

rem Test 9 - проверка вывода каретки в конце файла на новую строку
%PROGRAM% "test9.txt" "test9-out.txt" "." "!" > nul
if not ERRORLEVEL 0 goto err
echo Test 9 passed
echo _________

rem Test 10 - проверка ситуации ввода пустых аргументов строк
%PROGRAM% "test1.txt" "test10-out.txt" "" "" > nul
if not ERRORLEVEL 0 goto err
echo Test 10 passed
echo _________

echo All tests passed
exit /B 0

:err
echo Program testing failed
exit /B 1