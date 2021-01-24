#include<stdio.h>
#include<stdlib.h>

//pilha com lista
struct no
{
    int info;
    struct no *prox;
};

typedef struct no No;

struct f
{
    No* inicio;
    No* fim;
};

typedef struct f Fila;

Fila *criaFila()
{
    Fila *fi = (Fila*)malloc(sizeof(Fila));
    fi->inicio = NULL;
    fi->fim = NULL;
    return fi;
}

void insereElemento(Fila* fila, int info)
{
    No* novo;
    novo = (No*)malloc(sizeof(No));

    novo->info = info;
    novo->prox = NULL;

    if(fila->fim != NULL)
    {
        fila->inicio->prox = novo;
    }else
    {
        fila->inicio = novo;
    }
    fila->fim = novo;
}

_Bool filaVazia(Fila *fila)
{
    if(fila->inicio == NULL)
    {
        return 1==1;
    }else
    {
        return 1==2;
    }
}

void removeElemento(Fila *fila)
{
    int valor;
    No *aux;

    if(filaVazia(fila))
    {
        printf("Fila esta vazia! \n");
        exit(1);
    }
    aux = fila->inicio;
    valor = aux->info;
    fila->inicio = aux->prox;

    if(fila->inicio == NULL)
        fila->fim = NULL;

    free(aux);
    return valor;
}

void mostraLista(Fila *fila)
{
    No *aux;
    if(filaVazia(fila))
    {
        printf("Fila esta Vazia!\n");
    }else
    {
        aux = fila->inicio;

        printf("Inicio: %d \n", fila->inicio->info);
    }
}


//fila com lista




int mian()
{

}