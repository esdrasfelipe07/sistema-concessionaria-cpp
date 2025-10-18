#ifndef SAVECONCESSIONARIA_H
#define SAVECONCESSIONARIA_H

#include "Concessionaria.h"
#include <string>

void saveConcessionaria(const Concessionaria &concessionaria);     // Função para salvar os dados de uma concessionária em um arquivo.
Concessionaria *loadConcessionaria(const std::string &filename);   // Função para carregar uma concessionária a partir de um arquivo.

#endif
