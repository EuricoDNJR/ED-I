#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"container.h"
#include"navio.h"
#include"score.h"

int main()
{
    srand(time(NULL));

    //Teste de Container:
    //Pil_Cont *pilha_conteiner;
    //pilha_conteiner = criaPilha();
    //Cadastrar_Container(pilha_conteiner,1,0,1);
    //Cadastrar_Container(pilha_conteiner,2,1,0);
    //Cadastrar_Container(pilha_conteiner,3,0,1);
    //Mostra_Pilha(pilha_conteiner);
    //Remover_Pilha(pilha_conteiner);
    //printf("\n\n");
    //Mostra_Pilha(pilha_conteiner);

    //Teste de Navio:
    //Fila_Nav *n;
    //n=criaFila();
    //Cadastrar_Navio(n,1,0);
    //Cadastrar_Navio(n,0,1);
    //Cadastrar_Navio(n,0,0);

    //Mostra_Fila(n);
    //Remover_Fila(n);
    //printf("\n\n");
    //Mostra_Fila(n);

    //Teste de score
    int s=0;
    score_tonelada(200,&s);
    //score_tonelada(200,&s);
    printf("%d\n",s);
    score_desempilhagem(80,&s);
    score_espa_vazio(1,&s);
    printf("%d\n",s);

    return 0;
}