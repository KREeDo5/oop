#pragma once

#include "speedLimit.h"
#include <string>

using namespace std;

const string GEAR_REVERSE = "������ ��������";
const string GEAR_NEUTRAL = "��������";
const string GEAR_FIRST = "������ ��������";
const string GEAR_SECOND = "������ ��������";
const string GEAR_THIRD = "������ ��������";
const string GEAR_FOURTH = "�������� ��������";
const string GEAR_FIFTH = "����� ��������";
const string GEAR_UNKOWN = "����������� ��������";

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

string GearToString(Gear gear);
int GearToInt(Gear gear);
SpeedLimit GetSpeedLimits(Gear gear);