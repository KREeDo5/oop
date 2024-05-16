#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "automobile.h"
#include <sstream>
//TODO: ��������� ���������
SCENARIO("��������� ����� �������� � ���������")
{
    Car car;

    GIVEN("��������� ��������")
    {
        REQUIRE(car.isTurnedOn() == false); // ���������, ��� ��������� ��������
        WHEN("�������� ���������")
        {
            car.turnOnEngine(); // �������� ���������
            THEN("��������� ������ ���� �������")
            {
                REQUIRE(car.isTurnedOn() == true); // ���������, ��� ��������� �������
            }
        }

        WHEN("��������� ���������")
        {
            car.turnOnEngine(); // ����������, ��� ��������� �������
            car.turnOffEngine(); // ��������� ���������
            THEN("��������� ������ ���� ��������")
            {
                REQUIRE(car.isTurnedOn() == false); // ���������, ��� ��������� ��������
            }
        }
    }
}

SCENARIO("����� ���������� ��������")
{
    Car car;

    GIVEN("��������� �������")
    {
        car.turnOnEngine(); // �������� ���������
        REQUIRE(car.isTurnedOn() == true); // ���������, ��� ��������� �������

        WHEN("�������� ���������� ��������")
        {
            REQUIRE(car.setGear(1) == true); // �������� 1 ��������
            THEN("������ ���� ����������� ������ ��������")
            {
                REQUIRE(car.getGear() == 1); // ���������, ��� ������� �������� - ������
            }
        }
    }
}

SCENARIO("����� ������������ ��������")
{
    Car car;

    GIVEN("��������� �������")
    {
        car.turnOnEngine(); // �������� ���������
        REQUIRE(car.isTurnedOn() == true); // ���������, ��� ��������� �������

        WHEN("�������� ������������ ��������")
        {
            REQUIRE(car.setGear(5) == true); // �������� 5 ��������
            THEN("�������� �� ������ ����������. ������� �� �����������.")
            {
                REQUIRE(car.getGear() == 0); // ���������, ��� ������� �������� - �����������
            }
        }
    }
}

SCENARIO("����� ������ �������� � ������������ ������")
{
    Car car;

    GIVEN("��������� �������")
    {
        car.turnOnEngine(); // �������� ���������
        REQUIRE(car.isTurnedOn() == true); // ���������, ��� ��������� �������
        REQUIRE(car.setGear(1) == true); // �������� 1 ��������
        REQUIRE(car.setSpeed(10) == true); // �������� 10 ��������

        WHEN("�������� ������������ ��������")
        {
            REQUIRE(car.setGear(-1) == true); // �������� ������ ��������
            THEN("�������� �� ������ ����������. ������� �� ������.")
            {
                REQUIRE(car.getGear() == 0); // ���������, ��� ������� �������� - �����������
            }
        }
    }
}
