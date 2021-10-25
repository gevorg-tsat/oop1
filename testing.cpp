//
// Created by Gevorg Tsaturyan on 25.10.2021.
//

#include "testing.h"
#include <iostream>

void PlanFileCopyTest() {
    Plan  plan1;

    plan1.fromFile("/Users/gevorgtsaturyan/CLionProjects/laba_oop/input.txt");

    Plan plan2(plan1);

    for (int i = 0; i < plan1.getCapacity(); i++)
    {
        assert(plan1.getCar(i).getName() == plan2.getCar(i).getName());
        assert(plan1.getCar(i).getLength() == plan2.getCar(i).getLength());
        assert(plan1.getCar(i).getWidth() == plan2.getCar(i).getWidth());
        assert(plan1.getCar(i).getX() == plan2.getCar(i).getX());
        assert(plan1.getCar(i).getY() == plan2.getCar(i).getY());
        assert(plan1.getCar(i).getAngle() == plan2.getCar(i).getAngle());
    }
    std::cout << "No mistakes for comparison of 2 collections and constructors" << std::endl;
}
void PlanAddDelTest(){
    Plan  plan;

    Car car("BMW",1,2,3,4,5);

    plan.addCar(car);
    assert(plan.getCar(0).getName() == "BMW");
    assert(plan.getCar(0).getLength() == 1);
    assert(plan.getCar(0).getWidth() == 2);
    assert(plan.getCar(0).getX() == 3);
    assert(plan.getCar(0).getY() == 4);
    assert(plan.getCar(0).getAngle() == 5);

    std :: cout << "No mistakes for adding to collection" << std :: endl;

    int temp = plan.getCapacity();
    plan.removeCar(0);
    assert(plan.getCapacity() == temp - 1);

    std :: cout << "No mistakes for deleting an element from collection" << std :: endl;

    plan.fromFile("/Users/gevorgtsaturyan/CLionProjects/laba_oop/input.txt");
    assert(plan.getCapacity() > 1);
    plan.removeCar();
    assert(plan.getCapacity() == 0);

    std :: cout << "No mistakes for deleting all elements from collection" << std :: endl;
}
void printPlan(Plan plan) {
    for (int i = 0; i < plan.getCapacity(); i++) {
        std::cout << "No. " << i + 1 << std::endl;
        std::cout << plan.getCar(i).getName() << " ";
        std::cout << plan.getCar(i).getLength() << " " << plan.getCar(i).getWidth() << " ";
        std::cout << plan.getCar(i).getX() << " " << plan.getCar(i).getY() <<" " << plan.getCar(i).getAngle() << std::endl;
    }
}
void PlanFileTest() {
    Plan plan;
    std::string t;

    plan.fromFile("/Users/gevorgtsaturyan/CLionProjects/laba_oop/input.txt");
    plan.toFile("/Users/gevorgtsaturyan/CLionProjects/laba_oop/output.txt");
    std::cout << "The result of reading from a file:" << std::endl;
    printPlan(plan);
    std::ifstream file("/Users/gevorgtsaturyan/CLionProjects/laba_oop/output.txt");
    std::cout << "The result of writing to a file:" << std::endl;
    while (getline(file, t))
        std::cout << t << std::endl;
}