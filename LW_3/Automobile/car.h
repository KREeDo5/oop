#pragma once

#include <iostream>
#include <map>
#include <string>
#include <functional>

#include "gear.h"
#include "direction.h"
#include "speedLimit.h"

const string ENGINE_ON = "Двигатель включен";
const string ENGINE_OFF = "Двигатель выключен";

using namespace std;
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

        //private (public for tests)
        bool IsTurnedOn();
        int GetSpeed();
        int GetGear();
        string GetStringGear();
        string GetDirection();

        SpeedLimit GetSpeedLimits(Gear gear);

    private: //TODO: _____________________________________________релизовать методы для вывода значений для тестов____________________________________________________________________
        bool engineOn = false;                           // Состояние двигателя (включен или выключен)
        int currentSpeed = PARKING_SPEED;                // Текущая скорость движения (целое число от 0 до максимальной скорости)
        Gear currentGear = Gear::NEUTRAL;                // Текущая выбранная передача [-1..5]
        Direction currentDirection = Direction::PARKING; // Текущее направление
};