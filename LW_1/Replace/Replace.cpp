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
    const string invalidArgumentError = "Invalid argument count!";
    const string inputOpenError = "Error on opening input-file";
    const string outputOpenError = "Error on opening output-file";
    const string inputFormat = "Input format: replace.exe <input file> <output file> <search string> <replace string>";
    const int firstArgument = 1;
    const int secondArgument = 2;
    const int thirdArgument = 3;
    const int fourthArgument = 4;

    const int requiredQuantityArguments = 5;

    if (argc != requiredQuantityArguments)
    {
        cerr << invalidArgumentError << endl;
        cerr << inputFormat << endl;
        return 1;
    }

    string inputFileName = argv[firstArgument];
    string ouputFIleName = argv[secondArgument];
    string searchString = argv[thirdArgument];
    string replacingString = argv[fourthArgument];
    ifstream inf;
    ofstream outf;

    inf.open(inputFileName);

    if (!inf.is_open())
    {
        cerr << inputOpenError << endl;
        return 1;
    }
    else 
    {   
        outf.open(ouputFIleName);
        if (!outf.is_open())
        {
            cerr << outputOpenError << endl;
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