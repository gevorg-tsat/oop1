//
// Created by Gevorg Tsaturyan on 05.10.2021.
//

#ifndef LABA_OOP_PLAN_H
#define LABA_OOP_PLAN_H
#include "Car.h"
#include "Podium.h"
class Plan {
public:
    Plan();
    Plan(int size);
    Plan(const Plan &plan);
    ~Plan();
private:
    int capacity;
    int current;
    Car** cars;
    Podium** podiums;


};


#endif //LABA_OOP_PLAN_H
