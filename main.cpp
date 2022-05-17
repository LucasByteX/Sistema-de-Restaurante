#include "Abertura.h"
#include "Caixa.h"
#include "Comanda.h"
#include "Mesero.h"
#include "Produto.h"
#include "Relatorio.h"
#include <vector>
using namespace std;

void PrintLinha() {
  cout << "-------------------------" << endl;
  cout << "-------------------------" << endl;
}
void PrintEmblema() {
  PrintLinha();
  cout << "     RESTAURANTE IFPB" << endl;
  PrintLinha();
  cout << "\n\n";
}

void pause() {
  string *pause3 = new string();
  cout << "\n\n\n\n\nDigite e envie qualquer coisa para continuar...";
  cin >> *pause3;
  delete pause3;
}
void aviso() {
  PrintLinha();
  cout << "          AVISO" << endl;
  PrintLinha();
  cout << "\n\n";
}
vector<Produto> removeVector(vector<Produto> vet, int posicao) {
  vector<Produto>::iterator Iter;
  Iter = vet.begin();
  advance(Iter, posicao);
  vet.erase(Iter);
  return vet;
}
vector<Mesero> removeVector(vector<Mesero> vet, int posicao) {
  vector<Mesero>::iterator Iter;
  Iter = vet.begin();
  advance(Iter, posicao);
  vet.erase(Iter);
  return vet;
}
vector<Comanda> removeVector(vector<Comanda> vet, int posicao) {
  vector<Comanda>::iterator Iter;
  Iter = vet.begin();
  advance(Iter, posicao);
  vet.erase(Iter);
  return vet;
}

