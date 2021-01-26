#include <stdio.h>
#include <stdlib.h>
#include "imagem.h"


//STRUCTS
struct pixel{
    int pixel_value;//variar de 0 ate 255 usar rand();
};

struct imagem {
    int altura, largura; 
    Pixel *pixels_imagem; 
};


//PIXEL
Pixel criar_pixel(){

	Pixel p;

	p.pixel_value = rand() % 256;

	return p;

}

int valor_pixel( Pixel *p ){

	return p->pixel_value;

}


Pixel *pixel_do_indice(Imagem *i, int j, int k){

	return i->pixels_imagem + ((i->altura * j) + k);

}

void alterar_pixel( Pixel *p, int valor ){

	p->pixel_value = valor;

}


//GET IMAGEM
int altura_imagem( Imagem *i ){

	return i->altura;

}

int largura_imagem( Imagem *i ){

	return i->largura;
}


//IMAGEM
Imagem *declarar_imagem(int largura, int altura){

	Imagem *i = (Imagem *)malloc( sizeof( Imagem ) );

	i->altura = altura;
	i->largura = largura;
	i->pixels_imagem = (Pixel *)malloc( sizeof(Pixel) * altura * largura );

	return i;

}

Imagem *criar_imagem(){

	Imagem *i = NULL;
	int j, k, largura, altura;

	printf("Dimensao da imagem (Largura Altura): "); scanf("%d %d", &largura, &altura);

	i = declarar_imagem(largura, altura);

	for( j=0; j<i->altura; j++ ){
		for( k=0; k<i->largura; k++ )
			i->pixels_imagem[ (i->altura * j) + k ] = criar_pixel();
		
	}

	return i;

}

Imagem *carregar_imagem( const char *nome ){

	FILE *arq = fopen( nome , "r" );
	Imagem *i = NULL;
	int j, k, largura, altura;


	if( arq ){
			
		fscanf( arq, "%d %d", &altura, &largura );

		i = declarar_imagem(largura, altura);	

		for( j=0; j<i->altura; j++ ){
			for( k=0; k<i->largura; k++ )
				fscanf( arq, " %d", &i->pixels_imagem[ (i->altura * j) + k ] );
			
		}

		fclose( arq );

	}

	return i;

}

void salvar_imagem( Imagem *i, const char *nome ){

	int j, k, largura, altura;
	FILE *arq = fopen( nome, "w" );


	if( arq ){

		fprintf( arq, "%d %d\n", i->altura, i->largura );

		for( j=0; j<i->altura; j++ ){
			for( k=0; k<i->largura; k++ )
				fprintf( arq, "%d ", valor_pixel( i->pixels_imagem + ((j * i->altura) + k) ) );
			fprintf( arq, "\n" );

		}

		fclose( arq );

	}

}

Imagem *criar_copia_imagem( Imagem *i ){

	int j, k;
	Imagem *im = declarar_imagem( i->largura, i->altura );

	for( j=0; j<i->altura; j++ ){
		for( k=0; k<i->largura; k++ )
			im->pixels_imagem[ (i->altura * j) + k ] = i->pixels_imagem[ (i->altura * j) + k ];
	
	}

	return im;

}

void salvar_copia_imagem( Imagem *i, const char *nome );

void mostrar_imagem( Imagem *i ){

	int j, k;

	for(j=0; j<i->altura; j++){
		for(k=0; k<i->largura; k++)
			printf("%3d ", i->pixels_imagem[ (i->altura * j) + k ]);
		printf("\n");
	}

	printf("\n");

}

void liberar_imagem( Imagem *i ){

	free(i->pixels_imagem);
	free(i);

}
