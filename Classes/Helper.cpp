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
                // 3 19 754 984
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

bool compareDeliveries(Delivery i1, Delivery i2) {
    return (i1.getVolume() + i1.getWeight() > i2.getVolume() + i2.getWeight());
}

bool compareVans(Vehicle i1, Vehicle i2) {
    return (i1.getVolume() + i1.getWeight() > i2.getVolume() + i2.getWeight());
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

int Helper::firstFit(std::vector<Delivery> delis, std::vector<Vehicle> vans, std::vector<Delivery> *leftovers) {
    std::sort(delis.begin(), delis.end(), compareDeliveries);

    // As the original First Fit has every bin with the same size we will sort our vector of "bins" in order to have the
    //ones that can take more deliveries first.
    std::sort(vans.begin(), vans.end(), compareVans);

    return deliveryFirstFit(delis, vans, leftovers);
}


int Helper::deliveryFirstFit(std::vector<Delivery> delis, std::vector<Vehicle> vans, std::vector<Delivery> *leftover) {
    int res = 0;

    for (int i = 0; i < delis.size(); i++) {
        int j;
        for (j = 0; j < res; j++) {
            if (vans[j].getVolume() >= delis[i].getVolume() && vans[j].getWeight() >= delis[i].getWeight()) {
                vans[j].addCargo(delis[i].getVolume(), delis[i].getWeight());

                break;
            }
        }

        // If no vehicle of the already carrying cargo can take this cargo, check if there are vehicles available or if it is supposed to be discarded.
        if (j == res && res < vans.size()) {
            vans[res].addCargo(delis[i].getVolume(), delis[i].getWeight());
            res++;
        }
        else if (j == res)
            leftover->push_back(delis[i]);

    }

    return res;
}

int Helper::bestFitDecVol(std::vector<Delivery> delis, std::vector<Vehicle> vans, std::vector<Delivery> *leftovers) {
    std::sort(delis.begin(), delis.end(), compareDeliveriesWeiVol);

    // As the original First Fit has every bin with the same size we will sort our vector of "bins" in order to have the
    //ones that can take more deliveries first.
    std::sort(vans.begin(), vans.end(), compareVansWeiVol);

    return deliveryOwnBestFit(delis, vans, leftovers);

}

int Helper::bestFitDecWei(std::vector<Delivery> delis, std::vector<Vehicle> vans, std::vector<Delivery> *leftovers) {
    std::sort(delis.begin(), delis.end(), compareDeliveriesWeiVol);

    // As the original First Fit has every bin with the same size we will sort our vector of "bins" in order to have the
    //ones that can take more deliveries first.
    std::sort(vans.begin(), vans.end(), compareVansWeiVol);

    return deliveryOwnBestFit(delis, vans, leftovers);

}

int Helper::deliveryBestFit(std::vector<Delivery> delis, std::vector<Vehicle> vans, std::vector<Delivery> *leftover) {
    int res = 0;

    for (int i = 0; i < delis.size(); i++) {
        int j;
        int min = vans[0].getMaxVolume() + 1 + vans[0].getMaxWeight();
        int bi = 0;

        for (j = 0; j < res; j++) {
            if (vans[j].getVolume() >= delis[i].getVolume() && vans[j].getWeight() >= delis[i].getWeight()) {
                if (vans[j].getVolume() - delis[i].getVolume() + vans[j].getWeight() - delis[i].getWeight() < min) {
                    //vans[j].addCargo(delis[i].getVolume(), delis[i].getWeight());
                    bi = j;
                    min = vans[j].getVolume() - delis[i].getVolume() + vans[j].getWeight() - delis[i].getWeight();
                    break;
                }
            }
        }

        // If no bin could accommodate weight[i],
        // create a new bin
        if (min == vans[0].getMaxVolume() + 1 + vans[0].getMaxWeight() && res < vans.size()) {
            vans[res].addCargo(delis[i].getVolume(), delis[i].getWeight());
            res++;
        }
        else if (j == res)
            leftover->push_back(delis[i]);
        else // Assign the item to best bin
            vans[bi].addCargo(delis[i].getVolume(), delis[i].getWeight());

        // If no vehicle of the already carrying cargo can take this cargo, check if there are vehicles available or if it is supposed to be discarded.
        //if (j == res && res < vans.size()) {
        //    vans[res].addCargo(delis[i].getVolume(), delis[i].getWeight());
        //    res++;
        //}
        //else if (j == res)
        //    leftover->push_back(delis[i]);

    }

    return res;
}


int Helper::deliveryOwnBestFit(std::vector<Delivery> delis, std::vector<Vehicle> vans, std::vector<Delivery> *leftover) {
    int i = 0;

    for (i = 0; i < vans.size(); i++) {
        while (true) {
            double vansRatio = vans[i].getVolume() / vans[i].getWeight();
            int min = -1;
            std::pair<double, std::pair<int, int>> minimum = {vansRatio, {0, 0}};
            std::cout << i << "- Missing: " << vans[i].getVolume() << " " << vans[i].getWeight() << std::endl;
            for (int j = 0; j < delis.size(); j++) {
                double ratioDiff = vansRatio - (delis[j].getVolume() / (double) delis[j].getWeight());
                //std::cout << (delis[j].getVolume() / (double)delis[j].getWeight()) << std::endl;
                if (std::abs(ratioDiff) <= minimum.first
                    && vans[i].getVolume() > delis[j].getVolume()
                    && vans[i].getWeight() > delis[j].getWeight()) {
                    if ((vansRatio - (delis[j].getVolume() / (double)delis[j].getWeight()) == minimum.first)) {
                        if (minimum.second.first < delis[j].getVolume()) {
                            std::cout << "New min! " << std::abs(ratioDiff) <<  std::endl;
                            minimum = {std::abs(ratioDiff),
                                       {delis[j].getVolume(), delis[j].getWeight()}};
                            min = j;
                        }
                    }
                    else {
                        //std::cout << delis[j].getVolume() << " " << (double) delis[j].getWeight() << " New min! " << std::abs(ratioDiff) << std::endl;
                        minimum = {std::abs(ratioDiff), {delis[j].getVolume(), delis[j].getWeight()}};
                        min = j;
                    }
                }
            }
            //std::cout << delis.size() << std::endl;
            //std::cout << i << " v:" << vans[i].getVolume() << " w:" << vans[i].getWeight() << std::endl;
            if (min == -1) {
                std::cout << "min was -1" << std::endl;
                break;
            }
            else {
                //std::cout << delis.size() << " reducing ";
                vans[i].addCargo(delis[min].getVolume(), delis[min].getWeight());
                delis.erase(delis.begin() + min);
                //std::cout << delis.size() << std::endl;
            }
        }
        if (delis.size() == 0) break;
    }

    std::cout << "LeftOvers! " << delis.size() << std::endl;
    return i;
}
