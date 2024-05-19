//
// Definition of getters and setters
//

#include "scooter.h"
using namespace Domain;


//Setters definition
void Scooter::setVehicleState(VehicleState &state) {
    if (state >= PARKED && state <= OUT_OF_SERVICE) {
        this->carState = state;
    } else {
        cout << "Invalid vehicle state. Setting to default state.\n";
        this->carState = PARKED; // Set to default state or handle error appropriately
    }
}

Scooter::Scooter(VehicleState carState, const string& identifier, const string& model, const string& commDate, const string& place, float kilometer)
        : carState(carState), identifier(identifier), model(model), commDate(commDate), place(place), kilometer(kilometer) { }


void Scooter::setIdentifier(const string &identifier) {
    this->identifier = identifier;
}

void Scooter::setModel(const string &model) {
    this->model = model;
}

void Scooter::setCommDate(const string &commDate) {
    this->commDate = commDate;
}

void Scooter::setPlace(const string &place) {
    this->place = place;
}

void Scooter::setKilometer(const float &kilometer) {
    this->kilometer = kilometer;
}


//Getters definition
VehicleState Scooter::getVehicleState() const {
    return carState;
}

string Scooter::getIdentifier() const {
    return identifier;
}

string Scooter::getModel() const {
    return model;
}

string Scooter::getCommDate() const {
    return commDate;
}

string Scooter::getPlace() const {
    return place;
}

float Scooter::getKilometer() const {
    return kilometer;
}
