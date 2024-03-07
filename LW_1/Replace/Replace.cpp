#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string replaceString(string str, string oldWord, string newWord) {
    if (oldWord.length() == 0) return str;
    bool status = false;
    size_t startIndex = 0;
    size_t endIndex = oldWord.length();
    //начинаем искать в строке нужные слова
    for (size_t i = 0; i < str.length(); i++)
    {
        //если нашли первую букву искомого слова, проверяем равно ли оно ему
        if (str[i] == oldWord[0]) 
        {
            startIndex = i;
            for (size_t p = 0; p < oldWord.length(); p++, i++)
            {
                if (str[i] != oldWord[p]) 
                {
                    status = false;
                    i = startIndex + 1;
                    break;
                }
                else 
                {
                    status = true;
                }
            }
            if (status) 
            {
                str.replace(startIndex, endIndex, newWord);
            }
        }
    }
    return str;
}

int main(int argc, char* argv[]) {
    if (argc != 5)
    {
        cerr << "Invalid argument count!" << endl;
        return 1;
    }

    string inputFileName = argv[1];
    string ouputFIleName = argv[2];
    string searchString = argv[3];
    string replacingString = argv[4];
    ifstream inf;
    ofstream outf;

    inf.open(inputFileName);

    if (!inf.is_open())
    {
        cerr << "Error on opening input-file" << endl;
        return 1;
    }
    else 
    {   
        outf.open(ouputFIleName);
        if (!outf.is_open())
        {
            cerr << "Error on opening output-file" << endl;
            return 1;
        }
        string str;
        while (getline(inf, str))
        {
            str = replaceString(str, searchString, replacingString);
            outf << str << endl;
        }
    }

    inf.close();
    outf.close();
    return 0;
}