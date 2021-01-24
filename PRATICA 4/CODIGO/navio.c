#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include"navio.h"
#include"container.h"
//FILA

struct container
{
//    ▪ Tamanho
    int tamanho;// 1 = grande (80 toneladas); 2 = médio (50toneladas); ou 3 = pequeno (35 toneladas).
    //<???>
    //▪ Tipo do Produto
    //<???>
    //▪ É perecível?
    int corozivo; //1 - sim, 0 - não
    //▪ É corrosivo?
    int perecivel; //1 - sim, 0 - não

};

struct pil_cont
{
    Lis_Cont* topo;
};

struct navio
{
//▪ Capacidade em toneladas //máximo de 125 mínimo de 25
//deve-se usar um rand() para preenchimento obedecendo o
//intervalo acima.
    int capacidade;
//▪ Suporta cargas perecíveis?
    int sup_perecivel;//1 = sim, 0 = não
//▪ Suporta cargas corrosivas? //se suporta corrosivo não pode carregar perecível e vice-versa.
    int sup_corrozivo;//1 = sim, 0 = não
//▪ Containers * (inserir o(s) container(s) desde navio)
    Pil_Cont *c;
};

struct lista_nav
{
    Navio *info;
    struct lista_nav *prox;
};


struct fila_nav
{
    Lista_Nav* inicio;
    Lista_Nav* fim;
};


Fila_Nav *criaFila()
{
    Fila_Nav *fi = (Fila_Nav*)malloc(sizeof(Fila_Nav));
    fi->inicio = NULL;
    fi->fim = NULL;
    return fi;
}

void _mostrar_navio(Navio *n)
{
    printf("Capacidade suportada: %d\n",n->capacidade);
    if(n->sup_corrozivo == 1)
    {
        printf("Suporta carga coroziva!\n");
    }else
    {
        if(n->sup_perecivel==1)
        {
            printf("Suporta carga perecivel!\n");
        }
    }
}

void _insereElemento(Fila_Nav* fila, Navio *info)
{
    Lista_Nav* novo;
    novo = (Lista_Nav*)malloc(sizeof(Lista_Nav));

    novo->info = info;
    novo->prox = NULL;

    if(fila->fim != NULL)
    {
        fila->fim->prox = novo;
    }else
    {
        fila->inicio = novo;
    }
    fila->fim = novo;
    //_mostrar_navio(novo->info);
    printf("\n");
}

void Cadastrar_Navio(Fila_Nav* fila,int sup_perecivel, int sup_corrozivo)
{

    Navio *info;
    info = (Navio*)malloc(sizeof(Navio));

    info->capacidade = 25 + ( rand() % 101 );
    info->sup_corrozivo = sup_corrozivo;
    info->sup_perecivel = sup_perecivel;
    info->c = (Pil_Cont*)malloc(sizeof(Pil_Cont));
    _insereElemento(fila,info);

}

_Bool _filaVazia(Fila_Nav *fila)
{
    if(fila->inicio == NULL)
    {
        return 1==1;
    }else
    {
        return 1==2;
    }
}

Navio* Remover_Fila(Fila_Nav *fila)
{
    Navio *valor;
    Lista_Nav *aux;

    if(_filaVazia(fila))
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



void Mostra_Fila(Fila_Nav *fila)
{
    Lista_Nav *aux;
    if(_filaVazia(fila))
    {
        printf("Fila esta Vazia!\n");
    }else
    {
        aux = fila->inicio;
        //printf("Inicio: %d \n", fila->inicio->info);
        while(aux!=NULL)
        {
            _mostrar_navio(aux->info);
            aux = aux->prox;
            printf("\n");
        }
    }
}
