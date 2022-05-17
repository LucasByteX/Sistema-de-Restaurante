#include "Mesero.h"

Mesero::Mesero(){
  this->Nome="null";
  this->ID=0;
  this->gorjeta = 0;
}

Mesero::Mesero(string Nome, int ID) {
  this->Nome = Nome;
  this->ID = ID;
  this->gorjeta = 0;
}
void Mesero::setGorjeta(double gorjeta){
  this->gorjeta = gorjeta;
}
double Mesero::getGorjeta(){
  return this->gorjeta;
}
void Mesero::setNome(string Nome) { this->Nome = Nome; }
string Mesero::getNome() { return Nome; }
void Mesero::setId(int ID) { this->ID = ID; }
int Mesero::getId() { return this->ID; }