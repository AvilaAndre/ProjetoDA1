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
    int maxVol;
    /**
     * Value of the maximum weight that each vehicle can offer
     */
    int maxWeight;
    /**
     * Cost of each transportation
     */
    int volume;
    int weight;
    int cost;
    Vehicle(int vol, int peso, int cos);
    std::string toString();
    int getMaxVolume();
    int getMaxWeight();
    int getVolume();
    int getWeight();
    int getCost();
    void addCargo(int vol, int wei);
};


#endif //PROJETODA1_VEHICLE_H
