//
// Created by asus on 13/04/2022.
//

#ifndef PROJETODA1_HELPER_H
#define PROJETODA1_HELPER_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "Vehicle.h"
#include "Delivery.h"

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
};


#endif //PROJETODA1_HELPER_H
