//
// Created by Gevorg Tsaturyan on 25.09.2021.
//

#ifndef LABA_OOP_CAR_H
#define LABA_OOP_CAR_H
#include <string>
#define ZERO 0
#define EMPTY ""
class Car {
public:
    Car();
    ~Car();
    Car(const std::string& carName,int length, int width, int x, int y, int angle);
    Car(const Car& car);
    void setName(const std::string& carName);
    void setWidth(int width);
    void setX(int x);
    void setY(int Y);
    void setAngle(int angle);
    void setLength(int length);
    const std::string& getName() const;
    int getWidth() const;
    int getX() const;
    int getY() const;
    int getAngle() const;
    int getLength() const;
private:
    std::string carName;
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
