#ifndef VEICULO_H
#define VEICULO_H

#include <string>

// Declaração da classe base Veiculo.
class Veiculo {
protected:
    std::string marca;              // Membro protegido representando a marca do veículo.
    double preco;                   // Membro protegido representando o preço do veículo.
    std::string numChassi;          // Membro protegido representando o número do Chassi do veículo.
    int anoFabricacao;              // Membro protegido representando o ano de fabricação do veículo.

public:
    // Construtor da classe Veiculo que inicializa os membros com os valores fornecidos.
    Veiculo(std::string marca, double preco, std::string numChassi, int anoFabricacao);
    virtual ~Veiculo() {}                           // Destrutor virtual para permitir a destruição polimórfica.
    virtual void exibirDados() = 0;                 // Método puramente virtual para exibir os dados do veículo                                                                              implementado nas classes derivadas.
    // Métodos para obter informações do veículo.
    std::string getNumChassi() const;
    double getPreco() const;
    void setPreco(double novoPreco);
    int getAnoFabricacao() const;
};

#endif
