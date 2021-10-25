//
// Created by Gevorg Tsaturyan on 25.09.2021.
//

#ifndef LABA_OOP_CAR_H
#define LABA_OOP_CAR_H
#include <string>
#include "Showroom.h"
class Car : public Showroom {
public:
    Car();
    ~Car();
    Car(const std::string& name,int length, int width, int x, int y, int angle);
    Car(const Car& car);
    void setWidth(int width);
    void setAngle(int angle);
    void setLength(int length);
    int getWidth() const;
    int getAngle() const;
    int getLength() const;
private:
    int width;
    int length;
    int angle;
protected:
    bool checkAngle(int angle);
};

#endif //LABA_OOP_CAR_H
