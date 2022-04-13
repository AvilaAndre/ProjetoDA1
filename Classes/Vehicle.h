//
// Created by asus on 13/04/2022.
//

#ifndef PROJETODA1_VEHICLE_H
#define PROJETODA1_VEHICLE_H


#include <string>

class Vehicle {
public:
    /**
     * Value of the maximum volume that each vehicle can offer
     */
    int volMax;
    /**
     * Value of the maximum weight that each vehicle can offer
     */
    int pesoMax;
    /**
     * Cost of each transportation
     */
    int cost;
    Vehicle(int vol, int peso, int cos);
    std::string toString();
};


#endif //PROJETODA1_VEHICLE_H
