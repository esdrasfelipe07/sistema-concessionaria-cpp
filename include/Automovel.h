#ifndef AUTOMOVEL_H
#define AUTOMOVEL_H

#include "Veiculo.h"

// Declaração da classe Automovel que herda publicamente da classe Veiculo.
class Automovel : public Veiculo {
private:
    std::string tipoMotor; // Membro privado que armazena o tipo de motor do automóvel.

public:
    // Construtor da classe Automovel, que inicializa os membros da classe base e o membro tipoMotor.
    Automovel(std::string marca, double preco, std::string numChassi, int anoFabricacao, std::string tipoMotor);
    void exibirDados(); // Função para exibir os dados do automóvel na saída padrão.
    std::string getTipoMotor() const; // Função para obter o tipo de motor do automóvel.
};

#endif
