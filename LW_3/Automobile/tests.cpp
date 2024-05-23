#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "car.cpp"
#include <sstream>

SCENARIO("Двигатель можно включить и выключить")
{
    Car car;

    GIVEN("Двигатель выключен")
    {   
        REQUIRE(car.IsTurnedOn() == false); // Проверяем, что двигатель выключен
        WHEN("Включаем двигатель")
        {
            car.TurnOnEngine(); // Включаем двигатель
            THEN("Двигатель должен быть включен")
            {
                REQUIRE(car.IsTurnedOn() == true); // Проверяем, что двигатель включен
            }
        }

        WHEN("Выключаем двигатель")
        {
            car.TurnOnEngine(); // Убеждаемся, что двигатель включен
            car.TurnOffEngine(); // Выключаем двигатель
            THEN("Двигатель должен быть выключен")
            {
                REQUIRE(car.IsTurnedOn() == false); // Проверяем, что двигатель выключен
            }
        }
    }
}

SCENARIO("Выбор допустимой передачи")
{
    Car car;

    GIVEN("Двигатель включен")
    {
        car.TurnOnEngine(); // Включаем двигатель
        REQUIRE(car.IsTurnedOn() == true); // Проверяем, что двигатель включен

        WHEN("Выбираем допустимую передачу")
        {   
            bool onSuccessCalled = false;
            bool onErrorCalled = false;

            auto onSuccess = [&onSuccessCalled]()
            {
                onSuccessCalled = true;
            };

            auto onError = [&onErrorCalled](int error)
            {
                onErrorCalled = true;
            };

            REQUIRE(car.SetGear(1, onSuccess, onError) == true); // Выбираем 1 передачу

            THEN("Должна быть установлена первая передача")
            {
                REQUIRE(car.GetGear() == 1); // Проверяем, что текущая передача - первая
                REQUIRE(onSuccessCalled == true); // Проверяем, что onSuccess был вызван
                REQUIRE(onErrorCalled == false); // Проверяем, что onError не был вызван
            }
        }
    }
}

SCENARIO("Выбор недопустимой передачи")
{
    Car car;

    GIVEN("Двигатель включен")
    {
        car.TurnOnEngine(); // Включаем двигатель
        REQUIRE(car.IsTurnedOn() == true); // Проверяем, что двигатель включен

        WHEN("Выбираем недопустимую передачу")
        {
            bool onSuccessCalled = false;
            bool onErrorCalled = false;

            auto onSuccess = [&onSuccessCalled]()
            {
                onSuccessCalled = true;
            };

            auto onError = [&onErrorCalled](int error)
            {
                onErrorCalled = true;
            };

            REQUIRE(car.SetGear(5, onSuccess, onError) == false); // Выбираем 5 передачу

            THEN("Передача не должна измениться. Остаётся на нейтральной.")
            {
                REQUIRE(car.GetGear() == 0); // Проверяем, что текущая передача - нейтральная
                REQUIRE(onSuccessCalled == false); // Проверяем, что onSuccess не был вызван
                REQUIRE(onErrorCalled == true); // Проверяем, что onError был вызван
            }
        }
    }
}

SCENARIO("Выбор скорости")
{
    Car car;

    GIVEN("Двигатель включен")
    {
        car.TurnOnEngine(); // Включаем двигатель
        REQUIRE(car.IsTurnedOn() == true); // Проверяем, что двигатель включен

        WHEN("Выбираем необходимую скорость")
        {
            bool onSuccessCalled = false;
            bool onErrorCalled = false;

            auto onSuccess = [&onSuccessCalled]()
                {
                    onSuccessCalled = true;
                };

            auto onError = [&onErrorCalled](int error)
                {
                    onErrorCalled = true;
                };

            REQUIRE(car.SetGear(1, onSuccess, onError) == true); // Выбираем 1 передачу
           
            onSuccessCalled = false;
            onErrorCalled = false;

            REQUIRE(car.SetSpeed(10, onSuccess, onError) == true); // Выбираем 10 скорость

            THEN("Скорость должна измениться.")
            {
                REQUIRE(car.currentSpeed == 10); // Проверяем, что текущая передача - первая
                REQUIRE(onSuccessCalled == true); // Проверяем, что onSuccess был вызван
                REQUIRE(onErrorCalled == false); // Проверяем, что onError не был вызван
            }
        }
    }
}

SCENARIO("Выбор задней передачи в недопустимый момент")
{
    Car car;

    GIVEN("Двигатель включен")
    {
        car.TurnOnEngine(); // Включаем двигатель
        REQUIRE(car.IsTurnedOn() == true); // Проверяем, что двигатель включен

        WHEN("Выбираем недопустимую передачу")
        {
            bool onSuccessCalled = false;
            bool onErrorCalled = false;

            auto onSuccess = [&onSuccessCalled]()
                {
                    onSuccessCalled = true;
                };

            auto onError = [&onErrorCalled](int error)
                {
                    onErrorCalled = true;
                };

            REQUIRE(car.SetGear(1, onSuccess, onError) == true); // Выбираем 1 передачу
            REQUIRE(car.SetSpeed(10, onSuccess, onError) == true); // Выбираем 10 скорость

            onSuccessCalled = false;
            onErrorCalled = false;

            REQUIRE(car.SetGear(-1, onSuccess, onError) == false); // Выбираем заднюю передачу

            THEN("Передача не должна измениться. Остаётся на первой.")
            {
                REQUIRE(car.GetGear() == 1); // Проверяем, что текущая передача - первая
                REQUIRE(onSuccessCalled == false); // Проверяем, что onSuccess не был вызван
                REQUIRE(onErrorCalled == true); // Проверяем, что onError был вызван
            }
        }
    }
};