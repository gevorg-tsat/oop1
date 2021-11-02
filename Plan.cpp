//
// Created by Gevorg Tsaturyan on 31.10.2021.
//

#define PI 3.14159265
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
void Plan::addObject(const std::string& line) {
        std::vector<std::string> elems = split(line, ' ');
        if (elems.size() == 4) {
            Podium pod =  Podium(elems[0], std::stoi(elems[1]), std::stoi(elems[2]), std::stoi(elems[3]));
            //std::cout << pod->toString() << std::endl;
            addObject(pod);
        }
        else if (elems.size() == 6){
            Car car =  Car(elems[0], std::stoi(elems[1]), std::stoi(elems[2]), std::stoi(elems[3]), std::stoi(elems[4]), std::stoi(elems[5]));
            addObject(car);
        }
}

void Plan::addObject(const Podium& podium) {
    if (!capacity) {
        capacity++;
        sr = new Showroom*[1];
        sr[0] = new Podium(podium);
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
void Plan::addObject(const Car& car) {
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
    else throw std::exception();
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
                addObject(pod);
            }
            else if (elems.size() == 6){
                Car car =  Car(elems[0], std::stoi(elems[1]), std::stoi(elems[2]), std::stoi(elems[3]), std::stoi(elems[4]), std::stoi(elems[5]));
                addObject(car);
            }
            else
                throw std::exception();
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
int Plan::getAmountCars() const{
    int k=0;
    for (int i = 0; i<capacity; i++)
        if (!(sr[i]->getType()))
            k++;
    return k;
}
int Plan::getAmountPod() const{
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
bool Plan::PodiumsCheck() {
    int k = this->getCapacity();
    for(int i = 0; i<k-1;i++){
        if (sr[i]->getType() == 0)
            continue;
        else if(sr[i]->getType() == 1){
            for(int j=i+1; j<k; j++) {
                if (sr[j]->getType() == 0)
                    continue;
                else if(sr[j]->getType() == 1){
                    float r1, r2;
                    r1 = sqrt(std::pow(this->getPodium(i)->getX() - this->getPodium(j)->getX(),2) + std::pow(this->getPodium(i)->getY() - this->getPodium(j)->getY(),2));
                    r2 = this->getPodium(i)->getRadius()+this->getPodium(j)->getRadius();
                    if (r1>=r2)
                        continue;
                    else
                        return false;
                }
            }
        }
    }
    return true;
}
bool checkPoint(float x, float y, int coorX, int coorY, int r){
    if ((pow(x-coorX,2)+pow(y - coorY,2)) <= pow(r,2))
        return true;
    else
        return false;
}
int Plan::CarPodiumCheck(){
    int k = this->getCapacity();
    for(int i = 0; i<k;i++){
        int p = 0;
        if (sr[i]->getType() == 1)
            continue;
        else if(sr[i]->getType() == 0){
            for(int j=0; j<k; j++) {
                if (sr[j]->getType() == 0)
                    continue;
                else if(sr[j]->getType() == 1){
                    float ulx,uly,urx,ury,lrx,lry,llx,lly;
                    float ang = this->getCar(i)->getAngle() * PI / 180;
                    int px = this->getPodium(j)->getX(),py = this->getPodium(j)->getY(), r = this->getPodium(j)->getRadius();
                    llx = this->getCar(i)->getX();
                    lly = this->getCar(i)->getY();
                    ulx = llx + sin(ang)*this->getCar(i)->getWidth();
                    uly = lly + cos(ang)*this->getCar(i)->getWidth();
                    lrx = llx + cos(ang)*this->getCar(i)->getLength();
                    lry = lly + sin(ang)*this->getCar(i)->getLength();
                    urx = ulx + lrx - llx;
                    ury = uly + lry - lly;
                    if (!(checkPoint(llx,lly,px,py,r) || checkPoint(ulx,uly,px,py,r) || checkPoint(lrx,lry,px,py,r) || checkPoint(urx,ury,px,py,r) )) {
                        continue;
                    }
                    else if (checkPoint(llx,lly,px,py,r) && checkPoint(ulx,uly,px,py,r) && checkPoint(lrx,lry,px,py,r) && checkPoint(urx,ury,px,py,r) && (this->getPodium(j)->getName()== this->getCar(i)->getName()))
                        p++;
                    else
                        return i;
                }
            }
        }
        if (p>1 || p == 0){
            return i;

        }
    }
    return -1;
}
const std::string& Plan::toString(int i) {
    if (sr[i]->getType()==0)
        return this->getCar(i)->toString();
    else if (sr[i]->getType()==1)
        return this->getPodium(i)->toString();
}

