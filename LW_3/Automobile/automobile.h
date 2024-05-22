#pragma once

#include <iostream>
#include <map>
#include <string>
#include <functional>

using namespace std;

string DIVIDER = "________________________________\n\n";
string OPEN_BRACKET = " (";
string CLOSE_BRACKET = ")";
string ERROR = "������";

string DIRECTION_IS = "�����������: ";
string SPEED_IS = "��������: ";
string GEAR_IS = "��������: ";
string EXIT = "����� �� ���������.";
string INPUT_ERROR = "������������ ����. ����������, ������� ����� �� 0 �� 5.";
string YOUR_CHOICE = "��� �����: ";
string MAKE_CHOICE = "�������� ��������:";
string MENU_INFO = "1. ������� ���������� �� ����";
string MENU_ENGINE_ON = "2. �������� ���������";
string MENU_ENGINE_OFF = "3. ��������� ���������";
string MENU_CHANGE_GEAR = "4. ����������� ��������";
string MENU_CHANGE_SPEED = "5. �������� ��������";
string MENU_EXIT = "0. " + EXIT;

string TURN_ON_ENGINE = "��������� ��� �������";
string TURN_OFF_ERROR = "�� ������� ��������� ���������. ���������� ��������� � ����������� �������� �� �����������.";
string TURN_OFF_ENGINE = "��������� ��� ��������";

string OFF_ENGINE_SET_SPEED_ERROR = "���������� �� ����� ����� � ����������� ����������. �������� ���������.";
string NEUTRAL_SET_SPEED_ERROR = "�������� ����������� ��������. ������������ ������ �� ��������� �� ���. �������� ��������.";
string MIN_SET_SPEED_ERROR = "�������� ������� ���� ��� ������� ��������, �������� ��������.";
string NEGATIVE_SET_SPEED_ERROR = "�������� �� ����� ���� �������������. ������� ������������� ��������.";
string MAX_SET_SPEED_ERROR = "�������� ������� ������ ��� ������� ��������, �������� ��������.";
string SET_SPEED = "�������� ��������";

string INPUT_SET_GEAR = "������� ����� �������� (����� �� -1 �� 5): ";
string MIN_SET_GEAR_ERROR = "������� �������� �� �������� ��� ���� ��������. ��������� ��������.";
string MAX_SET_GEAR_ERROR = "������� �������� �� �������� ��� ���� ��������. �������� ��������.";
string NO_GEAR_SET_GEAR_ERROR = "����� �������� ���. �������� ���� �� ������������ ����� �������.";
string DRIVE_SET_GEAR_ERROR = "������ �������� ������ ��������, ���� �� ���������� � ��������. ������������ � ����������� ��������.";
string BACK_DRIVE_GEAR_SET_GEAR_ERROR = "������ �������� �������� �������� �� ����� �������� �����. ������������ � ����������� ��������.";
string SET_GEAR = "�������� �����������";

string RECOMMEND_SPEED_FROM = "������� �������� (�� ";
string RECOMMEND_SPEED_TO = " �� ";
string RECOMMEND_SPEED_CLOSE_BRACKET = "): ";
string RECOMMEND_SPEED_ENGINE_ERROR = "����� �������� �������� ���������� �������� ���������.";
string RECOMMEND_SPEED_NEUTRAL_ERROR = "����� �������� �������� ���������� �������� �������� �������� �� �����������.";


static void ShowMenu()
{
    cout << MAKE_CHOICE << endl;
    cout << MENU_INFO << endl;
    cout << MENU_ENGINE_ON << endl;
    cout << MENU_ENGINE_OFF << endl;
    cout << MENU_CHANGE_GEAR << endl;
    cout << MENU_CHANGE_SPEED << endl;
    cout << MENU_EXIT << endl;
}

static void ShowCarInfo(map<string, string> carInfo)
{
    cout << carInfo["engineStatus"] << endl;
    cout << DIRECTION_IS << carInfo["direction"] << endl;
    cout << SPEED_IS << carInfo["speed"] << endl;
    cout << GEAR_IS << carInfo["gear"] << OPEN_BRACKET << carInfo["stringGear"] << CLOSE_BRACKET << endl;
}

bool ShowRecommendSpeed(map<string, int> recommendSpeed)
{
    if (recommendSpeed["error"] > 0)
    {
        if (recommendSpeed["error"] == 1)
        {
            cout << RECOMMEND_SPEED_ENGINE_ERROR << endl;
        }
        if (recommendSpeed["error"] == 2)
        {
            cout << RECOMMEND_SPEED_NEUTRAL_ERROR << endl;
        }
        return false;
    }
    cout << RECOMMEND_SPEED_FROM << recommendSpeed["minSpeed"] << RECOMMEND_SPEED_TO << recommendSpeed["maxSpeed"] << RECOMMEND_SPEED_CLOSE_BRACKET;
    return true;
}

void showGearError(int error)
{
    switch (error)
    {
        case 1:
            cout << NO_GEAR_SET_GEAR_ERROR << endl;
            break;
        case 2:
            cout << DRIVE_SET_GEAR_ERROR << endl;
            break;
        case 3:
            cout << BACK_DRIVE_GEAR_SET_GEAR_ERROR << endl;
            break;
        case 4:
            cout << MIN_SET_GEAR_ERROR << endl;
            break;
        case 5:
            cout << MAX_SET_GEAR_ERROR << endl;
            break;
        default:
            cout << ERROR << endl;
    }
}

void showSpeedError(int error) 
{
    switch (error) 
    {
        case 1:
            cout << OFF_ENGINE_SET_SPEED_ERROR << endl;
            break;
        case 2:
            cout << NEUTRAL_SET_SPEED_ERROR << endl;
            break;
        case 3:
            cout << MIN_SET_SPEED_ERROR << endl;
            break;
        case 4:
            cout << NEGATIVE_SET_SPEED_ERROR << endl;
            break;
        case 5:
            cout << MAX_SET_SPEED_ERROR << endl;
            break;
        default:
            cout << ERROR << endl;
    }
}
