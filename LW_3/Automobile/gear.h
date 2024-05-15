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

std::pair<int, int> getSpeedLimits(Gear gear)
{
    switch (gear)
    {
    case Gear::REVERSE:
        return std::make_pair(0, 20);   // Ограничение скорости для задней передачи
    case Gear::NEUTRAL:
        return std::make_pair(0, 0);
    case Gear::FIRST:
        return std::make_pair(0, 20);   // Ограничение скорости для первой передачи
    case Gear::SECOND:
        return std::make_pair(0, 30);   // Ограничение скорости для второй передачи
    case Gear::THIRD:
        return std::make_pair(20, 40);  // Ограничение скорости для третьей передачи
    case Gear::FOURTH:
        return std::make_pair(35, 50);  // Ограничение скорости для четвёртой передачи
    case Gear::FIFTH:
        return std::make_pair(45, 70);  // Ограничение скорости для пятой передачи
    default:
        return std::make_pair(60, 160); // Ограничение скорости для всех остальных передач
    }
}