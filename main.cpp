#include <iostream>
#include <string>
#include "Podium.h"
#include <cassert>
#include "Plan.h"
#include "Car.h"
#include "testing.h"
int main() {
    Plan plan = Plan();
    Podium pod =  Podium("bmw",0,0,1), pod1 = Podium("hey",0,0,1);
    Car car = Car("bmw",1,6,0,0,90);
    plan.addObject(pod);
    plan.addObject(pod1);
    plan.addObject(car);
    assert(plan.CarPodiumCheck()==-1);
    PlanFileTest();
    PlanAddDelTest();
    return 0;
}
