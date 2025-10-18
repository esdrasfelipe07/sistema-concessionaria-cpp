#include "Veiculo.h"

// Construtor da classe Veiculo que inicializa os membros com os valores fornecidos.
Veiculo::Veiculo(std::string marca, double preco, std::string numChassi, int anoFabricacao)
    : marca(marca), preco(preco), numChassi(numChassi), anoFabricacao(anoFabricacao) {}      // inicializa os membros com os valores fornecidos

std::string Veiculo::getNumChassi() const {                    // Método para obter o número de chassi do veículo.
    return numChassi;
}

double Veiculo::getPreco() const {                              // Método para obter o preço do veículo.
    return preco;
}

int Veiculo::getAnoFabricacao() const {                         // Método para obter o ano de fabricação do veículo.
    return anoFabricacao;
}

void Veiculo::setPreco(double novoPreco) {                     // Método para atualizar o preço do veículo.
    preco = novoPreco;
}
