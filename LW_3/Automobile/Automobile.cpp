#include <iostream>
#include "automobile.h"

const std::string DIVIDER = "________________________________\n\n";
const std::string OPEN_BRACKET = " (";
const std::string CLOSE_BRACKET = ")";

const std::string DIRECTION_IS = "Направление: ";
const std::string SPEED_IS = "Скорость: ";
const std::string GEAR_IS = "Передача: ";
const std::string EXIT = "Выход из программы.";
const std::string INPUT_ERROR = "Некорректный ввод. Пожалуйста, введите число от 0 до 5.";
const std::string YOUR_CHOICE = "Ваш выбор: ";
const std::string MAKE_CHOICE = "Выберите действие:";
const std::string CHOICE_INFO = "1. Вывести информацию об авто";
const std::string CHOICE_ENGINE_ON = "2. Включить двигатель";
const std::string CHOICE_ENGINE_OFF = "3. Выключить двигатель";
const std::string CHOICE_CHANGE_GEAR = "4. Переключить передачу";
const std::string CHOICE_CHANGE_SPEED = "5. Поменять скорость";
const std::string CHOICE_EXIT = "0. " + EXIT;


void info(Car car)
{
    bool engineStatus = car.IsTurnedOn();
    if (engineStatus)
    {
        std::cout << ENGINE_ON << std::endl;
    }
    else {
        std::cout << ENGINE_OFF << std::endl;
    }
    std::cout << DIRECTION_IS << car.GetDirection() << std::endl;
    std::cout << SPEED_IS << car.GetSpeed() << std::endl;
    std::cout << GEAR_IS << car.GetGear() << OPEN_BRACKET << car.GetStringGear() << CLOSE_BRACKET << std::endl;
}

int main() {
    setlocale(LC_ALL, "Russian");

    Car car;

    int choice = -1;

    while (choice != 0) {
        std::cout << MAKE_CHOICE << std::endl;
        std::cout << CHOICE_INFO << std::endl;
        std::cout << CHOICE_ENGINE_ON << std::endl;
        std::cout << CHOICE_ENGINE_OFF << std::endl;
        std::cout << CHOICE_CHANGE_GEAR << std::endl;
        std::cout << CHOICE_CHANGE_SPEED << std::endl;
        std::cout << CHOICE_EXIT << std::endl;


        std::cout << YOUR_CHOICE;
        std::cin >> choice;
        std::cout << DIVIDER;

        

        switch (choice) {
            case 1:
                info(car);
                std::cout << DIVIDER;
                break;
            case 2:
                car.TurnOnEngine();
                std::cout << DIVIDER;
                break;
            case 3:
                car.TurnOffEngine();
                std::cout << DIVIDER;
                break;
            case 4:
                int gear;
                std::cout << INPUT_SET_GEAR;
                std::cin >> gear;
                car.SetGear(gear);
                std::cout << DIVIDER;
                break;
            case 5:
                int speed;
                bool result;
                result = car.GetRecommendSpeed();
                if (!result) {
                    std::cout << DIVIDER;
                    break;
                }
                std::cin >> speed;
                car.SetSpeed(speed);
                std::cout << DIVIDER;
                break;
            case 0:
                std::cout << EXIT << std::endl;
                break;
            default:
                std::cout << INPUT_ERROR << std::endl;
                std::cout << DIVIDER;
        }
    }

    return 0;
}