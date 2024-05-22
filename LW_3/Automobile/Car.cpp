#pragma once

#include "car.h"

using namespace std;

class Car
{
    //TODO: ����������� handler'�
    //TODO: ����� info ������ ���� � Car
    //TODO: ���������� �� ����� �������� � �������������
    //TODO: ����������� ���������� ���� ������� � car.spp (� car.h ������ ����������)
private:
    bool engineOn = false;                           // ��������� ��������� (������� ��� ��������)
    int currentSpeed = PARKING_SPEED;                // ������� �������� �������� (����� ����� �� 0 �� ������������ ��������) 
    Gear currentGear = Gear::NEUTRAL;                // ������� ��������� �������� [-1..5]
    Direction currentDirection = Direction::PARKING; // ������� �����������

public:

    map<string, string> info()
    {
        map<string, string> carInfo;
        carInfo["engineStatus"] = IsTurnedOn();
        carInfo["direction"] = GetDirection();
        carInfo["speed"] = to_string(GetSpeed());
        carInfo["gear"] = to_string(GetGear());
        carInfo["stringGear"] = GetStringGear();
        return carInfo;
    }

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

    map<string, int> GetRecommendSpeed()
    {   
        map<string, int> recommendSpeed;
        recommendSpeed["error"] = 0;
        if (!engineOn) {
            recommendSpeed["error"] = 1;
            return recommendSpeed;
        }
        if (currentGear == Gear::NEUTRAL) {
            recommendSpeed["error"] = 2;
            return recommendSpeed;
        }
        SpeedLimit speedLimit = GetSpeedLimits(currentGear);
        recommendSpeed["minSpeed"] = speedLimit.GetMinSpeed();
        recommendSpeed["maxSpeed"] = speedLimit.GetMaxSpeed();
        return recommendSpeed;
    }

    string GetStringGear()
    {
        return GearToString(currentGear);
    }

    string GetDirection()
    {
        return DirectionToString(currentDirection);
    }

    bool SetSpeed(int speed)
    {
        if (!engineOn) {
            cout << OFF_ENGINE_SET_SPEED_ERROR << endl;
            return false;
        }
        if (currentGear == Gear::NEUTRAL) {
            cout << NEUTRAL_SET_SPEED_ERROR << endl;
            return false;
        }

        SpeedLimit speedLimit = GetSpeedLimits(currentGear);
        int minSpeed = speedLimit.GetMinSpeed();
        int maxSpeed = speedLimit.GetMaxSpeed()
            ;
        if (speed >= minSpeed && speed <= maxSpeed) {
            currentSpeed = speed;
            currentDirection = (currentGear == Gear::REVERSE)
                ? Direction::BACK
                : Direction::FORWARD;
            cout << SET_SPEED << endl;
            return true;
        }
        if (speed < minSpeed)
        {
            cout << MIN_SET_SPEED_ERROR << endl;
        }
        if (speed < PARKING_SPEED)
        {
            cout << NEGATIVE_SET_SPEED_ERROR << endl;
        }
        if (speed > maxSpeed)
        {
            cout << MAX_SET_SPEED_ERROR << endl;
        }
        return false;
    }

    bool SetGear(int gear)
    {
        // ���� �������� �� ����������
        if (gear < GearToInt(Gear::REVERSE) || gear > GearToInt(Gear::FIFTH))
        {
            cout << NO_GEAR_SET_GEAR_ERROR << endl;
            return false;
        }

        // ���� �������� - ������, �� ������ �������� ������ ��� 0
        if (gear == GearToInt(Gear::REVERSE) && currentGear != Gear::REVERSE && currentSpeed > PARKING_SPEED)
        {
            cout << DRIVE_SET_GEAR_ERROR << endl;
            return false;
        }

        // ���� �������� 1-5, � ������ �������� ������ � �� ��������
        if (gear > GearToInt(Gear::NEUTRAL) && currentGear == Gear::REVERSE && currentSpeed > PARKING_SPEED)
        {
            cout << BACK_DRIVE_GEAR_SET_GEAR_ERROR << endl;
            return false;
        }

        SpeedLimit speedLimit = GetSpeedLimits(Gear(gear));
        int minSpeed = speedLimit.GetMinSpeed();
        int maxSpeed = speedLimit.GetMaxSpeed();

        // ���� �������� ������������ ��� �������� ��������
        if (currentSpeed < minSpeed)
        {
            cout << MIN_SET_GEAR_ERROR << endl;
            return false;
        }

        // ���� �������� ������ ��� �������� ��������
        if (currentSpeed > maxSpeed)
        {
            cout << MAX_SET_GEAR_ERROR << endl;
            return false;
        }

        currentGear = Gear(gear);
        cout << SET_GEAR << endl;
        return true;
    }

    bool TurnOnEngine()
    {
        engineOn = true;
        return true;
    }

    bool TurnOffEngine()
    {
        if (currentGear != Gear::NEUTRAL || currentSpeed > PARKING_SPEED)
        {
            return false;
        }
        engineOn = false;
        return true;
    }
};