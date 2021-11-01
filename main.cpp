#include <iostream>
#include <string>
#include "Podium.h"
#include <cassert>
#include "Plan.h"
#include "Car.h"
int main() {
    Plan plan = Plan();
    Podium pod =  Podium("bmw",1,2,3), pod1 = Podium("hey",6,6,4);
    Car car = Car("san",1,2,3,5,6);
    plan.addPodium(pod);
    plan.addPodium(pod1);
    plan.addCar(car);
    std::cout<<plan.PodiumsCheck();
    return 0;
}
