//
// Created by asus on 13/04/2022.
//

#include "Helper.h"
#include "Vehicle.h"
#include "Delivery.h"

void Helper::ReadDeliveries(std::vector<Delivery> *deliveries) {
    std::ifstream MyReadFile("../Input/encomendas.txt");
    int first_line = 0;
    if (MyReadFile.is_open()) {
        std::string line;
        while (getline(MyReadFile, line)) {
            if (first_line == 0) {
                first_line++;
            }
            else {
                //  3 19 754 984
                int last_space = 0;
                std::string volume = line.substr(last_space, line.find(' '));
                last_space = last_space + 1 + line.find(' ');
                std::string weight = line.substr(last_space, line.substr(last_space).find(' '));
                last_space = last_space + 1 + line.substr(last_space).find(' ');
                std::string reward = line.substr(last_space, line.substr(last_space).find(' '));
                last_space = last_space + 1 + line.substr(last_space).find(' ');
                std::string duration = line.substr(last_space, line.substr(last_space).find(' '));
                //std::cout << line << std::endl;
                //std::cout << "volume:" << volume << " weight:" << weight << " reward:" << reward << " duration:" << duration << std::endl;
                deliveries->emplace_back(false, std::stoi(volume), std::stoi(weight), std::stoi(reward), std::stoi(duration));
            }
        }
    }
    else {
        std::cout << "Failed to open" << std::endl;
    }
    // Close the MyReadFile
    MyReadFile.close();
    return;
}

void Helper::ReadVehicles(std::vector<Vehicle> *vehicles) {
    std::ifstream MyReadFile("../Input/carrinhas.txt");
    int first_line = 0;
    if (MyReadFile.is_open()) {
        std::string line;
        while (getline(MyReadFile, line)) {
            if (first_line == 0) {
                first_line++;
            }
            else {
                //  3 19 754 984
                int last_space = 0;
                std::string volume = line.substr(last_space, line.find(' '));
                last_space = last_space + 1 + line.find(' ');
                std::string weight = line.substr(last_space, line.substr(last_space).find(' '));
                last_space = last_space + 1 + line.substr(last_space).find(' ');
                std::string cost = line.substr(last_space, line.substr(last_space).find(' '));
                //std::cout << line << std::endl;
                //std::cout << "volume:" << volume << " weight:" << weight << " cost:" << cost << std::endl;
                vehicles->emplace_back(std::stoi(volume), std::stoi(weight), std::stoi(cost));
            }
        }
    }
    else {
        std::cout << "Failed to open" << std::endl;
    }
    // Close the MyReadFile
    MyReadFile.close();
    return;
}

bool compareDeliveriesVolWei(Delivery i1, Delivery i2)
{
    if (i1.getVolume() > i2.getVolume())
        return true;
    else if (i1.getVolume() == i2.getVolume()) {
        return (i1.getWeight() > i2.getWeight());
    }
    else
        return false;
}

bool compareVansVolWei(Vehicle i1, Vehicle i2)
{
    if (i1.getVolume() > i2.getVolume())
        return true;
    else if (i1.getVolume() == i2.getVolume()) {
        return (i1.getWeight() > i2.getWeight());
    }
    else
        return false;
}

bool compareDeliveriesWeiVol(Delivery i1, Delivery i2)
{
    if (i1.getWeight() > i2.getWeight())
        return true;
    else if (i1.getWeight() == i2.getWeight()) {
        return (i1.getVolume() > i2.getVolume());
    }
    else
        return false;
}

bool compareVansWeiVol(Vehicle i1, Vehicle i2)
{
    if (i1.getWeight() > i2.getWeight())
        return true;
    else if (i1.getWeight() == i2.getWeight()) {
        return (i1.getVolume() > i2.getVolume());
    }
    else
        return false;
}

int Helper::firstFitDecVol(std::vector<Delivery> delis, std::vector<Vehicle> vans, std::vector<Delivery> *leftovers) {
    std::sort(delis.begin(), delis.end(), compareDeliveriesVolWei);

    // As the original First Fit has every bin with the same size we will sort our vector of "bins" in order to have the
    //ones that can take more deliveries first.
    std::sort(vans.begin(), vans.end(), compareVansVolWei);

    return deliveryFirstFit(delis, vans, leftovers);

}

int Helper::firstFitDecWei(std::vector<Delivery> delis, std::vector<Vehicle> vans, std::vector<Delivery> *leftovers) {
    std::sort(delis.begin(), delis.end(), compareDeliveriesWeiVol);

    // As the original First Fit has every bin with the same size we will sort our vector of "bins" in order to have the
    //ones that can take more deliveries first.
    std::sort(vans.begin(), vans.end(), compareVansWeiVol);

    return deliveryFirstFit(delis, vans, leftovers);

}


int Helper::deliveryFirstFit(std::vector<Delivery> delis, std::vector<Vehicle> vans, std::vector<Delivery> *leftover) {
    int res = 0;

    for (int i = 0; i < delis.size(); i++) {
        // Find the first bin that can accommodate
        // weight[i]
        int j;
        for (j = 0; j < res; j++) {
            if (vans[j].getVolume() >= delis[i].getVolume() && vans[j].getWeight() >= delis[i].getWeight()) {
                vans[j].addCargo(delis[i].getVolume(), delis[i].getWeight());

                break;
            }
        }

        // If no bin could accommodate weight[i]
        if (j == res && res < vans.size()) {
            vans[res].addCargo(delis[i].getVolume(), delis[i].getWeight());
            res++;
        }
        else if (j == res)
            leftover->push_back(delis[i]);

    }

    std::cout << "LeftOvers! " << leftover->size() << std::endl;
    return res;
}
