#include <iostream>
#include <string>
#include "Podium.h"
#include <cassert>
#include "Plan.h"
int main() {
    Plan plan = Plan();
    Podium pod =  Podium("bmw",1,2,3), pod1 = Podium("mers",1,2,3),pod2 = Podium("san",1,2,3);
    plan.addPodium(pod);
    plan.addPodium(pod1);
    plan.addPodium(pod2);
    std::cout<<plan.getCapacity();
    std::cout<<plan.getPodium(0)->getName();
    plan.removeObject(0);
    std::cout<<plan.getCapacity();
    std::cout<<plan.getPodium(1)->getName();
    return 0;
}
