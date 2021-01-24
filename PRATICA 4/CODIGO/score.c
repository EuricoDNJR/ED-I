#include<stdio.h>
#include<stdlib.h>

#include"score.h"
#include"container.h"
#include"navio.h"


void score_tonelada(int soma_tonelada,int *score)
{
    int t = soma_tonelada;
    *score = *score +(soma_tonelada * 2);
}

void score_espa_vazio(int num_esp_livre,int *score)
{
    //<???>
    int n = num_esp_livre * 100;
    *score = *score - ((num_esp_livre/2)/100);
}

void score_desempilhagem(int tonelada,int *score)
{
    int n = tonelada * 100;
    *score = *score -( (n * (5))/100);
}

void score_desenfileragem(int tonelada,int *score)
{
    int n = tonelada * 100;
    *score = *score -((n * (5))/100);

}