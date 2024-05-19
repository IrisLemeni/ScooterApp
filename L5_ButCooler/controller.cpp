#include "controller.h"
#include <iostream>
using namespace std;
using namespace Controller;
using namespace Domain;

void ScooterController::addElement(VehicleState carState, const string& identifier, const string& model, const string& commDate,const string& place, float kilometer){
    //Control if the element already exist
    if (findElement(identifier) != nullptr) {
        throw std::invalid_argument("Scooter with the same identifier already exists");
    }

    //If it doesn't exist just add it
    auto elem = make_shared<Scooter>(carState, identifier, model, commDate, place, kilometer);

    repo.addScooter(elem);
}

void ScooterController::deleteElement(const string& identifier) {
    // If it finds the element it deletes it
    auto foundElement = findElement(identifier);
    if (foundElement == nullptr) {
        throw runtime_error("Scooter with the same identifier doesn't exist");
    }
    repo.deleteScooter(foundElement);
}

void ScooterController::modifyElement(const string& identifier, int selection) {
    auto foundElement = findElement(identifier);

    switch (selection) {
        case 1:
        {
            string newIdentifier;
            cout << "Enter the new identifier: ";
            cin >> newIdentifier;
            foundElement->setIdentifier(newIdentifier);
        }
            break;
        case 2:
        {
            int newStateInput;
            cout << "Enter new state (0 - PARKED, 1 - RESERVED, 2 - IN_USE, 3 - IN_MAINTENANCE, 4 - OUT_OF_SERVICE): ";
            cin >> newStateInput;

            VehicleState newVehicleState;
            switch (newStateInput) {
                case 0:
                    newVehicleState = PARKED;
                    break;
                case 1:
                    newVehicleState = RESERVED;
                    break;
                case 2:
                    newVehicleState = IN_USE;
                    break;
                case 3:
                    newVehicleState = IN_MAINTENANCE;
                    break;
                case 4:
                    newVehicleState = OUT_OF_SERVICE;
                    break;
                default:
                    cout << "Invalid state input. Setting to default state.\n";
                    newVehicleState = PARKED; // Set to default state or handle error appropriately
            }

            foundElement->setVehicleState(newVehicleState);

        }
            break;
        case 3:
        {
            string newCommDate;
            cout << "Enter the new communication date: ";
            cin >> newCommDate;
            foundElement->setCommDate(newCommDate);
        }
            break;
        case 4:
        {
            string newModel;
            cout << "Enter the new model: ";
            cin >> newModel;
            foundElement->setModel(newModel);
        }
            break;
        case 5:
        {
            string newPlace;
            cout << "Enter the new place: ";
            cin >> newPlace;
            foundElement->setPlace(newPlace);
        }
            break;
        case 6:
        {
            int newKilometer;
            cout << "Enter the new kilometer: ";
            cin >> newKilometer;
            foundElement->setKilometer(newKilometer);
        }
            break;
        default:
            // Handle invalid selection
            break;
    }
}


shared_ptr<Scooter> ScooterController::findElement(string Find_ID) {
    for(const shared_ptr<Scooter>& Scoot: repo.get_all()){
        if(Scoot->getIdentifier() == Find_ID){
            //If found, return the element
            return Scoot;
        }
    }
    // Throw an exception if no matching Scooter object is found
    return nullptr;
}



void ScooterController::PrintByCity(const string& place) {
    //TODO
    for(const shared_ptr<Scooter>& Scoot: repo.get_all()){
        if(Scoot->getPlace() == place){
            //If found, print the element
            cout << "Identifier: " << (*Scoot).getIdentifier() << endl;
            cout << "Vehicle State: " << Scoot->getVehicleState() << endl;
            cout << "Communication Date: " << Scoot->getCommDate() << endl;
            cout << "Model: " << Scoot->getModel() << endl;
            cout << "Place: " << Scoot->getPlace() << endl;
            cout << "Kilometer: " << Scoot->getKilometer() << endl;
        }
    }
}

bool compareByDate(const shared_ptr<Scooter>& a, const shared_ptr<Scooter>& b) {
    //TODO
    const std::string& date1 = a->getCommDate();
    const std::string& date2 = b->getCommDate();

    if (date1.length() < 10 || date2.length() < 10) {
        throw std::invalid_argument("Invalid CommDate format");
    }

    std::string date1Substring = date1.substr(6, 4) + date1.substr(3, 2) + date1.substr(0, 2);
    std::string date2Substring = date2.substr(6, 4) + date2.substr(3, 2) + date2.substr(0, 2);
    return date1Substring < date2Substring;
}

