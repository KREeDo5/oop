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
            return "Задняя передача";
        case Gear::NEUTRAL:
            return "Нейтраль";
        case Gear::FIRST:
            return "Первая передача";
        case Gear::SECOND:
            return "Вторая передача";
        case Gear::THIRD:
            return "Третья передача";
        case Gear::FOURTH:
            return "Четвёртая передача";
        case Gear::FIFTH:
            return "Пятая передача";
        default:
            return "Неизвестная передача";
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
            return SpeedLimit(PARKING_SPEED, REVERSE_MAX_SPEED);   // Ограничение скорости для задней передачи
        case Gear::NEUTRAL:
            return SpeedLimit(PARKING_SPEED, MAX_SPEED);
        case Gear::FIRST:
            return SpeedLimit(PARKING_SPEED, FIRST_MAX_SPEED);   // Ограничение скорости для первой передачи
        case Gear::SECOND:
            return SpeedLimit(SECOND_MIN_SPEED, SECOND_MAX_SPEED);   // Ограничение скорости для второй передачи
        case Gear::THIRD:
            return SpeedLimit(THIRD_MIN_SPEED, THIRD_MAX_SPEED);  // Ограничение скорости для третьей передачи
        case Gear::FOURTH:
            return SpeedLimit(FOURTH_MIN_SPEED, FOURTH_MAX_SPEED);  // Ограничение скорости для четвёртой передачи
        default:
            return SpeedLimit(DEFAULT_MIN_SPEED, MAX_SPEED); // Ограничение скорости для всех остальных передач
    }
}