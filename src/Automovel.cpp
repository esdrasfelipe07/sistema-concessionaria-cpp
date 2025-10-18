#include "Automovel.h"
#include <iostream>

// Construtor da classe Automovel, que inicializa os membros da classe e chama o construtor da classe base (Veiculo).
Automovel::Automovel(std::string marca, double preco, std::string numChassi, int anoFabricacao, std::string tipoMotor)
    : Veiculo(marca, preco, numChassi, anoFabricacao), tipoMotor(tipoMotor) {} // inicializa os membros da classe base e o membro modelo

// Função para exibir os dados do automóvel na saída padrão.
void Automovel::exibirDados() {
    std::cout << "\nMarca: " << marca << "\n"
              << "Preço: R$ " << preco << "\n"
              << "Chassi: " << numChassi << "\n"
              << "Ano: " << anoFabricacao << "\n"
              << "Tipo de motor: " << tipoMotor << "\n";
}

// Função para obter o tipo de motor do automóvel.
std::string Automovel::getTipoMotor() const {
    return tipoMotor;
}
