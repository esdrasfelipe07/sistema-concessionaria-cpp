#include "Concessionaria.h"
#include "Automovel.h" 
#include "Moto.h"      
#include "Caminhao.h"
#include <iostream>

// Construtor da classe Concessionaria, inicializa o nome e o CNPJ da concessionária.
Concessionaria::Concessionaria(std::string nome, std::string CNPJ)
    : nome(nome), CNPJ(CNPJ) {}

// Destrutor da classe Concessionaria, libera a memória alocada para cada veículo no estoque.
Concessionaria::~Concessionaria() {
    for(auto veiculo : estoque) {
        delete veiculo;
    }
}

// Retorna o nome da concessionária.
std::string Concessionaria::getNome() const {
    return nome;
}

// Retorna o CNPJ da concessionária.
std::string Concessionaria::getCNPJ() const {
    return CNPJ;
}

// Retorna uma referência constante ao vetor de veículos no estoque.
const std::vector<Veiculo*>& Concessionaria::getEstoque() const {
    return estoque;
}

// Função responsavel por adicionar um veículo ao estoque.
void Concessionaria::adicionarVeiculo(Veiculo* veiculo) {
    estoque.push_back(veiculo); // O push_back é responsavel por adicionar um veículo ao estoque
}

// Faz a verificação se um veículo com o número de chassi fornecido existe no estoque.
bool Concessionaria::veiculoExiste(std::string numChassi) const {
    for(auto veiculo : estoque) {                  // Itera sobre cada veículo no estoque.
        if(veiculo->getNumChassi() == numChassi) { // Verifica se o número de chassi do veículo é igual ao número de chassi fornecido.
            return true;
        }
    }
    return false;
}

bool Concessionaria::removerVeiculo(std::string numChassi) {    // Remove um veículo com o número de chassi fornecido do estoque.
    for(size_t i = 0; i < estoque.size(); i++) {                // Itera sobre o vetor de veículos no estoque.
        if(estoque[i]->getNumChassi() == numChassi) {
            delete estoque[i];                                  // Libera a memória do veículo a ser removido.
            estoque.erase(estoque.begin() + i);                 // Remove o veículo do vetor.
            return true;
        }
    }
    return false;
}

Veiculo* Concessionaria::buscarVeiculo(std::string numChassi) {  // Busca um veículo com o número de chassi fornecido no estoque e retorna um ponteiro para ele.
    for(auto veiculo : estoque) {                                // Itera sobre o vetor de veículos no estoque.
        if(veiculo->getNumChassi() == numChassi) {
            return veiculo;
        }
    }
    return nullptr;                                               // Retorna nullptr se o veículo não for encontrado.
}

// Função para aumentar o preço de um veículo no estoque.
void Concessionaria::aumentarPrecos(double x) {
    int totalAutomoveis = 0;
    int totalMotos = 0;
    int totalCaminhoes = 0;

    for (auto veiculo : estoque) {
        if (dynamic_cast<Automovel*>(veiculo)) {
            veiculo->setPreco(veiculo->getPreco() * (1 + x / 100.0)); // X%
            totalAutomoveis++;
        } else if (dynamic_cast<Moto*>(veiculo)) {
            veiculo->setPreco(veiculo->getPreco() * (1 + 2 * x / 100.0)); // 2X%
            totalMotos++;
        } else if (dynamic_cast<Caminhao*>(veiculo)) {
            veiculo->setPreco(veiculo->getPreco() * (1 + 3 * x / 100.0)); // 3X%
            totalCaminhoes++;
        }
    }

    // Exibe as mensagens de confirmação ou ausência de veículos
    if (totalAutomoveis > 0) {
        std::cout << "Aumento de " << x << "% nos preços de automóveis da Concessionária " << nome << " realizado.\n";
    } else {
        std::cout << "Nenhum automóvel encontrado na Concessionária " << nome << ".\n";
    }

    if (totalMotos > 0) {
        std::cout << "Aumento de " << 2 * x << "% nos preços de motos da Concessionária " << nome << " realizado.\n";
    } else {
        std::cout << "Nenhuma moto encontrada na Concessionária " << nome << ".\n";
    }

    if (totalCaminhoes > 0) {
        std::cout << "Aumento de " << 3 * x << "% nos preços de caminhões da Concessionária " << nome << " realizado.\n";
    } else {
        std::cout << "Nenhum caminhão encontrado na Concessionária " << nome << ".\n";
    }
}
