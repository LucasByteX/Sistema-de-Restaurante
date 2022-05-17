#include "Comanda.h"

Comanda::Comanda(){
  this->codMesa = 0;
  this->codGarcon = 0;
}
Comanda::Comanda(int codMesa, int codGarcon) {
  this->codMesa = codMesa;
  this->codGarcon = codGarcon;
}

int Comanda::getCodMesa() { return this->codMesa; }
int Comanda::getCodGarcon() { return this->codGarcon; }

vector<int> Comanda::getV_CodProd() { return this->vCodProd; }
vector<int> Comanda::getV_QuantProd() { return this->vQuantProd; }

bool Comanda::addProduto(int codProd, int quantProd, vector<Produto> &vProd) {
  bool t1 = 0;
  for (int i = 0; i < vProd.size(); i++) {
    if (codProd == vProd[i].getCodigo()) {
      vCodProd.push_back(codProd);
      vQuantProd.push_back(quantProd);
      vProd[i].setQuant(vProd[i].getQuant() + quantProd); // Adicionando quantidade ao produto
      cout << "Produto adiciocionado!!" << endl;
      t1 = 1;
      return 1;
    }
  }
  if (t1 == 0){
    cout << "Produto invalido!!" << endl;
    return 0;
    }
}

vector<int> Comanda::removeVector(vector<int> vet, int posicao) {
  vector<int>::iterator Iter;
  Iter = vet.begin();
  advance(Iter, posicao);
  vet.erase(Iter);
  return vet;
}

void Comanda::removeProduto(int vCodProd) {
  int aux;
  aux=0;
  for (int i = 0; i < this->vCodProd.size(); i++) {
    if(this->vCodProd[i] == vCodProd){
       this->vCodProd=removeVector(this->vCodProd,i);
       this->vQuantProd=removeVector(this->vQuantProd,i);
        cout << "Removido com Sucesso !" << endl;
        aux=1;
    }
    

    
  }
  if(aux!=1)
    cout << "Produto não encontrado" << endl;

}

void Comanda::alteraQuant(int codProd, int novaQuant) {
  bool t1 = 0;
  for (int i = 0; i < vCodProd.size(); i++) {
    if (codProd == vCodProd[i]) {
      vQuantProd[i] = novaQuant;
      t1 = 1;
      break;
    }
  }
  if (t1 == 0)
    cout << "Codigo invalido" << endl;
}

void Comanda::imprimirComanda(vector<Produto> &vProd) {
  for (int i = 0; i < vCodProd.size(); i++) {
    if (vCodProd[i] == vProd[i].getCodigo()) {
      cout << "Produto: " << vProd[i].getNome() << " ";
      cout << "Quantidade: " << vQuantProd[i] << endl;
      cout << "Preço do Produto: R$" << vProd[i].getPreco() << endl;
    }
  }
}

void Comanda::PrintaItens(vector<Produto> &P){
  for(int i=0;i<vCodProd.size();i++){
    for(int j=0;j<P.size();j++){
      if(vCodProd[i]==P[j].getCodigo()){
          cout << "Nome:" << P[j].getNome() << "  X" << vQuantProd[i] <<endl;
          break;
        }
        }
  }
}

bool Comanda::TestaProduto(int Produto){
  for (int i=0;i<vCodProd.size();i++){
    if(vCodProd[i]==Produto){
      return 1;
    }
  }
  return 0;
}