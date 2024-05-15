#include <iostream>
#include "automobile.h"

void info(Car car)
{
    bool engineStatus = car.isTurnedOn();
    if (engineStatus)
    {
        std::cout << "Двигатель включен" << std::endl;
    }
    else {
        std::cout << "Двигатель выключен" << std::endl;
    }

    std::cout << "Направление: " << car.getDirection() << std::endl;

    std::cout << "Скорость: " << car.getSpeed() << std::endl;

    std::cout << "Передача: " << car.getGear() << " (" << car.getStringGear() << ")" << std::endl;
}

int main()
{   
    setlocale(LC_ALL, "Russian");

    std::cout << "Hello World!\n";
    Car ladaNeVesta = Car();
    info(ladaNeVesta);
}