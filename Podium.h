//
// Created by Gevorg Tsaturyan on 13.10.2021.
//

#ifndef LABA_OOP_PODIUM_H
#define LABA_OOP_PODIUM_H
#include "Showroom.h"

class Podium : public Showroom{
public:
    Podium();
    ~Podium();
    Podium(const std::string& name, int x, int y, int r);
    Podium(const Podium& pod);
    void setRadius(int r);
    int getRadius() const;
    int getType() const;
private:
    int r;
};


#endif //LABA_OOP_PODIUM_H
