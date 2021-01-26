#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cadastro.h"
#include "manipulacao_imagem.h"


int main(){

	srand( time(NULL) );
	int v, x1, x2, y1, y2;

	Imagem *i = carregar_imagem( "img.txt" ),
		   *im = NULL;

	int **m = NULL;

	/*
	ListaDocente *ldo = criar_listaDocente();
	ListaDiscente *ldi = criar_listaDiscente();

	while( menu(&ldo, &ldi) );

	liberar_listaDocente(ldo);
	liberar_listaDiscente(ldi);
	*/

	mostrar_imagem( i );

	v = maximo_valor_imagem( i, &x1, &y1 );
	printf("Maximo: %d Coords = %d %d\n", v, x1, y1);

	v = minimo_valor_imagem( i, &x2, &y2 );
	printf("Minimo: %d Coords = %d %d\n", v, x2, y2);

	printf("Distancia euclidian: %.2f\n", distancia_euclidian( x1, y1, x2, y2 ) );
	printf("Distancia manhattan: %.2f\n", distancia_manhattan( x1, y1, x2, y2 ) );
	printf("\n");

	im = Local_Binary_Pattern( i );

	mostrar_imagem( im );

	m = Matriz_de_Coocorrencia( i, 2, 135 );

	y1 = maximo_valor_imagem( i, NULL, NULL ) + 1;

	for( x1 = 0; x1 < y1 ; x1++ ){
		for( x2=0; x2 < y1 ; x2++ )
			printf("%d ", m[x1][x2]);
		printf("\n");
		free( *(m + x1) );
	}
	free(m);
	printf("\n");

	im = Filtro_da_media( i );

	mostrar_imagem( im );

	im = Filtro_da_mediana( i );

	mostrar_imagem( im );

	liberar_imagem( i );
	liberar_imagem( im );

}
