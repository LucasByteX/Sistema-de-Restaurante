#include "Caixa.h"

Caixa::Caixa(){
  this->data = "";
  this->hora = "";
  this->valorCompra = 0;
}

Caixa::Caixa(string data, string hora) {
  this->data = data;
  this->hora = hora;
  this->valorCompra = 0;
}

void Caixa::setData(string data){
  this->data = data;
}
void Caixa::setHora(string hora){
  this->hora = hora;
}
void Caixa::setValorCompra(double valorCompra){
  this->valorCompra = valorCompra;
}

string Caixa::getData(){
  return this->data;
}
string Caixa::getHora(){
  return this->hora;
}

double Caixa::getValorCompra(){
  return this->valorCompra;
}

double Caixa::pagamento(int codMesa, int codGarcon,  vector<Comanda> &vComanda, vector<Produto> &vProduto, vector<Mesero> &vGarcon) {

  
  double valorTotal;
  int cod_garcon;
  string nome_Garcon;
  vector<int> novoCod;
  vector<int> novoQuant;

  //Resgatar o vetor com produtos
  for (int i = 0; i < vComanda.size(); i++) {
    if (codMesa == vComanda[i].getCodMesa()) {
      novoCod = vComanda[i].getV_CodProd();
      novoQuant = vComanda[i].getV_QuantProd();
    }
  }

  //verificar Garçon
  for (int i = 0; i < vGarcon.size(); i++) {
    if (codGarcon == vGarcon[i].getId()) {
      cod_garcon = codGarcon;
      nome_Garcon = vGarcon[i].getNome();
    }
  }
  
  cout << "---------------------" << endl;
  cout << "        CONTA" << endl;
  cout << "---------------------" << endl;

  //emitir a conta e receber o valor total da conta
  valorTotal = emitirConta(novoCod, novoQuant, vProduto, cod_garcon, nome_Garcon, vGarcon);

  
  cout << "---------------------" << endl;
  int tipoPagamento;
  cout << "Qual o tipo de Pagamento?" << endl;
  cout << "1.Dinheiro" << endl;
  cout << "2.Cheque" << endl;
  cout << "3.Cartão de credito" << endl;
  cin >> tipoPagamento;
  system("clear");
  
  emitirNotaFiscal(novoCod, novoQuant, vProduto, tipoPagamento, codGarcon, nome_Garcon, vGarcon);
  this->setValorCompra(valorTotal);
  return valorTotal;
}

void Caixa::emitirNotaFiscal(vector<int> &novoCod, vector<int> &novoQuant,
                             vector<Produto> &prod, int tipoPagamento,
                              int codGarcon,
                             string nomeGarcon, vector<Mesero> &vGarcon) {
  
  cout << "--------------------" << endl;
  cout << "    NOTA FISCAL" << endl;
  cout << "--------------------" << endl;
  cout << getData() << "  " << getHora() << endl;

  //Para descrição dos produtos e receber o valor total
  double total = emitirConta(novoCod, novoQuant, prod, codGarcon, nomeGarcon, vGarcon);

   //Adicionando gorjeta ao garcon
  double porcentagemGarcon;
  porcentagemGarcon = total/10;
  for(int i=0; i< vGarcon.size(); i++){
    if(codGarcon == vGarcon[i].getId()){
      vGarcon[i].setGorjeta(vGarcon[i].getGorjeta() + porcentagemGarcon);
    }
  }

  //Para pagar pelo tipo
  if (tipoPagamento == 1) {
    cout << "1.Dinheiro" << endl;
    double dinheiro;
    cout << "Dinheiro Cliente: R$";
    cin >> dinheiro;
    cout << "Total da Compra: " << total << endl;
    cout << "Dinheiro recebido: " << dinheiro << endl;
    if (total > dinheiro) {
      int valor = total - dinheiro;
      cout << "Troco: R$" << total << endl;
    } else {
      cout << "Troco: R$" << dinheiro - total << endl;
    } 
  } else if (tipoPagamento == 2) {
    cout << "2.Cheque" << endl;
    cout << "Total da Compra: " << total << endl;
    cout << "Dinheiro recebido: " << total << endl;
    cout << "Troco: R$0.00" << endl;
  } else if (tipoPagamento == 3) {
    int vezes;
    cout << "3.Cartão de Credito" << endl;
    cout << "Quantas vezes quer dividir: ";
    cin >> vezes;
    double div = total / vezes;
    cout << "Seu pagamento sera: "<<  vezes << " vezes de R$" << div << endl;
    cout << "Total da Compra: " << total << endl;
    cout << "Dinheiro recebido: " << total << endl;
    cout << "Troco: R$0.00" << endl;
  }
}

double Caixa::emitirConta(vector<int> &novoCod, vector<int> &novoQuant,vector<Produto> &prod, int codGarcon, string nomeGarcon, vector<Mesero> &vGarcon) {

  for (int i = 0; i < novoCod.size(); i++) {
    descricaoProduto(novoCod[i], novoQuant[i], prod);
  }
  
  //Calculando o valor total
  double valorTotal = 0;
  for (int i = 0; i < prod.size(); i++) {
    if (novoCod[i] == prod[i].getCodigo()) {
      valorTotal += (prod[i].getPreco() * novoQuant[i]);
    }
  }

  //Calculando a porcentagem do garçon
  double porcentagemGarcon = valorTotal / 10;
  cout << "Codigo: " << codGarcon << " Garcon: " << nomeGarcon << " Gorjeta: R$"  << porcentagemGarcon
       << endl;

 
  valorTotal += porcentagemGarcon;
  cout << "Valor total: R$" << valorTotal << endl;
  return valorTotal;
}

void Caixa::descricaoProduto(int codProd, int quant, vector<Produto> &prod) {
  for (int i = 0; i < prod.size(); i++) {
    if (codProd == prod[i].getCodigo()) {
      cout << "Codigo: " << codProd << " Nome: " << prod[i].getNome() << " Quantidade: " << quant << " Valor: R$" << prod[i].getPreco() << endl;
    }
  }
}