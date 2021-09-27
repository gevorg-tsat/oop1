//
// Created by Gevorg Tsaturyan on 25.09.2021.
//

#ifndef LABA_OOP_CAR_H
#define LABA_OOP_CAR_H
#include <string>

class Car {
public:
    Car();
    Car(std::string carName,int height, int width, int length,int x, int y, int angle);
    Car(const Car& car);
    void setName(std::string carName);
    void setHeight(int height);
    void setWidth(int width);
    void setX(int x);
    void setY(int Y);
    void setAngle(int angle);
    void setLength(int length);
    const std::string& getName() const;
    int getHeight() const;
    int getWidth() const;
    int getX() const;
    int getY() const;
    int getAngle() const;
    int getLength() const;
private:
    std::string carName;
    int height;
    int width;
    int length;
    int x;
    int y;
    int angle;
protected:
    bool checkHWLXY(int value);
    bool checkAngle(int angle);
};

#endif //LABA_OOP_CAR_H
