#include "Sistema.h"

Sistema::Sistema() {}                    // Construtor padrão do sistema

Sistema::~Sistema() {                    // Destrutor do Sistema, libera a memória alocada para as concessionárias.
    for (auto concessionaria : concessionarias) {                    // Itera para cada concessionária na lista de concessionárias
        delete concessionaria;                                       // Libera a memória alocada para a concessionária
    }
}

void Sistema::run() {                                           // Função que chama o método run()

  while (true) {                                                // Loop principal do sistema.
    std::cout << "\nPor favor, escolha um comando:\n"
              << "\ncreate-concessionaria\n"
              << "add-car\n" 
              << "add-truck\n" 
              << "add-bike\n"
              << "remove-vehicle\n"
              << "search-vehicle\n"
              << "list-concessionaria\n"
              << "save-concessionaria\n"
              << "load-concessionaria\n"
              << "raise-price\n"
              << "quit\n"
              << "\nComando: ";

    std::string comando;                                      // Variável que armazena o comando escolhido pelo usuário
    std::cin >> comando;                                      // Lê o comando escolhido pelo usuário

    if (comando == "create-concessionaria") {                 // Comando para criar nova concessionaria
        std::string nome, CNPJ;                               // Variáveis para armazenar o nome e CNPJ da concessionaria
        std::cout << "\nDigite o nome da concessionária: ";
        std::cin >> nome;                                     // Lê o nome da concessionaria

        bool cnpjExistente = false;                           // Flag para verificar se o CNPJ já existe
        std::cout << "Digite o CNPJ da concessionária: ";
        std::cin >> CNPJ;

        for (auto concessionaria : concessionarias) {         // Itera para cada concessionária na lista de concessionárias
            if (concessionaria->getCNPJ() == CNPJ) {          // Verifica se o CNPJ já existe
                cnpjExistente = true;                         // Atualiza a flag para indicar que o CNPJ já existe e imprime um erro
                std::cout << "\nERRO - Já existe uma concessionária com o CNPJ " << CNPJ << ".\n";
                break;
            }
        }

        if (!cnpjExistente) {                                // Se o CNPJ não existir, cria uma nova concessionaria 
            Concessionaria* concessionaria = new Concessionaria(nome, CNPJ); // Cria uma nova concessionaria com o nome e CNPJ
            concessionarias.push_back(concessionaria);                       // Adiciona a concessionaria à lista de concessionárias
            std::cout << "\nConcessionária " << nome << " criada com sucesso.\n";
        }

    } else if (comando == "add-car") {                        // Comando para adicionar um carro à concessionária
        std::string nomeConcessionaria, marca, numChassi, tipoMotor;         // Variaveis para armazenar os dados
        double preco;                                         // Variável para armazenar o preço do carro
        int anoFabricacao;                                    // Variável para armazenar o ano de fabricação do carro  
        std::cout << "\nDigite o nome da concessionária: ";                                      
        std::cin >> nomeConcessionaria;                       // Lê o nome da concessionaria

        Concessionaria* concessionariaExistente = nullptr;    // Função que Verifica se a concessionária existe
        for (auto concessionaria : concessionarias) {         // Itera para cada concessionária na lista de concessionárias
            if (concessionaria->getNome() == nomeConcessionaria) {              // Verifica se a concessionária existe
                concessionariaExistente = concessionaria;                // Atualiza a variável para a concessionária existente
                break;
            }
        }

        if (concessionariaExistente == nullptr) {                   // Se a concessionária não existir, imprime um erro
            std::cout << "\nERRO - Concessionária " << nomeConcessionaria << " não encontrada.\n";
            continue;                                               // Volta para o início do loop
        }

        std::cout << "Digite a marca do automóvel: ";
        std::cin >> marca;
        std::cout << "Digite o preço do automóvel: ";
        std::cin >> preco;
        std::cout << "Digite o número do chassi do automóvel: ";
        std::cin >> numChassi;
        std::cout << "Digite o ano de fabricação do automóvel: ";
        std::cin >> anoFabricacao;
        std::cout << "Digite o tipo de motor do automóvel (gasolina ou elétrico): ";
        std::cin >> tipoMotor;

        if (concessionariaExistente->veiculoExiste(numChassi)) {        // Verifica se o carro já existe na concessionária
            std::cout << "\nERRO - Veículo " << numChassi << " já adicionado à concessionária " << nomeConcessionaria << ".\n";
        } else {                                                        // Se o carro não existir, adiciona o carro à concessionária
            Automovel* automovel = new Automovel(marca, preco, numChassi, anoFabricacao, tipoMotor);
            concessionariaExistente->adicionarVeiculo(automovel);
            std::cout << "\nAutomóvel adicionado com sucesso à concessionária " << nomeConcessionaria << ".\n";
        }

    } else if (comando == "add-truck") {                                // Comando para adicionar um caminhão à concessionária
        std::string nomeConcessionaria, marca, numChassi, tipoCarga;    // Variaveis para armazenar os dados
        double preco;                                                   // Variável para armazenar o preço do caminhão          
        int anoFabricacao;                                              // Variável para armazenar o ano de fabricação do camin
        std::cout << "\nDigite o nome da concessionária: ";             
        std::cin >> nomeConcessionaria;                                 // Lê o nome da concessionária

        Concessionaria* concessionariaExistente = nullptr;              // Função que Verifica se a concessionária existe
        for (auto concessionaria : concessionarias) {                   // Itera para cada concessionária na lista de concessionárias
            if (concessionaria->getNome() == nomeConcessionaria) {      // Verifica se a concessionária existe
                concessionariaExistente = concessionaria;               // Atualiza a variável para a concessionária existente
                break;
            }
        }

        if (concessionariaExistente == nullptr) {                       // Se a concessionária não existir, imprime um erro
            std::cout << "\nERRO - Concessionária " << nomeConcessionaria << " não encontrada.\n";
            continue;                                                   // Volta para o início do loop
        }

        std::cout << "Digite a marca do caminhão: ";
        std::cin >> marca;
        std::cout << "Digite o preço do caminhão: ";
        std::cin >> preco;
        std::cout << "Digite o número do chassi do caminhão: ";
        std::cin >> numChassi;
        std::cout << "Digite o ano de fabricação do caminhão: ";
        std::cin >> anoFabricacao;
        std::cout << "Digite o tipo de carga do caminhão (comum ou perigosa): ";
        std::cin >> tipoCarga;

        if (concessionariaExistente->veiculoExiste(numChassi)) {        // Verifica se o caminhão já existe na concessionária
            std::cout << "\nERRO - Veículo " << numChassi << " já adicionado à concessionária " << nomeConcessionaria << ".\n";
        } else {                                            // Se o caminhão não existir, adiciona o caminhão à  concessionaria
            Caminhao* caminhao = new Caminhao(marca, preco, numChassi, anoFabricacao, tipoCarga);
            concessionariaExistente->adicionarVeiculo(caminhao);
            std::cout << "\nCaminhão adicionado com sucesso à concessionária " << nomeConcessionaria << ".\n";
        }

    } else if (comando == "add-bike") {                                // Comando para adicionar uma moto à concessionária
        std::string nomeConcessionaria, marca, numChassi, modelo;      // Variaveis para armazenar os dados
        double preco;                                                  // Variável para armazenar o preço da moto
        int anoFabricacao;                                             // Variável para armazenar o ano de fabricação da moto
        std::cout << "\nDigite o nome da concessionária: ";                    
        std::cin >> nomeConcessionaria;                                // Lê o nome da concessionária

        Concessionaria* concessionariaExistente = nullptr;             // Função que Verifica se a concessionária existe
        for (auto concessionaria : concessionarias) {                  // Itera para cada concessionária na lista de concessionárias
            if (concessionaria->getNome() == nomeConcessionaria) {     // Verifica se a concessionária existe
                concessionariaExistente = concessionaria;              // Atualiza a variável para a concessionária existente
                break;
            }
        }

        if (concessionariaExistente == nullptr) {                      // Se a concessionária não existir, imprime um erro
            std::cout << "\nERRO - Concessionária " << nomeConcessionaria << " não encontrada.\n";
            continue;                                                  // Volta para o início do loop  
        }

        std::cout << "Digite a marca da moto: ";
        std::cin >> marca;
        std::cout << "Digite o preço da moto: ";
        std::cin >> preco;
        std::cout << "Digite o número do chassi da moto: ";
        std::cin >> numChassi;
        std::cout << "Digite o ano de fabricação da moto: ";
        std::cin >> anoFabricacao;
        std::cout << "Digite o modelo da moto (clássico ou esportivo): ";
        std::cin >> modelo;

        if (concessionariaExistente->veiculoExiste(numChassi)) {          // Verifica se a moto já existe na concessionária          
            std::cout << "\nERRO - Veículo " << numChassi << " já adicionado à concessionária " << nomeConcessionaria << ".\n";
        } else {                                                          // Se a moto não existir, adiciona a moto à concessionária
            Moto* moto = new Moto(marca, preco, numChassi, anoFabricacao, modelo);
            concessionariaExistente->adicionarVeiculo(moto);
            std::cout << "\nMoto adicionada com sucesso à concessionária " << nomeConcessionaria << ".\n";
        }

    } else if (comando == "remove-vehicle") {                          // Comando para remover um veículo da concessionária
        std::string numChassi;                                         // Variável para armazenar o número do chassi do veí
        std::cout << "\nDigite o número do chassi do veículo a ser removido: ";
        std::cin >> numChassi;                                         // Lê o número do chassi do veículo a ser removido  

        for (auto concessionaria : concessionarias) {                  // Itera para cada concessionária na lista de concessionárias
            if (concessionaria->removerVeiculo(numChassi)) {           // Verifica se o veículo foi removido com sucesso
                std::cout << "Veículo " << numChassi << " removido da concessionária " << concessionaria->getNome() << ".\n";
                break;
            }
        }

    } else if (comando == "search-vehicle") {                          // Comando para buscar um veículo na concessionária
        std::string numChassi;                                         // Variável para armazenar o número do chassi do veículo
        bool veiculoEncontrado = false;                                // Variável para armazenar se o veículo foi encontrado
        std::cout << "\nDigite o número do chassi do veículo a ser buscado: ";
        std::cin >> numChassi;                                         // Lê o número do chassi do veículo a ser buscado    

        for (auto concessionaria : concessionarias) {                  // Itera para cada concessionária na lista de concessionárias
            Veiculo* veiculo = concessionaria->buscarVeiculo(numChassi);      // Busca o veículo na concessionária
            if (veiculo != nullptr) {                                  // Se o veículo foi encontrado
                std::cout << "\nVeículo encontrado na concessionária " << concessionaria->getNome() << ":\n";
                veiculo->exibirDados();                                // Exibe os dados do veículo
                veiculoEncontrado = true;                              // Define que o veículo foi encontrado
                break;
            }
        }

        if (!veiculoEncontrado) {                                      // Se o veículo não foi encontrado
            std::cout << "\nVeículo não encontrado.\n";
        }

    } else if (comando == "list-concessionaria") {                     // Comando para listar as concessionárias cadastradas
        std::string nomeConcessionaria;                                // Variável para armazenar o nome da concessionária
        std::cout << "\nDigite o nome da concessionária: ";
        std::cin >> nomeConcessionaria;                                // Lê o nome da concessionária

        bool concessionariaEncontrada = false;                        // Variável para armazenar se a concessionária foi encontrada
        for (auto concessionaria : concessionarias) {                 // Itera para cada concessionária na lista de concessionárias
            if (concessionaria->getNome() == nomeConcessionaria) {    // Verifica se a concessionária atual é a concessionária                                                                                buscada
                concessionariaEncontrada = true;                      // Define que a concessionária foi encontrada            
                break;
            }
        }

        if (!concessionariaEncontrada) {                          // Se a concessionária não foi encontrada imprime mensagem de erro
            std::cout << "\nERRO - Concessionária " << nomeConcessionaria << " não encontrada.\n";
        } else {                      // Se a concessionária foi encontrada Chama a função para listar os veículos da concessionária
            listarFrotaConcessionaria(concessionarias, nomeConcessionaria);             
        }
    } else if (comando == "save-concessionaria") {                     // Comando para salvar as concessionárias cadastradas
        std::string nomeConcessionaria;                                // Variável para armazenar o nome da concessionária
        std::cout << "\nDigite o nome da concessionária: ";
        std::cin >> nomeConcessionaria;                                // Lê o nome da concessionária

        for (auto concessionaria : concessionarias) {                  // Itera para cada concessionária na lista de concessionárias
            if (concessionaria->getNome() == nomeConcessionaria) {     // Verifica se a concessionária atual é a concessionária                                                                                buscada
                saveConcessionaria(*concessionaria);                   // Chama a função para salvar a concessionária
                break;
            }
        }

    } else if (comando == "load-concessionaria") {                     // Comando para carregar as concessionárias cadastradas       
        std::string filename;                                          // Variável para armazenar o nome do arquivo  
        std::cout << "\nDigite o nome do arquivo da concessionária: "; 
        std::cin >> filename;                                          // Lê o nome do arquivo

        Concessionaria* loadedConcessionaria = loadConcessionaria(filename);      // Chama a função para carregar a concessionária

        if (loadedConcessionaria != nullptr) {                           // Se a concessionária foi carregada com sucesso
            concessionarias.push_back(loadedConcessionaria);             // Adiciona a concessionária carregada à lista de                                                                                       concessionárias
        }
    } else if (comando == "raise-price") {                              // Comando para aumentar o preço de um veículo
            std::string nomeConcessionaria;
            double x;
            std::cout << "\nDigite o nome da concessionária: ";
            std::cin >> nomeConcessionaria;
            std::cout << "Digite o valor de X (percentual de aumento): ";
            std::cin >> x;

            Concessionaria* concessionariaExistente = nullptr;
            for (auto concessionaria : concessionarias) {
                if (concessionaria->getNome() == nomeConcessionaria) {
                    concessionariaExistente = concessionaria;
                    break;
                }
            }

            if (concessionariaExistente == nullptr) {
                std::cout << "\nERRO - Concessionária " << nomeConcessionaria << " não encontrada.\n";
            } else {
                concessionariaExistente->aumentarPrecos(x);
                std::cout << "\nAumento de preços realizado com sucesso na concessionária " << nomeConcessionaria << ".\n";
            }
        } else if (comando == "quit") {                                  // Comando para sair do programa
            std::cout << "Saindo...\n";
            break;
        }
    }
}
