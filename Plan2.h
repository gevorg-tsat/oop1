//
// Created by Gevorg Tsaturyan on 31.10.2021.
//

#ifndef LABA_OOP_PLAN2_H
#define LABA_OOP_PLAN2_H
#include "Showroom.h"
#include "Car.h"
#include "Podium.h"
#include <vector>
#include <fstream>

class Plan {
public:
    Plan() = default;
    Plan(const Plan& otherPlan) = default;
    Plan(Showroom** sr, int capacity);
    ~Plan() = default;
    void addCar(Car car);
    void addPodium(Podium podium);
    void removeObject(int i);
    void removeObject();
    Showroom getObject(int i);
    int getCapacity();
    int getAmountCars();
    int getAmountPod();
    void PlanToFile(const std::string& filename);
    void PlanFromFile(const std::string& filename);
    bool CarPodiumCheck();
    bool nameCheck();
    bool Podiumscheck();
private:
    int capacity=0;
    Showroom **sr;
};


#endif //LABA_OOP_PLAN2_H
