#pragma once

#include <iostream>
#include <map>
#include <string>
#include <functional>

#include "gear.h"
#include "direction.h"
#include "speedLimit.h"

using namespace std;
//TODO: ����������� handler'�
//TODO: ����� info ������ ���� � Car (READY)
//TODO: ���������� �� ����� �������� � �������������
//TODO: ����������� ���������� ���� ������� � car.spp (� car.h ������ ����������)
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
        bool engineOn = false;                           // ��������� ��������� (������� ��� ��������)
        int currentSpeed = PARKING_SPEED;                // ������� �������� �������� (����� ����� �� 0 �� ������������ ��������)
        Gear currentGear = Gear::NEUTRAL;                // ������� ��������� �������� [-1..5]
        Direction currentDirection = Direction::PARKING; // ������� �����������

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