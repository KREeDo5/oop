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
            return "������ ��������";
        case Gear::NEUTRAL:
            return "��������";
        case Gear::FIRST:
            return "������ ��������";
        case Gear::SECOND:
            return "������ ��������";
        case Gear::THIRD:
            return "������ ��������";
        case Gear::FOURTH:
            return "�������� ��������";
        case Gear::FIFTH:
            return "����� ��������";
        default:
            return "����������� ��������";
    }
}

std::pair<int, int> GetSpeedLimits(Gear gear) 
{
    switch (gear) 
    {
        case Gear::REVERSE:
            return std::make_pair(0, 20);   // ����������� �������� ��� ������ ��������
        case Gear::NEUTRAL:
            return std::make_pair(0, 0);
        case Gear::FIRST:
            return std::make_pair(0, 20);   // ����������� �������� ��� ������ ��������
        case Gear::SECOND:
            return std::make_pair(0, 30);   // ����������� �������� ��� ������ ��������
        case Gear::THIRD:
            return std::make_pair(20, 40);  // ����������� �������� ��� ������� ��������
        case Gear::FOURTH:
            return std::make_pair(35, 50);  // ����������� �������� ��� �������� ��������
        case Gear::FIFTH:
            return std::make_pair(45, 70);  // ����������� �������� ��� ����� ��������
        default:
            return std::make_pair(60, 160); // ����������� �������� ��� ���� ��������� �������
    }
}

class Car 
{
    private:
        bool engineOn = false;            // ��������� ��������� (������� ��� ��������)
        Gear currentGear = Gear::NEUTRAL; // ������� ��������� �������� [-1..5]
        int currentSpeed = PARKING_SPEED; // ������� �������� �������� (����� ����� �� 0 �� ������������ ��������) 

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
                return "����� �� �����";
            }
            if (currentGear == Gear::REVERSE && currentSpeed > 0) {
                return "���� �����";
            }
            return "���� �����";
        }

        bool setSpeed(int speed)
            //������ ��������� ��������. ���������� true, ���� �������� ������� �������� 
            // � false, ���� �������� �������� �������� �� ��������� ����������
            // (��������, �� ����������� �������� ������ �����������).
        {
            if (currentGear == Gear::NEUTRAL) {
                return false;
            }
            return true;
        }


        //TODO: ����������� ������ � �������������� ��������
        bool setGear(int gear)
            //������� ��������� �������� [-1..5]. � ������ ��������� ������������ ��������
            // (� ��� ����� � �� ���� ����) ���������� true.
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