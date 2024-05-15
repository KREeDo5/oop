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
            return SpeedLimit(0, 20);   // ����������� �������� ��� ������ ��������
        case Gear::NEUTRAL:
            return SpeedLimit(0, 160);
        case Gear::FIRST:
            return SpeedLimit(0, 20);   // ����������� �������� ��� ������ ��������
        case Gear::SECOND:
            return SpeedLimit(0, 30);   // ����������� �������� ��� ������ ��������
        case Gear::THIRD:
            return SpeedLimit(20, 40);  // ����������� �������� ��� ������� ��������
        case Gear::FOURTH:
            return SpeedLimit(35, 50);  // ����������� �������� ��� �������� ��������
        case Gear::FIFTH:
            return SpeedLimit(45, 70);  // ����������� �������� ��� ����� ��������
        default:
            return SpeedLimit(60, 160); // ����������� �������� ��� ���� ��������� �������
    }
}