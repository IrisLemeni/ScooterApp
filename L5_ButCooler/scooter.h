#ifndef L5_SCOOTER_H
#define L5_SCOOTER_H

#include <iostream>

using namespace std;

enum VehicleState {
    PARKED,
    RESERVED,
    IN_USE,
    IN_MAINTENANCE,
    OUT_OF_SERVICE
};

namespace Domain {
    class Scooter {
    private:
        VehicleState carState;
        string identifier;
        string model;
        string commDate;
        string place;
        float kilometer;
    public:
        //General constructor
//        Scooter(VehicleState state, string basicString, string string1, string string2, string string3, float d){};
        Scooter(VehicleState carState, const string &identifier, const string &model, const string &commDate,
                const string &place, float kilometer);

        //Setters
        void setVehicleState(VehicleState &carState);

        void setIdentifier(const string &identifier);

        void setModel(const string &model);

        void setCommDate(const string &commDate);

        void setPlace(const string &place);

        void setKilometer(const float &kilometer);

        //Getters
        VehicleState getVehicleState() const;

        string getIdentifier() const;

        string getModel() const;

        string getCommDate() const;

        string getPlace() const;

        float getKilometer() const;

        //Destructor
        ~Scooter() {};
    };
}

#endif //L5_SCOOTER_H
