#pragma once

#include <string>

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

string DirectionToString(Direction direction);