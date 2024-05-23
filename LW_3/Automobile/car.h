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