#ifndef carregar_h
#define carregar_h

typedef struct navio Navio;

typedef struct lista_nav Lista_Nav;

typedef struct fila_nav Fila_Nav;

typedef struct container Container;

typedef struct pil_cont Pil_Cont;

typedef struct lis_cont Lis_Cont;


//*Desempilhar
void desempilhar(Pil_Cont *pil_origem,Pil_Cont *pil_destino);

//*Desenfileirar
void desenfilerar(Fila_Nav *f);

//*Compara o topo da pilha com inicio da fila
int compativel_cont_nav(Container *c,Navio *n);

//*Saber se o vavio tem espaço
int nav_tem_espaco(Navio *n, Container *c);

//*Retornar o valor do container
int retorna_tamanho_container(Container *c);

//verificar se na fila tem container perecivel
int _tem_cont_perecivel(Pil_Cont *p1);

//Retorna o priemiro container com as caracteristicas desejadas
Container* _retorna_container(Pil_Cont *p1,int perecivel, int corrosivo);

//processo de priorizar os containers pereciveis
int _prioridade_perecivel(Fila_Nav *n, Pil_Cont *p1, Pil_Cont *p2, float *score);

//Verirfica compatipilidade de um navio com uma pilha
int nav_comp_pilha(Pil_Cont *p,Navio *n);

//*Carregamernto
void carregar(Pil_Cont *p1, Pil_Cont *p2, Fila_Nav *n, float *score);

//compara uma pilha e uma lista e ve se elas são compativeis
int _pilha_comp_fila(Pil_Cont *p, Fila_Nav *c);

#endif /* carregar.h */