//
// Created by Gevorg Tsaturyan on 31.10.2021.
//

#ifndef LABA_OOP_PLAN_H
#define LABA_OOP_PLAN_H
#include <iostream>
#include "Showroom.h"
#include "Car.h"
#include "Podium.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>
class Plan {
public:
    Plan() = default;
    Plan(const Plan& otherPlan) = default;
    Plan(Showroom** sr, int capacity);
    ~Plan() = default;
    void addCar(const Car& car);
    void addPodium(const Podium& podium);
    void removeObject(int i);
    void removeObject();
    Podium* getPodium(int i);
    Car* getCar(int i);
    int getCapacity() const;
    int getAmountCars();
    int getAmountPod();
    void toFile(const std::string& filename);
    void fromFile(const std::string& filename);
    int CarPodiumCheck();
    bool nameCheck();
    bool PodiumsCheck();
private:
    int capacity=0;
    Showroom **sr;
};


#endif //LABA_OOP_PLAN_H
