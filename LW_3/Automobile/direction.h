#pragma once

enum class Direction
{
    BACK = -1,
    PARKING = 0,
    FORWARD = 1
};

std::string directionToString(Direction direction)
{
    switch (direction)
    {
    case Direction::FORWARD:
        return "Едем вперёд";
    case Direction::BACK:
        return "Едем назад";
    default:
        return "Стоим на месте";
    }
}

int directionToInt(Direction direction)
{
    return static_cast<int>(direction);
}