#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"container.h"
#include"navio.h"
#include"score.h"
#include"carregar.h"
#include"interface.h"

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

int main()
{
    inicializar();

    return 0;
}