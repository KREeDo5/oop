#pragma once
#include "gear.h"
#include "direction.h"
#include "speedLimit.h"


const std::string ENGINE_ON = "Двигатель включен";
const std::string ENGINE_OFF = "Двигатель выключен";
const std::string TURN_ON_ENGINE = "Двигатель был включен";
const std::string TURN_OFF_ERROR = "Не удалось выключить двигатель. Остановите транспорт и переключите скорость на нейтральную.";
const std::string TURN_OFF_ENGINE = "Двигатель был выключен";

const std::string OFF_ENGINE_SET_SPEED_ERROR = "Автомобиль не может ехать с выключенным двигателем. Включите двигатель.";
const std::string NEUTRAL_SET_SPEED_ERROR = "Включена нейтральная передача. Вращательный момент не передаётся на ось. Включите передачу.";
const std::string MIN_SET_SPEED_ERROR = "Скорость слишком мала для текущей передачи, понизьте передачу.";
const std::string NEGATIVE_SET_SPEED_ERROR = "Скорость не может быть отрицательной. Введите положительное значение.";
const std::string MAX_SET_SPEED_ERROR = "Скорость слишком высока для текущей передачи, повысьте передачу.";
const std::string SET_SPEED = "Скорость изменена";

const std::string INPUT_SET_GEAR = "Введите номер передачи (число от -1 до 5): ";
const std::string MIN_SET_GEAR_ERROR = "Текущая скорость не подходит для этой передачи. Увеличьте скорость.";
const std::string MAX_SET_GEAR_ERROR = "Текущая скорость не подходит для этой передачи. Понизьте скорость.";
const std::string NO_GEAR_SET_GEAR_ERROR = "Такой передачи нет. Выберите одну из предложенных ранее передач.";
const std::string DRIVE_SET_GEAR_ERROR = "Нельзя включать заднюю передачу, если вы находитесь в движении. Остановитесь и переключите передачу.";
const std::string BACK_DRIVE_GEAR_SET_GEAR_ERROR = "Нельзя включать передние передачи во время движения назад. Остановитесь и переключите передачу.";
const std::string SET_GEAR = "Передача переключена";

const std::string RECOMMEND_SPEED_FROM = "Введите скорость (от ";
const std::string RECOMMEND_SPEED_TO = " до ";
const std::string RECOMMEND_SPEED_CLOSE_BRACKET = "): ";
const std::string RECOMMEND_SPEED_ENGINE_ERROR = "Чтобы поменять скорость необходимо включить двигатель.";
const std::string RECOMMEND_SPEED_NEUTRAL_ERROR = "Чтобы поменять скорость необходимо включить передачу отличную от нейтральной.";

class Car 
{
    private:
        bool engineOn = false;                           // Состояние двигателя (включен или выключен)
        int currentSpeed = PARKING_SPEED;                // Текущая скорость движения (целое число от 0 до максимальной скорости) 
        Gear currentGear = Gear::NEUTRAL;                // Текущая выбранная передача [-1..5]
        Direction currentDirection = Direction::PARKING; // Текущее направление

    public:
        bool isTurnedOn()
        {
            return engineOn;
        }

        int getSpeed()
        {
            return currentSpeed;
        }

        int getGear()
        {
            return gearToInt(currentGear);
        }

        bool getRecommendSpeed()
        {   
            if (!engineOn) {
                std::cout << RECOMMEND_SPEED_ENGINE_ERROR << std::endl;;
                return false;
            }
            if (currentGear == Gear::NEUTRAL) {
                std::cout << RECOMMEND_SPEED_NEUTRAL_ERROR << std::endl;;
                return false;
            }
            SpeedLimit speedLimit = getSpeedLimits(currentGear);
            int minSpeed = speedLimit.getMinSpeed();
            int maxSpeed = speedLimit.getMaxSpeed();
            std::cout << RECOMMEND_SPEED_FROM << minSpeed << RECOMMEND_SPEED_TO << maxSpeed << RECOMMEND_SPEED_CLOSE_BRACKET;
            return true;
        }

        std::string getStringGear()
        {
            return gearToString(currentGear);
        }

        std::string getDirection()
        {
            return directionToString(currentDirection);
        }

        bool setSpeed(int speed)
        {    
            if (!engineOn) {
                std::cout << OFF_ENGINE_SET_SPEED_ERROR << std::endl;
                return false;
            }
            if (currentGear == Gear::NEUTRAL) {
                std::cout << NEUTRAL_SET_SPEED_ERROR << std::endl;
                return false;
            }
            SpeedLimit speedLimit = getSpeedLimits(currentGear);
            int minSpeed = speedLimit.getMinSpeed();
            int maxSpeed = speedLimit.getMaxSpeed();
            if (speed >= minSpeed && speed <= maxSpeed) {
                currentSpeed = speed;
                currentDirection = (currentGear == Gear::REVERSE)
                    ? Direction::BACK
                    : Direction::FORWARD;
                std::cout << SET_SPEED << std::endl;
                return true;
            }
            if (speed < minSpeed)
            {
                std::cout << MIN_SET_SPEED_ERROR << std::endl;
            }
            if (speed < PARKING_SPEED)
            {
                std::cout << NEGATIVE_SET_SPEED_ERROR << std::endl;
            }
            if (speed > maxSpeed)
            {
                std::cout << MAX_SET_SPEED_ERROR << std::endl;
            }
            return false;
        }

        bool setGear(int gear)
        {
            // если передачи не существует
            if (gear < gearToInt(Gear::REVERSE) || gear > gearToInt(Gear::FIFTH))
            {
                std::cout << NO_GEAR_SET_GEAR_ERROR << std::endl;
                return false;
            }

            // если передача - задняя, но сейчас скорость больше чем 0
            if (gear == gearToInt(Gear::REVERSE) && currentGear != Gear::REVERSE && currentSpeed > PARKING_SPEED)
            {
                std::cout << DRIVE_SET_GEAR_ERROR << std::endl;
                return false;
            }

            // если передача 1-5, а сейчас включена задняя и мы движемся
            if (gear > gearToInt(Gear::NEUTRAL) && currentGear == Gear::REVERSE && currentSpeed > PARKING_SPEED)
            {
                std::cout << BACK_DRIVE_GEAR_SET_GEAR_ERROR << std::endl;
                return false;
            }

            SpeedLimit speedLimit = getSpeedLimits(Gear(gear));
            int minSpeed = speedLimit.getMinSpeed();
            int maxSpeed = speedLimit.getMaxSpeed();

            // если скорость недостаточна для желаемой передачи
            if (currentSpeed < minSpeed)
            {   
                std::cout << MIN_SET_GEAR_ERROR << std::endl;
                return false;
            }

            // если скорость велика для желаемой передачи
            if (currentSpeed > maxSpeed)
            {
                std::cout << MAX_SET_GEAR_ERROR << std::endl;
                return false;
            }

            currentGear = Gear(gear);
            std::cout << SET_GEAR << std::endl;
            return true;
        }

        bool turnOnEngine()
        {   
            std::cout << TURN_ON_ENGINE << std::endl;
            engineOn = true;
            return true;
        }

        bool turnOffEngine()
        {
            if (currentGear != Gear::NEUTRAL || currentSpeed > PARKING_SPEED)
            {   
                std::cout << TURN_OFF_ERROR << std::endl;
                return false;
            }
            engineOn = false;
            std::cout << TURN_OFF_ENGINE << std::endl;
            return true;
        }
};