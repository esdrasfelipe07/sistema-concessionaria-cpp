#ifndef CONCESSIONARIA_H
#define CONCESSIONARIA_H

#include <vector>
#include "Veiculo.h"

class Concessionaria {                       // Declaração da classe Concessionaria.
private:
    std::string nome;                        // Nome da concessionária.
    std::string CNPJ;                        // CNPJ da concessionária.
    std::vector<Veiculo*> estoque;           // Vetor de ponteiros para Veiculo representando o estoque.

public:
    Concessionaria(std::string nome, std::string CNPJ);      // Construtor da classe Concessionaria, inicializa o nome e o CNPJ da                                                                    concessionária.  
    ~Concessionaria();               // Destrutor da classe Concessionaria, libera a memória alocada para cada veículo no estoque.
    std::string getNome() const;     // Retorna o nome da concessionária.
    std::string getCNPJ() const;     // Retorna o CNPJ da concessionária.
    const std::vector<Veiculo*>& getEstoque() const;        // Retorna uma referência constante ao vetor de veículos no estoque.
    void adicionarVeiculo(Veiculo* veiculo);                // Adiciona um veículo ao estoque.
    bool veiculoExiste(std::string numChassi) const;        // Verifica se um veículo com o número de chassi fornecido existe no                                                                     estoque.
    // Remove um veículo com o número de chassi fornecido do estoque.
    // Retorna true se o veículo foi removido com sucesso, false se o veículo não foi encontrado.
    bool removerVeiculo(std::string numChassi);
    Veiculo* buscarVeiculo(std::string numChassi);              // Busca um veículo com o número de chassi fornecido no estoque e retorna um ponteiro para ele.
    void aumentarPrecos(double x); // Aumenta o preço de todos os veículos no estoque em um valor x.
};

#endif
