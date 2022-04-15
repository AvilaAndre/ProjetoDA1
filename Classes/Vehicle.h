//
// Created by asus on 13/04/2022.
//

#ifndef PROJETODA1_VEHICLE_H
#define PROJETODA1_VEHICLE_H


#include <string>

class Vehicle {
public:
    /**
     * Value of the maximum volume that each vehicle can offer.
     */
    int maxVol;
    /**
     * Value of the maximum weight that each vehicle can offer.
     */
    int maxWeight;
    /**
     * The value of the volume this vehicle is able to transport, useful for changing the volume left while keeping track of the maximum.
     */
    int volume;
    /**
     * The value of the weight this vehicle is able to transport, useful for changing the weight left while keeping track of the maximum.
     */
    int weight;
    /**
     * Cost of each transportation.
     */
    int cost;
    /**
     * The constructor of the vehicle class.
     * @param vol Defines the value of maxVol and volume.
     * @param peso Defines the value of weight.
     * @param cos Defines the value of cost.
     */
    Vehicle(int vol, int peso, int cos);
    /**
     * @return Returns a string with a few information about this class, primarily created for debugging.
     */
    std::string toString();
    /**
     * @return Returns the maxVol value.
     */
    int getMaxVolume();
    /**
     * @return Returns the maxWeight value.
     */
    int getMaxWeight();
    /**
     * @return Returns the volume value.
     */
    int getVolume();
    /**
     * @return Returns the weight value.
     */
    int getWeight();
    /**
     * @return Returns the cost value.
     */
    int getCost();
    /**
     * Subtracts the value vol and wei from volume and weight respectively.
     * @param vol The volume to subtract.
     * @param wei The weight to subtract.
     */
    void addCargo(int vol, int wei);
};


#endif //PROJETODA1_VEHICLE_H
