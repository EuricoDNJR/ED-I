#ifndef score_h
#define score_h

typedef struct navio Navio;

typedef struct lista_nav Lista_Nav;

typedef struct fila_nav Fila_Nav;

typedef struct container Container;

typedef struct pil_cont Pil_Cont;

typedef struct lis_cont Lis_Cont;


//Mais 2 pontos por tonelada de container no navio
void score_tonelada(Navio *n,float *score);

//-0.5 por espaço livre
void score_espa_vazio(Navio *n,float *score);

//Desempilhagem desnecessaria
void score_desempilhagem(Container *c,float *score);

//Desenfileiramento desnecessario
void score_desenfileragem(Navio *na,float *score);

#endif /* score.h */