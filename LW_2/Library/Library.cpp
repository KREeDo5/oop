#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include "windows.h"
using namespace std;

const string CHANGES_SAVED = "Изменения сохранены.";
const string CHANGES_NOT_SAVED = "Изменения не сохранены.";
const string EMPTY_CHANGES = "Изменений не было.";
const string HAS_CHANGES_TAKE_CHOICE = "В словарь были внесены изменения.Введите Y или y для сохранения перед выходом.";
const string EXIT_COMMAND = "...";
const string INPUT_FORMAT = "Input format : <program_name> < library_file";

std::map<std::string, std::string> loadLibrary(const std::string& filename) 
{
    std::map<std::string, std::string> dictionary;
    std::ifstream inputFile(filename);
    std::string en, ru;

    while (getline(inputFile, en) && getline(inputFile, ru)) 
    {
        dictionary[en] = ru;
    }
    return dictionary;
}

void saveLibrary(const std::map<std::string, std::string>& library, const std::string& fileName) 
{
   //TODO: сохранять словарь
}

int main(int argc, char* argv[]) 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    if (argc != 2) 
    {
        std::cerr << INPUT_FORMAT << std::endl;
        return 1; //TODO: обработка в bat файле ошибки ввода аргументов
    }

    std::string fileName = argv[1];
    auto dictionary = loadLibrary(fileName);
    bool dictionaryChanged = false;

    std::string searchWord;

    while (true) {
        std::getline(std::cin, searchWord);
        if (searchWord == EXIT_COMMAND) break;

        //TODO: обработка ввода пользователя
    }

    if (dictionaryChanged) 
    {
        std::cout << HAS_CHANGES_TAKE_CHOICE << std::endl;
        std::string choice;
        std::getline(std::cin, choice);
        if (choice == "Y" || choice == "y") 
        {
            saveLibrary(dictionary, fileName);
            std::cout << CHANGES_SAVED << std::endl;
        }
        else 
        {
            std::cout << CHANGES_NOT_SAVED << std::endl;
        }
    }
    else 
    {
        std::cout << EMPTY_CHANGES << std::endl;
    }

    return 0;
}
