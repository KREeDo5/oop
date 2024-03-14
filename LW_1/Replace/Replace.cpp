#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const string ARGUMENT_COUNT_ERROR = "Invalid argument count!";
const string INPUT_OPEN_ERROR = "Error on opening input-file";
const string OUTPUT_OPEN_ERROR = "Error on opening output-file";
const string INPUT_FORMAT = "Input format: replace.exe <input file> <output file> <search string> <replace string>";
const int SECOND_ARGUMENT = 1;
const int THIRD_ARGUMENT = 2;
const int FOURTH_ARGUMENT = 3;
const int FIVE_ARGUMENT = 4;
const int REQUIRED_QUANTITY_ARGUMENTS = 5;

string replaceString(string str, string oldWord, string newWord) 
{
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
                status = true;
            }
            if (status) 
            {
                str.replace(startIndex, endIndex, newWord);
            }
        }
    }
    return str;
}

int main(int argc, char* argv[])
{

    if (argc != REQUIRED_QUANTITY_ARGUMENTS)
    {
        cerr << ARGUMENT_COUNT_ERROR << endl;
        cerr << INPUT_FORMAT << endl;
        return 1;
    }

    string inputFileName = argv[SECOND_ARGUMENT];
    string ouputFIleName = argv[THIRD_ARGUMENT];
    string searchString = argv[FOURTH_ARGUMENT];
    string replacingString = argv[FIVE_ARGUMENT];
    ifstream inf;
    ofstream outf;

    inf.open(inputFileName);

    if (!inf.is_open())
    {
        cerr << INPUT_OPEN_ERROR << endl;
        return 1;
    }
    outf.open(ouputFIleName);
    if (!outf.is_open())
    {
        cerr << OUTPUT_OPEN_ERROR << endl;
        return 1;
    }
    string str;
    while (getline(inf, str))
    {
        str = replaceString(str, searchString, replacingString);
        outf << str << endl;
    }

    inf.close();
    outf.close();
    return 0;
}