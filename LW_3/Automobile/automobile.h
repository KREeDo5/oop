#pragma once

#include <iostream>
#include <map>
#include <string>
#include <functional>

using namespace std;

string DIVIDER = "________________________________\n\n";
string OPEN_BRACKET = " (";
string CLOSE_BRACKET = ")";
string ERROR = "Ошибка";

string DIRECTION_IS = "Направление: ";
string SPEED_IS = "Скорость: ";
string GEAR_IS = "Передача: ";
string EXIT = "Выход из программы.";
string INPUT_ERROR = "Некорректный ввод. Пожалуйста, введите число от 0 до 5.";
string YOUR_CHOICE = "Ваш выбор: ";
string MAKE_CHOICE = "Выберите действие:";
string MENU_INFO = "1. Вывести информацию об авто";
string MENU_ENGINE_ON = "2. Включить двигатель";
string MENU_ENGINE_OFF = "3. Выключить двигатель";
string MENU_CHANGE_GEAR = "4. Переключить передачу";
string MENU_CHANGE_SPEED = "5. Поменять скорость";
string MENU_EXIT = "0. " + EXIT;

string TURN_ON_ENGINE = "Двигатель был включен";
string TURN_OFF_ERROR = "Не удалось выключить двигатель. Остановите транспорт и переключите скорость на нейтральную.";
string TURN_OFF_ENGINE = "Двигатель был выключен";

string OFF_ENGINE_SET_SPEED_ERROR = "Автомобиль не может ехать с выключенным двигателем. Включите двигатель.";
string NEUTRAL_SET_SPEED_ERROR = "Включена нейтральная передача. Вращательный момент не передаётся на ось. Включите передачу.";
string MIN_SET_SPEED_ERROR = "Скорость слишком мала для текущей передачи, понизьте передачу.";
string NEGATIVE_SET_SPEED_ERROR = "Скорость не может быть отрицательной. Введите положительное значение.";
string MAX_SET_SPEED_ERROR = "Скорость слишком высока для текущей передачи, повысьте передачу.";
string SET_SPEED = "Скорость изменена";

string INPUT_SET_GEAR = "Введите номер передачи (число от -1 до 5): ";
string MIN_SET_GEAR_ERROR = "Текущая скорость не подходит для этой передачи. Увеличьте скорость.";
string MAX_SET_GEAR_ERROR = "Текущая скорость не подходит для этой передачи. Понизьте скорость.";
string NO_GEAR_SET_GEAR_ERROR = "Такой передачи нет. Выберите одну из предложенных ранее передач.";
string DRIVE_SET_GEAR_ERROR = "Нельзя включать заднюю передачу, если вы находитесь в движении. Остановитесь и переключите передачу.";
string BACK_DRIVE_GEAR_SET_GEAR_ERROR = "Нельзя включать передние передачи во время движения назад. Остановитесь и переключите передачу.";
string SET_GEAR = "Передача переключена";

string RECOMMEND_SPEED_FROM = "Введите скорость (от ";
string RECOMMEND_SPEED_TO = " до ";
string RECOMMEND_SPEED_CLOSE_BRACKET = "): ";
string RECOMMEND_SPEED_ENGINE_ERROR = "Чтобы поменять скорость необходимо включить двигатель.";
string RECOMMEND_SPEED_NEUTRAL_ERROR = "Чтобы поменять скорость необходимо включить передачу отличную от нейтральной.";


static void ShowMenu()
{
    cout << MAKE_CHOICE << endl;
    cout << MENU_INFO << endl;
    cout << MENU_ENGINE_ON << endl;
    cout << MENU_ENGINE_OFF << endl;
    cout << MENU_CHANGE_GEAR << endl;
    cout << MENU_CHANGE_SPEED << endl;
    cout << MENU_EXIT << endl;
}

static void ShowCarInfo(map<string, string> carInfo)
{
    cout << carInfo["engineStatus"] << endl;
    cout << DIRECTION_IS << carInfo["direction"] << endl;
    cout << SPEED_IS << carInfo["speed"] << endl;
    cout << GEAR_IS << carInfo["gear"] << OPEN_BRACKET << carInfo["stringGear"] << CLOSE_BRACKET << endl;
}

bool ShowRecommendSpeed(map<string, int> recommendSpeed)
{
    if (recommendSpeed["error"] > 0)
    {
        if (recommendSpeed["error"] == 1)
        {
            cout << RECOMMEND_SPEED_ENGINE_ERROR << endl;
        }
        if (recommendSpeed["error"] == 2)
        {
            cout << RECOMMEND_SPEED_NEUTRAL_ERROR << endl;
        }
        return false;
    }
    cout << RECOMMEND_SPEED_FROM << recommendSpeed["minSpeed"] << RECOMMEND_SPEED_TO << recommendSpeed["maxSpeed"] << RECOMMEND_SPEED_CLOSE_BRACKET;
    return true;
}

void showGearError(int error)
{
    switch (error)
    {
        case 1:
            cout << NO_GEAR_SET_GEAR_ERROR << endl;
            break;
        case 2:
            cout << DRIVE_SET_GEAR_ERROR << endl;
            break;
        case 3:
            cout << BACK_DRIVE_GEAR_SET_GEAR_ERROR << endl;
            break;
        case 4:
            cout << MIN_SET_GEAR_ERROR << endl;
            break;
        case 5:
            cout << MAX_SET_GEAR_ERROR << endl;
            break;
        default:
            cout << ERROR << endl;
    }
}

void showSpeedError(int error) 
{
    switch (error) 
    {
        case 1:
            cout << OFF_ENGINE_SET_SPEED_ERROR << endl;
            break;
        case 2:
            cout << NEUTRAL_SET_SPEED_ERROR << endl;
            break;
        case 3:
            cout << MIN_SET_SPEED_ERROR << endl;
            break;
        case 4:
            cout << NEGATIVE_SET_SPEED_ERROR << endl;
            break;
        case 5:
            cout << MAX_SET_SPEED_ERROR << endl;
            break;
        default:
            cout << ERROR << endl;
    }
}
