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

Vehicle::Vehicle(int vol, int peso, int cos) : volMax(vol), pesoMax(peso), cost(cos){

 }

std::string Vehicle::toString() {
    return "Maximum volume " + std::to_string(volMax) + ", maximum weight " + std::to_string(this->pesoMax) + ", cost " + std::to_string(this->cost);
}

