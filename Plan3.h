//
// Created by Gevorg Tsaturyan on 05.10.2021.
//

#ifndef LABA_OOP_PLAN3_H
#define LABA_OOP_PLAN3_H
#include "Car.h"
#include "Podium.h"
#include <vector>
#include <fstream>
struct CarPod {
    Podium pod;
    Car car;
};
class Plan2 {
public:
    Plan2() = default;
    Plan2(const Plan2& otherPlan) = default;
    Plan2(CarPod* cp, int capacity);
    Plan2(Car *cars,Podium* podium, int amount, int capacity);
    ~Plan2() = default;
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


#endif //LABA_OOP_PLAN3_H
