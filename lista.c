#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lista.h"


struct Nodo{
  int Soldado;
  nodo *prox;
};

struct Sentinela{
  nodo *prim;
};

nodo *inicializaNodo(int soldado){
  nodo *n;
  n = (nodo*) malloc (sizeof(nodo));
  n->Soldado = soldado;
  printf("Nodo iniciado.\n");
  return n;
}

sentinela *inicializaLista(){
  sentinela *s;
  s = (sentinela*) malloc (sizeof(sentinela));
  s->prim = NULL;
  printf("Lista iniciada.\n");
  return s;
}

void matarSoldado(sentinela *s, int numeroDeSoldados) {
  //Como foi optado por nao haver soldado número 0 retira-se 1
  //do total de soldados no batalhao
  int soldadoQueIniciaraContagem = sortearSoldado((numeroDeSoldados-1));
  int numeroSorteado = sortearNumero ((numeroDeSoldados-1));

  int count = soldadoQueIniciaraContagem + numeroSorteado - 1;
  //para fins matematicos começar do soldado X e contar até o número sorteado é
  //equivalente a começar do primeiro e contar até o número sorteado + x
  int i; //variável auxiliar de controle do laço for
  nodo *aux; //variável auxiliar que percorrerá a lista
  aux = s->prim;
  //laço que percorre a lista, ao sair dele,
  // o aux está na posição anterior à que será retirada
  for (i = 1; i < count; i++) {
    aux = aux->prox;
  }
  //Condicional que remove caso não seja o primeiro
  if (aux->prox != s->prim){
    printf("%s\t", "Soldado que perdeu");
    imprimirElemento(aux->prox);
    removerElemento(aux->prox, aux);
  }else{
    //se for o primeiro, como ele será removido
    nodo *aux2;
    aux2 = s->prim;
    s->prim = aux2->prox;
    printf("%s\t", "Soldado que perdeu");
    imprimirElemento(aux->prox);
    free(aux->prox);
    aux->prox = s->prim;
  }
  printf("\n" );
}
//faz o nodo anterior apontar do que será removido para o sucessor dele
//não remove o nodo que estiver na primeria posição
void removerElemento(nodo *queSeraRemovido, nodo *anterior){
  anterior->prox = queSeraRemovido->prox;
  free(queSeraRemovido);
}

void inserirElemento (nodo *n, sentinela *s){
  nodo *aux, *aux2;
  aux = s->prim;
  if (s->prim != NULL){
    //percorre a lista para chegar na ultima posiçao
    while (aux->prox != s->prim) {
      aux = aux->prox;
    }
    //insere o elemento na ultima posição
    aux->prox  = n;
    aux2 = aux->prox;
    aux2->prox = s->prim;
  }else{
    s->prim = n;
    n->prox = n;
  }
}

void imprimirElemento (nodo *n){
  printf("%d ",  n->Soldado);
}

void imprimirlista(sentinela *s){
  nodo *aux;
  aux = s->prim;
  printf("%s:\t", "Soldados restantes");
  while (aux->prox != s->prim){
    imprimirElemento(aux);
    aux = aux->prox;
  }imprimirElemento(aux);
}

int sortearSoldado(int numeroDeSoldados){
  //como não há o soldado 0 soma-se 1 ao resto
  int Soldado = ((rand()%numeroDeSoldados) + 1);
  printf("\nSoldado que começará a contagem é o %d\n", Soldado );
  return Soldado;
}

int sortearNumero(int numeroDeSoldados){
  int i, Numero = 0;
  for (i = 0; i < numeroDeSoldados; i++){
    Numero += rand()%11;
  }
  printf("Numero sorteado = %d\n", Numero );
  return Numero;
}

int getSoldado(sentinela *s){
  return (s->prim)->Soldado;
}
