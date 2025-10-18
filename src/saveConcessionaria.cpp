#include "saveConcessionaria.h"
#include "Automovel.h"
#include "Moto.h"
#include "Caminhao.h"
#include <fstream>
#include <iostream>

// Função para salvar os dados de uma concessionária em um arquivo.
void saveConcessionaria(const Concessionaria& concessionaria) {
    std::ofstream outputFile(concessionaria.getNome() + ".txt");                // Cria um arquivo com o nome da concessionária.

    if (outputFile.is_open()) {                                                 // Verifica se o arquivo foi aberto
        outputFile << concessionaria.getNome() << "\n";                         // Escreve o nome da concessionária no arquivo.
        outputFile << concessionaria.getCNPJ() << "\n";                         // Escreve o CNPJ da concessionária no arquivo.

        for (const Veiculo* veiculo : concessionaria.getEstoque()) {            // Itera sobre o estoque da concessionária.
            outputFile << veiculo->getNumChassi() << " " << veiculo->getPreco() << " " << veiculo->getAnoFabricacao() << " ";

            // Adiciona dados adicionais com base no tipo de veículo.
            if (const Automovel* automovel = dynamic_cast<const Automovel*>(veiculo)) {
                outputFile << "automovel " << automovel->getTipoMotor() << "\n";
            } else if (const Moto* moto = dynamic_cast<const Moto*>(veiculo)) {
                outputFile << "moto " << moto->getModelo() << "\n";
            } else if (const Caminhao* caminhao = dynamic_cast<const Caminhao*>(veiculo)) {
                outputFile << "caminhao " << caminhao->getTipoCarga() << "\n";
            }
        }

        outputFile.close();
        std::cout << "Arquivo " << concessionaria.getNome() << ".txt criado com sucesso.\n";
    } else {
        std::cout << "Erro ao criar o arquivo.\n";
    }
}

Concessionaria* loadConcessionaria(const std::string& filename) {              // Função para carregar uma concessionária
    std::ifstream inputFile(filename);                                         // Abre o arquivo com o nome da concessionária.    

    if (inputFile.is_open()) {                                                 // Verifica se o arquivo foi aberto
        std::string nome, CNPJ;                                                // Variáveis para armazenar os dados do arquivo.  
        std::getline(inputFile, nome);                                         // Lê o nome da concessionária do arquivo.    
        std::getline(inputFile, CNPJ);                                         // Lê o CNPJ da concessionária do arquivo.  

        Concessionaria* concessionaria = new Concessionaria(nome, CNPJ);       // Cria uma nova concessionária com os dados lidos.

        while (!inputFile.eof()) {                                             // Lê os dados do arquivo até o final.
            std::string numChassi;
            double preco;
            int anoFabricacao;
            std::string tipoVeiculo;

            inputFile >> numChassi >> preco >> anoFabricacao >> tipoVeiculo;    // Lê os dados do arquivo.

            // Com base no tipo de veículo, lê informações adicionais e cria a instância correspondente.
            if (tipoVeiculo == "automovel") {                
                std::string tipoMotor;
                inputFile >> tipoMotor;
                Automovel* automovel = new Automovel("", preco, numChassi, anoFabricacao, tipoMotor);
                concessionaria->adicionarVeiculo(automovel);
            } else if (tipoVeiculo == "moto") {
                std::string modelo;
                inputFile >> modelo;
                Moto* moto = new Moto("", preco, numChassi, anoFabricacao, modelo);
                concessionaria->adicionarVeiculo(moto);
            } else if (tipoVeiculo == "caminhao") {
                std::string tipoCarga;
                inputFile >> tipoCarga;
                Caminhao* caminhao = new Caminhao("", preco, numChassi, anoFabricacao, tipoCarga);
                concessionaria->adicionarVeiculo(caminhao);
            }
        }

        inputFile.close();                                                    // Fecha o arquivo.
        std::cout << "Concessionaria " << nome << " criada com sucesso.\n";
        return concessionaria;                                                // Retorna a concessionária criada.
    } else {
        std::cout << "Erro ao abrir o arquivo.\n";
        return nullptr;
    }
}
