#ifndef L5_UI_H
#define L5_UI_H
#include <iostream>
#include "controller.h"


using namespace std;
using namespace Controller;

class UI{
public:
    UI(){};
    void start();
    void manager_ui(ScooterController controller);
    void customer_ui(ScooterController controller);
};

#endif //L5_UI_H
