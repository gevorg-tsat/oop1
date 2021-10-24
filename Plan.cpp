//
// Created by Gevorg Tsaturyan on 05.10.2021.
//

#include "Plan.h"

Plan::Plan() {
    this->capacity = 0;
}
Plan::Plan(Car *cars, int capacity) :
    cars(cars), capacity(capacity) {
}
void Plan::addCar(Car car) {
    if (!capacity)
    {
        capacity++;
        cars = new Car[capacity];
        cars[capacity - 1] = car;
    }
    else
    {
        Car *temp = new Car[capacity + 1];
        for (int i = 0; i < capacity; i++)
            temp[i] = cars[i];
        delete [] cars;
        cars = temp;
        cars[capacity] = car;
        capacity++;
    }
}
void Plan::removeCar(int i) {
    if (capacity == 1)
    {
        delete [] cars;
        capacity--;
    }
    else
    {
        for (int j = capacity - 1; j > i; j--)
            cars[j - 1] = cars[j];
        Car *temp = new Car[capacity - 1];
        for (int i = 0; i < capacity - 1; i++)
            temp[i] = cars[i];
        delete [] cars;
        cars = temp;
        capacity--;
    }
}
void Plan::removeCar() {
    delete [] cars;
    capacity = 0;
}
Car Plan::getCar(int i) {
    return cars[i];
}
int Plan::getCapacity() {
    return capacity;
}
bool Plan::checkCarPodium() {
    //later
}
void Plan::toFile(const std::string &filename) {
    std::ofstream fin(filename);

    for (int i = 0; i < capacity; i++)
    {
        std::string  name = cars[i].getName();
        int size_x = cars[i].getLength(), size_y = cars[i].getWidth(), coor_x = cars[i].getX(), coor_y = cars[i].getY();
        fin << name << " ";
        fin << size_x << " " << size_y << " ";
        fin << coor_x << " " << coor_y << " " << std::endl;
    }
    fin.close();
}
void Plan::fromFile(const std::string &filename) {
    std::ifstream fout(filename);
    std::string name;
    int length, width, x , y;
    std::vector <Car> temp;
    Car *tmp;

    while (fout >> name >> length >> width >> x >> y)
    {
        tmp = new Car;
        (*tmp).setName(name);
        (*tmp).setLength(length);
        (*tmp).setWidth(width);
        (*tmp).setX(x);
        (*tmp).setY(y);
        temp.push_back(*tmp);
        delete tmp;
        this->addCar(temp.back());
    }
    temp.clear();
    fout.close();
}
