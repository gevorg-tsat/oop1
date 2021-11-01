//
// Created by Gevorg Tsaturyan on 31.10.2021.
//

#include "Plan.h"

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

void Plan::removeObject() {
    for (int i=0; i<capacity;i++)
        delete sr[i];
    capacity = 0;
};