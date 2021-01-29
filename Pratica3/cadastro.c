#include <stdio.h>
#include <stdlib.h>
#include "cadastro.h"


int id_pessoa = 0;


//STRUCTS
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

struct listaDocente{

	Docente *docente;
	struct listaDocente *prox;

};

struct listaDiscente{

	Discente *discente;
	struct listaDiscente *prox;

};


//FUNÇÕES
char *ler_string(){

	char *s = (char *)malloc( sizeof(char) );
	int i=0;

	while( ( s[i] = getchar() ) != '\n' ){
		i++;
		s = (char *)realloc( s, sizeof(char) * (i+1) );
	}
	s[i] = 0;

	return s;

}


//PESSOA
void criar_pessoa( Pessoa *p ){

	setbuf( stdin, NULL );

	id_pessoa++;

	printf("Nome: ");
	p->nome = ler_string();
	printf("Idade "); scanf("%d", &p->idade);
	p->ID = id_pessoa;
	p->matricula = ( id_pessoa * 10 ) + ( rand() % 10 );

}

void mostrar_pessoa( Pessoa p ){

	printf("Nome: %s\n", p.nome);
	printf("Idade: %d\n", p.idade);
	printf("ID: %d\n", p.ID);
	printf("Matricula: %d\n", p.matricula);

}

void liberar_pessoa( Pessoa *p ){

	free( p->nome );

}


//DOCENTE
Docente *criar_docente(){

	Docente *d = (Docente *)malloc( sizeof(Docente) );

	criar_pessoa( &d->info_docente );
	d->qtd_orientacoes_graduacao = 0;
	d->qtd_orientacoes_pos_graduacao = 0;

	printf("\n");

	return d;

}

void mostrar_docente( Docente *d ){

	if( d ){

		mostrar_pessoa( d->info_docente );
		printf("Quantidade de orientacoes(Graduacao): %d\n", d->qtd_orientacoes_graduacao);
		printf("Quantidade de orientacoes(Pos-Graduacao): %d\n", d->qtd_orientacoes_pos_graduacao);

		printf("\n");

	}

}

void liberar_docente( Docente *d ){

	liberar_pessoa( &d->info_docente );
	free( d );

}


//DISCENTE
Discente *criar_discente(){

	Discente *d = (Discente *)malloc( sizeof(Discente) );

	criar_pessoa( &d->info_discente );
	printf("Nivel: "); scanf("%d", &d->nivel);

	setbuf( stdin, NULL );

	printf("Nome do curso: ");
	d->nome_curso = ler_string(); 
    printf("Senha: "); scanf("%d", &d->senha);
    d->ID_orientador = -1;
    d->ID_coorientador = -1;

	printf("\n");

	return d;

}

void mostrar_discente( Discente *d ){

	if( d ){

		mostrar_pessoa( d->info_discente );
		printf("Nivel: %d\n", d->nivel);
		printf("Nome do curso: %s\n", d->nome_curso);
		printf("Senha: %d\n", d->senha);
		printf("Id do orientador: %d\n", d->ID_orientador);
		printf("Id do co-orientador: %d\n", d->ID_coorientador);

		printf("\n");

	}

}

void liberar_discente( Discente *d ){

	liberar_pessoa( &d->info_discente );
	free( d->nome_curso );
	free( d );

}


//LISTA DOCENTE
ListaDocente *criar_listaDocente(){

	return NULL;

}

ListaDocente *cadastrar_docente(ListaDocente *l){

	ListaDocente *novo = (ListaDocente *)malloc( sizeof(ListaDocente) ),
				 *aux = NULL;

	novo->docente = criar_docente();
	novo->prox = NULL;

	if( l == NULL )
		return novo;
	else{

		aux = l;
		while( aux->prox )
			aux = aux->prox;

		aux->prox = novo;

	}

	return l;

}

Docente *buscar_docente( ListaDocente *l, int id ){

	while( l ){

		if( l->docente->info_docente.ID == id )
			return l->docente;

		l = l->prox;

	}

	return NULL;

}

ListaDocente *remover_docente( ListaDocente *l, int id ){

	ListaDocente *aux, *aux2;

	if( l == NULL )
		return l;
	if( l->docente->info_docente.ID == id ){
		if( l->docente->qtd_orientacoes_graduacao + l->docente->qtd_orientacoes_pos_graduacao > 0)
				printf("Docente com orientandos não pode ser removido\n");
		else
			return l->prox;
	}

	aux = l;
	while( aux->prox ){
		if( aux->prox->docente->info_docente.ID == id ){
			if( aux->prox->docente->qtd_orientacoes_graduacao + aux->prox->docente->qtd_orientacoes_pos_graduacao > 0)
				printf("Docente com orientandos não pode ser removido\n");
			else{
				aux2 = aux->prox;
				aux->prox = aux->prox->prox;
				liberar_docente( aux2->docente );	
				free( aux2 );
			}
			break;
		}

		aux = aux->prox;

	}

	return l;

}

