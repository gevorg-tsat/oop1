//
// Created by Gevorg Tsaturyan on 25.09.2021.
//
#include "Car.h"
Car::Car(const std::string& name, int length,int width,int x, int y, int angle) : Showroom(name,x,y){
    if (!checkAngle(angle))
        throw std::exception();
    if (!checkHWLXY(width))
        throw std::exception();
    if (!checkHWLXY(length))
        throw std::exception();
    this->width = width;
    this->length = length;
    this->angle = angle;
}
Car::Car() : Showroom(){
    this->width = ZERO;
    this->length = ZERO;
    this->angle = ZERO;
}
Car::Car(const Car& car) : Showroom(car.getName(),car.getX(),car.getY()) {
    this->width = car.getWidth();
    this->length = car.getLength();
    this->angle = car.getAngle();
}
Car::~Car(){

}
void Car::setAngle(int angle) {
    if (!checkAngle(angle))
        throw std::exception();
    this->angle = angle;
}
void Car::setWidth(int width) {
    if (!checkHWLXY(width))
        throw std::exception();
    this->width = width;
}
void Car::setLength(int length) {
    if (!checkHWLXY(length))
        throw std::exception();
    this->length = length;
}
int Car::getWidth() const{
    return this->width;
}
int Car::getAngle() const{
    return this->angle;
}
int Car::getLength() const{
    return this->length;
}
bool Car::checkAngle(int angle) {
    if (angle<0 || angle>=360)
        return false;
    return true;
}

