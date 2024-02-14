#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;


/*
  TODO: replace.exe <input file> <output file> <search string> <replace string>

    программа корректно должна обрабатывать ситуацию, когда длина искомой строки равна нулю
    В этом случае замены символов производиться не должно.
    Также корректно должна обрабатываться ситуация с многократным вхождением искомой строки в строку-заменитель
    (например, замена строки «ма» на «мама» не должна приводить к зацикливанию).
*/
string replaceString(string str, string oldWord, string newWord) {
    if (oldWord.length() == 0) return str;
    bool status = false;
    int startIndex = 0, endIndex = oldWord.length();
    //начинаем искать в строке нужные слова
    for (int i = 0; i < str.length(); i++) {
        //если нашли первую букву искомого слова, проверяем равно ли оно ему
        if (str[i] == oldWord[0]) {
            startIndex = i;
            for (int p = 0; p < oldWord.length(); p++, i++){
                if (str[i] != oldWord[p]) {
                    status = false;
                    break;
                }
                else {
                    status = true;
                }
            }
            if (status) {
                str.replace(startIndex, endIndex, newWord);
            }
        }
    }
    return str;
}

int main()
{   
    setlocale(LC_ALL, "ru");

    string inputFileName;
    string ouputFIleName;
    string searchWord;
    string replaceWord;

    cout << "Введите имя файла который надо открыть:" << endl;
    cin >> inputFileName;
    cout << endl;

    cout << "Введите имя файла в который надо сохранить:" << endl;
    cin >> ouputFIleName;
    cout << endl;

    SetConsoleCP(1251);
    cout << "Введите cлово, которое надо заменить:" << endl;
    cin >> searchWord;
    cout << endl;

    cout << "Введите cлово, которым надо заменить искомое:" << endl;
    cin >> replaceWord;
    cout << endl;

    ifstream inf;
    ofstream outf;

    inf.open(inputFileName);

    if (!inf.is_open()) {
        cout << "Ошибка открытия входного файла" << endl;
        return 1;
    } 
    
    else {
        outf.open(ouputFIleName);
        string str;
        while (getline(inf, str)) {
            str = replaceString(str, searchWord, replaceWord);
            outf << str << endl;
        }
    }

    inf.close();
    outf.close();
    SetConsoleCP(866);
    return 0;
}
