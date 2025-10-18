#include "Caminhao.h"
#include <iostream>

// Construtor da classe Caminhao, que inicializa os membros da classe base e o membro tipoCarga.
Caminhao::Caminhao(std::string marca, double preco, std::string numChassi, int anoFabricacao, std::string tipoCarga)
    : Veiculo(marca, preco, numChassi, anoFabricacao), tipoCarga(tipoCarga) {}    // inicializa os membros da classe base e o membro modelo

void Caminhao::exibirDados() {                   // Função para exibir os dados do caminhão na saída padrão.
    std::cout << "\nMarca: " << marca << "\n"
              << "Preço: R$ " << preco << "\n"
              << "Chassi: " << numChassi << "\n"
              << "Ano: " << anoFabricacao << "\n"
              << "Tipo de carga: " << tipoCarga << "\n";
}

// Função para obter o tipo de carga do caminhão.
std::string Caminhao::getTipoCarga() const { 
    return tipoCarga;
}
