//*Um orientador pode orientar até 10 alunos, sendo, 40% de graduação e 60% a 
//nível de pós-graduação (mestrado e doutorado)

#ifndef cadastro_h
#define cadastro_h

typedef struct pessoa Pessoa;
typedef struct docente Docente;
typedef struct discente Discente;



/*
cadastrar, 
remover, 
altarar, 
buscar e 
mostrar)

listar alunos de um determinado orientador; 
listar alunos que não possuem orientador; 
mudar orientador de um determinado aluno

*/

//Criando documento
Docente* criar_docente();
Discente* criar_discente();

//Cadastrando docente
void cadastra_docente(Docente *d, int *qtd_docentes, int *qtd_pessoas, char *nome, int idade, int qtd_orientecoes_graduacao, int qtd_orientecoes_pos_graduacao);
void cadastrar_discente(Discente *d, Docente *doc, int *qtd_discentes, int *qtd_docentes, int *qtd_pessoas, char *nome, int idade, int nivel, char *nome_curso, int senha);
int _orientador_existe(int num_orientador, Docente *doc, int *qtd_docentes);
void mostra_docentes(Docente *doc,int *qtd_docentes); 
void _mostrar_teste_docente(Docente *d);
void _mostrar_teste_discente(Discente *d);

#endif /* cadastro.h */