#pragma once

class Car {
private:
    bool engineOn = false; // Состояние двигателя (включен или выключен)
    int currentGear = 0; // Текущая выбранная передача [-1..5]
    int currentSpeed = 0; // Текущая скорость движения (целое число от 0 до максимальной скорости) 

public:
    bool isTurnedOn()
    {
        return engineOn;
    }

    int getSpeed()
    {
        return currentGear;
    }

    int getGear()
    {
        return currentGear;
    }

    std::string getDirection()
    {
        if (currentSpeed == 0) {
            return "Стоим на месте";
        }
        if (currentGear > 0) {
            return "Едем вперёд";
        }
        return "Едем назад";
    }

    bool setSpeed(int speed)
        //Задать указанную скорость. Возвращает true, если скорость удалось изменить 
        // и false, если изменить скорость движения на указанную невозможно
        // (например, на нейтральной передаче нельзя разогнаться).
    {
        if (currentGear == 0) {
            return false;
        }
        return true;
    }


    //TODO: реализовать подход с использованием массивов
    bool setGear(int gear)
        //Выбрать указанную передачу [-1..5]. В случае успешного переключения передачи
        // (в том числе и на саму себя) возвращает true.
    {
        if (gear < -1 || gear > 5){
            return false;
        }
        if (gear == -1 && currentGear != -1 && currentSpeed > 0) {
            return false;
        }
        if (gear > 0 && currentGear == -1 && currentSpeed > 0) {
            return false;
        }
        currentGear = gear;
        return true;
    }

    bool turnOnEngine()
    {
        engineOn = true;
        return true;
    }

    bool turnOffEngine()
    {
        if (currentGear != 0 || currentSpeed > 0) {
            return false;
        }
        engineOn = false;
        return true;
    }
};