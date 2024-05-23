#pragma once

const int PARKING_SPEED = 0;
const int REVERSE_MAX_SPEED = 20;
const int FIRST_MAX_SPEED = 30;
const int SECOND_MIN_SPEED = 20;
const int SECOND_MAX_SPEED = 50;
const int THIRD_MIN_SPEED = 30;
const int THIRD_MAX_SPEED = 60;
const int FOURTH_MIN_SPEED = 40;
const int FOURTH_MAX_SPEED = 90;
const int DEFAULT_MIN_SPEED = 50;
const int MAX_SPEED = 150;

class SpeedLimit
{
    public:
        SpeedLimit(int minSpeed, int maxSpeed) : minSpeed(minSpeed), maxSpeed(maxSpeed) {}

        int GetMinSpeed() const {
            return minSpeed;
        }

        int GetMaxSpeed() const {
            return maxSpeed;
        }

    private:
        int minSpeed;
        int maxSpeed;
};