int main() {
  int opcao;
  vector<Produto> Cardapio;
  vector<Mesero> Garçons;
  vector<Comanda> vComanda;
  vector<Caixa> vCaixa;
  Mesero *g1 = new Mesero("Chaves do Oito", 8);
  Produto *p1 = new Produto(100, "Agua", 2.75, 0);
  Comanda *M1 = new Comanda(100, 8);
  Abertura montante;
  Relatorio relatorio;
  Garçons.push_back(*g1);
  Cardapio.push_back(*p1);
  p1 = new Produto(20, "Pizza", 5.70, 1);
  Cardapio.push_back(*p1);
  M1->addProduto(100, 5, Cardapio);
  M1->addProduto(20, 7, Cardapio);
  vComanda.push_back(*M1);
  delete g1;
  delete p1;
  delete M1;
  system("clear");

  do {

    PrintEmblema();
    cout << "1.Abertura do caixa" << endl;
    cout << "2.Movimentação do caixa" << endl;
    cout << "3.Cadastro de produtos" << endl;
    cout << "4.Fornecimento de balanço" << endl;
    cout << "5.Cadastro de garçons" << endl;
    cout << "6.Encerrar" << endl;
    cin >> opcao;
    system("clear");

    switch (opcao) {
    case 1:
      int op;
      do {
        PrintEmblema();
        cout << "1.Inserir valor montante" << endl;
        cout << "2.Ver valor do montante" << endl;
        cout << "0.Voltar ao menu anterior" << endl;
        cin >> op;
        system("clear");
        switch (op)
        case 1: {
          double valor;
          cout << "Digite o valor: R$";
          cin >> valor;
          montante.setMontante(valor);
          system("clear");
          aviso();
          cout << "Valor adicionado com sucesso!" << endl;
          pause();
          system("clear");
          break;

        case 2:
          PrintEmblema();
          cout << "Valor Montante: R$" << montante.getMontante() << endl;
          pause();
          system("clear");
          break;
        case 0:
          system("clear");
          break;
        default:
          aviso();
          cout << "Opção incorreta!" << endl;
          break;
        }

      } while (op != 0);
      system("clear");
      break;

    case 2:
      int op2;
      do {
        PrintEmblema();
        cout << "1.Inserir comanda" << endl;
        cout << "2.Pagar comanda" << endl;
        cout << "3.Ver comandas" << endl;
        cout << "4.Alterar quantidade da comanda" << endl;
        cout << "5.Adicionar produto na comanda" << endl;
        cout << "6.Remover produto da comanda" << endl;
        cout << "7.Remover comanda" << endl;
        cout << "0.Voltar ao menu anterior" << endl;
        cin >> op2;
        system("clear");
        switch (op2) {
        case 1: {
          int codProd;
          int quant;
          int codComanda;
          int codGarcon;
          bool aux = true;
          string continuar;
          PrintEmblema();
          cout << "Digite o codigo da comanda: ";
          cin >> codComanda;
          cout << "Digite o codigo do Garçon: ";
          cin >> codGarcon;
          Comanda *comanda = new Comanda(codComanda, codGarcon);
          system("clear");
          PrintEmblema();
          cout << "Adicione o produto consumido" << endl;
          cout << "-----------------------------" << endl;
          while (aux) {
            
            cout << "Digite o codigo do produto: ";
            cin >> codProd;
            cout << "Digite a Quantidade: ";
            cin >> quant;
            bool aux2 = comanda->addProduto(codProd, quant, Cardapio);
            cout << "Deseja adicionar mais produtos[S/N]: ";
            do {

              cin >> continuar;

              system("clear");
              if (continuar == "n" || continuar == "N") {
                aux = false;
                if (aux2 != false)
                  vComanda.push_back(*comanda);

                break;
              } else if (continuar == "s" || continuar == "S") {
                PrintEmblema();
                break;

              }

              else
                aviso();
              cout << "Informação errada tente novamente" << endl;
              cout << "Deseja adicionar mais produtos[S/N]:";

            } while (continuar != "n" || continuar != "N" || continuar != "s" ||
                     continuar != "S");
          }
          break;
        }
        case 2: {
          string data;
          string hora;
          int codMesa;
          int codGarcon2;
          PrintEmblema();
          cout << "Digite a data do pagamento: ";
          cin >> data;
          cout << "Digite a hora do pagamento: ";
          cin >> hora;
          Caixa *caixa = new Caixa(data, hora);
          system("clear");
          PrintEmblema();
          cout << "Digite o codigo da comanda: ";
          cin >> codMesa;
          cout << "Digite o codigo do garçon: ";
          cin >> codGarcon2;
          system("clear");
          //vCaixa.push_back(*caixa);
          double montant;
          montant = caixa->pagamento(codMesa, codGarcon2, vComanda, Cardapio,Garçons);
          caixa->setValorCompra(montant);
          vCaixa.push_back(*caixa);
          montante.setMontante(montante.getMontante() + montant);
          
          pause();
          system("clear");
          for (int i = 0; i < vComanda.size(); i++) {
            if (codMesa == vComanda[i].getCodMesa()) {
              vComanda = removeVector(vComanda, i);
              break;
            }
          }
          break;
        }
        case 3: {
          PrintLinha();
          cout << "        Comandas:" << endl;
          PrintLinha();
          cout << "\n\n\n";
          PrintLinha();

          for (int i = 0; i < vComanda.size(); i++) {
            cout << "Codigo da Comanda /Mesa: " << vComanda[i].getCodMesa()
                 << endl;
            cout << "Codigo do Garçom: " << vComanda[i].getCodGarcon() << endl;
            cout << "Itens:" << endl;
            vComanda[i].PrintaItens(Cardapio);
            PrintLinha();
          }
          pause();
          system("clear");
          break;
        }
        case 4: {
          PrintEmblema();
          cout << "Digite o codigo da comanda que deseja alterar:" << endl;
          int CMesa;
          cin >> CMesa;
          bool n1;
          bool aux2 = 0;
          for (int i = 0; i < vComanda.size(); i++) {
            n1 = 0;
            if (vComanda[i].getCodMesa() == CMesa) {
              int CProduto;
              cout << "Digite o codigo do Produto que deseja alterar:" << endl;
              cin >> CProduto;
              n1 = vComanda[i].TestaProduto(CProduto);
              if (n1 == 1) {
                int NVQ;
                cout << "Digite a nova quantidade do produto:" << endl;
                cin >> NVQ;
                vComanda[i].alteraQuant(CProduto, NVQ);
                system("clear");
                aviso();
                cout << "Alterado com sucesso!" << endl;
                pause();
                system("clear");

              } else {
                aux2 = 1;
                system("clear");
                aviso();
                cout << "Não encontrado!" << endl;
                pause();
                system("clear");
              }
            }
          }
          if (n1 != 1 && aux2 == 0){
            system("clear");
            aviso();
            cout << "Não encontrado!" << endl;
            pause();
            system("clear");
          }

          break;
        }
        case 7: {
          PrintEmblema();
          cout << "Digite o codigo da comanda que deseja remover:" << endl;
          int COD;
          cin >> COD;
          system("clear");
          bool n1 = 0;
          for (int i = 0; i < vComanda.size(); i++) {
            if (vComanda[i].getCodMesa() == COD) {
              vComanda = removeVector(vComanda, i);
              n1 = 1;
              aviso();
              cout << "Removido com sucesso!" << endl;
              pause();
              system("clear");
            }
          }
          if (n1 == 0) {
            aviso();
            cout << "Não encontrado!" << endl;
            pause();
            system("clear");
          }
          break;
        }
        case 5: {
          PrintEmblema();
          cout << "Digite o codigo da comanda que deseja alterar:" << endl;
          int CMesa;
          cin >> CMesa;
          system("clear");
          bool n1;
          bool aux2 = 0;
          for (int i = 0; i < vComanda.size(); i++) {
            if (vComanda[i].getCodMesa() == CMesa) {
              aux2=1;
              bool aux;
              int codProd, quantProd;
              PrintEmblema();
              cout << "Digite o codigo do produto:" << endl;
              cin >> codProd;
              cout << "Digite a quantidade" << endl;
              cin >> quantProd;
              system("clear");
                aviso();
                vComanda[i].addProduto(codProd, quantProd, Cardapio);
                pause();
                system("clear");

               
            }
          }
          if(aux2==0){
            aviso();
            cout << "Não encontrado!" << endl;
            pause();
            system("clear");
          }
          break;
        }
        case 6: {
          PrintEmblema();
          cout << "Digite o codigo da comanda que deseja alterar:" << endl;
          int CMesa;
          cin >> CMesa;
          bool n1;
          bool aux2 = 0;
          for (int i = 0; i < vComanda.size(); i++) {
            n1 = 0;
            if (vComanda[i].getCodMesa() == CMesa) {
              int CProduto;
              cout << "Digite o codigo do Produto que deseja remover:" << endl;
              cin >> CProduto;
              n1 = vComanda[i].TestaProduto(CProduto);
              if (n1 == 1) {
                vComanda[i].removeProduto(CProduto);
                system("clear");
                aviso();
                cout << "Removido com sucesso!" << endl;
                pause();
                system("clear");

              } else {
                aux2 = 1;
                system("clear");
                aviso();
                cout << "Não encontrado!" << endl;
                pause();
                system("clear");
              }
            }
          }
          if (n1 != 1 && aux2 == 0) {
            system("clear");
            aviso();
            cout << "Não encontrado!" << endl;
            pause();
            system("clear");
          }
          break;
        }
        

        case 0:
          system("clear");
          break;
        default: {
          aviso();
          cout << "Opção incorreta !" << endl;
          pause();
          system("clear");
          break;
        }
        }

      } while (op2 != 0);
      system("clear");
      break;

    case 3:
      int t;
      do {

        PrintEmblema();
        cout << "1.Inserir Produto" << endl;
        cout << "2.Remover Ultimo Produto" << endl;
        cout << "3.Ver Produtos" << endl;
        cout << "4.Remover Produto Especifico" << endl;
        cout << "0.Voltar ao Menu Anterior" << endl;
        cin >> t;
        system("clear");
        switch (t) {

        case 1: {
          Produto *novo = new Produto();
          int *p2 = new int();
          PrintEmblema();
          cout << "Por Favor informe o Codigo do produto:" << endl;

          bool *m = new bool();
          while (1) {

            if (*m == 1) {
              novo->setCodigo(*p2);
              delete p2;
              delete m;
              break;
            }
            *m = 1;
            cin >> *p2;
            system("clear");

            for (int i = 0; i < Cardapio.size(); i++) {

              if (Cardapio[i].getCodigo() == *p2) {
                aviso();
                cout << "Erro : Codigo ja pertence a outro produto" << endl;
                cout << "Informe Outro Codigo:";
                *m = 0;
                break;
              }
            }
          }
          system("clear");

          PrintEmblema();
          cout << "Informe o Nome do produto:";
          string *p3 = new string();
          cin >> *p3;
          novo->setNome(*p3);
          delete p3;
          system("clear");

          PrintEmblema();
          cout << "Informe o preco do produto: R$";
          double *p4 = new double();
          cin >> *p4;
          novo->setPreco(*p4);
          delete p4;
          system("clear");

          int t3;
          do {
            PrintEmblema();
            cout << "Informe o tipo do produto: " << endl;
            cout << "0.Bebida" << endl;
            cout << "1.Prato" << endl;
            cin >> t3;

            system("clear");
            if (t3 != 0 && t3 != 1) {
              aviso();
              cout << "ERRO: Valor invalido tente novamente..." << endl;
              pause();
              system("clear");
            } else {
              aviso();
              cout << "Adicionado com Sucesso!" << endl;
              pause();
              system("clear");
            }

          } while (t3 != 0 && t3 != 1);

          novo->setTipo(t3);
          Cardapio.push_back(*novo);
          delete novo;
          break;
        }
        case 2: {
          if (Cardapio.size() == 0) {
            aviso();
            cout << "Erro: Cardapio vazio" << endl;
            pause();
            system("clear");
            break;
          } else {
            Cardapio.pop_back();
            aviso();
            cout << "Ultimo Produto Removido com Sucesso!" << endl;
            pause();
            system("clear");

            break;
          }
        }
        case 3: {
          PrintLinha();
          cout << "        Cardapio:" << endl;
          PrintLinha();
          cout << "\n\n\n";
          PrintLinha();

          for (int i = 0; i < Cardapio.size(); i++) {
            cout << "Nome: " << Cardapio[i].getNome() << endl;
            cout << "Codigo: " << Cardapio[i].getCodigo() << endl;
            printf("Preco: R$%.2f\n", Cardapio[i].getPreco());
            cout << "Tipo: " << Cardapio[i].getTipo() << endl;
            PrintLinha();
          }
          pause();
          system("clear");
          break;
        }
        case 4: {
          int r;
          aviso();
          cout << "Digite o Codigo que Deseja Remover : ";
          cin >> r;
          system("clear");
          int aux;
          aux = 0;
          for (int i = 0; i < Cardapio.size(); i++) {
            if (Cardapio[i].getCodigo() == r) {
              aviso();
              Cardapio = removeVector(Cardapio, i);
              cout << "Removido com Sucesso!";
              pause();
              aux = 1;
              system("clear");
            }
          }
          if (aux == 0) {
            system("clear");
            aviso();
            cout << "Codigo Nao Corresponde a Nenhum Produto" << endl;
            pause();
            system("clear");
            break;
          }
          break;
        }
        case 0:
          system("clear");
          break;
        default:
          system("clear");
          aviso();
          cout << "Opção Invalida..." << endl;
          pause();
          system("clear");
          break;
        }

      } while (t != 0);
      break;
    case 4:
      int op3;
      do {
        PrintEmblema();
        cout << "1.Balanço do caixa" << endl;
        cout << "2.Produto mais/menos vendido" << endl;
        cout << "3.Total de Gorjeta de um Garçon" << endl;
        cin >> op3;
        system("clear");
        switch (op3) {
        case 1:
          relatorio.balancoCaixa(vCaixa, montante);
          pause();
          break;
        case 2:
          relatorio.balancoProduto(Cardapio);
          pause();
          break;
        case 3:
          int cod_Garcon;
          cout << "Digite o codigo do Garçon: ";
          cin >> cod_Garcon;
          relatorio.gorjetaGarcon(cod_Garcon, Garçons);
          pause();
          break;
        default:
          break;
        }

      } while (op3 == 0);
      system("clear");
      break;
    case 5: {
      int op;
      do {
        PrintEmblema();
        cout << "1.Cadastrar Novo Garçom" << endl;
        cout << "2.Ver Garçons Cadastrados" << endl;
        cout << "3.Remover Ultimo Garçom" << endl;
        cout << "4.Remover Garçom Especifico" << endl;
        cout << "5.Voltar ao Menu Anterior" << endl;
        cin >> op;
        system("clear");
        switch (op) {
        case 1: {
          Mesero *Novo = new Mesero();
          PrintEmblema();
          cout << "Informe o nome do funcionario :" << endl;
          string *n = new string();
          cin >> *n;
          Novo->setNome(*n);
          delete n;
          system("clear");
          int *p2 = new int();

          PrintEmblema();
          cout << "Informe o ID do Funcionario :" << endl;
          bool *m = new bool();
          while (1) {

            if (*m == 1) {
              Novo->setId(*p2);
              Garçons.push_back(*Novo);
              delete Novo;
              aviso();
              cout << "Adicionado com Sucesso!" << endl;
              delete p2;
              delete m;
              pause();
              system("clear");
              break;
            }
            *m = 1;
            cin >> *p2;
            system("clear");

            for (int i = 0; i < Garçons.size(); i++) {

              if (Garçons[i].getId() == *p2) {
                aviso();
                cout << "Erro : ID já Pertence a Outro Garçom" << endl;
                cout << "Informe Outro Codigo:";
                *m = 0;
                break;
              }
            }
          }
          break;
        }
        case 2: {
          PrintLinha();
          cout << "        Garçons:" << endl;
          PrintLinha();
          cout << "\n\n\n";
          PrintLinha();

          for (int i = 0; i < Garçons.size(); i++) {
            cout << "Nome: " << Garçons[i].getNome() << endl;
            cout << "Codigo: " << Garçons[i].getId() << endl;
            PrintLinha();
          }
          pause();
          system("clear");
          break;
        }
        case 3: {
          if (Garçons.size() == 0) {
            aviso();
            cout << "Erro: Nenhum Garçon Cadastrado" << endl;
            pause();
            system("clear");
            break;
          } else {
            Garçons.pop_back();
            aviso();
            cout << "Ultimo Garçon Removido com Sucesso!" << endl;
            pause();
            system("clear");

            break;
          }
        } // c3
        case 4: {
          int *r = new int();
          PrintEmblema();
          cout << "Digite o ID do garçom que deseja remover : ";
          cin >> *r;
          system("clear");
          int *aux = new int();
          *aux = 0;
          for (int i = 0; i < Garçons.size(); i++) {
            if (Garçons[i].getId() == *r) {
              aviso();
              cout << "Removido com sucesso!";
              Garçons = removeVector(Garçons, i);
              pause();
              *aux = 1;
              system("clear");
              delete r;
              delete aux;
            }
          }
          if (*aux == 0) {
            system("clear");
            aviso();
            cout << "Codigo nao corresponde a nenhum Garçom" << endl;
            pause();
            system("clear");
            break;
          }
          break;
        }
        case 5:
          break;
        default:
          system("clear");
          aviso();
          cout << "Opção Invalida..." << endl;
          pause();
          system("clear");
          break;
        }

      } while (op != 5);
      break;
      system("clear");
    }
    case 6:
      system("clear");
      break;

    default:
      system("clear");
      aviso();
      cout << "Opção Invalida..." << endl;
      pause();
      system("clear");
      break;
    }

  } while (opcao != 6);
  aviso();
  cout << "Sistema OFF...";
}
