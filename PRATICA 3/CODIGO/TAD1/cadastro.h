#ifndef cadastro_h
#define cadastro_h


typedef struct pessoa Pessoa;
typedef struct docente Docente;
typedef struct discente Discente;
typedef struct listaDocente ListaDocente;
typedef	struct listaDiscente ListaDiscente;

char *ler_string();

//PESSOA
void criar_pessoa( Pessoa *p, int id );
void mostrar_pessoa( Pessoa p );
void liberar_pessoa( Pessoa *p );

//DOCENTE
Docente *criar_docente();
void mostrar_docente( Docente *d );
void liberar_docente( Docente *d );

//DISCENTE
Discente *criar_discente();
void mostrar_discente( Discente *d );
void liberar_discente( Discente *d );

//LISTA DOCENTE
ListaDocente *criar_listaDocente();
ListaDocente *cadastrar_docente(ListaDocente *l);
Docente *buscar_docente( ListaDocente *l, int id );
ListaDocente *remover_docente( ListaDocente *l, int id );
void mostrar_listaDocente( ListaDocente *l );
void liberar_listaDocente( ListaDocente *l );

//LISTA DISCENTE
ListaDiscente *criar_listaDiscente();
ListaDiscente *cadastrar_discente(ListaDiscente *l);
Discente *buscar_discente( ListaDiscente *l, int id );
ListaDiscente *remover_discente( ListaDiscente *l, int id );
void mostrar_listaDiscente( ListaDiscente *l );
void liberar_listaDiscente( ListaDiscente *l );


//FUNÇÕES ADICIONAIS
void alunos_de_um_orientador( ListaDiscente *l, int id_orientador );
void alunos_sem_orientador( ListaDiscente *l );
void mudar_orientador_de_um_aluno( ListaDocente *ldo, Discente *d, int id_orientador_novo );
int menu( ListaDocente **ldo, ListaDiscente **ldi );

 
#endif