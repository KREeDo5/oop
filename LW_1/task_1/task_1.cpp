#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{   
    setlocale(LC_ALL, "ru");

    string path = "input.txt";

    ifstream inputFile;

    inputFile.open(path);

    if (!inputFile.is_open())
    {
        cout << "Ошибка открытия файла" << endl;
    }
    else
    {
        cout << "Файл был открыт успешно" << endl;
        
        string str;

        while (!inputFile.eof())
        {   
            str = "";
            getline(inputFile, str);
            cout << str << endl;
        }
    }

    inputFile.close();

    return 0;
}
