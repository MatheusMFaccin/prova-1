#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;


//struct utilizado tanto pra pilha quanto pra lista
typedef struct no {
  int valor1;
  
  struct no *prox;
  
} Celula;



//mostra os valores glicemicos do mais recente (topo) ao mais antigo
void exibirPilha(Celula *topo) {
  Celula *p;
  for (p = topo; p; p = p->prox) {
    cout << p->valor1 << endl;
  }
}

Celula *inserirPilha(int valor, Celula *topo) {
  //alocar memoria
  Celula *novo = (Celula*)malloc(sizeof(Celula));

  //depositar valores
  novo->valor1 = valor;

  //engatar o ultimo no topo
  novo->prox = topo;
  
  //retornar o novo topo
  return novo;
}

//mostra os valores ordenados, do menor ao maior
void exibirLista(Celula *lista) {
  Celula *p;
  for (p = lista; p; p = p->prox) {
    cout << p->valor1 << endl;
    
  }
}
/*3) Faça um método que receba 2 listas simples e encadeadas (com números 
  inteiros) e exiba (imprima) os números que aparecem nas 2 listas.*/
void exibiriguais(Celula *lista,Celula *lista2) {
  Celula *p,*y;
  for (p = lista; p; p = p->prox) {
    for(y=lista2;y;y=y->prox){
      if(p->valor1 == y->valor1){
        cout << p->valor1 << endl;
      }  
    }
  }
}



//inserir na lista de forma ordenada tendo como chave o valorGlicemia
Celula *inserirLista(int valor,Celula *lista) {
  //alocar memoria
  Celula *novo = (Celula*)malloc(sizeof(Celula));
  
  //depositar valores
  novo->valor1 = valor;
  
  novo->prox = NULL;
  
  
  //percorrer para encontrar o local adequado na lista
  //testar se é a primeira vez
  
    
   
  
  if (!lista) return novo;

  Celula *p, *pR;
  for (pR = NULL, p = lista; p; pR = p, p = p->prox) {
    if (valor < p->valor1) break;
    
    //1) No método inserir de lista simples e encadeada, altere o método para que       um mesmo valor não seja inserido mais de uma vez.
    if(valor==p->valor1){
      
      return lista;
    }
  }
  
    
  //é o primeiro
  if (p == lista) {
    novo->prox = lista;
    return novo;
  }
  //é o último
  if (!p) {
    pR->prox = novo;
  } else { //está no meio de duas celulas
    pR->prox = novo;
    novo->prox = p;
  }
  //retorna o inicio da lista
  return lista;
  if (p == lista) {
    novo->prox = lista;
    return novo;
  }
  
  return lista;

}

//metodo que recebe uma lista e retorna a quantidade de elementos
int contarElementos(Celula *lista) {
  int contador = 0;
  Celula *p;
  for (p = lista; p ; p = p->prox) {
    contador++;
  }
  return contador;
}

float media(Celula *lista) {
  int soma = 0;

  Celula *p;
  for (p = lista; p ; p = p->prox) {
    soma+= p->valor1;
  }
  return soma/contarElementos(lista);
}

float mediana(Celula *lista) {
  int quantidadeElementos = contarElementos(lista);
  bool ehPar;

  if (quantidadeElementos % 2 == 0) {
    ehPar = true;
  } else {
    ehPar = false;
  }

  int i;
  int metade;
  Celula *p;
  if (!ehPar) {
    metade = (int)quantidadeElementos/2;
  } else {
    metade = (int)quantidadeElementos/2 - 1;
  }
  for (i = 0, p = lista; i < metade; i++, p = p->prox);

  
  if (!ehPar) return p->valor1;
  
  return (p->valor1 + p->prox->valor1)/2;
}

//2) No método excluirOcorrencias (trabalhado na última aula), faça alteração para que ele, além de excluir as ocorrências de um número passado como parâmetro, imprima na tela quantos números foram excluídos.
Celula *excluirOcorrenciasLista(int valor, Celula *lista) {
  Celula *p, *pR;

  if (!lista) {
    cout << "Lista vazia. Operação cancelada!" << endl;
    return lista;
  }

  bool houveExclusao;
  int contador=0;
  do {
    houveExclusao = false;
    for (pR = NULL, p = lista; p; pR = p, p = p->prox) {
      if (valor == p->valor1) {
        //eh o primeiro
        if (p == lista) {
          lista = lista->prox;
        } else if (!p->prox) { //eh o ultimo
          pR->prox = NULL;
        } else { //esta entre celulas
          pR->prox = p->prox;
        }
        free(p);
        houveExclusao = true;
        ++contador;
        break;
      }
    }   
  } while (houveExclusao);
  cout<<"numero de itens que foram apagados: "<<contador;
  return lista;
}

/*4) Faça um método que receba 2 listas simples e encadeadas (com números inteiros). O método deve unir a primeira lista com a segunda lista e retornar a nova lista gerada.*/
Celula* concatena(Celula* lista, Celula* lista2){


if (lista == NULL) return lista2;
if (lista2 == NULL) return lista;

  while (lista != NULL) {
    lista2 = inserirLista(lista->valor1,lista2);
    lista = lista->prox;
  }

    

return lista2;
}