//
// Created by asus on 13/04/2022.
//

#ifndef PROJETODA1_HELPER_H
#define PROJETODA1_HELPER_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>


class Delivery;
class Vehicle;

class Helper {
public:
    /**
     * Reads the values from the file encomendas.txt creating objects that will be stored in the @param deliveries vector.
     */
    void ReadDeliveries(std::vector<Delivery> *deliveries);
    /**
     * Reads the values from the file carrinhas.txt creating objects that will be stored in the @param vehicles vector.
     */
    void ReadVehicles(std::vector<Vehicle> *vehicles);
    /**
     * It's whole purpose is to sort delis and vans and execute deliveryFirstFit.
     * @param delis a vector with deliveries.
     * @param vans a vector with the vehicles.
     * @param leftovers a vector that receives the deliveries that aren't going to be delivered.
     * @return Returns the amount of vehicles needed.
     */
    int sit1FirstFit(std::vector<Delivery> delis, std::vector<Vehicle> vans, std::vector<Delivery> *leftovers);
    /**
     * Applies the First Fit Decreasing algorithm (one of the many solutions to the bin packing problem) adapted to this particular situation.
     * It starts by looping through every cargo, first it adds cargo to the first vehicle, then it fills that vehicle with the next cargo, when the cargo being looped doesn't fit the vehicle(s) being filled it gets a new vehicle to fill, however, if there are no more vehicles the cargo is added to a vector with every delivery that is not going to be delivered.
     * @param delis a vector with deliveries.
     * @param vans a vector with the vehicles.
     * @param leftovers a vector that receives the deliveries that aren't going to be delivered.
     * @return Returns the amount of vehicles needed.
     */
    int deliveryFirstFit(std::vector<Delivery> delis, std::vector<Vehicle> vans, std::vector<Delivery> *leftovers);
    /**
     * It's whole purpose is to sort delis and vans and execute lucrativeFirstFit.
     * @param delis a vector with deliveries.
     * @param vans a vector with the vehicles.
     * @param leftovers a vector that receives the deliveries that aren't going to be delivered.
     * @return Returns the amount of vehicles needed.
     */
    int sit2FirstFit(std::vector<Delivery> delis, std::vector<Vehicle> vans, std::vector<Delivery> *leftover);
    /**
     * Applies the First Fit Decreasing algorithm (one of the many solutions to the bin packing problem) adapted to this particular situation.
     * It starts by looping through every cargo, first it adds cargo to the first vehicle, then it fills that vehicle with the next cargo, when the cargo being looped doesn't fit the vehicle(s) being filled it gets a new vehicle to fill, however, if there are no more vehicles the cargo is added to a vector with every delivery that is not going to be delivered.
     * @param delis a vector with deliveries.
     * @param vans a vector with the vehicles.
     * @param leftovers a vector that receives the deliveries that aren't going to be delivered.
     * @return Returns the amount of vehicles needed.
     */
    int lucrativeFirstFit(std::vector<Delivery> delis, std::vector<Vehicle> vans, std::vector<Delivery> *leftover);
};


#endif //PROJETODA1_HELPER_H
