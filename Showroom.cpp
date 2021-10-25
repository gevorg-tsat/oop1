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
    if (!checkHWLXY(x))
        throw std::exception();
    if (!checkHWLXY(y))
        throw std::exception();
    this->name = name;
    this->x = x;
    this->y = y;
}
void Showroom::setName(const std::string& name) {
    this->name = name;
}
void Showroom::setX(int x) {
    if (!checkHWLXY(x))
        throw std::exception();
    this->x = x;
}
void Showroom::setY(int y) {
    if (!checkHWLXY(y))
        throw std::exception();
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