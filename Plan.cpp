//
// Created by Gevorg Tsaturyan on 05.10.2021.
//

#include "Plan.h"

Plan::Plan(CarPod* cp, int capacity) :
    cp(cp), capacity(capacity) {
}
Plan::Plan(Car *cars,Podium* podium, int amount, int tcapacity) {
    for (int i=0;i<tcapacity;i++) {
        this->addPod(podium[i]);
    }
    for (int i = 0; i<amount;i++)
        this->addCar(cars[i]);
}
void Plan::addCar(Car car) {
    if (!capacity)
        throw std::exception();
    else if (amountCars==capacity)
        throw std::exception();
    else if (amountCars<capacity) {
        for (int i = 0; i < capacity; i++)
            if (cp[i].car.getName()=="") {
                cp[i].car = car;
                break;
            }
        amountCars++;
    }
}
void Plan::addPod(Podium podium) {
    if (!capacity) {
        capacity++;
        cp = new CarPod[capacity];
        cp[capacity - 1].pod = podium;
    } else {
        CarPod *tmp = new CarPod[capacity + 1];
        for (int j = 0; j < capacity; j++)
            tmp[j] = cp[j];
        delete[] cp;
        cp = tmp;
        cp[capacity].pod = podium;
        capacity++;
    }
}
void Plan::removeCar(int i) {
    if (i>capacity)
        throw std::exception();
    else {
        cp[i].car = Car();
        amountCars--;
    }
    /*if (capacity == 1)
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
    } */
}
void Plan::removeCar() {
    for (int i=0;i<capacity;i++){
        cp[i].car = Car();
    }
    amountCars = 0;
}
Car Plan::getCar(int i) {
    if (!amountCars)
        throw std::exception();
    else {
        if (cp[i].car.getName()=="")
            throw std::exception();
        else
            return cp[i].car;
    }

}
int Plan::getCapacity() {
    return capacity;
}
int Plan::getAmountCars() {
    return amountCars;
}
void Plan::CarsToFile(const std::string &filename) {
    std::ofstream fin(filename);

    for (int i = 0; i < capacity; i++)
    {
        std::string  name = cp[i].car.getName();
        int size_x = cp[i].car.getLength(), size_y = cp[i].car.getWidth(), coor_x = cp[i].car.getX(), coor_y = cp[i].car.getY(), angle = cp[i].car.getAngle();
        fin << name << " ";
        fin << size_x << " " << size_y << " ";
        fin << coor_x << " " << coor_y << " ";
        fin << angle << std::endl;
    }
    fin.close();
}
void Plan::CarsFromFile(const std::string &filename) {
    std::ifstream fout(filename);
    std::string name;
    int length, width, x , y, angle;
    std::vector <Car> temp;
    Car *tmp;
    while (fout >> name >> length >> width >> x >> y >> angle)
    {
        tmp = new Car;
        (*tmp).setName(name);
        (*tmp).setLength(length);
        (*tmp).setWidth(width);
        (*tmp).setX(x);
        (*tmp).setY(y);
        (*tmp).setAngle(angle);
        temp.push_back(*tmp);
        delete tmp;
        this->addCar(temp.back());
    }
    temp.clear();
    fout.close();
}
void Plan::PodFromFile(const std::string& filename) {
    std::ifstream fout(filename);
    std::string name;
    int rad, x , y;
    std::vector <Podium> temp;
    Podium *tmp;
    while (fout >> name >> x >> y >> rad)
    {
        tmp = new Podium;
        (*tmp).setName(name);
        (*tmp).setX(x);
        (*tmp).setY(y);
        (*tmp).setRadius(rad);
        temp.push_back(*tmp);
        delete tmp;
        this->addPod(temp.back());
    }
    temp.clear();
    fout.close();
}
void Plan::PodToFile(const std::string& filename) {
    std::ofstream fin(filename);

    for (int i = 0; i < capacity; i++)
    {
        std::string  name = cp[i].pod.getName();
        int rad = cp[i].pod.getRadius(), coor_x = cp[i].car.getX(), coor_y = cp[i].car.getY();
        fin << name << " ";
        fin << coor_x << " " << coor_y << " ";
        fin << rad << std::endl;
    }
    fin.close();
}
bool Plan::CarPodiumCheck(int i) {
   if (i>=capacity)
       throw std::exception();
   if ((cp[i].car.getName() == cp[i].pod.getName()) || (cp[i].car.getName()==""))
       return true;
   else
       return false;
}
bool Plan::CarPodiumCheck() {
    for (int i; i<capacity;i++)
        if (!CarPodiumCheck(i))
            return false;
    return true;
}