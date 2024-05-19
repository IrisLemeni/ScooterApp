#include "UI.h"
#include "controller.h"
#include <iostream>

using namespace std;
using namespace Controller;


void UI::start() {
    int selection = 0;
    ScooterController controller;
    controller.addRandomElements();
    while (selection != 3) {
        cout << "Choose a user:" << endl;
        cout << "1. Manager\n"
             << "2. Client\n"
             << "3. Exit\n"
             << "Enter your choice: ";
        cin >> selection;
        switch (selection) {
            case 1:
                manager_ui(controller);
                break;
            case 2:
                customer_ui(controller);
                break;
            case 3:
                cout<<"Goodbye";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}

void UI::manager_ui(ScooterController controller) {
    int selection_manager = 0;
    while (selection_manager != 8) {
        cout << "Choose an action:" << endl;
        cout << "1. Add an element\n"
             << "2. Delete an element\n"
             << "3. Modify an element\n"
             << "4. Sort by city\n"
             << "5. Sort by date\n"
             << "6. List all scooters\n"
             << "7. Filter by km or date\n"
             << "8. EXIT\n"
             << "Enter your choice: ";
        cin >> selection_manager;
        VehicleState carState;
        string identifier, model, commDate, place;
        float kilometer;
        switch (selection_manager) {
            case 1:
                cout << "SELECTED: Add an element"<< endl;
                cout << "Give an identifier:";
                cin >> identifier;
                cout << "Select a vehicle state (0=PARKED, 1=RESERVED, 2=IN_USE, 3=IN_MAINTENANCE, 4=OUT_OF_SERVICE): ";
                int state;
                cin >> state;
                VehicleState vehicleState;
                switch (state) {
                    case 0:
                        vehicleState = PARKED;
                        break;
                    case 1:
                        vehicleState = RESERVED;
                        break;
                    case 2:
                        vehicleState = IN_USE;
                        break;
                    case 3:
                        vehicleState = IN_MAINTENANCE;
                        break;
                    case 4:
                        vehicleState = OUT_OF_SERVICE;
                        break;
                    default:
                        cout << "Invalid state\n";
                }
                cout << "You selected state " << state << "\n";
                cout << "Write a model:";
                cin >> model;
                cout << "Write the commDate:";
                cin >> commDate;
                cout << "Write the Place:";
                cin >> place;
                cout << "How much kms does it have:";
                cin >> kilometer;
                controller.addElement(vehicleState, identifier, model, commDate, place, kilometer);
                break;
            case 2:
                cout << "SELECTED:Delete an element:"<< endl;
                cout << "Select an element by identifier:"<< endl;
                cin >> identifier;
                controller.deleteElement(identifier);
                break;
            case 3:
                cout<<"SELECTED:Modify an element" << endl;
                cout <<"Select an element by identifier:"<< endl;
                cin >> identifier;
                cout <<"Select an action:"<< endl;
                int action;
                cin >> action;
                controller.modifyElement(identifier, action);
                break;
            case 4:
                cout << "SELECTED:Sort by city" << endl;
                cout << "City" << endl;
                cin >> identifier;
                controller.PrintByCity(identifier);
                break;
            case 5:
                cout << "SELECTED:Sort by date" << endl;
                controller.PrintByDate();
                break;
            case 6:
                cout << "SELECTED: List all scooters" << endl;
                controller.listAllScooters();
                break;
            case 7:
                cout <<"SELECTED: Filter by km or date "<< endl;
                controller.filtrate();
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

}

void UI::customer_ui(ScooterController controller) {
    int selection_customer;
    while (selection_customer != 7){
        cout << "Choose an action:" << endl;
        cout << "1. Find by city\n"
             << "2. Filter by km or date\n"
             << "4. Reserve\n"
             << "5. EXIT\n"
             << "Enter your choice: ";
        cin >> selection_customer;
        string elem;
        switch (selection_customer) {
            case 1:
                std::cout << "Find by city selected." << std::endl;
                cout << "City" << endl;
                cin >> elem;
                controller.PrintByCity(elem);
                break;
            case 2:
                std::cout << "Filter by km or date selected." << std::endl;
                controller.filtrate();
                break;
            case 3:
                std::cout << "Reserve selected." << std::endl;
                cout <<"Select an element by identifier:"<< endl;
                cin >> elem;
                controller.reserved(elem);

                // Perform reserve logic
                break;
        }

    }

}
