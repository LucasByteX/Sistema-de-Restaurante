#ifndef COMANDA_H
#define COMANDA_H
#include "Mesero.h"
#include "Produto.h"
#include <vector>

class Comanda {

private:
  vector<int> vCodProd;
  vector<int> vQuantProd;
  int codMesa;
  int codGarcon;

public:
  Comanda();
  Comanda(int codMesa, int codGarson);
  int getCodMesa();
  int getCodGarcon();
  vector<int> getV_CodProd();
  vector<int> getV_QuantProd();
  bool addProduto(int codProd, int quantProd, vector<Produto> &vProd);
  void removeProduto(int vCodProd);
  void alteraQuant(int codProd, int novaQuant);
  void imprimirComanda(vector<Produto> &vProd);
  vector<int> removeVector(vector<int> vet, int posicao);
  void PrintaItens(vector<Produto> &P);
  bool TestaProduto(int Produto);
};

#endif // COMANDA_H