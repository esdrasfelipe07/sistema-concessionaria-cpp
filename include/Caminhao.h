#ifndef CAMINHAO_H
#define CAMINHAO_H

#include "Veiculo.h"

// Declaração da classe Caminhao que herda publicamente da classe Veiculo.
class Caminhao : public Veiculo {
private:
    std::string tipoCarga; // Membro privado que armazena o tipo de carga do caminhão.

public:
    // Construtor da classe Caminhao, que inicializa os membros da classe base e o membro tipoCarga.
    Caminhao(std::string marca, double preco, std::string numChassi, int anoFabricacao, std::string tipoCarga);
    void exibirDados(); // Função para exibir os dados do caminhão na saída padrão.
    std::string getTipoCarga() const; // Função para obter o tipo de carga do caminhão.
};

#endif
