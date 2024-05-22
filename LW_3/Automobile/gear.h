#pragma once

#include "speedLimit.h"

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

string GearToString(Gear gear)
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

int GearToInt(Gear gear)
{
    return static_cast<int>(gear);
}

SpeedLimit GetSpeedLimits(Gear gear)
{
    switch (gear)
    {
        case Gear::REVERSE:
            return SpeedLimit(PARKING_SPEED, REVERSE_MAX_SPEED);   // Ограничение скорости для задней передачи
        case Gear::NEUTRAL:
            return SpeedLimit(PARKING_SPEED, MAX_SPEED);
        case Gear::FIRST:
            return SpeedLimit(PARKING_SPEED, FIRST_MAX_SPEED);     // Ограничение скорости для первой передачи
        case Gear::SECOND:
            return SpeedLimit(SECOND_MIN_SPEED, SECOND_MAX_SPEED); // Ограничение скорости для второй передачи
        case Gear::THIRD:
            return SpeedLimit(THIRD_MIN_SPEED, THIRD_MAX_SPEED);   // Ограничение скорости для третьей передачи
        case Gear::FOURTH:
            return SpeedLimit(FOURTH_MIN_SPEED, FOURTH_MAX_SPEED); // Ограничение скорости для четвёртой передачи
        default:
            return SpeedLimit(DEFAULT_MIN_SPEED, MAX_SPEED);       // Ограничение скорости для всех остальных передач
    }
}