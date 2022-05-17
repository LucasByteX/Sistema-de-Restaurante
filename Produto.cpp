#include "Produto.h"

Produto::Produto(int Codigo, string Nome, double Preco, bool Tipo) {
  this->Codigo = Codigo;
  this->Nome = Nome;
  this->Preco = Preco;
  this->Tipo = Tipo;
  this->TipoVdd = (Tipo == 0) ? "Bebida" : "Prato";
}
Produto::Produto() {
  this->Codigo = 0;
  this->Nome = "null";
  this->Preco = 0;
  this->Tipo = "0";
  this->TipoVdd = "não informado";
  this->quant = 0;
}

void Produto::setCodigo(int Codigo) { this->Codigo = Codigo; }
int Produto::getCodigo() { return this->Codigo; }
void Produto::setNome(string Nome) { this->Nome = Nome; }
string Produto::getNome() { return this->Nome; }
void Produto::setPreco(double Preco) { this->Preco = Preco; }
double Produto::getPreco() { return this->Preco; }
void Produto::setTipo(bool Tipo) { this->Tipo = Tipo; }
string Produto::getTipo() {
  this->TipoVdd = (Tipo == 0) ? "Bebida" : "Prato";
  return this->TipoVdd;
}
void Produto::setQuant(int quant){
  this->quant = quant;
}
int Produto::getQuant(){
  return quant;
}
