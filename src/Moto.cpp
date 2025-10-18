#include "Moto.h"
#include <iostream>

// Construtor da classe Moto que inicializa os membros da classe base e o membro modelo.
Moto::Moto(std::string marca, double preco, std::string numChassi, int anoFabricacao, std::string modelo)
    : Veiculo(marca, preco, numChassi, anoFabricacao), modelo(modelo) {}    // inicializa os membros da classe base e o membro modelo

void Moto::exibirDados() {                          // Método para exibir os dados da moto na saída padrão.
    std::cout << "\nMarca: " << marca << "\n"
              << "Preço: R$ " << preco << "\n"
              << "Chassi: " << numChassi << "\n"
              << "Ano: " << anoFabricacao << "\n"
              << "Modelo: " << modelo << "\n";
}

std::string Moto::getModelo() const {              // Método para obter o modelo da moto.
    return modelo;
}
