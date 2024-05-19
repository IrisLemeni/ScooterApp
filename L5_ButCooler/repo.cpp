#include "repo.h"
#include <memory>
#include <algorithm>
#include <vector>

using namespace Repository;

void ScooterRepo::addScooter(const shared_ptr<Scooter> &Scooter) {
    scootersList.push_back(Scooter);
}

void ScooterRepo::deleteScooter(const shared_ptr<Scooter> &Scooter) {
    // Find the scooter in the list
    auto it = find(scootersList.begin(), scootersList.end(), Scooter);

    // If the scooter is found, erase it from the list
    if (it != scootersList.end()) {
        scootersList.erase(it);
    }

}

vector<shared_ptr<Scooter>> ScooterRepo::get_all() {
    return scootersList;
}
