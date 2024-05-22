#pragma once

#include <string>

using namespace std;

const string DIRECTION_FORWARD = "Едем вперёд";
const string DIRECTION_BACK = "Едем назад";
const string DIRECTION_PARKING = "Стоим на месте";

enum class Direction
{
    BACK = -1,
    PARKING = 0,
    FORWARD = 1
};

string DirectionToString(Direction direction);