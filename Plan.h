//
// Created by Gevorg Tsaturyan on 05.10.2021.
//

#ifndef LABA_OOP_PLAN_H
#define LABA_OOP_PLAN_H
#include "Car.h"
#include "Podium.h"
#include <vector>
#include <fstream>
struct CarPod {
    Podium pod;
    Car car;
};
class Plan {
public:
    Plan() = default;
    Plan(const Plan& otherPlan) = default;
    Plan(Car *cars, int capacity);
    ~Plan() = default;
    void addCar(Car car);
    void removeCar(int i);
    void removeCar();
    Car getCar(int i);
    int getCapacity();
    bool checkCarPodium();
    void toFile(const std::string& filename);
    void fromFile(const std::string& filename);

private:
    int capacity=0;
    Car* cars;
};


#endif //LABA_OOP_PLAN_H
