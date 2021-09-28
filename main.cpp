#include <iostream>
#include <string>
#include "Car.h"
#include <cassert>
#define ZERO 0
#define EMPTY ""
int main() {
    Car tachka = Car("BMW",10,10,10,0,0,45);
    Car tachkaDefault = Car();
    Car tachkaCopy = Car(tachka);
    assert(tachka.getName() == "BMW");
    assert(tachka.getHeight() == 10);
    assert(tachka.getWidth() == 10);
    assert(tachka.getLength() == 10);
    assert(tachka.getX() == 0);
    assert(tachka.getY() == 0);
    assert(tachka.getAngle() == 45);
    assert(tachkaDefault.getName() == EMPTY);
    assert(tachkaDefault.getHeight() == ZERO);
    assert(tachkaDefault.getWidth() == ZERO);
    assert(tachkaDefault.getLength() == ZERO);
    assert(tachkaDefault.getX() == ZERO);
    assert(tachkaDefault.getY() == ZERO);
    assert(tachkaDefault.getAngle() == ZERO);
    assert(tachkaCopy.getName() == tachka.getName());
    assert(tachkaCopy.getHeight() == tachka.getHeight());
    assert(tachkaCopy.getWidth() == tachka.getWidth());
    assert(tachkaCopy.getLength() == tachka.getLength());
    assert(tachkaCopy.getX() == tachka.getX());
    assert(tachkaCopy.getY() == tachka.getY());
    assert(tachkaCopy.getAngle() == tachka.getAngle());
    tachka.setName("Mercedes");
    tachka.setLength(20);
    assert(tachka.getLength() == 20);
    assert(tachka.getName() == "Mercedes");
    std::cout<<"Finished without errors"<<std::endl;
    return 0;
}
