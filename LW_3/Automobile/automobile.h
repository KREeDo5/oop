#pragma once
#include "gear.h"
#include "direction.h"

const int PARKING_SPEED = 0;

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
            //������ ��������� ��������. ���������� true, ���� �������� ������� �������� 
            // � false, ���� �������� �������� �������� �� ��������� ����������
            // (��������, �� ����������� �������� ������ �����������).
        {
            if (currentGear == Gear::NEUTRAL) {
                return false;
            }
            return true;
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