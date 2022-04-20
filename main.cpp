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
    /*
    Cenario 2 otimizacao do lucro da empresa:
    estafetas:
    - cobram uma quantia pelo n total de pedidos entregues num dia.
            pela entrega a empresa recebe uma quantia paga pelo solicitador
    dos estafetas registados na plataforma deve-se selecionar os que maximizam o lucro da empresa naquele dia
    os pedidos que nao puderem ser entregues sao descartados e retornam ao fornecedor
    Dados de entrada:
    E -> estafetas registados com capacidade de volume Ve, peso We e custo Ce
    P -> pedidos a entregar com volume Vp, peso Wp e recompensa Rp

    OBJETIVO PRINCIPAL: maximizar o lucro da empresa (diferença entre a receita total e o custo total)
    para a entrega de todos os pedidos ou do maior número de pedidos, num dia, pelos estafetas
            selecionados
    */

    //Organizar por custo/(volume + peso)

   print("Situacao 2");

    Helper sitHelper;
    std::vector<Vehicle> vehicles;
    sitHelper.ReadVehicles(&vehicles);
    std::vector<Delivery> deliveries;
    sitHelper.ReadDeliveries(&deliveries);

    std::vector<Delivery> leftovers;
    std::cout << "* Estafetas: ";
    print(std::to_string(sitHelper.sit2WIP(deliveries, vehicles, &leftovers)));
    std::cout << "* Encomendas por entregar: " << leftovers.size() << std::endl;
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
void separator() {
    std::cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << std::endl;
}

int main() {
    int n;

    while (true) {
        separator();
        std::cout << "* PRESS 0 TO QUIT" << std::endl << "*" << std::endl;
        std::cout << "* Cenario:";
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
                Situation1();
                break;
            case 2 :
                Situation2();
                break;
            case 3 :
                Situation3();
                break;
            case 0 :
                separator();
                exit(0);
            default:
                std::cout << "\n Invalid input!\n";
        }
    }
 }

