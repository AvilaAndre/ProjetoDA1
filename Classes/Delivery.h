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
    /**
     * The constructor of the delivery class.
     * @param express Defines if it is an express delivery or a normal delivery.
     * @param wei Defines the value of weight.
     * @param vol Defines the value of volume.
     * @param rew Defines the value of reward.
     * @param dur Defines the value of duration.
     */
    Delivery(bool express, int wei, int vol, int rew, int dur);
    /**
     * @return Returns a string with a few information about this class, primarily created for debugging.
     */
    std::string toString();
    /**
     * @return Returns the weight value.
     */
    int getWeight();
    /**
     * @return Returns the volume value.
     */
    int getVolume();
    /**
     * @return Returns the reward value.
     */
    int getReward();
    /**
     * @return Returns the duration value.
     */
    int getDuration();
};


#endif //PROJETODA1_DELIVERY_H
