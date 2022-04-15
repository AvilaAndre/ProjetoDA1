//
// Created by asus on 13/04/2022.
//

#include "Vehicle.h"
 /*
  * volume(volMax)
  * peso (pesoMax)
  * matrícula
  * custo de transporte
  *
  */

Vehicle::Vehicle(int vol, int peso, int cos) : maxVol(vol), maxWeight(peso), cost(cos), volume(vol), weight(peso){
 }

std::string Vehicle::toString() {
    return "Maximum volume " + std::to_string(maxVol) + ", maximum weight " + std::to_string(this->maxWeight) + ", cost " + std::to_string(this->cost);
}

int Vehicle::getMaxVolume() {
    return this->maxVol;
}

int Vehicle::getMaxWeight() {
    return this->maxWeight;
}

int Vehicle::getVolume() {
    return this->volume;
}

int Vehicle::getWeight() {
    return this->weight;
}

int Vehicle::getCost() {
    return this->cost;
}

void Vehicle::addCargo(int vol, int wei) {
    this->volume -= vol;
    this->weight -= wei;
}

