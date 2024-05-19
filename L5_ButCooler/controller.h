#ifndef L5_CONTROLLER_H
#define L5_CONTROLLER_H

#include "scooter.h"
#include "repo.h"
#include <memory>

using namespace Domain;
using namespace Repository;

namespace Controller{
    class ScooterController{
    private:
        ScooterRepo repo;
    public:
        ScooterController(): repo(){};

        void addElement(VehicleState carState, const string& identifier, const string& model, const string& commDate,const string& place, float kilometer);
        void deleteElement(const string& identifier);
        void modifyElement(const string& identifier, int selection);
        shared_ptr<Scooter> findElement(string identifier);
        void PrintByCity(const string& place);
        void PrintByDate();
        void filtrate();
        bool reserved(const string& identifier);
        void addRandomElements();

        void listAllScooters();
    };
}

#endif //L5_CONTROLLER_H
