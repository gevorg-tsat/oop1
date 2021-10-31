//
// Created by Gevorg Tsaturyan on 31.10.2021.
//

#include "Plan2.h"

Plan::Plan(Showroom** sr, int capacity) :
        sr(sr), capacity(capacity) {
}
void Plan::addPodium(Podium podium) {
    if (!capacity) {
        capacity++;
        sr = new Showroom[capacity]*;
        sr[capacity - 1] = new Podium(podium);
    } else {
        Showroom **tmp = new Showroom[capacity + 1]*;
        for (int j = 0; j < capacity; j++)
            tmp[j] = cp[j];
        delete[] cp;
        cp = tmp;
        cp[capacity].pod = podium;
        capacity++;
    }
}