#include<stdio.h>
#include<string.h>
#include<stdio_ext.h>

typedef struct{
    int idade;
    char nome[40];
}INFO;

typedef struct{
    INFO info;
    struct NO *ant;
    struct NO *prox;
}NO;

typedef struct{
    NO * inicio;
    NO * fim;
}FILA;

INFO getInfo(){
    INFO info;
    __fpurge(stdin);
    puts("Informe o nome\t");
    gets(info.nome);
    puts("Informe a idade\t");
    scanf("%d",&info.idade);
    return info;
}

void exibirInfo(INFO info){
    printf("Nome  :%s\n", info.nome);
    printf("Idade :%d\n", info.idade);
}
NO * criarNO(){
    return (NO *) malloc(sizeof(NO));
}

void inserir(FILA *fila, INFO info){
    NO *no = criarNO();
    no->info = info;
    if(fila->fim == NULL){
        no->ant = no;
        no->prox = no;
        fila->inicio = no;
        fila->fim = no;
    }else{

        no->ant = fila->fim;
        fila->fim->prox = no;
        fila->fim=no;
        fila->fim->prox = fila->inicio;
        fila->inicio->ant = fila->fim;

    }
}

void remover(FILA *fila){
    if(fila->inicio == NULL){
        perror("Fila vazia");
    }else{
        NO *aux = fila->inicio;
        if(fila->inicio->ant == fila->inicio){
            fila->inicio = NULL;
            fila->fim = NULL;
            free(aux);
        }else{
            fila->inicio = aux->prox;
            fila->fim->prox = fila->inicio;
            fila->inicio->ant = fila->fim;
            aux->ant = NULL;
            aux->prox = NULL;
            free(aux);
        }
    }
}

void imprimirFila(FILA *fila){
    if(fila->inicio == NULL){
        perror("Fila vazia");
    }else{
        NO * aux = fila->inicio;
        do{
            exibirInfo(aux->info);
            aux = aux->prox;
        }while(aux !=fila->inicio);
    }
}

void imprimirInterativo(FILA *fila){
    if(fila->inicio == NULL){
        perror("Fila vazia");
    }else{
        char op = 'S';
        puts("Informe P para próximo, A para anterior e S para sair.");
        NO * aux = fila->inicio;
        do{
            exibirInfo(aux->info);
            __fpurge(stdin);
            scanf("%c",&op);
            if(op == 'P' || op == 'p'){
                aux = aux->prox;
            }else if(op == 'A' || op == 'a'){
                aux = aux->ant;
            }
        }while(op != 'S' && op != 's');
    }
}

