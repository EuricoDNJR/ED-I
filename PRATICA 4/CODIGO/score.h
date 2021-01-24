#ifndef score_h
#define score_h

typedef struct navio Navio;

typedef struct container Container;

//Mais 2 pontos por tonelada de container no navio
void score_tonelada(int soma_tonelada,int *score);
//-0.5 por espaço livre
void score_espa_vazio(int num_esp_livre,int *score);
//Desempilhagem desnecessaria
void score_desempilhagem(int tonelada,int *score);
//Desenfileiramento desnecessario
void score_desenfileragem(int tonelada,int *score);

#endif /* score.h */