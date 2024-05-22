#pragma once

#include "automobile.h"
#include "car.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    Car car;
    map<string, string> carInfo;
    map<string, int> recommendSpeed;

    int choice = -1;

    while (choice != 0)
    { 
        ShowMenu();

        cout << YOUR_CHOICE;
        cin >> choice;
        cout << DIVIDER;

        switch (choice)
        {
            case 1:
                carInfo = car.info();
                ShowCarInfo(carInfo);
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
                    cout << DIVIDER;
                    break;
                }
                cout << TURN_OFF_ENGINE << endl;
                cout << DIVIDER;
                break;
            case 4:
                int gear;
                cout << INPUT_SET_GEAR;
                cin >> gear;
                car.SetGear(gear,
                    []() { 
                        cout << SET_GEAR << endl;
                    },
                    [](int error) {
                        showGearError(error);
                    }
                );
                cout << DIVIDER;
                break;
            case 5:
                int speed;
                bool showSpeed;
                recommendSpeed = car.GetRecommendSpeed();
                showSpeed = ShowRecommendSpeed(recommendSpeed);
                if (!showSpeed)
                {
                    cout << DIVIDER;
                    break;
                }
                cin >> speed;
                car.SetSpeed(
                    speed,
                    []() {
                        cout << SET_SPEED << endl;
                    },
                    [](int error) {
                        showSpeedError(error);
                    }
                );
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