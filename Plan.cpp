//
// Created by Gevorg Tsaturyan on 31.10.2021.
//

#include "Plan.h"
std::vector<std::string> split(const std::string &s, char delim) {
    std::stringstream ss(s);
    std::string item;
    std::vector<std::string> elems;
    while (std::getline(ss, item, delim)) {
        elems.push_back(std::move(item));
    }
    return elems;
}
Plan::Plan(Showroom** sr, int capacity) :
        sr(sr), capacity(capacity) {
}
void Plan::addPodium(const Podium& podium) {
    if (!capacity) {
        capacity++;
        sr = new Showroom*[capacity];
        sr[capacity - 1] = new Podium(podium);
    } else {
        Showroom **tmp = new Showroom*[capacity + 1];
        for (int j = 0; j < capacity; j++)
            tmp[j] = sr[j];
        delete[] sr;
        sr = tmp;
        sr[capacity] = new Podium(podium);
        capacity++;
    }
}
void Plan::addCar(const Car& car) {
    if (!capacity) {
        capacity++;
        sr = new Showroom*[capacity];
        sr[capacity - 1] = new Car(car);
    } else {
        Showroom **tmp = new Showroom*[capacity + 1];
        for (int j = 0; j < capacity; j++)
            tmp[j] = sr[j];
        delete[] sr;
        sr = tmp;
        sr[capacity] = new Car(car);
        capacity++;
    }
}
int Plan::getCapacity() const {
    return capacity;
}Podium* Plan::getPodium(int i) {
    if (sr[i]->getType()==1)
        return reinterpret_cast<Podium*>(sr[i]);
    else throw std::exception();
}
Car* Plan::getCar(int i) {
    if (sr[i]->getType()==0)
        return reinterpret_cast<Car*>(sr[i]);

}
void Plan::toFile(const std::string &filename) {
    std::ofstream fin(filename);
    for (int i = 0; i < capacity; i++)
    {
        if (sr[i]->getType()==0) {
            Car tmp = *(this->getCar(i));
            std::string name = tmp.getName();
            int size_x = tmp.getLength(), size_y = tmp.getWidth(), coor_x = tmp.getX(), coor_y = tmp.getY(), angle = tmp.getAngle();
            fin << name << " ";
            fin << size_x << " " << size_y << " ";
            fin << coor_x << " " << coor_y << " ";
            fin << angle << std::endl;
        }
        else if (sr[i]->getType() == 1) {
            Podium tmp = *(this->getPodium(i));
            std::string name = tmp.getName();
            int rad = tmp.getRadius(), coor_x = tmp.getX(), coor_y = tmp.getY();
            fin << name << " ";
            fin << coor_x << " " << coor_y << " ";
            fin << rad << std::endl;
        }
    }
    fin.close();
}
void Plan::fromFile(const std::string &filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::vector<std::string> elems = split(line, ' ');
            if (elems.size() == 4) {
                Podium pod =  Podium(elems[0], std::stoi(elems[1]), std::stoi(elems[2]), std::stoi(elems[3]));
                //std::cout << pod->toString() << std::endl;
                addPodium(pod);
            }
            else if (elems.size() == 6){
                Car car =  Car(elems[0], std::stoi(elems[1]), std::stoi(elems[2]), std::stoi(elems[3]), std::stoi(elems[4]), std::stoi(elems[5]));
                addCar(car);
            }
        }
        }
        file.close();
    file.close();
}
void Plan::removeObject(int i){
    if (capacity == 1)
    {
        delete [] sr;
        capacity--;
    }
    else
    {
        for (int j = i; j < capacity; j++)
            sr[j] = sr[j+1];
        Showroom* *temp = new Showroom*[capacity - 1];
        for (int j = 0; j < capacity - 1; j++)
            temp[j] = sr[j];
        delete [] sr;
        sr = temp;
        //for (int j=0; j<capacity-1;j++)
            //*sr[j] = *temp[j];
        capacity--;
    }
};
int Plan::getAmountCars(){
    int k=0;
    for (int i = 0; i<capacity; i++)
        if (!(sr[i]->getType()))
            k++;
    return k;
}
int Plan::getAmountPod(){
    int k=0;
    for (int i = 0; i<capacity; i++)
        if (sr[i]->getType() == 1)
            k++;
    return k;
}
void Plan::removeObject() {
    for (int i=0; i<capacity;i++)
        delete sr[i];
    capacity = 0;
};