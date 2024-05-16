#pragma once

#include "gear.h"
#include "direction.h"
#include "speedLimit.h"


const std::string ENGINE_ON = "��������� �������";
const std::string ENGINE_OFF = "��������� ��������";
const std::string TURN_ON_ENGINE = "��������� ��� �������";
const std::string TURN_OFF_ERROR = "�� ������� ��������� ���������. ���������� ��������� � ����������� �������� �� �����������.";
const std::string TURN_OFF_ENGINE = "��������� ��� ��������";

const std::string OFF_ENGINE_SET_SPEED_ERROR = "���������� �� ����� ����� � ����������� ����������. �������� ���������.";
const std::string NEUTRAL_SET_SPEED_ERROR = "�������� ����������� ��������. ������������ ������ �� ��������� �� ���. �������� ��������.";
const std::string MIN_SET_SPEED_ERROR = "�������� ������� ���� ��� ������� ��������, �������� ��������.";
const std::string NEGATIVE_SET_SPEED_ERROR = "�������� �� ����� ���� �������������. ������� ������������� ��������.";
const std::string MAX_SET_SPEED_ERROR = "�������� ������� ������ ��� ������� ��������, �������� ��������.";
const std::string SET_SPEED = "�������� ��������";

const std::string INPUT_SET_GEAR = "������� ����� �������� (����� �� -1 �� 5): ";
const std::string MIN_SET_GEAR_ERROR = "������� �������� �� �������� ��� ���� ��������. ��������� ��������.";
const std::string MAX_SET_GEAR_ERROR = "������� �������� �� �������� ��� ���� ��������. �������� ��������.";
const std::string NO_GEAR_SET_GEAR_ERROR = "����� �������� ���. �������� ���� �� ������������ ����� �������.";
const std::string DRIVE_SET_GEAR_ERROR = "������ �������� ������ ��������, ���� �� ���������� � ��������. ������������ � ����������� ��������.";
const std::string BACK_DRIVE_GEAR_SET_GEAR_ERROR = "������ �������� �������� �������� �� ����� �������� �����. ������������ � ����������� ��������.";
const std::string SET_GEAR = "�������� �����������";

const std::string RECOMMEND_SPEED_FROM = "������� �������� (�� ";
const std::string RECOMMEND_SPEED_TO = " �� ";
const std::string RECOMMEND_SPEED_CLOSE_BRACKET = "): ";
const std::string RECOMMEND_SPEED_ENGINE_ERROR = "����� �������� �������� ���������� �������� ���������.";
const std::string RECOMMEND_SPEED_NEUTRAL_ERROR = "����� �������� �������� ���������� �������� �������� �������� �� �����������.";

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

        bool GetRecommendSpeed()
        {   
            if (!engineOn) {
                std::cout << RECOMMEND_SPEED_ENGINE_ERROR << std::endl;;
                return false;
            }
            if (currentGear == Gear::NEUTRAL) {
                std::cout << RECOMMEND_SPEED_NEUTRAL_ERROR << std::endl;;
                return false;
            }
            SpeedLimit speedLimit = GetSpeedLimits(currentGear);
            int minSpeed = speedLimit.GetMinSpeed();
            int maxSpeed = speedLimit.GetMaxSpeed();
            std::cout << RECOMMEND_SPEED_FROM << minSpeed << RECOMMEND_SPEED_TO << maxSpeed << RECOMMEND_SPEED_CLOSE_BRACKET;
            return true;
        }

        std::string GetStringGear()
        {
            return GearToString(currentGear);
        }

        std::string GetDirection()
        {
            return DirectionToString(currentDirection);
        }

        bool SetSpeed(int speed)
        {    
            if (!engineOn) {
                std::cout << OFF_ENGINE_SET_SPEED_ERROR << std::endl;
                return false;
            }
            if (currentGear == Gear::NEUTRAL) {
                std::cout << NEUTRAL_SET_SPEED_ERROR << std::endl;
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
                std::cout << SET_SPEED << std::endl;
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
            if (speed > maxSpeed)
            {
                std::cout << MAX_SET_SPEED_ERROR << std::endl;
            }
            return false;
        }

        bool SetGear(int gear)
        {
            // ���� �������� �� ����������
            if (gear < GearToInt(Gear::REVERSE) || gear > GearToInt(Gear::FIFTH))
            {
                std::cout << NO_GEAR_SET_GEAR_ERROR << std::endl;
                return false;
            }

            // ���� �������� - ������, �� ������ �������� ������ ��� 0
            if (gear == GearToInt(Gear::REVERSE) && currentGear != Gear::REVERSE && currentSpeed > PARKING_SPEED)
            {
                std::cout << DRIVE_SET_GEAR_ERROR << std::endl;
                return false;
            }

            // ���� �������� 1-5, � ������ �������� ������ � �� ��������
            if (gear > GearToInt(Gear::NEUTRAL) && currentGear == Gear::REVERSE && currentSpeed > PARKING_SPEED)
            {
                std::cout << BACK_DRIVE_GEAR_SET_GEAR_ERROR << std::endl;
                return false;
            }

            SpeedLimit speedLimit = GetSpeedLimits(Gear(gear));
            int minSpeed = speedLimit.GetMinSpeed();
            int maxSpeed = speedLimit.GetMaxSpeed();

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
            std::cout << SET_GEAR << std::endl;
            return true;
        }

        bool TurnOnEngine()
        {   
            std::cout << TURN_ON_ENGINE << std::endl;
            engineOn = true;
            return true;
        }

        bool TurnOffEngine()
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