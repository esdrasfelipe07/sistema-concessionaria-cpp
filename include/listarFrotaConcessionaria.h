#ifndef LISTARFROTACONCESSIONARIA_H
#define LISTARFROTACONCESSIONARIA_H

#include "Concessionaria.h"
#include <vector>
#include <string>

// Declaração da função listarFrotaConcessionaria.
// Recebe um vetor de ponteiros para Concessionaria e o nome de uma concessionária como parâmetros.
void listarFrotaConcessionaria(const std::vector<Concessionaria*>& concessionarias, const std::string& nomeConcessionaria);

#endif
