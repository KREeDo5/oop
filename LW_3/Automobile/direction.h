#pragma once

const std::string DIRECTION_FORWARD = "Едем вперёд";
const std::string DIRECTION_BACK = "Едем назад";
const std::string DIRECTION_PARKING = "Стоим на месте";

enum class Direction
{
    BACK = -1,
    PARKING = 0,
    FORWARD = 1
};

std::string DirectionToString(Direction direction)
{
    switch (direction)
    {
        case Direction::FORWARD:
            return DIRECTION_FORWARD;
        case Direction::BACK:
            return DIRECTION_BACK;
        default:
            return DIRECTION_PARKING;
    }
}

int DirectionToInt(Direction direction)
{
    return static_cast<int>(direction);
}