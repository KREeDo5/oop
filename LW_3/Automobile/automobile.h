#pragma once
#include "gear.h"
#include "direction.h"
#include "speedLimit.h"

const int PARKING_SPEED = 0;
const std::string NEUTRAL_SET_SPEED_ERROR = "�������� ����������� ��������. ������������ ������ �� ��������� �� ���. �������� ��������.";
const std::string MIN_SET_SPEED_ERROR = "�������� ������� ���� ��� ������� ��������, �������� ��������.";
const std::string NEGATIVE_SET_SPEED_ERROR = "�������� �� ����� ���� �������������. ������� ������������� ��������.";
const std::string MAX_SET_SPEED_ERROR = "�������� ������� ������ ��� ������� ��������, �������� ��������.";

class Car 
{
    private:
        bool engineOn = false;                           // ��������� ��������� (������� ��� ��������)
        int currentSpeed = PARKING_SPEED;                // ������� �������� �������� (����� ����� �� 0 �� ������������ ��������) 
        Gear currentGear = Gear::NEUTRAL;                // ������� ��������� �������� [-1..5]
        Direction currentDirection = Direction::PARKING; // ������� �����������

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

        //TODO: ����������� ������ � �������������� ��������
        bool setGear(int gear)
            //������� ��������� �������� [-1..5]. � ������ ��������� ������������ ��������
            // (� ��� ����� � �� ���� ����) ���������� true.
        {
            // ���� �������� �� ����������
            if (gear < gearToInt(Gear::REVERSE) || gear > gearToInt(Gear::FIFTH))
            {
                return false;
            }
            // ���� �������� - ������, �� ������ �������� ������ ��� 0
            if (gear == gearToInt(Gear::REVERSE) && currentGear != Gear::REVERSE && currentSpeed > PARKING_SPEED)
            {
                return false;
            }
            // ���� �������� 1-5, � ������ �������� ������ � �� �������� - 
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