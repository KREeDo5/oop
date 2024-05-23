#pragma once

#include <iostream>
#include <map>
#include <string>
#include <functional>

#include "gear.h"
#include "direction.h"
#include "speedLimit.h"

const string ENGINE_ON = "��������� �������";
const string ENGINE_OFF = "��������� ��������";
const int SUCCESS = 0;
const int ENGINE_IS_OFF = 1;
const int NEUTRAL_SPEED_ERROR = 2;
const int OVER_MIN_SPEED_ERROR = 3;
const int NEGATIVE_SPEED_ERROR = 4;
const int OVER_MAX_SPEED_ERROR = 5;

const int DEFAULT_GEAR_ERROR = 1;
const int REVERSE_SPEED_ERROR = 2;
const int REVERSE_GEAR_ERROR = 3;
const int RANGE_SPEED_MIN_ERROR = 4;
const int RANGE_SPEED_MAX_ERROR = 5;

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

    private: //TODO: _____________________________________________���������� ������ ��� ������ �������� ��� ������____________________________________________________________________
        bool engineOn = false;                           // ��������� ��������� (������� ��� ��������)
        int currentSpeed = PARKING_SPEED;                // ������� �������� �������� (����� ����� �� 0 �� ������������ ��������)
        Gear currentGear = Gear::NEUTRAL;                // ������� ��������� �������� [-1..5]
        Direction currentDirection = Direction::PARKING; // ������� �����������
};