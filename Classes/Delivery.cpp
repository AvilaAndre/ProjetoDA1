//
// Created by asus on 13/04/2022.
//

#include "Delivery.h"

Delivery::Delivery(bool express, int wei, int vol, int rew, int dur) {
    if (express) {
        type = Normal;
    } else {
        type = Express;
    }

    this->weight = wei;
    this->volume = vol;
    this->reward = rew;
    this->duration = dur;
}

std::string Delivery::toString() {
    if (type == Normal)
        return "Delivery type Normal, weight " + std::to_string(this->weight) + ", volume " + std::to_string(this->volume) + ", reward " + std::to_string(this->reward) + ", duration " + std::to_string(this->duration);
    else
        return "Delivery type Express, weight " + std::to_string(this->weight) + ", volume " + std::to_string(this->volume) + ", reward " + std::to_string(this->reward) + ", duration " + std::to_string(this->duration);
}

int Delivery::getWeight() {
    return this->weight;
}

int Delivery::getVolume() {
    return this->volume;
}
int Delivery::getReward() {
    return this->reward;
}

int Delivery::getDuration() {
    return this->duration;
}
