#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const string ARGUMENT_COUNT_ERROR = "Invalid argument count!";
const string INPUT_OPEN_ERROR = "Error on opening input-file";
const string OUTPUT_OPEN_ERROR = "Error on opening output-file";
const string INPUT_FORMAT = "Input format: replace.exe <input file> <output file> <search string> <replace string>";
const string SPACE = " ";
const size_t SEARCH_START_POSITION = 0;
const size_t NOT_FOUND = std::string::npos;
const int SECOND_ARGUMENT = 1;
const int THIRD_ARGUMENT = 2;
const int FOURTH_ARGUMENT = 3;
const int FIVE_ARGUMENT = 4;
const int REQUIRED_QUANTITY_ARGUMENTS = 5;


std::string replaceStringOccurrences(std::string str, const std::string& oldWord, const std::string& newWord) 
{
    if (oldWord.empty()) return str;

    size_t searchPosition = SEARCH_START_POSITION;

    while ((searchPosition = str.find(oldWord, searchPosition)) != NOT_FOUND)
    {
        str.replace(searchPosition, oldWord.length(), newWord);
        searchPosition += newWord.length();
    }

    return str;
}

int main(int argc, char* argv[])
{

    if (argc != REQUIRED_QUANTITY_ARGUMENTS)
    {
        cerr << ARGUMENT_COUNT_ERROR + SPACE + INPUT_FORMAT << endl;
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
        return 2;
    }
    outf.open(ouputFIleName);
    if (!outf.is_open())
    {
        cerr << OUTPUT_OPEN_ERROR << endl;
        return 3;
    }
    string str;
    while (getline(inf, str))
    {
        str = replaceStringOccurrences(str, searchString, replacingString);
        outf << str << endl;
    }

    inf.close();
    outf.close();
    return 0;
}