#ifndef MOTO_H
#define MOTO_H

#include "Veiculo.h"

// Declaração da classe Moto, que herda publicamente da classe Veiculo.
class Moto : public Veiculo {                 
private:
    std::string modelo;            // Membro privado representando o modelo da moto.

public:
    // Construtor da classe Moto que inicializa os membros da classe base e o membro modelo.
    Moto(std::string marca, double preco, std::string numChassi, int anoFabricacao, std::string modelo);
    void exibirDados();                            // Método para exibir os dados da moto.
    std::string getModelo() const;                 // Método para obter o modelo da moto.
};

#endif
