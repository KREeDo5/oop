#pragma once

#include "car.h"

using namespace std;

map<string, string> Car::info()
{
    map<string, string> carInfo;
    carInfo["engineStatus"] = IsTurnedOn() ? ENGINE_ON : ENGINE_OFF;
    carInfo["direction"] = GetDirection();
    carInfo["speed"] = to_string(GetSpeed());
    carInfo["gear"] = to_string(GetGear());
    carInfo["stringGear"] = GetStringGear();
    return carInfo;
}

map<string, int> Car::GetRecommendSpeed()
{
    map<string, int> recommendSpeed;
    recommendSpeed["error"] = 0;
    if (!engineOn) {
        recommendSpeed["error"] = 1;
        return recommendSpeed;
    }
    if (currentGear == Gear::NEUTRAL && currentSpeed == PARKING_SPEED) {
        recommendSpeed["error"] = 2;
        return recommendSpeed;
    }
    SpeedLimit speedLimit = GetSpeedLimits(currentGear);
    recommendSpeed["minSpeed"] = speedLimit.GetMinSpeed();
    recommendSpeed["maxSpeed"] = speedLimit.GetMaxSpeed();
    return recommendSpeed;
}

bool Car::IsTurnedOn()
{
    return engineOn;
}

int Car::GetSpeed()
{
    return currentSpeed;
}
int Car::GetGear()
{
    return GearToInt(currentGear);
}

string Car::GetStringGear()
{
    return GearToString(currentGear);
}

string Car::GetDirection()
{
    return DirectionToString(currentDirection);
}

bool Car::TurnOnEngine()
{
    engineOn = true;
    return true;
}

bool Car::TurnOffEngine()
{
    if (currentGear != Gear::NEUTRAL || currentSpeed > PARKING_SPEED)
    {
        return false;
    }
    engineOn = false;
    return true;
}

bool Car::SetSpeed(int speed, function<void()> onSuccess, function<void(int)> onError)
{
    if (!engineOn) {
        onError(1);
        return false;
    }
    if (currentGear == Gear::NEUTRAL && currentSpeed == PARKING_SPEED) {
        onError(2);
        return false;
    }

    SpeedLimit speedLimit = GetSpeedLimits(currentGear);
    int minSpeed = speedLimit.GetMinSpeed();
    int maxSpeed = speedLimit.GetMaxSpeed();

    if (speed >= minSpeed && speed <= maxSpeed) {
        currentSpeed = speed;
        currentDirection = (currentGear == Gear::REVERSE)
            ? Direction::BACK
            : Direction::FORWARD;
        onSuccess();
        return true;
    }
    if (speed < minSpeed)
    {
        onError(3);
    }
    if (speed < PARKING_SPEED)
    {
        onError(4);
    }
    if (speed > maxSpeed)
    {
        onError(5);
    }
    return false;
}

bool Car::SetGear(int gear, function<void()> onSuccess, function<void(int)> onError)
{
    // если передачи не существует
    if (gear < GearToInt(Gear::REVERSE) || gear > GearToInt(Gear::FIFTH))
    {
        onError(1);
        return false;
    }

    // если передача - задняя, но сейчас скорость больше чем 0
    if (gear == GearToInt(Gear::REVERSE) && currentGear != Gear::REVERSE && currentSpeed > PARKING_SPEED)
    {
        onError(2);
        return false;
    }

    // если передача 1-5, а сейчас включена задняя и мы движемся
    if (gear > GearToInt(Gear::NEUTRAL) && currentGear == Gear::REVERSE && currentSpeed > PARKING_SPEED)
    {
        onError(3);
        return false;
    }

    SpeedLimit speedLimit = GetSpeedLimits(Gear(gear));
    int minSpeed = speedLimit.GetMinSpeed();
    int maxSpeed = speedLimit.GetMaxSpeed();

    // если скорость недостаточна для желаемой передачи
    if (currentSpeed < minSpeed)
    {
        onError(4);
        return false;
    }

    // если скорость велика для желаемой передачи
    if (currentSpeed > maxSpeed)
    {
        onError(5);
        return false;
    }

    currentGear = Gear(gear);
    onSuccess();
    return true;
}

SpeedLimit Car::GetSpeedLimits(Gear gear)
{
    switch (gear)
    {
    case Gear::REVERSE:
        return SpeedLimit(PARKING_SPEED, REVERSE_MAX_SPEED);
    case Gear::NEUTRAL:
        return SpeedLimit(PARKING_SPEED, currentSpeed);
    case Gear::FIRST:
        return SpeedLimit(PARKING_SPEED, FIRST_MAX_SPEED);
    case Gear::SECOND:
        return SpeedLimit(SECOND_MIN_SPEED, SECOND_MAX_SPEED);
    case Gear::THIRD:
        return SpeedLimit(THIRD_MIN_SPEED, THIRD_MAX_SPEED);
    case Gear::FOURTH:
        return SpeedLimit(FOURTH_MIN_SPEED, FOURTH_MAX_SPEED);
    default:
        return SpeedLimit(DEFAULT_MIN_SPEED, MAX_SPEED);
    }
}