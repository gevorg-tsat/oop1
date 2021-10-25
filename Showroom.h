//
// Created by Gevorg Tsaturyan on 25.10.2021.
//

#ifndef LABA_OOP_SHOWROOM_H
#define LABA_OOP_SHOWROOM_H
#include <string>
#define ZERO 0
#define EMPTY ""
class Showroom {
public:
    Showroom();
    ~Showroom();
    Showroom(const std::string& name, int x, int y);
    void setName(const std::string& name);
    void setX(int x);
    void setY(int Y);
    const std::string& getName() const;
    int getX() const;
    int getY() const;

private:
   std::string name;
   int x;
   int y;
protected:
    bool checkHWLXY(int value);
};


#endif //LABA_OOP_SHOWROOM_H
