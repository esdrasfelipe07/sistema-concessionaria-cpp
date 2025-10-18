#ifndef SISTEMA_H
#define SISTEMA_H

#include "Veiculo.h"
#include "Automovel.h"
#include "Moto.h"
#include "Caminhao.h"
#include "Concessionaria.h"
#include "listarFrotaConcessionaria.h"
#include "saveConcessionaria.h"
#include <vector>
#include <iostream>

// Declaração da classe Sistema.
class Sistema {
private:
    std::vector<Concessionaria*> concessionarias;      // Vetor de ponteiros para objetos da classe Concessionaria.
public:
    Sistema();                                         // Construtor da classe Sistema.
    ~Sistema();                                        // Destrutor da classe Sistema.    
    void run();                                        // Método run() que inicia o programa.
};

#endif 
