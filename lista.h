#ifndef LISTA_H
#define LISTA_H

typedef struct Nodo nodo;
typedef struct Sentinela sentinela;


nodo *inicializaNodo();
//cria um celula/nodo
sentinela *inicializaLista();
//cria uma lista vazia

void matarSoldado (sentinela *s, int numeroDeSoldados);
//Cada vez que eliminar escreve o soldado eliminado na tela / arquivo

void removerElemento(nodo *queSeraRemovido, nodo *anterior);
//Retira um elemento da lista apontando o seu anterior para o seu sucessor
void inserirElemento(nodo *n, sentinela *s);
//adiciona um elemento ao final da lista, apontando-o para o primerio
void imprimirElemento(nodo *n);
//Imprime os dados que possui na celula/nodo

void imprimirlista(sentinela *s);
//Imprime a lista inteira

int sortearSoldado(int numeroDeSoldados);
//valor randomico entre 1 e o numero de soldados
int sortearNumero();
//Com o intuito de gerar valores na faixa do possivel,
//Imaginamos que o sorteito funcionava da seguinte forma:
//Cada soldado poderá colocar um valor de 0 a 10
//o que equivale a possibilidade de números que eles podem fazer com as mãos.
//O numero Sorteado equivale a soma desses valores

int getSoldado(sentinela *s);
//retorna o soldado que esta na primeira posição da lista


#endif
