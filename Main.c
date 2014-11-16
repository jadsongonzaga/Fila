#include "FilaUtils.h"

int main(){
  FILA * fila = (FILA *) malloc(sizeof(FILA));
  INFO info1;
  INFO info2;
  INFO info3;

  strcpy(info1.nome, "teste 1");
  info1.idade = 15;
  strcpy(info2.nome, "teste 2");
  info2.idade = 20;
  strcpy(info3.nome, "teste 3");
  info3.idade = 30;
  inserir(fila, info1);
  inserir(fila, info2);
  inserir(fila, info3);

imprimirFila(fila);

  imprimirInterativo(fila);


  imprimirFila(fila);

  remover(fila);
  imprimirFila(fila);
  remover(fila);
  imprimirFila(fila);
  remover(fila);
  imprimirFila(fila);

}


