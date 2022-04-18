#include <iostream>
#include <fstream>
#include <iomanip>

#include "estruturas.h"

using namespace std;

void popularDoArquivo(Celula **topo, Celula **lista) {
  char nomeArquivo[200];
  ifstream procurador;
  
  cout << "Informe caminho e nome do arquivo com dados glicemicos: ";
  cin >> nomeArquivo;

  procurador.open(nomeArquivo);
  if (!procurador) {
      cout << "Arquivo digitado nao localizado!";
      return;
  }

  string linha;
  string glicemia;
  
  int posicaoEspaco = 0;
  while (getline(procurador,linha)){ //"1,-9"
    posicaoEspaco = linha.find(" ");
    //extrair glicemia
    glicemia = linha.substr(0,posicaoEspaco);
    *topo = inserirPilha(stoi(glicemia), *topo);
    *lista = inserirLista(stoi(glicemia), *lista);
  } 
  procurador.close();
}


int main() {
  Celula *pilha = NULL;
  Celula *lista = NULL;
  Celula *lista3 = NULL;
  

  popularDoArquivo(&pilha, &lista);
  
  Celula *lista2 = NULL;

  
  
  popularDoArquivo(&pilha, &lista2);
  

  cout << "Valores ordenados de glicemia do mais baixo ao mais alto" << endl;
  cout<<"lista 1: \n";
  exibirLista(lista);
  cout<<"\n lista 2: \n";
  exibirLista(lista2);


  /*2) No método excluirOcorrencias (trabalhado na última aula), faça alteração       para que ele, além de excluir as ocorrências de um número passado como parâmetro,   imprima na tela quantos números foram excluídos. */
  int numero;
  
  cout << "Qual o número que você deseja apagar da lista? ";
  cin >> numero;


  
  lista = excluirOcorrenciasLista(numero, lista);
  cout<<"\n";
  exibirLista(lista);
  /*3) Faça um método que receba 2 listas simples e encadeadas (com números     
  inteiros) e exiba (imprima) os números que aparecem nas 2 listas.*/
  cout << "numeros iguais \n";
  exibiriguais(lista2,lista);
  lista3= concatena(lista2,lista);
  /*4) Faça um método que receba 2 listas simples e encadeadas (com números inteiros). O método deve unir a primeira lista com a segunda lista e retornar a nova lista gerada.*/
  cout<<"\n lista concatenada: \n";
  exibirLista(lista3);
}
