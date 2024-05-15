#pragma once
#include "gear.h"
#include "direction.h"

const int PARKING_SPEED = 0;

class Car 
{
    private:
        bool engineOn = false;                           // —осто€ние двигател€ (включен или выключен)
        int currentSpeed = PARKING_SPEED;                // “екуща€ скорость движени€ (целое число от 0 до максимальной скорости) 
        Gear currentGear = Gear::NEUTRAL;                // “екуща€ выбранна€ передача [-1..5]
        Direction currentDirection = Direction::PARKING; // “екущее направление

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
            //«адать указанную скорость. ¬озвращает true, если скорость удалось изменить 
            // и false, если изменить скорость движени€ на указанную невозможно
            // (например, на нейтральной передаче нельз€ разогнатьс€).
        {
            if (currentGear == Gear::NEUTRAL) {
                return false;
            }
            return true;
        }

        //TODO: реализовать подход с использованием массивов
        bool setGear(int gear)
            //¬ыбрать указанную передачу [-1..5]. ¬ случае успешного переключени€ передачи
            // (в том числе и на саму себ€) возвращает true.
        {
            // если передачи не существует
            if (gear < gearToInt(Gear::REVERSE) || gear > gearToInt(Gear::FIFTH))
            {
                return false;
            }
            // если передача - задн€€, но сейчас скорость больше чем 0
            if (gear == gearToInt(Gear::REVERSE) && currentGear != Gear::REVERSE && currentSpeed > PARKING_SPEED)
            {
                return false;
            }
            // если передача 1-5, а сейчас включена задн€€ и мы движемс€ - 
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