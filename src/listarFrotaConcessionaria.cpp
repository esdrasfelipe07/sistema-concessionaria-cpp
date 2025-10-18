#include "listarFrotaConcessionaria.h"
#include "Automovel.h"
#include "Moto.h"
#include "Caminhao.h"
#include <iostream>
#include <iostream>

// Função para listar a frota de veículos de uma concessionária específica.
void listarFrotaConcessionaria(const std::vector<Concessionaria*>& concessionarias, const std::string& nomeConcessionaria) {
    bool concessionariaEncontrada = false;                  // Variável  responsavel por verificar se a concessionária foi encontrada.

    for (auto concessionaria : concessionarias) {           // Itera sobre o vetor de ponteiros para Concessionaria.
        if (concessionaria->getNome() == nomeConcessionaria) {     // Verifica se a concessionaria corresponde ao nome fornecido.
            concessionariaEncontrada = true;
            std::cout << "\nConcessionaria " << nomeConcessionaria << "\n";

            // Variáveis para contar e calcular o valor total de cada tipo de veículo.
            int totalAutomoveis = 0;
            int totalMotos = 0;
            int totalCaminhoes = 0;
            double valorTotalAutomoveis = 0.0;
            double valorTotalMotos = 0.0;
            double valorTotalCaminhoes = 0.0;

            for (auto veiculo : concessionaria->getEstoque()) {              // Itera sobre o vetor de veículos da concessionária.
                if (dynamic_cast<Automovel*>(veiculo)) {                     // Verifica o tipo de veículo usando dynamic_cast.
                    totalAutomoveis++;
                    valorTotalAutomoveis += veiculo->getPreco();
                } else if (dynamic_cast<Moto*>(veiculo)) {
                    totalMotos++;
                    valorTotalMotos += veiculo->getPreco();
                } else if (dynamic_cast<Caminhao*>(veiculo)) {
                    totalCaminhoes++;
                    valorTotalCaminhoes += veiculo->getPreco();
                }
            }

            // Imprime as estatísticas de cada tipo de veículo.
            std::cout << "Total de Automóveis: " << totalAutomoveis << "; Valor total: R$ " << valorTotalAutomoveis << "\n";
            std::cout << "Total de Motos: " << totalMotos << "; Valor total: R$ " << valorTotalMotos << "\n";
            std::cout << "Total de Caminhões: " << totalCaminhoes << "; Valor total: R$ " << valorTotalCaminhoes << "\n";

            // Calcula e imprime o valor total da frota.
            double valorTotalFrota = valorTotalAutomoveis + valorTotalMotos + valorTotalCaminhoes;
            std::cout << "Valor Total da frota: R$ " << valorTotalFrota << "\n";

            // Encerra a busca assim que a concessionária é encontrada.
            break;
        }
    }

    if (!concessionariaEncontrada) {            // Se a concessionária não for encontrada, exibe uma mensagem de erro.
        std::cout << "\nERRO - Concessionária " << nomeConcessionaria << " não encontrada.\n";
    }
}
