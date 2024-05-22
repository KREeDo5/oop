#pragma once

#include "gear.h"
#include "direction.h"
#include "speedLimit.h"

const std::string DIVIDER = "________________________________\n\n";
const std::string OPEN_BRACKET = " (";
const std::string CLOSE_BRACKET = ")";

const std::string DIRECTION_IS = "Направление: ";
const std::string SPEED_IS = "Скорость: ";
const std::string GEAR_IS = "Передача: ";
const std::string EXIT = "Выход из программы.";
const std::string INPUT_ERROR = "Некорректный ввод. Пожалуйста, введите число от 0 до 5.";
const std::string YOUR_CHOICE = "Ваш выбор: ";
const std::string MAKE_CHOICE = "Выберите действие:";
const std::string MENU_INFO = "1. Вывести информацию об авто";
const std::string MENU_ENGINE_ON = "2. Включить двигатель";
const std::string MENU_ENGINE_OFF = "3. Выключить двигатель";
const std::string MENU_CHANGE_GEAR = "4. Переключить передачу";
const std::string MENU_CHANGE_SPEED = "5. Поменять скорость";
const std::string MENU_EXIT = "0. " + EXIT;

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