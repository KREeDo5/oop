#include <iostream>
#include "automobile.h"

const std::string DIVIDER = "________________________________\n\n";
const std::string ENGINE_ON = "Двигатель включен";
const std::string ENGINE_OFF = "Двигатель выключен";
const std::string DIRECTION_IS = "Направление: ";
const std::string SPEED_IS = "Скорость: ";
const std::string GEAR_IS = "Передача: ";
const std::string OPEN_BRACKET = " (";
const std::string CLOSE_BRACKET = ")";

void info(Car car)
{
    bool engineStatus = car.isTurnedOn();
    if (engineStatus)
    {
        std::cout << ENGINE_ON << std::endl;
    }
    else {
        std::cout << ENGINE_OFF << std::endl;
    }
    std::cout << DIRECTION_IS << car.getDirection() << std::endl;
    std::cout << SPEED_IS << car.getSpeed() << std::endl;
    std::cout << GEAR_IS << car.getGear() << OPEN_BRACKET << car.getStringGear() << CLOSE_BRACKET << std::endl;
}
/*
int main()
{   
    setlocale(LC_ALL, "Russian");

    Car ladaNeVesta;
    info(ladaNeVesta);

    ladaNeVesta.turnOnEngine();
    ladaNeVesta.setGear(-1);
    ladaNeVesta.setSpeed(10);

    std::cout << "________________________________________________" << std::endl;

    info(ladaNeVesta);

    return 0;
}
*/

int main() {
    setlocale(LC_ALL, "Russian");

    Car ladaNeVesta;

    int choice = -1;

    while (choice != 0) {
        std::cout << "Выберите действие:" << std::endl;
        std::cout << "1. Вывести информацию об авто" << std::endl;
        std::cout << "2. Включить двигатель" << std::endl;
        std::cout << "3. Выключить двигатель" << std::endl;
        std::cout << "4. Переключить передачу" << std::endl;
        std::cout << "5. Поменять скорость" << std::endl;
        std::cout << "0. Выход из программы" << std::endl;


        std::cout << "Ваш выбор: ";
        std::cin >> choice;
        std::cout << DIVIDER;

        // Проверяем, является ли введенное значение числом и находится ли в диапазоне допустимых вариантов
        if (std::cin.fail() || (choice < 0 || choice > 5)) {
            std::cout << "Некорректный ввод. Пожалуйста, введите число от 0 до 5." << std::endl;
            std::cin.clear(); // Очищаем флаг ошибки ввода
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищаем буфер ввода
           // continue; // Переходим к следующей итерации цикла
        }

        switch (choice) {
            case 1:
                info(ladaNeVesta);
                std::cout << DIVIDER;
                break;
            case 2:
                ladaNeVesta.turnOnEngine();
                std::cout << DIVIDER;
                break;
            case 3:
                ladaNeVesta.turnOffEngine();
                std::cout << DIVIDER;
                break;
            case 4:
                int gear;
                std::cout << "Введите номер передачи: ";
                std::cin >> gear;
                ladaNeVesta.setGear(gear);
                break;
            case 5:
                int speed;
                std::cout << DIVIDER;
                std::cout << "Введите скорость: ";
                std::cin >> speed;
                ladaNeVesta.setSpeed(speed);
                break;
            case 0:
                std::cout << "Выход из программы." << std::endl;
                break;
            default:
                std::cout << "Некорректный ввод. Пожалуйста, выберите действие от 0 до 5." << std::endl;
        }
    }

    return 0;
}