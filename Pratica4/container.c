
#include<stdio.h>
#include<stdlib.h>

#include"container.h"
#include"navio.h"

//PILHA

//o Container
struct container
{
//    ▪ Tamanho
    int tamanho;// 1 = grande (80 toneladas); 2 = médio (50toneladas); ou 3 = pequeno (35 toneladas).
    //<???>
    //▪ Tipo do Produto
    //char tipo_produto;
    //▪ É perecível?
    int corozivo; //1 - sim, 0 - não
    //▪ É corrosivo?
    int perecivel; //1 - sim, 0 - não

};

struct lis_cont
{
    Container* info;
    struct lis_cont* prox; 
};

struct pil_cont
{
    Lis_Cont* topo;
};

Pil_Cont* criaPilha()
{
    Pil_Cont *p = (Pil_Cont*)malloc(sizeof(Pil_Cont));
    p->topo = NULL;
    return p;
}


void _inserir_conteiner(Pil_Cont *pilha, Container *info)
{
    Lis_Cont* novo;
    novo = (Lis_Cont*)malloc(sizeof(Lis_Cont));
    novo->info = info;
    novo->prox = pilha->topo;
    pilha->topo = novo;

}

//1 – Cadastro
void Cadastrar_Container(Pil_Cont *pilha,int tamanho,int perecivel,int corrosivo)
{
    Container *info;
    info = (Container*)malloc(sizeof(Container));
    info->tamanho = tamanho;
    info->perecivel = perecivel;
    info->corozivo = corrosivo;
    _inserir_conteiner(pilha, info);

}

int _pilhaVazia(Pil_Cont *pilha)
{
    if (pilha->topo == NULL)
        return 1;

     return 0;
    
}

void _mostrar_container(Container *c)
{
    switch (c->tamanho)
    {
    case 1:
        printf("Conteiner GRANDE(80 toneladas)!\n");
        break;
    case 2:
        printf("Conteiner MEDIO(50 toneladas)!\n");
        break;    
    case 3:
        printf("Conteiner PEQUENO(35 toneladas)!\n");
        break;

    default:
        printf("Tamanho informado Invalido!\n");
        break;
    }
    if(c->corozivo==1)
    {
        printf("Conteiner com produtos CORROZIVOS!\n");
    }else
    {
        if(c->perecivel==1)
            printf("Conteiner com produtos PERECIVEIS!\n");
    }

}

void Mostra_Pilha(Pil_Cont *pilha)
{
    Lis_Cont *aux;
    if(_pilhaVazia(pilha))
    {
        printf("Pilha vazia\n");
    }else{
        aux = pilha->topo;
        _mostrar_container(aux->info);
        printf("\nDemais valores: \n");
        for(aux = aux->prox; aux != NULL; aux = aux = aux->prox)
        {
            printf("\n");
            _mostrar_container(aux->info);
        }
    }
}

Container* Remover_Pilha(Pil_Cont *pilha)
{
    Container *valor;
    Lis_Cont *aux;

    if(_pilhaVazia(pilha))
    {
        printf("Lista vazia\n");
        exit(-1);
    }
    aux = pilha->topo;
    valor = aux->info;
    pilha->topo = aux->prox;
    free(aux);
    return valor;

}

void pilha_libera (Pil_Cont* p_c){
    Lis_Cont* q = p_c->topo, *t;
    while (q!=NULL) {
        t = q->prox;
        free(q->info);
        free(q);
        q = t;
    }
    free(p_c);
}