#ifndef Mesero_H
#define Mesero_H
#pragma once

#include <iostream>
using namespace std;

class Mesero { // Homenagem a chaves ")

private:
  string Nome;
  int ID;
  double gorjeta;

public:
  Mesero();
  Mesero(string Nome, int ID);
  void setGorjeta(double gorjeta);
  double getGorjeta();
  void setNome(string Nome);
  string getNome();
  void setId(int ID);
  int getId();
};

#endif