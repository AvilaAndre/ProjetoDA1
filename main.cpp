#include <iostream>
#include "Classes/Helper.h"
#include "Classes/Vehicle.h"


int main() {
    std::cout << "Hello, World!" << std::endl;

    Helper reader;
    std::vector<Vehicle> vehicles;
    reader.ReadVehicles(&vehicles);
    for (auto carrinha : vehicles) {
        std::cout << carrinha.toString() << std::endl;
    }
    std::vector<Delivery> deliveries;
    reader.ReadDeliveries(&deliveries);
    for (auto encomenda : deliveries) {
        std::cout << encomenda.toString() << std::endl;
    }
    return 0;
}

/*
 * Classes:
 *  Delivery
 *  Courier
 *  Vehicle
 *  Helper
 */
