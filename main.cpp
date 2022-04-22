#include <iostream>
#include "Classes/Helper.h"
#include "Classes/Vehicle.h"
#include "Classes/Delivery.h"

//Só para ser mais rápido a dar debug, não vou usar isto no que for necessário para o programa.
void print(std::string yo) {
    std::cout << yo << std::endl;
}

void Situation1(std::vector<Delivery> deliveries) {
    std::cout << "*" << std::endl;
    Helper sitHelper;
    std::vector<Vehicle> vehicles;
    sitHelper.ReadVehicles(&vehicles);
    sitHelper.ReadDeliveries(&deliveries);

    std::vector<Delivery> leftovers;
    std::cout << "* Couriers: ";
    std::cout <<std::to_string(sitHelper.sit1FirstFit(deliveries, vehicles, &leftovers)) << std::endl;
    std::cout << "* Deliveries not delivered: " << leftovers.size() << std::endl;

    if (leftovers.size() == 0) return;
    int n;
    while (true) {
        std::cout << "*" << std::endl << "* Press 0 if you wish to go back to menu" << std::endl;
        std::cout << "* Press 1 if you wish to repeat adding the deliveries not delivered" << std::endl;
        std::cout << std::endl;
        std::cin >> n;
        std::cout << "*" << std::endl;
        if (std::cin.eof()) {
            exit(1);
        }
        if (!std::cin.good()) {
            std::cout << "\n Invalid input!\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        switch (n) {
            case 0:
                return;
            case 1:
                Situation1(leftovers);
                return;
            default:
                continue;
        }
    }

}

void Situation2(std::vector<Delivery> deliveries) {
    Helper sitHelper;
    std::vector<Vehicle> vehicles;
    sitHelper.ReadVehicles(&vehicles);
    sitHelper.ReadDeliveries(&deliveries);

    std::vector<Delivery> leftovers;
    int couriers =  sitHelper.sit2FirstFit(deliveries, vehicles, &leftovers);
    std::cout << "* Couriers: " << couriers << std::endl;
    std::cout << "* Deliveries not delivered: " << leftovers.size() << std::endl;


    if (leftovers.size() == 0) return;
    int n;
    while (true) {
        std::cout << "*" << std::endl << "* Press 0 if you wish to go back to menu" << std::endl;
        std::cout << "* Press 1 if you wish to repeat adding the deliveries not delivered" << std::endl;
        std::cout << std::endl;
        std::cin >> n;
        std::cout << "*" << std::endl;
        if (std::cin.eof()) {
            exit(1);
        }
        if (!std::cin.good()) {
            std::cout << "\n Invalid input!\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        switch (n) {
            case 0:
                return;
            case 1:
                Situation2(leftovers);
                return;
            default:
                continue;
        }
    }
}

bool timeCost(Delivery i1, Delivery i2) {
    return (i1.getDuration() < i2.getDuration());
}

void Situation3(std::vector<Delivery> deliveries) {
    Helper sitHelper;
    sitHelper.ReadDeliveries(&deliveries);
    std::sort(deliveries.begin(), deliveries.end(), timeCost);

    std::vector<Delivery> leftovers;
    //28800 segundos disponiveis
    int timeLeft = 28800;
    for(auto deli: deliveries) {
        if (timeLeft > deli.getDuration()) {
            timeLeft -= deli.getDuration();
        } else {
            leftovers.push_back(deli);
        }
    }

    std::cout << "* Deliveries: " << deliveries.size() - leftovers.size() << std::endl << "* Deliveries to return: " << leftovers.size() << std::endl;
    std::cout << "* Average delivery time: " << (28800 - timeLeft)/(deliveries.size() - leftovers.size()) << " seconds" << std::endl;

    if (leftovers.size() == 0) return;
    int n;
    while (true) {
        std::cout << "*" << std::endl << "* Press 0 if you wish to go back to menu" << std::endl;
        std::cout << "* Press 1 if you wish to repeat adding the deliveries not delivered" << std::endl;
        std::cout << std::endl;
        std::cin >> n;
        std::cout << "*" << std::endl;
        if (std::cin.eof()) {
            exit(1);
        }
        if (!std::cin.good()) {
            std::cout << "\n Invalid input!\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        switch (n) {
            case 0:
                return;
            case 1:
                Situation3(leftovers);
                return;
            default:
                continue;
        }
    }
}

void separator() {
    std::cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << std::endl;
}

int main() {
    int n;

    while (true) {
        std::vector<Delivery> deliveries;
        separator();
        std::cout << "* PRESS 0 TO QUIT" << std::endl << "*" << std::endl;
        std::cout << "* Situation:";
        std::cin >> n;
        std::cout << "*" << std::endl;
        if (std::cin.eof()) {
            separator();
            exit(1);
        }
        if (!std::cin.good()) {
            std::cout << "\n Invalid input!\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        switch (n) {
            case 1:
                Situation1(deliveries);
                break;
            case 2 :
                Situation2(deliveries);
                break;
            case 3 :
                Situation3(deliveries);
                break;
            case 0 :
                separator();
                exit(0);
            default:
                std::cout << "\n Invalid input!\n";
        }
    }
 }

