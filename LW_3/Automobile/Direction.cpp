#include "direction.h"

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