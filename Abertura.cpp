#include "Abertura.h"

Abertura::Abertura(){
   this->montante = 0;
}

Abertura::Abertura(double montante) { this->montante = montante; }

double Abertura::getMontante() { return this->montante; }

void Abertura::setMontante(double montante) { this->montante = montante; }