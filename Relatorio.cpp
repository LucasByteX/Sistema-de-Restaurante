#include "Relatorio.h"

Relatorio::Relatorio(){}

void Relatorio::balancoCaixa(vector<Caixa> &vCaixa, Abertura montante){
  cout << "------------------------" << endl;
  cout << "   Relatorio de caixa" << endl;
  cout << "------------------------" << endl;
  for(int i=0; i<vCaixa.size(); i++){
    cout << vCaixa[i].getData() << " " << vCaixa[i].getHora() << endl;
    cout << "Valor da compra: R$" << vCaixa[i].getValorCompra() << endl;
    cout << "------------------------" << endl;
  }
  cout << "Valor Acumulado: R$" << montante.getMontante() << endl;
}
void Relatorio::balancoProduto(vector<Produto> &vProd){
  int posMax;
  int posMin;
 
  int auxMax = 0;
  int auxMin = 0;
  for(int i=0; i<vProd.size(); i++){
    if(vProd[i].getQuant() > auxMax ){
      auxMax = vProd[i].getQuant();
      posMax = i;
    }
    if(vProd[i].getQuant() < auxMin ){
      auxMin = vProd[i].getQuant();
      posMin = i;
    }
  }
  cout << "Produto mais vendido: " << "Codigo: " << vProd[posMax].getCodigo() << " Nome: " << vProd[posMax].getNome() << " Quantidade: "<< vProd[posMax].getQuant() << endl;
  cout << "Produto menos vendido: " << "Codigo: " << vProd[posMin].getCodigo() << " Nome: " << vProd[posMin].getNome() << " Quantidade: "<< vProd[posMin].getQuant() << endl;
}

void Relatorio::gorjetaGarcon(int codGarcon, vector<Mesero> &vGarcon){
  for(int i=0; i<vGarcon.size(); i++){
    if(codGarcon == vGarcon[i].getId()){
      cout << "Codigo: " <<  vGarcon[i].getId() << " Nome: " <<
        vGarcon[i].getNome() << " Total de Gorjeta: R$" << vGarcon[i].getGorjeta() << endl;
    }
  }
}