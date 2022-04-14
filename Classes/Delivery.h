//
// Created by asus on 13/04/2022.
//
#include <string>


#ifndef PROJETODA1_DELIVERY_H
#define PROJETODA1_DELIVERY_H

enum DELIVERY_TYPE {
    Normal = 0,
    Express = 1
};

class Delivery {
private:
    DELIVERY_TYPE type;
    int weight;
    int volume;
    int reward;
    int duration;
public:
    Delivery(bool express, int wei, int vol, int rew, int dur);
    std::string toString();
};


#endif //PROJETODA1_DELIVERY_H
