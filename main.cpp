#include <iostream>
#include <string>
#include "Car.h"
#include <cassert>
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
    assert(tachkaDefault.getName() == "");
    assert(tachkaDefault.getHeight() == 0);
    assert(tachkaDefault.getWidth() == 0);
    assert(tachkaDefault.getLength() == 0);
    assert(tachkaDefault.getX() == 0);
    assert(tachkaDefault.getY() == 0);
    assert(tachkaDefault.getAngle() == 0);
    assert(tachkaCopy.getName() == tachka.getName());
    assert(tachkaCopy.getHeight() == tachka.getHeight());
    assert(tachkaCopy.getWidth() == tachka.getWidth());
    assert(tachkaCopy.getLength() == tachka.getLength());
    assert(tachkaCopy.getX() == tachka.getX());
    assert(tachkaCopy.getY() == tachka.getY());
    assert(tachkaCopy.getAngle() == tachka.getAngle());
    tachka.setName("Mercedes");
    assert(tachka.getName() == "Mercedes");

    std::cout<<"Finished without errors"<<std::endl;
    return 0;
}
