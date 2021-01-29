#include<stdio.h>
#include<stdlib.h>

#include"score.h"
#include"container.h"
#include"navio.h"
#include"carregar.h"

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

struct lis_cont
{
    Container* info;
    struct lis_cont* prox; 
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

void score_tonelada(Navio *n,float *score)
{
    int soma_tonelada = 0;
    Lis_Cont *aux = n->c->topo;
    while(aux!=NULL)
    {
        soma_tonelada += retorna_tamanho_container(aux->info);
        aux = aux->prox;
    }
    float num = soma_tonelada*2;
    *score = *score + num;
}

void score_espa_vazio(Navio *n,float *score)
{
    float soma_tonelada = 0;
    Lis_Cont *aux = n->c->topo;
    while(aux!=NULL)
    {
        soma_tonelada += retorna_tamanho_container(aux->info);
        aux = aux->prox;
    }
    
    float num_esp_livre = n->capacidade - soma_tonelada;
    float num = (num_esp_livre*0.5);

    *score = (*score - num);

}

void score_desempilhagem(Container *c,float *score)
{
    float tonelada = retorna_tamanho_container(c);
    
    float n = tonelada*0.05;
    
    *score = *score - n;
    
}

void score_desenfileragem(Navio *na,float *score)
{
    
    float n = (na->capacidade *0.05);
    
    *score = *score - n;

}