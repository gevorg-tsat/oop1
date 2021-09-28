//
// Created by Gevorg Tsaturyan on 25.09.2021.
//
#define ZERO 0
#define EMPTY ""
#include "Car.h"
Car::Car(std::string carName,int height, int width, int length,int x, int y, int angle) {
    if (!checkHWLXY(height))
        throw std::exception();
    if (!checkAngle(angle))
        throw std::exception();
    if (!checkHWLXY(width))
        throw std::exception();
    if (!checkHWLXY(length))
        throw std::exception();
    if (!checkHWLXY(x))
        throw std::exception();
    if (!checkHWLXY(y))
        throw std::exception();
    this->carName = carName;
    this->height = height;
    this->width = width;
    this->length = length;
    this->x = x;
    this->y = y;
    this->angle = angle;
}
Car::Car() { //default
    this->carName = EMPTY;
    this->height = ZERO;
    this->width = ZERO;
    this->length = ZERO;
    this->x = ZERO;
    this->y = ZERO;
    this->angle = ZERO;
}
Car::Car(const Car& car) {
    this->carName = car.carName;
    this->height = car.height;
    this->width = car.width;
    this->length = car.length;
    this->x = car.x;
    this->y = car.y;
    this->angle = car.angle;
}
void Car::setHeight(int height) {
    if (!checkHWLXY(height))
        throw std::exception();
    this->height = height;
}
void Car::setAngle(int angle) {
    if (!checkAngle(angle))
        throw std::exception();
    this->angle = angle;
}
void Car::setName(std::string carName) {
    this->carName = carName;
}
void Car::setWidth(int width) {
    if (!checkHWLXY(width))
        throw std::exception();
    this->width = width;
}
void Car::setX(int x) {
    if (!checkHWLXY(x))
        throw std::exception();
    this->x = x;
}
void Car::setY(int y) {
    if (!checkHWLXY(y))
        throw std::exception();
    this->y = y;
}
void Car::setLength(int length) {
    if (!checkHWLXY(length))
        throw std::exception();
    this->length = length;
}
const std::string& Car::getName() const {
    return this->carName;
}
int Car::getHeight() const {
    return this->height;
}
int Car::getWidth() const{
    return this->width;
}
int Car::getX() const{
    return this->x;
}
int Car::getY() const{
    return this->y;
}
int Car::getAngle() const{
    return this->angle;
}
int Car::getLength() const{
    return this->length;
}
bool  Car::checkHWLXY(int value) {
    if (value<0)
        return false;
    return true;
}
bool Car::checkAngle(int angle) {
    if (angle<0 || angle>=360)
        return false;
    return true;
}

