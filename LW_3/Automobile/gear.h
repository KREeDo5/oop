#pragma once

#include "speedLimit.h"

const std::string GEAR_REVERSE = "������ ��������";
const std::string GEAR_NEUTRAL = "��������";
const std::string GEAR_FIRST = "������ ��������";
const std::string GEAR_SECOND = "������ ��������";
const std::string GEAR_THIRD = "������ ��������";
const std::string GEAR_FOURTH = "�������� ��������";
const std::string GEAR_FIFTH = "����� ��������";
const std::string GEAR_UNKOWN = "����������� ��������";

enum class Gear
{
    REVERSE = -1,
    NEUTRAL = 0,
    FIRST = 1,
    SECOND = 2,
    THIRD = 3,
    FOURTH = 4,
    FIFTH = 5
};

std::string gearToString(Gear gear)
{
    switch (gear)
    {
        case Gear::REVERSE:
            return GEAR_REVERSE;
        case Gear::NEUTRAL:
            return GEAR_NEUTRAL;
        case Gear::FIRST:
            return GEAR_FIRST;
        case Gear::SECOND:
            return GEAR_SECOND;
        case Gear::THIRD:
            return GEAR_THIRD;
        case Gear::FOURTH:
            return GEAR_FOURTH;
        case Gear::FIFTH:
            return GEAR_FIFTH;
        default:
            return GEAR_UNKOWN;
    }
}

int gearToInt(Gear gear)
{
    return static_cast<int>(gear);
}

SpeedLimit getSpeedLimits(Gear gear)
{
    switch (gear)
    {
        case Gear::REVERSE:
            return SpeedLimit(PARKING_SPEED, REVERSE_MAX_SPEED);   // ����������� �������� ��� ������ ��������
        case Gear::NEUTRAL:
            return SpeedLimit(PARKING_SPEED, MAX_SPEED);
        case Gear::FIRST:
            return SpeedLimit(PARKING_SPEED, FIRST_MAX_SPEED);     // ����������� �������� ��� ������ ��������
        case Gear::SECOND:
            return SpeedLimit(SECOND_MIN_SPEED, SECOND_MAX_SPEED); // ����������� �������� ��� ������ ��������
        case Gear::THIRD:
            return SpeedLimit(THIRD_MIN_SPEED, THIRD_MAX_SPEED);   // ����������� �������� ��� ������� ��������
        case Gear::FOURTH:
            return SpeedLimit(FOURTH_MIN_SPEED, FOURTH_MAX_SPEED); // ����������� �������� ��� �������� ��������
        default:
            return SpeedLimit(DEFAULT_MIN_SPEED, MAX_SPEED);       // ����������� �������� ��� ���� ��������� �������
    }
}