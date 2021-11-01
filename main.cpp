#include <iostream>
#include <string>
#include "Podium.h"
#include <cassert>
#include "Plan.h"
#include "Car.h"
int main() {
    Plan plan = Plan();
    Podium pod =  Podium("bmw",0,0,7), pod1 = Podium("hey",36,36,1);
    Car car = Car("san",1,6,0,0,90);
    plan.addPodium(pod);
    plan.addPodium(pod1);
    plan.addCar(car);
    std::cout<<plan.CarPodiumCheck();
    return 0;
}