void mostrar_listaDocente( ListaDocente *l ){

	if( l == NULL )
		return ;
	else{

		mostrar_docente( l->docente );
		mostrar_listaDocente( l->prox );

	}

}

void liberar_listaDocente( ListaDocente *l ){

	if( l == NULL )
		return ;


	liberar_listaDocente( l->prox );

	liberar_docente( l->docente );	
	free(l);

}


//LISTA DISCENTE
ListaDiscente *criar_listaDiscente(){

	return NULL;

}

ListaDiscente *cadastrar_discente(ListaDiscente *l){

	ListaDiscente *novo = (ListaDiscente *)malloc( sizeof(ListaDiscente) ),
				  *aux = NULL;

	novo->discente = criar_discente();
	novo->prox = NULL;

	if( l == NULL )
		return novo;
	else{

		aux = l;
		while( aux->prox )
			aux = aux->prox;

		aux->prox = novo;

	}

	return l;

}

Discente *buscar_discente( ListaDiscente *l, int id ){

	while( l ){

		if( l->discente->info_discente.ID == id )
			return l->discente;

		l = l->prox;

	}

	return NULL;

}

ListaDiscente *remover_discente( ListaDiscente *l, int id ){

	ListaDiscente *aux, *aux2;

	if( l == NULL )
		return l;
	if( l->discente->info_discente.ID == id )
		return l->prox;

	aux = l;
	while( aux->prox ){
		if( aux->prox->discente->info_discente.ID == id ){
			aux2 = aux->prox;
			aux->prox = aux->prox->prox;
			liberar_discente( aux2->discente );	
			free( aux2 );
			break;
		}

		aux = aux->prox;

	}

	return l;

}

void mostrar_listaDiscente( ListaDiscente *l ){

	if( l == NULL )
		return;
	else{

		mostrar_discente( l->discente );
		mostrar_listaDiscente(l->prox);

	}

}

void liberar_listaDiscente( ListaDiscente *l ){

	if( l == NULL )
		return ;


	liberar_listaDiscente( l->prox );

	liberar_discente( l->discente );	
	free(l);

}


//FUNÇÕES ADICIONAIS
void alunos_de_um_orientador( ListaDiscente *l, int id_orientador ){

	while( l ){

		if( l->discente->ID_orientador == id_orientador )
			mostrar_discente( l->discente );

		l = l->prox;

	}

}

void alunos_sem_orientador( ListaDiscente *l ){

	while( l ){

		if( l->discente->ID_orientador == -1 )
			mostrar_discente( l->discente );

		l = l->prox;

	}

}

void mudar_orientador_de_um_aluno( ListaDocente *ldo, Discente *d, int id_orientador_novo ){

	Docente *doc = buscar_docente( ldo, id_orientador_novo );
	int flag = 0;

	if( d ){

		//SE ENCONTRAR O DOCENTE E SE ALUNO JA TIVER UM ORIENTADOR
		if( doc && d->ID_orientador != -1 ){

			//VERIFICANDO O NIVEL E SE O ORIENTADOR TEM VAGA SOBRANDO
			if( d->nivel == 1 && doc->qtd_orientacoes_graduacao < 4 ){
				doc->qtd_orientacoes_graduacao += 1;
				flag = 1;
			}else if( d->nivel == 2 && doc->qtd_orientacoes_pos_graduacao < 6 ){
				doc->qtd_orientacoes_pos_graduacao += 1;
				flag = 1;
			}
			
			if( flag ){

				if( d->ID_orientador != -1 ){

					doc = buscar_docente( ldo, d->ID_orientador );

					if( d->nivel == 1 )
						doc->qtd_orientacoes_graduacao -= 1;
					else if( d->nivel == 2 )
						doc->qtd_orientacoes_pos_graduacao -= 1;

				}

				d->ID_orientador = id_orientador_novo;

			}

		}

	}

}

