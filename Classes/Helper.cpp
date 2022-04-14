//
// Created by asus on 13/04/2022.
//

#include "Helper.h"

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
