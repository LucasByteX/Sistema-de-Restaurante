#ifndef CAIXA_H
#define CAIXA_H
#include "Abertura.h"
#include "Comanda.h"
#include "Mesero.h"
#include "Produto.h"
#include <vector>
using namespace std;

class Caixa{

private:
  string data;
  string hora;
  double valorCompra;
  
  
public:
  Caixa();
  Caixa(string data, string hora);

  void setData(string data);
  void setHora(string hora);
  void setValorCompra(double valorCompra);
  string getData();
  string getHora();
  double getValorCompra();

  double pagamento(int codMesa, int codGarcon, vector<Comanda> &vComanda, vector<Produto> &vProduto, vector<Mesero> &vGarcon);

  void emitirNotaFiscal(vector<int> &novoCod, vector<int> &novoQuant, vector<Produto> &prod, int tipoPagamento, int codGarcon, string nomeGarcon, vector<Mesero> &vGarcon);

  double emitirConta(vector<int> &novoCod, vector<int> &novoQuant, vector<Produto> &prod, int codGarcon, string nomeGarcon, vector<Mesero> &vGarcon);

  void descricaoProduto(int codProd, int quant, vector<Produto> &prod);
};

#endif // CAIXA_H