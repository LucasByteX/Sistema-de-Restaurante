#ifndef RELATORIO_H
#define RELATORIO_H
#include "Caixa.h"

class Relatorio{

  public:
    Relatorio();
    void balancoCaixa(vector<Caixa> &vCaixa, Abertura montante);
    void balancoProduto(vector<Produto> &vProd);
    void gorjetaGarcon(int codGarcon, vector<Mesero> &vGarcon);

};

#endif //RELATORIO_H