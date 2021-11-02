//
// Created by Gevorg Tsaturyan on 25.10.2021.
//

#include "Showroom.h"
Showroom::Showroom() {
    this->name = EMPTY;
    this->x = ZERO;
    this->y = ZERO;
}
Showroom::~Showroom() {
    //
}
Showroom::Showroom(const std::string& name, int x, int y) {
    this->name = name;
    this->x = x;
    this->y = y;
}
void Showroom::setName(const std::string& name) {
    this->name = name;
}
void Showroom::setX(int x) {
    this->x = x;
}
void Showroom::setY(int y) {
    this->y = y;
}
const std::string& Showroom::getName() const {
    return this->name;
}
int Showroom::getX() const{
    return this->x;
}
int Showroom::getY() const{
    return this->y;
}
bool  Showroom::checkHWLXY(int value) {
    if (value<0)
        return false;
    return true;
}
int Showroom::getType() const{

}

std::string Showroom::toString() {

}