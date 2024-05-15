#pragma once
const int PARKING_SPEED = 0;

enum class Gear 
{
    REVERSE = -1,
    NEUTRAL = 0,
    FIRST = 1,
    SECOND = 2,
    THIRD = 3,
    FOURTH = 4,
    FIFTH = 5
};

std::string GearToString(Gear gear) 
{
    switch (gear) 
    {
        case Gear::REVERSE:
            return "Задняя передача";
        case Gear::NEUTRAL:
            return "Нейтраль";
        case Gear::FIRST:
            return "Первая передача";
        case Gear::SECOND:
            return "Вторая передача";
        case Gear::THIRD:
            return "Третья передача";
        case Gear::FOURTH:
            return "Четвёртая передача";
        case Gear::FIFTH:
            return "Пятая передача";
        default:
            return "Неизвестная передача";
    }
}

std::pair<int, int> GetSpeedLimits(Gear gear) 
{
    switch (gear) 
    {
        case Gear::REVERSE:
            return std::make_pair(0, 20);   // Ограничение скорости для задней передачи
        case Gear::NEUTRAL:
            return std::make_pair(0, 0);
        case Gear::FIRST:
            return std::make_pair(0, 20);   // Ограничение скорости для первой передачи
        case Gear::SECOND:
            return std::make_pair(0, 30);   // Ограничение скорости для второй передачи
        case Gear::THIRD:
            return std::make_pair(20, 40);  // Ограничение скорости для третьей передачи
        case Gear::FOURTH:
            return std::make_pair(35, 50);  // Ограничение скорости для четвёртой передачи
        case Gear::FIFTH:
            return std::make_pair(45, 70);  // Ограничение скорости для пятой передачи
        default:
            return std::make_pair(60, 160); // Ограничение скорости для всех остальных передач
    }
}

class Car 
{
    private:
        bool engineOn = false;            // Состояние двигателя (включен или выключен)
        Gear currentGear = Gear::NEUTRAL; // Текущая выбранная передача [-1..5]
        int currentSpeed = PARKING_SPEED; // Текущая скорость движения (целое число от 0 до максимальной скорости) 

    public:
        bool isTurnedOn()
        {
            return engineOn;
        }

        int getSpeed()
        {
            return currentSpeed;
        }

        std::string getGear()
        {
            return GearToString(currentGear);
        }

        std::string getDirection()
        {
            if (currentSpeed == PARKING_SPEED) {
                return "Стоим на месте";
            }
            if (currentGear == Gear::REVERSE && currentSpeed > 0) {
                return "Едем назад";
            }
            return "Едем вперёд";
        }

        bool setSpeed(int speed)
            //Задать указанную скорость. Возвращает true, если скорость удалось изменить 
            // и false, если изменить скорость движения на указанную невозможно
            // (например, на нейтральной передаче нельзя разогнаться).
        {
            if (currentGear == Gear::NEUTRAL) {
                return false;
            }
            return true;
        }


        //TODO: реализовать подход с использованием массивов
        bool setGear(int gear)
            //Выбрать указанную передачу [-1..5]. В случае успешного переключения передачи
            // (в том числе и на саму себя) возвращает true.
        {
            if (gear < static_cast<int>(Gear::REVERSE) || gear > static_cast<int>(Gear::FIFTH)){
                return false;
            }
            if (gear == static_cast<int>(Gear::REVERSE) && currentGear != Gear::REVERSE && currentSpeed > PARKING_SPEED) {
                return false;
            }
            if (gear > static_cast<int>(Gear::NEUTRAL) && currentGear == Gear::REVERSE && currentSpeed > PARKING_SPEED) {
                return false;
            }
            currentGear = Gear(gear);
            return true;
        }

        bool turnOnEngine()
        {
            engineOn = true;
            return true;
        }

        bool turnOffEngine()
        {
            if (currentGear != Gear::NEUTRAL || currentSpeed > PARKING_SPEED) {
                return false;
            }
            engineOn = false;
            return true;
        }
};