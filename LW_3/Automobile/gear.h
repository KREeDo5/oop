#pragma once

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

std::pair<int, int> getSpeedLimits(Gear gear)
{
    switch (gear)
    {
    case Gear::REVERSE:
        return std::make_pair(0, 20);   // ����������� �������� ��� ������ ��������
    case Gear::NEUTRAL:
        return std::make_pair(0, 0);
    case Gear::FIRST:
        return std::make_pair(0, 20);   // ����������� �������� ��� ������ ��������
    case Gear::SECOND:
        return std::make_pair(0, 30);   // ����������� �������� ��� ������ ��������
    case Gear::THIRD:
        return std::make_pair(20, 40);  // ����������� �������� ��� ������� ��������
    case Gear::FOURTH:
        return std::make_pair(35, 50);  // ����������� �������� ��� �������� ��������
    case Gear::FIFTH:
        return std::make_pair(45, 70);  // ����������� �������� ��� ����� ��������
    default:
        return std::make_pair(60, 160); // ����������� �������� ��� ���� ��������� �������
    }
}