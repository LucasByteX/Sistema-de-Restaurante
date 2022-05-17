#ifndef ABERTURA_H
#define ABERTURA_H
#include <iostream>

class Abertura {

private:
  double montante;

public:
  Abertura();
  Abertura(double montante);
  double getMontante();
  void setMontante(double montante);
};

#endif // ABERTURA_H