void menu_cadastro( ListaDocente **ldo, ListaDiscente **ldi ){

	int op, id;
	char aux;
	Docente *doc = NULL;
	Discente *dis = NULL;

	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("1 - Docente\n");
	printf("2 - Discente\n");
	printf("3 - Cadastrar orientando\n");
	printf("4 - Remover orientando\n");
	printf("5 - Alunos de um determinado orientador\n");
	printf("6 - Alunos que nao possuem orientador\n");
	printf("7 - Mudar orientador de um aluno\n");
	printf("\n");
	printf("Opcao: "); scanf("%d", &op);
	printf("\n\n");

	if( op == 1 ){

		printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
		printf("1 - Cadastrar docente\n");
		printf("2 - Remover docente\n");
		printf("3 - Mostrar docentes\n");
		printf("\n");
		printf("Opcao: "); scanf("%d", &op);
		printf("\n\n");

		if( op == 1 ){

			*ldo = cadastrar_docente( *ldo );

			printf("\n");

		}else if( op == 2 ){

			printf("Id do docente: "); scanf("%d", &id);

			*ldo = remover_docente( *ldo, id );

			printf("\n");

		}else if( op == 3 ){

			mostrar_listaDocente( *ldo );

		}

	}else if( op == 2 ){

		printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
		printf("1 - Cadastrar discente\n");
		printf("2 - Remover discente\n");
		printf("3 - Mostrar discentes\n");
		printf("\n");
		printf("Opcao: "); scanf("%d", &op);
		printf("\n\n");

		if( op == 1 ){

			*ldi = cadastrar_discente( *ldi );

			printf("\n");

		}else if( op == 2 ){

			printf("Id do discente: "); scanf("%d", &id);

			dis = buscar_discente( *ldi, id );

			if( dis ){
				doc = buscar_docente( *ldo, dis->ID_orientador );

				if( doc ){

					if( dis->nivel == 1 )
						doc->qtd_orientacoes_graduacao -= 1;
					else if( dis->nivel == 2 )
						doc->qtd_orientacoes_pos_graduacao -= 1;
				}	

			}

			*ldi = remover_discente( *ldi, id );

			printf("\n");

		}else if( op == 3 ){

			mostrar_listaDiscente( *ldi );

		}

	}else if( op == 3 ){

		printf("Id do discente: "); scanf("%d", &id);

		dis = buscar_discente( *ldi, id );

		printf("Id do docente: "); scanf("%d", &id);

		doc = buscar_docente( *ldo, id );

		if( dis && doc ){

			if( dis->ID_orientador == -1 ){

				if( dis->nivel == 1 && doc->qtd_orientacoes_graduacao < 4){

					dis->ID_orientador = doc->info_docente.ID;
					doc->qtd_orientacoes_graduacao += 1;

				}else if( dis->nivel == 2 && doc->qtd_orientacoes_pos_graduacao < 6){

					dis->ID_orientador = doc->info_docente.ID;
					doc->qtd_orientacoes_pos_graduacao += 1;

				}

			}else if( dis->ID_coorientador == -1 ){

				printf("Aluno ja tem orientador, deseja cadastrar docente como coorientador?\nresposta(sim ou nao): "); scanf("%c", &aux);

				setbuf(stdin, NULL); //PRECAUÇÃO

				if(aux == 's' || aux == 'S'){

					if( dis->nivel == 1 && doc->qtd_orientacoes_graduacao < 4){

						dis->ID_coorientador = doc->info_docente.ID;
						doc->qtd_orientacoes_graduacao += 1;

					}else if( dis->nivel == 2 && doc->qtd_orientacoes_pos_graduacao < 6){

						dis->ID_coorientador = doc->info_docente.ID;
						doc->qtd_orientacoes_pos_graduacao += 1;

					}

				}

			}

		}

	}else if( op == 4 ){

		printf("Id do discente: "); scanf("%d", &id);

		dis = buscar_discente( *ldi, id );

		//ENCONTROU DISCENTE
		if( dis ){

			//SE TIVER ORIENTADOR
			if(dis->ID_orientador != -1){

				doc = buscar_docente( *ldo, dis->ID_orientador );

				if( dis->nivel == 1 )
					doc->qtd_orientacoes_graduacao--;
				if( dis->nivel == 2 )
					doc->qtd_orientacoes_pos_graduacao--;

				dis->ID_orientador = -1;

			}

			//SE TIVER COORIENTADOR
			if(dis->ID_orientador != -1){

				doc = buscar_docente( *ldo, dis->ID_coorientador );

				if( dis->nivel == 1 )
					doc->qtd_orientacoes_graduacao--;
				if( dis->nivel == 2 )
					doc->qtd_orientacoes_pos_graduacao--;

				dis->ID_coorientador = -1;

			}

		}

	}else if( op == 5 ){

		printf("Id do orientador: "); scanf("%d", &id);

		alunos_de_um_orientador(*ldi, id);

	}else if( op == 6 ){

		alunos_sem_orientador(*ldi);

	}else if( op == 7 ){

		printf("Id do discente: "); scanf("%d", &id);

		dis = buscar_discente( *ldi, id );

		printf("Id do novo orientador: "); scanf("%d", &id);

		mudar_orientador_de_um_aluno( *ldo, dis, id );

	}
	
	printf("\n");

}

int login( ListaDocente *ldo, ListaDiscente *ldi ){


	int id, senha;
	Discente *dis = NULL;
	Docente *doc = NULL;

	printf("Id da pessoa(Discente ou Docente): "); scanf("%d", &id);

	doc = buscar_docente(ldo, id);
	if( doc )
		return 1;

	dis = buscar_discente(ldi, id);
	if( dis ){

		if( dis->ID_orientador != -1 ){
			printf("senha: "); scanf("%d", &senha);

			if(dis->senha == senha)
				return 1;
		}

	}

	return 0;

}
