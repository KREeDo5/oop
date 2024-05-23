#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "car.cpp"
#include <sstream>

SCENARIO("��������� ����� �������� � ���������")
{
    Car car;

    GIVEN("��������� ��������")
    {   
        REQUIRE(car.IsTurnedOn() == false); // ���������, ��� ��������� ��������
        WHEN("�������� ���������")
        {
            car.TurnOnEngine(); // �������� ���������
            THEN("��������� ������ ���� �������")
            {
                REQUIRE(car.IsTurnedOn() == true); // ���������, ��� ��������� �������
            }
        }

        WHEN("��������� ���������")
        {
            car.TurnOnEngine(); // ����������, ��� ��������� �������
            car.TurnOffEngine(); // ��������� ���������
            THEN("��������� ������ ���� ��������")
            {
                REQUIRE(car.IsTurnedOn() == false); // ���������, ��� ��������� ��������
            }
        }
    }
}

SCENARIO("����� ���������� ��������")
{
    Car car;

    GIVEN("��������� �������")
    {
        car.TurnOnEngine(); // �������� ���������
        REQUIRE(car.IsTurnedOn() == true); // ���������, ��� ��������� �������

        WHEN("�������� ���������� ��������")
        {   
            bool onSuccessCalled = false;
            bool onErrorCalled = false;

            auto onSuccess = [&onSuccessCalled]()
            {
                onSuccessCalled = true;
            };

            auto onError = [&onErrorCalled](int error)
            {
                onErrorCalled = true;
            };

            REQUIRE(car.SetGear(1, onSuccess, onError) == true); // �������� 1 ��������

            THEN("������ ���� ����������� ������ ��������")
            {
                REQUIRE(car.GetGear() == 1); // ���������, ��� ������� �������� - ������
                REQUIRE(onSuccessCalled == true); // ���������, ��� onSuccess ��� ������
                REQUIRE(onErrorCalled == false); // ���������, ��� onError �� ��� ������
            }
        }
    }
}

SCENARIO("����� ������������ ��������")
{
    Car car;

    GIVEN("��������� �������")
    {
        car.TurnOnEngine(); // �������� ���������
        REQUIRE(car.IsTurnedOn() == true); // ���������, ��� ��������� �������

        WHEN("�������� ������������ ��������")
        {
            bool onSuccessCalled = false;
            bool onErrorCalled = false;

            auto onSuccess = [&onSuccessCalled]()
            {
                onSuccessCalled = true;
            };

            auto onError = [&onErrorCalled](int error)
            {
                onErrorCalled = true;
            };

            REQUIRE(car.SetGear(5, onSuccess, onError) == false); // �������� 5 ��������

            THEN("�������� �� ������ ����������. ������� �� �����������.")
            {
                REQUIRE(car.GetGear() == 0); // ���������, ��� ������� �������� - �����������
                REQUIRE(onSuccessCalled == false); // ���������, ��� onSuccess �� ��� ������
                REQUIRE(onErrorCalled == true); // ���������, ��� onError ��� ������
            }
        }
    }
}

SCENARIO("����� ��������")
{
    Car car;

    GIVEN("��������� �������")
    {
        car.TurnOnEngine(); // �������� ���������
        REQUIRE(car.IsTurnedOn() == true); // ���������, ��� ��������� �������

        WHEN("�������� ����������� ��������")
        {
            bool onSuccessCalled = false;
            bool onErrorCalled = false;

            auto onSuccess = [&onSuccessCalled]()
                {
                    onSuccessCalled = true;
                };

            auto onError = [&onErrorCalled](int error)
                {
                    onErrorCalled = true;
                };

            REQUIRE(car.SetGear(1, onSuccess, onError) == true); // �������� 1 ��������
           
            onSuccessCalled = false;
            onErrorCalled = false;

            REQUIRE(car.SetSpeed(10, onSuccess, onError) == true); // �������� 10 ��������

            THEN("�������� ������ ����������.")
            {
                REQUIRE(car.currentSpeed == 10); // ���������, ��� ������� �������� - ������
                REQUIRE(onSuccessCalled == true); // ���������, ��� onSuccess ��� ������
                REQUIRE(onErrorCalled == false); // ���������, ��� onError �� ��� ������
            }
        }
    }
}

SCENARIO("����� ������ �������� � ������������ ������")
{
    Car car;

    GIVEN("��������� �������")
    {
        car.TurnOnEngine(); // �������� ���������
        REQUIRE(car.IsTurnedOn() == true); // ���������, ��� ��������� �������

        WHEN("�������� ������������ ��������")
        {
            bool onSuccessCalled = false;
            bool onErrorCalled = false;

            auto onSuccess = [&onSuccessCalled]()
                {
                    onSuccessCalled = true;
                };

            auto onError = [&onErrorCalled](int error)
                {
                    onErrorCalled = true;
                };

            REQUIRE(car.SetGear(1, onSuccess, onError) == true); // �������� 1 ��������
            REQUIRE(car.SetSpeed(10, onSuccess, onError) == true); // �������� 10 ��������

            onSuccessCalled = false;
            onErrorCalled = false;

            REQUIRE(car.SetGear(-1, onSuccess, onError) == false); // �������� ������ ��������

            THEN("�������� �� ������ ����������. ������� �� ������.")
            {
                REQUIRE(car.GetGear() == 1); // ���������, ��� ������� �������� - ������
                REQUIRE(onSuccessCalled == false); // ���������, ��� onSuccess �� ��� ������
                REQUIRE(onErrorCalled == true); // ���������, ��� onError ��� ������
            }
        }
    }
};