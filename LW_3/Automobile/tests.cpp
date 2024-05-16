#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "automobile.h"
#include <sstream>
//TODO: отдельная программа
SCENARIO("Двигатель можно включить и выключить")
{
    Car car;

    GIVEN("Двигатель выключен")
    {
        REQUIRE(car.isTurnedOn() == false); // Проверяем, что двигатель выключен
        WHEN("Включаем двигатель")
        {
            car.turnOnEngine(); // Включаем двигатель
            THEN("Двигатель должен быть включен")
            {
                REQUIRE(car.isTurnedOn() == true); // Проверяем, что двигатель включен
            }
        }

        WHEN("Выключаем двигатель")
        {
            car.turnOnEngine(); // Убеждаемся, что двигатель включен
            car.turnOffEngine(); // Выключаем двигатель
            THEN("Двигатель должен быть выключен")
            {
                REQUIRE(car.isTurnedOn() == false); // Проверяем, что двигатель выключен
            }
        }
    }
}

SCENARIO("Выбор допустимой передачи")
{
    Car car;

    GIVEN("Двигатель включен")
    {
        car.turnOnEngine(); // Включаем двигатель
        REQUIRE(car.isTurnedOn() == true); // Проверяем, что двигатель включен

        WHEN("Выбираем допустимую передачу")
        {
            REQUIRE(car.setGear(1) == true); // Выбираем 1 передачу
            THEN("Должна быть установлена первая передача")
            {
                REQUIRE(car.getGear() == 1); // Проверяем, что текущая передача - первая
            }
        }
    }
}

SCENARIO("Выбор недопустимой передачи")
{
    Car car;

    GIVEN("Двигатель включен")
    {
        car.turnOnEngine(); // Включаем двигатель
        REQUIRE(car.isTurnedOn() == true); // Проверяем, что двигатель включен

        WHEN("Выбираем недопустимую передачу")
        {
            REQUIRE(car.setGear(5) == true); // Выбираем 5 передачу
            THEN("Передача не должна измениться. Остаётся на нейтральной.")
            {
                REQUIRE(car.getGear() == 0); // Проверяем, что текущая передача - нейтральная
            }
        }
    }
}

SCENARIO("Выбор задней передачи в недопустимый момент")
{
    Car car;

    GIVEN("Двигатель включен")
    {
        car.turnOnEngine(); // Включаем двигатель
        REQUIRE(car.isTurnedOn() == true); // Проверяем, что двигатель включен
        REQUIRE(car.setGear(1) == true); // Выбираем 1 передачу
        REQUIRE(car.setSpeed(10) == true); // Выбираем 10 скорость

        WHEN("Выбираем недопустимую передачу")
        {
            REQUIRE(car.setGear(-1) == true); // Выбираем заднюю передачу
            THEN("Передача не должна измениться. Остаётся на первой.")
            {
                REQUIRE(car.getGear() == 0); // Проверяем, что текущая передача - нейтральная
            }
        }
    }
}
