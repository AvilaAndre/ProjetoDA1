#include <iostream>
#include "Classes/Helper.h"
#include "Classes/Vehicle.h"
#include "Classes/Delivery.h"

//Só para ser mais rápido a dar debug, não vou usar isto no que for necessário para o programa.
void print(std::string yo) {
    std::cout << yo << std::endl;
}

void Situation1() {
    print("* Otimizacao do numero de estafetas");
    std::cout << "*" << std::endl;
    Helper sitHelper;
    std::vector<Vehicle> vehicles;
    sitHelper.ReadVehicles(&vehicles);
    std::vector<Delivery> deliveries;
    sitHelper.ReadDeliveries(&deliveries);

    std::vector<Delivery> leftovers;
    std::cout << "* Estafetas: ";
    print(std::to_string(sitHelper.firstFit(deliveries, vehicles, &leftovers)));
    std::cout << "* Encomendas por entregar: " << leftovers.size() << std::endl;

}

void Situation2() {
   print("Situacao 2");
}

bool timeCost(Delivery i1, Delivery i2) {
    return (i1.getDuration() < i2.getDuration());
}

void Situation3() {
    Helper sitHelper;
    std::vector<Delivery> deliveries;
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

    std::cout << "* Entregas: " << deliveries.size() - leftovers.size() << std::endl << "* Encomendas para devolver: " << leftovers.size() << std::endl;
    std::cout << "* Tempo medio de entrega: " << (28800- timeLeft)/(deliveries.size() - leftovers.size()) << " segundos" << std::endl;
}

int main() {
    int n;
    /*
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
     */
    std::cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<std::endl;
    std::cout << "* Cenário: ";
    std::cin >> n;
    std::cout << "*" << std::endl;
    switch(n) {
        case 1:
            Situation1();
            break;
        case 2 :
            Situation2();
            break;
        case 3 :
            Situation3();
            break;
    }
    std::cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<std::endl;
    return 0;
}

/*
 * Classes:
 *  Delivery
 *  Courier
 *  Vehicle
 *  Helper
 */
