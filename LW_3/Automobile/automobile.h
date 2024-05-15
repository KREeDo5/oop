#pragma once

class Car {
private:
    bool engineOn = false; // ��������� ��������� (������� ��� ��������)
    int currentGear = 0; // ������� ��������� �������� [-1..5]
    int currentSpeed = 0; // ������� �������� �������� (����� ����� �� 0 �� ������������ ��������) 

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
            return "����� �� �����";
        }
        if (currentGear > 0) {
            return "���� �����";
        }
        return "���� �����";
    }

    bool setSpeed(int speed)
        //������ ��������� ��������. ���������� true, ���� �������� ������� �������� 
        // � false, ���� �������� �������� �������� �� ��������� ����������
        // (��������, �� ����������� �������� ������ �����������).
    {
        if (currentGear == 0) {
            return false;
        }
        return true;
    }


    //TODO: ����������� ������ � �������������� ��������
    bool setGear(int gear)
        //������� ��������� �������� [-1..5]. � ������ ��������� ������������ ��������
        // (� ��� ����� � �� ���� ����) ���������� true.
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