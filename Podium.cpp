//
// Created by Gevorg Tsaturyan on 13.10.2021.
//

#include "Podium.h"

Podium::Podium() : Showroom() {
    this->r=ZERO;
}
Podium::~Podium() {

}
Podium::Podium(const std::string& name,int x, int y, int r) : Showroom(name,x,y) {
    this->r = r;
}

Podium::Podium(const Podium& pod) : Showroom(pod.getName(),pod.getX(),pod.getY()){
    this->r = pod.getRadius();
}
int Podium::getRadius() const{
    return this->r;
}
void Podium::setRadius(int r) {
    this->r = r;
}
int Podium::getType() const{
    return 1;
}
std::string Podium::toString(){
    std::stringstream ss;
    ss << this->getName()<<" "<<this->getX()<<" "<<this->getY()<<" "<<this->getRadius();
    return ss.str();
}