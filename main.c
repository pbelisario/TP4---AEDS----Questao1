#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lista.h"

int main(int argc, char const *argv[]) {

  srand(time(0));

  sentinela *lista;
  nodo *celula;
  int i, numerodesoldados = 25;
  //numero de soldados = numero de soldados -1

  lista = inicializaLista();

  //preeche a lista com soldados
  for(i = 1; i < numerodesoldados; i ++){
    celula = inicializaNodo(i);
    inserirElemento(celula, lista);
  }
  printf("%s %d %s\n", "O Batalhao contem", numerodesoldados, "soldados");
  imprimirlista(lista);
  printf( "\n" );
  //laço de repetição que escolherá o soldado que sobreviverá
  while (numerodesoldados > 2){
    imprimirlista (lista);
    matarSoldado(lista, numerodesoldados);
    numerodesoldados--;
  }
  printf("%s %d %s\n", "O soldado",getSoldado(lista),"que se salvou" );

  return 0;
}
