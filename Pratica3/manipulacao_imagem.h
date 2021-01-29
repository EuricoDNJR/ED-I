#ifndef manipulacao_imagem_h
#define manipulacao_imagem_h
#include "imagem.h"


//FUNÇÕES ADICIONAIS
int decimal( int *v, int tam );
int media( int *v, int tam );
int mediana( int *v, int tam );

//Matriz
int **criar_matriz( int linha, int coluna );
void printa_matriz_quadrada(int **m, int tam);
void liberar_matriz( int **m, int linha );

//MANIPULACAO IMAGENS
int maximo_valor_imagem( Imagem *i, int *x, int *y );
int minimo_valor_imagem( Imagem *i, int *x, int *y );
float distancia_euclidian( int p1_x,int p1_y, int p2_x, int p2_y );
float distancia_manhattan( int p1_x,int p1_y, int p2_x, int p2_y);
Imagem *Local_Binary_Pattern( Imagem *i );
int **Matriz_de_Coocorrencia( Imagem *i, int dist, int angulo, int *tam );
Imagem *Filtro_da_media( Imagem *i );
Imagem *Filtro_da_mediana( Imagem *i );
void menu_manipulacao_imagem( Imagem **im );


#endif