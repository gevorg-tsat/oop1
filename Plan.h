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
    Plan(CarPod* cp, int capacity);
    Plan(Car *cars,Podium* podium, int amount, int capacity);
    ~Plan() = default;
    void addCar(Car car);
    void addPod(Podium podium);
    void removeCar(int i);
    void removeCar();
    Car getCar(int i);
    int getCapacity();
    int getAmountCars();
    void CarsToFile(const std::string& filename);
    void CarsFromFile(const std::string& filename);
    void PodToFile(const std::string& filename);
    void PodFromFile(const std::string& filename);
    bool CarPodiumCheck(int i);
    bool CarPodiumCheck();
private:
    int capacity=0;
    int amountCars=0;
    CarPod* cp;
};


#endif //LABA_OOP_PLAN_H
