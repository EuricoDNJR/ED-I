#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cadastro.h"


struct pessoa{
    char *nome;
    int idade; 
    int ID;//identificador
    int matricula;//deve ser gerada automaticamente
};

struct docente{
    Pessoa info_docente;
    int qtd_orientacoes_graduacao; 
    int qtd_orientacoes_pos_graduacao;
};

struct discente{
    Pessoa info_discente;
    int nivel;// 1- graduacao ou 2 - posgraduacao
    char *nome_curso;
    int senha; 
    int ID_orientador; 
    int ID_coorientador;
};


/*
char *nome;
    int idade; 
    int ID;//identificador
    int matricula;//deve ser gerada automaticamente
    int qtd_orientacoes_graduacao; 
    int qtd_orientacoes_pos_graduacao;
*/


//cadastrar doscente
Docente* criar_docente()
{
    //printf("Entrol no criar docente\n");
    Docente *d;
    d = (Docente *)malloc(sizeof(Docente));

    return d;
}


Discente* criar_discente()
{
    //printf("Entrol no criar dicente\n");
    Discente *d;
    d = (Discente *)malloc(sizeof(Discente));

    return d;
}


void cadastra_docente(Docente *d, int *qtd_docentes, int *qtd_pessoas, char *nome, int idade, int qtd_orientecoes_graduacao, int qtd_orientecoes_pos_graduacao)
{
    //printf("Entrol no cadastrar docente\n");

    d = (Docente*)realloc(d, sizeof(Docente) * ( (*qtd_docentes)  + 1));

    strcpy(d[*qtd_docentes].info_docente.nome, nome);
    d[*qtd_docentes].info_docente.idade = idade;
    d[*qtd_docentes].info_docente.ID =  *qtd_pessoas; 
    
    d[*qtd_docentes].info_docente.matricula = *qtd_docentes;
    d[*qtd_docentes].qtd_orientacoes_graduacao = 0;
    d[*qtd_docentes].qtd_orientacoes_pos_graduacao = 0;

    *qtd_docentes += 1;
}

void mostra_docentes(Docente *doc,int *qtd_docentes){
        printf("Entrol no mostrar docente\n");
        int i;
        printf("Doscentes disponiveis:\n");
        for(i = 0; i < *qtd_docentes; i++){
            printf("Id do docente: %d, Nome do docente: %s\n",doc[i].info_docente.ID,doc[i].info_docente.nome);
        }
}

int _orientador_existe(int num_orientador, Docente *doc, int *qtd_docentes)
{
    printf("Entrou no existe docente\n");
        int i;
        int flag = 0;
        for(i = 0; i < *qtd_docentes; i++){
            if(doc[i].info_docente.ID == doc[num_orientador].info_docente.ID)
            {
                flag = 1;
            }
        }
        return flag;
}

void cadastrar_discente(Discente *d, Docente *doc, int *qtd_discentes, int *qtd_docentes, int *qtd_pessoas, char *nome, int idade, int nivel, char *nome_curso, int senha)
{
    
    int num_orientador = 0, num_Coorientador = 0;
    
    d = (Discente *)realloc(d, (*qtd_discentes) * sizeof(Discente));
    
    strcpy(d[*qtd_discentes - 1].info_discente.nome, nome);
    printf("Entrol no cadastra dicente\n");
    
    d[*qtd_discentes - 1].info_discente.idade = idade;
    d[*qtd_discentes - 1].info_discente.ID =  *qtd_pessoas;
    d[*qtd_discentes - 1].info_discente.matricula =  *qtd_discentes;
    d[*qtd_discentes - 1].nivel = nivel;
    strcpy(d[*qtd_discentes - 1].nome_curso, nome_curso);
    d[*qtd_discentes - 1].senha = senha;
    
    while(1)
    {
        mostra_docentes(doc,qtd_docentes);
        printf("Informe o ID do seu Orientador:\n");
        scanf("%d", &num_orientador);
        if(_orientador_existe(num_orientador,doc,qtd_docentes))//orientador existe 
        {
            d[*qtd_discentes - 1].ID_orientador = num_orientador;
            break;
        }else
        {
            printf("Numero de orientador Invalido!!!\n");
        }
    }
    while(1)
    {
        mostra_docentes(doc,qtd_docentes);
        printf("Informe o ID do seu Orientador:\n");
        scanf("%d", &num_Coorientador);
        if(_orientador_existe(num_Coorientador,doc,qtd_docentes)&&num_Coorientador != num_orientador)//orientador existe 
        {
            d[*qtd_discentes - 1].ID_coorientador = num_Coorientador;
            break;
        }else
        {
            printf("Numero de Coorientador Invalido!!!\n");
        }
    }
}


void _mostrar_teste_docente(Docente *d)
{
    //nome
    printf("nome: %s\n",d[0].info_docente.nome);
    
    //idade
    printf("Idade: %d\n",d[0].info_docente.idade);
    
    //ID
    printf("ID: %d\n",d[0].info_docente.ID);
    
    //matricula
    printf("Matricula: %d\n",d[0].info_docente.matricula);
    
    //qtd_orientacoes_graduacao
    printf("Quantidade de orientados da graduacao: %d\n",d[0].qtd_orientacoes_graduacao);

    //qnt_orientacoes_pos_graduacao
    printf("Quantidade de orientados da pos: %d\n",d[0].qtd_orientacoes_pos_graduacao);
    
}

void _mostrar_teste_discente(Discente *d)
{
    //nome
    printf("nome: %s\n",d->info_discente.nome);
    
    //idade
    printf("Idade: %d\n",d->info_discente.idade);
    
    //ID
    printf("ID: %d\n",d->info_discente.ID);
    
    //matricula
    printf("Matricula: %d\n",d->info_discente.matricula);
    
    //nivel
    printf("Quantidade de orientados da graduacao: %d\n",d->nivel);

    //nome_curso
    printf("Quantidade de orientados da pos: %s\n",d->nome_curso);

    //senha
    printf("Quantidade de orientados da pos: %d\n",d->senha);

    //ID_orientador
    printf("Quantidade de orientados da pos: %d\n",d->ID_orientador);

    //ID_coorientador
    printf("Quantidade de orientados da pos: %d\n",d->ID_coorientador);

    
}


//remover, 
//altarar, 
//buscar e 
//mostrar 
// mostar_docente
// mostrar_discente


//listar alunos de um determinado orientador; 
//listar alunos que não possuem orientador; 
//mudar orientador de um determinado aluno

