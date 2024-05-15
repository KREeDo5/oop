#pragma once

class SpeedLimit {
public:
    SpeedLimit(int minSpeed, int maxSpeed) : minSpeed(minSpeed), maxSpeed(maxSpeed) {}

    int getMinSpeed() const {
        return minSpeed;
    }

    int getMaxSpeed() const {
        return maxSpeed;
    }

private:
    int minSpeed;
    int maxSpeed;
};