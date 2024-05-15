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
        return "���� �����";
    case Direction::BACK:
        return "���� �����";
    default:
        return "����� �� �����";
    }
}

int directionToInt(Direction direction)
{
    return static_cast<int>(direction);
}