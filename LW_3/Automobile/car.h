#pragma once

#include <iostream>
#include <map>
#include <string>
#include <functional>

#include "gear.h"
#include "direction.h"
#include "speedLimit.h"

using namespace std;
//TODO: реализовать handler'ы
//TODO: метод info должен быть в Car (READY)
//TODO: Автомобиль не может общаться с пользователем
//TODO: реализовать объявление всех методов в car.spp (в car.h только объявление)
class Car {
    public:
        map<string, string> info();
        map<string, int> GetRecommendSpeed();
        bool TurnOnEngine();
        bool TurnOffEngine();
        bool SetSpeed(
            int speed, 
            function<void()> onSuccess,
            function<void(int)> onError
        );
        bool SetGear(
            int gear, 
            function<void()> onSuccess, 
            function<void(int)> onError
        );

    private:
        bool engineOn = false;                           // Состояние двигателя (включен или выключен)
        int currentSpeed = PARKING_SPEED;                // Текущая скорость движения (целое число от 0 до максимальной скорости)
        Gear currentGear = Gear::NEUTRAL;                // Текущая выбранная передача [-1..5]
        Direction currentDirection = Direction::PARKING; // Текущее направление

        bool IsTurnedOn() 
        { 
            return engineOn; 
        }
        int GetSpeed() 
        { 
            return currentSpeed; 
        }
        int GetGear() 
        { 
            return GearToInt(currentGear);
        }
        string GetStringGear();
        string GetDirection();

        SpeedLimit GetSpeedLimits(Gear gear) 
        {
            return GetSpeedLimits(currentGear);
        }
};