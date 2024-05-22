#pragma once

using namespace std;

const string DIRECTION_FORWARD = "���� �����";
const string DIRECTION_BACK = "���� �����";
const string DIRECTION_PARKING = "����� �� �����";

enum class Direction
{
    BACK = -1,
    PARKING = 0,
    FORWARD = 1
};

string DirectionToString(Direction direction)
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