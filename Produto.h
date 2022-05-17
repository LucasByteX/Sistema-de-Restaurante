#ifndef PRODUTO_H
#define PRODUTO_H
#include "iostream"
using namespace std;

class Produto {

private:
  int Codigo;
  string Nome;
  double Preco;
  string TipoVdd;
  bool Tipo;
  int quant;

public:
  Produto(int Codigo, string Nome, double Preco, bool Tipo);
  Produto();
  void setCodigo(int Codigo);
  int getCodigo();
  void setNome(string Nome);
  string getNome();
  void setPreco(double Preco);
  double getPreco();
  void setTipo(bool Tipo);
  string getTipo();
  void setQuant(int quant);
  int getQuant();
};

#endif