#pragma once

#include "gear.h"
#include "direction.h"
#include "speedLimit.h"

const std::string DIVIDER = "________________________________\n\n";
const std::string OPEN_BRACKET = " (";
const std::string CLOSE_BRACKET = ")";

const std::string DIRECTION_IS = "�����������: ";
const std::string SPEED_IS = "��������: ";
const std::string GEAR_IS = "��������: ";
const std::string EXIT = "����� �� ���������.";
const std::string INPUT_ERROR = "������������ ����. ����������, ������� ����� �� 0 �� 5.";
const std::string YOUR_CHOICE = "��� �����: ";
const std::string MAKE_CHOICE = "�������� ��������:";
const std::string MENU_INFO = "1. ������� ���������� �� ����";
const std::string MENU_ENGINE_ON = "2. �������� ���������";
const std::string MENU_ENGINE_OFF = "3. ��������� ���������";
const std::string MENU_CHANGE_GEAR = "4. ����������� ��������";
const std::string MENU_CHANGE_SPEED = "5. �������� ��������";
const std::string MENU_EXIT = "0. " + EXIT;

const std::string ENGINE_ON = "��������� �������";
const std::string ENGINE_OFF = "��������� ��������";
const std::string TURN_ON_ENGINE = "��������� ��� �������";
const std::string TURN_OFF_ERROR = "�� ������� ��������� ���������. ���������� ��������� � ����������� �������� �� �����������.";
const std::string TURN_OFF_ENGINE = "��������� ��� ��������";

const std::string OFF_ENGINE_SET_SPEED_ERROR = "���������� �� ����� ����� � ����������� ����������. �������� ���������.";
const std::string NEUTRAL_SET_SPEED_ERROR = "�������� ����������� ��������. ������������ ������ �� ��������� �� ���. �������� ��������.";
const std::string MIN_SET_SPEED_ERROR = "�������� ������� ���� ��� ������� ��������, �������� ��������.";
const std::string NEGATIVE_SET_SPEED_ERROR = "�������� �� ����� ���� �������������. ������� ������������� ��������.";
const std::string MAX_SET_SPEED_ERROR = "�������� ������� ������ ��� ������� ��������, �������� ��������.";
const std::string SET_SPEED = "�������� ��������";

const std::string INPUT_SET_GEAR = "������� ����� �������� (����� �� -1 �� 5): ";
const std::string MIN_SET_GEAR_ERROR = "������� �������� �� �������� ��� ���� ��������. ��������� ��������.";
const std::string MAX_SET_GEAR_ERROR = "������� �������� �� �������� ��� ���� ��������. �������� ��������.";
const std::string NO_GEAR_SET_GEAR_ERROR = "����� �������� ���. �������� ���� �� ������������ ����� �������.";
const std::string DRIVE_SET_GEAR_ERROR = "������ �������� ������ ��������, ���� �� ���������� � ��������. ������������ � ����������� ��������.";
const std::string BACK_DRIVE_GEAR_SET_GEAR_ERROR = "������ �������� �������� �������� �� ����� �������� �����. ������������ � ����������� ��������.";
const std::string SET_GEAR = "�������� �����������";

const std::string RECOMMEND_SPEED_FROM = "������� �������� (�� ";
const std::string RECOMMEND_SPEED_TO = " �� ";
const std::string RECOMMEND_SPEED_CLOSE_BRACKET = "): ";
const std::string RECOMMEND_SPEED_ENGINE_ERROR = "����� �������� �������� ���������� �������� ���������.";
const std::string RECOMMEND_SPEED_NEUTRAL_ERROR = "����� �������� �������� ���������� �������� �������� �������� �� �����������.";