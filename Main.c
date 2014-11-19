#include <stdio.h>
#include "FilaUtils.h"
void menu();
int main(){
  FILA * fila = (FILA *) malloc(sizeof(FILA));
  int op = 0;

  do{
      menu();
      scanf("%d", &op);
      switch(op){
          case 1:
            inserir(fila, getInfo());
            break;
          case 2:
            remover(fila);
            __fpurge(stdin);
            getchar();
            break;
          case 3:
            imprimirFila(fila);
            __fpurge(stdin);
            getchar();
            break;
          case 4:
            imprimirInterativo(fila);
            __fpurge(stdin);
            getchar();
            break;
          case 0:
            return;
            break;
           default:
             puts("Opção iválida.");
             break;
      }
      system("clear");
  }while(op != 0);
}

void menu(){
    printf("1 - Inserir elemento\n2 - Remover elemento \n3 - Imprimir todos elementos\n4 - Percorrer os elementos \n0 - Sair.\n");
}





