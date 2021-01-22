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

char *copia_string( char *str_orig ){

	int i=0;
	char *str_dest = (char *)malloc( sizeof(char) );

	while( (str_dest[i] = str_orig[i]) ){
		i++;
		str_dest = (char *)realloc( str_dest, sizeof(char) * (i + 1) );
	}

	return str_dest;

}

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

    d[*qtd_docentes].info_docente.nome = copia_string( nome );
    d[*qtd_docentes].info_docente.idade = idade;
    d[*qtd_docentes].info_docente.ID =  *qtd_pessoas; 
    d[*qtd_docentes].info_docente.matricula = *qtd_docentes;
    d[*qtd_docentes].qtd_orientacoes_graduacao = 0;
    d[*qtd_docentes].qtd_orientacoes_pos_graduacao = 0;

    *qtd_docentes += 1;
}

void mostra_docentes(Docente *doc,int *qtd_docentes){
        int i;
        printf("\nDoscentes disponiveis:\n");
        for(i = 0; i < *qtd_docentes; i++){
            printf("Id do docente: %d, Nome do docente: %s\n",doc[i].info_docente.ID,doc[i].info_docente.nome);
        }
        printf("\n");
}

int _orientador_existe(int num_orientador, Docente *doc, int *qtd_docentes)
{
    printf("Entrou no existe docente\n");
        int i;
        int flag = 0;
        for(i = 0; i < *qtd_docentes + 1; i++){
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
    
    d = (Discente *)realloc(d, ( (*qtd_discentes) + 1 ) * sizeof(Discente));
    
    d[*qtd_discentes].info_discente.nome = copia_string( nome );
    d[*qtd_discentes].info_discente.idade = idade;
    d[*qtd_discentes].info_discente.ID =  *qtd_pessoas;
    d[*qtd_discentes].info_discente.matricula =  *qtd_discentes;
    d[*qtd_discentes].nivel = nivel;
    d[*qtd_discentes].nome_curso = copia_string( nome_curso );
    d[*qtd_discentes].senha = senha;
    
    *qtd_discentes += 1;
    
    while(1)
    {
        mostra_docentes(doc,qtd_docentes);
        printf("Informe o ID do seu Orientador(0 = sem orientador):\n");
        scanf("%d", &num_orientador);
        if(num_orientador == 0)
        {
            break;
        }
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
        printf("Informe o ID do seu Coorientador (0 = sem coorientador):\n");
        scanf("%d", &num_Coorientador);
        if(num_orientador == 0)
        {
            break;
        }
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
    printf("nome: %s\n",d[0].info_discente.nome);
    
    //idade
    printf("Idade: %d\n",d[0].info_discente.idade);
    
    //ID
    printf("ID: %d\n",d[0].info_discente.ID);
    
    //matricula
    printf("Matricula: %d\n",d[0].info_discente.matricula);
    
    //nivel
    printf("Nivel do discente: %d\n",d[0].nivel);

    //nome_curso
    printf("Nome do curso do discente: %s\n",d[0].nome_curso);

    //senha
    printf("Senha do discente: %d\n",d[0].senha);

    //ID_orientador
    printf("Id do orientador do discente: %d\n",d[0].ID_orientador);

    //ID_coorientador
    printf("Id do Coorientador do discente: %d\n",d[0].ID_coorientador);

    
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

