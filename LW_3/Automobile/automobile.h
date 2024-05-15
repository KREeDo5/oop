#pragma once
#include "gear.h"
#include "direction.h"
#include "speedLimit.h"

const int PARKING_SPEED = 0;
const std::string NEUTRAL_SET_SPEED_ERROR = "Включена нейтральная передача. Вращательный момент не передаётся на ось. Включите передачу.";
const std::string MIN_SET_SPEED_ERROR = "Скорость слишком мала для текущей передачи, понизьте передачу.";
const std::string NEGATIVE_SET_SPEED_ERROR = "Скорость не может быть отрицательной. Введите положительное значение.";
const std::string MAX_SET_SPEED_ERROR = "Скорость слишком высока для текущей передачи, повысьте передачу.";

class Car 
{
    private:
        bool engineOn = false;                           // Состояние двигателя (включен или выключен)
        int currentSpeed = PARKING_SPEED;                // Текущая скорость движения (целое число от 0 до максимальной скорости) 
        Gear currentGear = Gear::NEUTRAL;                // Текущая выбранная передача [-1..5]
        Direction currentDirection = Direction::PARKING; // Текущее направление

    public:
        bool isTurnedOn()
        {
            return engineOn;
        }

        int getSpeed()
        {
            return currentSpeed;
        }

        std::string getGear()
        {
            return gearToString(currentGear);
        }

        std::string getDirection()
        {
            return directionToString(currentDirection);
        }

        bool setSpeed(int speed)
        {
            if (currentGear == Gear::NEUTRAL) {
                std::cout << NEUTRAL_SET_SPEED_ERROR << std::endl;
                return false;
            }
            SpeedLimit speedLimit = getSpeedLimits(currentGear);
            int minSpeed = speedLimit.getMinSpeed();
            int maxSpeed = speedLimit.getMaxSpeed();
            if (speed > minSpeed && speed < maxSpeed) {
                currentSpeed = speed;
                return true;
            }
            if (speed < minSpeed)
            {
                std::cout << MIN_SET_SPEED_ERROR << std::endl;
            }
            if (speed < PARKING_SPEED)
            {
                std::cout << NEGATIVE_SET_SPEED_ERROR << std::endl;
            }
            if (speed > minSpeed)
            {
                std::cout << MAX_SET_SPEED_ERROR << std::endl;
            }
            return false;
        }

        //TODO: реализовать подход с использованием массивов
        bool setGear(int gear)
            //Выбрать указанную передачу [-1..5]. В случае успешного переключения передачи
            // (в том числе и на саму себя) возвращает true.
        {
            // если передачи не существует
            if (gear < gearToInt(Gear::REVERSE) || gear > gearToInt(Gear::FIFTH))
            {
                return false;
            }
            // если передача - задняя, но сейчас скорость больше чем 0
            if (gear == gearToInt(Gear::REVERSE) && currentGear != Gear::REVERSE && currentSpeed > PARKING_SPEED)
            {
                return false;
            }
            // если передача 1-5, а сейчас включена задняя и мы движемся - 
            if (gear > gearToInt(Gear::NEUTRAL) && currentGear == Gear::REVERSE && currentSpeed > PARKING_SPEED)
            {
                return false;
            }
            currentGear = Gear(gear);
            return true;
        }

        bool turnOnEngine()
        {
            engineOn = true;
            return true;
        }

        bool turnOffEngine()
        {
            if (currentGear != Gear::NEUTRAL || currentSpeed > PARKING_SPEED)
            {
                return false;
            }
            engineOn = false;
            return true;
        }
};