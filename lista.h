#ifndef LISTA_H
#define LISTA_H

typedef struct Nodo nodo;
typedef struct ListaCircular listacircular;


listacircular *iniciaLista();
listacircular *removerElemento(nodo *n, listacircular *l);

nodo *sortearSoldado(listacircular *l);
nodo *matarSoldadoSorteado (nodo *soldadoInicialdaContagem, int posicaoDoqueSaira);
//Cada vez que eliminar escreve o soldado eliminado na tela / arquivo
//Retorna o soldado seguinte ao eliminado

void inserirElemento(nodo *n, listacircular *l);
int sortearNumero();



#endif
