#pragma once

#include "speedLimit.h"
#include <string>

using namespace std;

const string GEAR_REVERSE = "Задняя передача";
const string GEAR_NEUTRAL = "Нейтраль";
const string GEAR_FIRST = "Первая передача";
const string GEAR_SECOND = "Вторая передача";
const string GEAR_THIRD = "Третья передача";
const string GEAR_FOURTH = "Четвёртая передача";
const string GEAR_FIFTH = "Пятая передача";
const string GEAR_UNKOWN = "Неизвестная передача";

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