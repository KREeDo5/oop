#pragma once

#include "speedLimit.h"

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
            return "������ ��������";
        case Gear::NEUTRAL:
            return "��������";
        case Gear::FIRST:
            return "������ ��������";
        case Gear::SECOND:
            return "������ ��������";
        case Gear::THIRD:
            return "������ ��������";
        case Gear::FOURTH:
            return "�������� ��������";
        case Gear::FIFTH:
            return "����� ��������";
        default:
            return "����������� ��������";
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
            return SpeedLimit(PARKING_SPEED, FIRST_MAX_SPEED);   // ����������� �������� ��� ������ ��������
        case Gear::SECOND:
            return SpeedLimit(SECOND_MIN_SPEED, SECOND_MAX_SPEED);   // ����������� �������� ��� ������ ��������
        case Gear::THIRD:
            return SpeedLimit(THIRD_MIN_SPEED, THIRD_MAX_SPEED);  // ����������� �������� ��� ������� ��������
        case Gear::FOURTH:
            return SpeedLimit(FOURTH_MIN_SPEED, FOURTH_MAX_SPEED);  // ����������� �������� ��� �������� ��������
        default:
            return SpeedLimit(DEFAULT_MIN_SPEED, MAX_SPEED); // ����������� �������� ��� ���� ��������� �������
    }
}