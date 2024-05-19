#ifndef L5_REPO_H
#define L5_REPO_H
#include <vector>
#include <memory>
#include "scooter.h"

using namespace Domain;

namespace Repository{
    class ScooterRepo{
    private:
        //Vector of shared pointers to elements Scooter
        vector<shared_ptr<Scooter>> scootersList;
    public:
        //Constructor
        ScooterRepo(){};

        //Functions
        void addScooter(const shared_ptr<Scooter>& Scooter);

        void deleteScooter(const shared_ptr<Scooter>& Scooter);

        vector<shared_ptr<Scooter>> get_all();

    };
}

#endif //L5_REPO_H