void ScooterController::PrintByDate() {
    std::vector<std::shared_ptr<Scooter>> scooters = repo.get_all();

    // Sort the scooter elements by date using the compareByDate function
    std::sort(scooters.begin(), scooters.end(), compareByDate);

    // Print the sorted scooter elements
    for (const std::shared_ptr<Scooter>& scooter : scooters) {
        cout << "Identifier: " << scooter->getIdentifier() << endl;
        cout << "Vehicle State: " << scooter->getVehicleState() << endl;
        cout << "Communication Date: " << scooter->getCommDate() << endl;
        cout << "Model: " << scooter->getModel() << endl;
        cout << "Place: " << scooter->getPlace() << endl;
        cout << "Kilometer: " << scooter->getKilometer() << endl;
        cout << endl;
    }
}

void ScooterController::addRandomElements() {
    addElement(VehicleState::PARKED, "ID001", "Model A", "01/01/2022", "Paris", 500.0);
    addElement(VehicleState::RESERVED, "ID002", "Model B", "02/01/2022", "London", 750.0);
    addElement(VehicleState::IN_MAINTENANCE, "ID003", "Model C", "03/01/2022", "Rome", 1000.0);
    addElement(VehicleState::PARKED, "ID004", "Model D", "04/01/2022", "Madrid", 2000.0);
    addElement(VehicleState::IN_USE, "ID005", "Model E", "05/02/2022", "Rome", 3000.0);
    addElement(VehicleState::RESERVED, "ID006", "Model F", "06/01/2022", "Athens", 500.0);
    addElement(VehicleState::IN_MAINTENANCE, "ID007", "Model G", "07/01/2022", "Vienna", 750.0);
    addElement(VehicleState::IN_USE, "ID009", "Model H", "08/01/2022", "Brussels", 1000.0);
    addElement(VehicleState::IN_USE, "ID010", "Model I", "09/01/2022", "Dublin", 2000.0);
    addElement(VehicleState::IN_USE, "ID011", "Model J", "10/01/2022", "Rome", 3000.0);

}

void ScooterController::listAllScooters() {
    for (const shared_ptr<Scooter>& scooter : repo.get_all()) {
        cout << "Identifier: " << scooter->getIdentifier() << endl;
        cout << "Vehicle State: " << scooter->getVehicleState() << endl;
        cout << "Communication Date: " << scooter->getCommDate() << endl;
        cout << "Model: " << scooter->getModel() << endl;
        cout << "Place: " << scooter->getPlace() << endl;
        cout << "Kilometer: " << scooter->getKilometer() << endl;
        cout << endl;
    }
}

bool ScooterController::reserved(const string& identifier) {
    auto foundElement = findElement(identifier);
    VehicleState NEW = RESERVED;
    if (foundElement->getVehicleState() == PARKED ){
        foundElement->setVehicleState(NEW);
        return true;
    }
    return false;
}

void ScooterController::filtrate() {
    int sel = 0;
    int qt = 0;
    string date;
    cout << "1-By date \n"
         << "2-By km \n"
         << "Enter your choice \n";
    cin >> sel;

    switch(sel){
        case 1: {
            cout << "Enter the filter:" << endl;
            cin >> qt;
            std::vector<std::shared_ptr<Scooter>> scooters = repo.get_all();

            std::sort(scooters.begin(), scooters.end(), [](const std::shared_ptr<Scooter>& a, const std::shared_ptr<Scooter>& b) {
                return a->getKilometer() < b->getKilometer();
            });

            // Print the scooter elements with kilometer values smaller than qt
            for (const std::shared_ptr<Scooter>& scooter : scooters) {
                if (scooter->getKilometer() < qt) {
                    cout << "Identifier: " << scooter->getIdentifier() << endl;
                    cout << "Vehicle State: " << scooter->getVehicleState() << endl;
                    cout << "Communication Date: " << scooter->getCommDate() << endl;
                    cout << "Model: " << scooter->getModel() << endl;
                    cout << "Place: " << scooter->getPlace() << endl;
                    cout << "Kilometer: " << scooter->getKilometer() << endl;
                    cout << endl;
                }
            }


        }
            break;
        case 2:
            cout << "Enter the filter:" << endl;
            cin >> date;
            std::vector<std::shared_ptr<Scooter>> scooters = repo.get_all();

            // Sort the scooter elements by date using the compareByDate function
            std::sort(scooters.begin(), scooters.end(), compareByDate);

            for (const std::shared_ptr<Scooter>& scooter : scooters) {
                const std::string& scooterDate = scooter->getCommDate();
                std::string scooterDateSubstring = scooterDate.substr(6, 4) + scooterDate.substr(3, 2) + scooterDate.substr(0, 2);

                if (scooterDateSubstring < date) {
                    cout << "Identifier: " << scooter->getIdentifier() << endl;
                    cout << "Vehicle State: " << scooter->getVehicleState() << endl;
                    cout << "Communication Date: " << scooter->getCommDate() << endl;
                    cout << "Model: " << scooter->getModel() << endl;
                    cout << "Place: " << scooter->getPlace() << endl;
                    cout << "Kilometer: " << scooter->getKilometer() << endl;
                    cout << endl;
                }
            }
            break;

    }

}
