#pragma once

#include <iostream>
#include "automobile.h"
#include "car.cpp"

using namespace std;

void showMenu() {
    cout << MENU_INFO << endl;
    cout << MAKE_CHOICE << endl;
    cout << MENU_ENGINE_ON << endl;
    cout << MENU_ENGINE_OFF << endl;
    cout << MENU_CHANGE_GEAR << endl;
    cout << MENU_CHANGE_SPEED << endl;
    cout << MENU_EXIT << endl;
}

void showCarInfo(map<string, string> carInfo) {

    /*
    if (carInfo["engineStatus"] == )
    {
        std::cout << ENGINE_ON << std::endl;
    }
    else {
        std::cout << ENGINE_OFF << std::endl;
    }
     */
    cout << carInfo["engineStatus"] << endl;
    cout << carInfo["direction"] << endl;
    cout << carInfo["speed"] << endl;
    cout << GEAR_IS << carInfo["gear"] << OPEN_BRACKET << carInfo["stringGear"] << CLOSE_BRACKET << endl;
}

int showRecommendSpeed(map<string, int> recommendSpeed) {
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
        return 1;
    }
    cout << RECOMMEND_SPEED_FROM << recommendSpeed["minSpeed"] << RECOMMEND_SPEED_TO << recommendSpeed["maxSpeed"] << RECOMMEND_SPEED_CLOSE_BRACKET;
    return 0;
}


int main() {
    setlocale(LC_ALL, "Russian");

    Car car;
    map<string, string> carInfo;
    map<string, int> recommendSpeed;

    int choice = -1;

    while (choice != 0) { 
        showMenu();

        cout << YOUR_CHOICE;
        cin >> choice;
        cout << DIVIDER;

        switch (choice) {
            case 1:
                carInfo = car.info();
                showCarInfo(carInfo);
                cout << DIVIDER;
                break;
            case 2:
                car.TurnOnEngine();
                cout << TURN_ON_ENGINE << endl;
                cout << DIVIDER;
                break;
            case 3:
                bool result;
                result = car.TurnOffEngine();
                if (!result) {
                    cout << TURN_OFF_ERROR << endl;
                }
                cout << TURN_OFF_ENGINE << endl;
                cout << DIVIDER;
                break;
            case 4:
                int gear;
                cout << INPUT_SET_GEAR;
                cin >> gear;
                car.SetGear(gear);
                cout << DIVIDER;
                break;
            case 5:
                int speed;
                int result;
                recommendSpeed = car.GetRecommendSpeed();
                result = showRecommendSpeed(recommendSpeed);
                if (result > 0) {
                    cout << DIVIDER;
                    break;
                }
                cin >> speed;
                car.SetSpeed(speed);
                cout << DIVIDER;
                break;
            case 0:
                cout << EXIT << endl;
                break;
            default:
                cout << INPUT_ERROR << endl;
                cout << DIVIDER;
        }
    }

    return 0;
}