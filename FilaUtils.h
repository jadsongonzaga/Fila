#include "FilaUtils.c"

typedef struct INFO;
typedef struct NO;
typedef struct FILA;

INFO getInfo();
void exibirInfo(INFO);
NO * criarNO();
void inserir(FILA *, INFO);
void remover(FILA *);
void imprimirFila(FILA *);
void imprimirInterativo(FILA *);

