#pragma once
#include "gear.h"
#include "direction.h"
#include "speedLimit.h"

const std::string TURN_ON_ENGINE = "��������� ��� �������";
const std::string TURN_OFF_ERROR = "�� ������� ��������� ���������. ���������� ��������� � ����������� �������� �� �����������.";
const std::string TURN_OFF_ENGINE = "��������� ��� ��������";

const std::string OFF_ENGINE_SET_SPEED_ERROR = "���������� �� ����� ����� � ����������� ����������. �������� ���������.";
const std::string NEUTRAL_SET_SPEED_ERROR = "�������� ����������� ��������. ������������ ������ �� ��������� �� ���. �������� ��������.";
const std::string MIN_SET_SPEED_ERROR = "�������� ������� ���� ��� ������� ��������, �������� ��������.";
const std::string NEGATIVE_SET_SPEED_ERROR = "�������� �� ����� ���� �������������. ������� ������������� ��������.";
const std::string MAX_SET_SPEED_ERROR = "�������� ������� ������ ��� ������� ��������, �������� ��������.";

const std::string MIN_SET_GEAR_ERROR = "������� �������� �� �������� ��� ���� ��������. ��������� ��������.";
const std::string MAX_SET_GEAR_ERROR = "������� �������� �� �������� ��� ���� ��������. �������� ��������.";
const std::string NO_GEAR_SET_GEAR_ERROR = "����� �������� ���. �������� ���� �� ������������ ����� �������.";
const std::string DRIVE_SET_GEAR_ERROR = "������ �������� ������ ��������, ���� �� ���������� � ��������. ������������ � ����������� ��������.";
const std::string BACK_DRIVE_GEAR_SET_GEAR_ERROR = "������ �������� �������� �������� �� ����� �������� �����. ������������ � ����������� ��������.";

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

        int getGear()
        {
            return gearToInt(currentGear);
        }

        std::string getStringGear()
        {
            return gearToString(currentGear);
        }

        std::string getDirection()
        {
            return directionToString(currentDirection);
        }

        bool setSpeed(int speed)
        {    
            if (!engineOn) {
                std::cout << OFF_ENGINE_SET_SPEED_ERROR << std::endl;
                return false;
            }
            if (currentGear == Gear::NEUTRAL) {
                std::cout << NEUTRAL_SET_SPEED_ERROR << std::endl;
                return false;
            }
            SpeedLimit speedLimit = getSpeedLimits(currentGear);
            int minSpeed = speedLimit.getMinSpeed();
            int maxSpeed = speedLimit.getMaxSpeed();
            if (speed > minSpeed && speed < maxSpeed) {
                currentSpeed = speed;
                currentDirection = (currentGear == Gear::REVERSE) 
                    ? Direction::BACK 
                    : Direction::FORWARD;
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

        bool setGear(int gear)
        {
            // ���� �������� �� ����������
            if (gear < gearToInt(Gear::REVERSE) || gear > gearToInt(Gear::FIFTH))
            {
                std::cout << NO_GEAR_SET_GEAR_ERROR << std::endl;
                return false;
            }

            // ���� �������� - ������, �� ������ �������� ������ ��� 0
            if (gear == gearToInt(Gear::REVERSE) && currentGear != Gear::REVERSE && currentSpeed > PARKING_SPEED)
            {
                std::cout << DRIVE_SET_GEAR_ERROR << std::endl;
                return false;
            }

            // ���� �������� 1-5, � ������ �������� ������ � �� ��������
            if (gear > gearToInt(Gear::NEUTRAL) && currentGear == Gear::REVERSE && currentSpeed > PARKING_SPEED)
            {
                std::cout << BACK_DRIVE_GEAR_SET_GEAR_ERROR << std::endl;
                return false;
            }

            SpeedLimit speedLimit = getSpeedLimits(Gear(gear));
            int minSpeed = speedLimit.getMinSpeed();
            int maxSpeed = speedLimit.getMaxSpeed();

            // ���� �������� ������������ ��� �������� ��������
            if (currentSpeed < minSpeed)
            {   
                std::cout << MIN_SET_GEAR_ERROR << std::endl;
                return false;
            }

            // ���� �������� ������ ��� �������� ��������
            if (currentSpeed > maxSpeed)
            {
                std::cout << MAX_SET_GEAR_ERROR << std::endl;
                return false;
            }

            currentGear = Gear(gear);
            return true;
        }

        bool turnOnEngine()
        {   
            std::cout << TURN_ON_ENGINE << std::endl;
            engineOn = true;
            return true;
        }

        bool turnOffEngine()
        {
            if (currentGear != Gear::NEUTRAL || currentSpeed > PARKING_SPEED)
            {   
                std::cout << TURN_OFF_ERROR << std::endl;
                return false;
            }
            engineOn = false;
            std::cout << TURN_OFF_ENGINE << std::endl;
            return true;
        }
};