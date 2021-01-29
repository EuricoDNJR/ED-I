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

//LER STRING ADICIONANDO .txt no final
char *ler_string_imagem(){

	char *s = (char *)malloc( sizeof(char) );
	int i=0, j=0;

	while( ( s[i] = getchar() ) != '\n' ){
		i++;
		s = (char *)realloc( s, sizeof(char) * (i+1) );
	}

	s = (char *)realloc( s, sizeof(char) * (i+5) );

	s[i] = '.';
	s[i+1] = 't';
	s[i+2] = 'x';
	s[i+3] = 't';
	s[i+4] = 0;

	return s;

}


//PIXEL
Pixel criar_pixel(){

	Pixel p;

	p.pixel_value = rand() % 256;

	return p;

}

void definir_valor_pixel( Pixel *p, int valor ){

	p->pixel_value = valor;

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

	return NULL;

}

Imagem *criar_imagem_com_valores(){

	Imagem *i = NULL;
	int j, k, largura, altura;

	printf("Dimensao da imagem (Largura Altura): "); scanf("%d %d", &largura, &altura);

	if( largura > 0 && altura > 0){

		i = declarar_imagem(largura, altura);

		for( j=0; j<i->altura; j++ ){
			for( k=0; k<i->largura; k++ )
				i->pixels_imagem[ (i->altura * j) + k ] = criar_pixel();
			
		}

		return i;
	}
	
	return NULL;

}

Imagem *carregar_imagem( const char *nome ){

	FILE *arq = fopen( nome , "r" );
	Imagem *i = NULL;
	int j, k, largura, altura, aux;


	if( arq ){
			
		fscanf( arq, "%d %d", &altura, &largura );

		i = declarar_imagem(largura, altura);	

		for( j=0; j<i->altura; j++ ){
			for( k=0; k<i->largura; k++ )
				fscanf( arq, " %d", &aux );
                definir_valor_pixel( i->pixels_imagem + (i->altura * j) + k, aux);
			
		}

		fclose( arq );

	}

	return i;

}

void salvar_imagem( Imagem *i, const char *nome ){

	int j, k, largura, altura;
	FILE *arq;


	if( i ){

		arq = fopen( nome, "w" );

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

	if( i ){

		Imagem *im = declarar_imagem( i->largura, i->altura );

		for( j=0; j<i->altura; j++ ){
			for( k=0; k<i->largura; k++ )
				im->pixels_imagem[ (i->altura * j) + k ] = i->pixels_imagem[ (i->altura * j) + k ];
		
		}

		return im;

	}

	return i;

}

void mostrar_imagem( Imagem *i ){

	int j, k;

	if( i ){

		for(j=0; j<i->altura; j++){
			for(k=0; k<i->largura; k++)
				printf("%3d ", valor_pixel( i->pixels_imagem + (i->altura * j) + k  ));
			printf("\n");
		}

		printf("\n");

	}
}

void liberar_imagem( Imagem *i ){

	if( i ){

		free(i->pixels_imagem);
		free(i);
		
	}

}

void menu_imagem( Imagem **im, Imagem **im_copia ){

	int op;
	char *s = NULL;

	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("1 - Criar imagem(Com valores)\n" );
	printf("2 - Carregar imagem\n" );
	printf("3 - Salvar imagem\n");
	printf("4 - Criar copia da imagem\n");
	printf("5 - Salvar copia da imagem\n");
	printf("6 - Mostrar imagem\n");
	printf("\n");
	printf("Opcao: "); scanf("%d", &op);
	printf("\n\n");

	if( op == 1 )
		*im = criar_imagem_com_valores();
	else if( op == 2 ){
		printf("Digite o nome da imagem(Ex: imagem): ");
		setbuf(stdin, NULL);
		s = ler_string_imagem();

		*im = carregar_imagem(s);

		free(s);
	}else if( op == 3 ){
		printf("Digite o nome da imagem(Ex: imagem): ");
		setbuf(stdin, NULL);
		s = ler_string_imagem();

		salvar_imagem(*im, s);

		free(s);
	}else if( op == 4 )
		*im_copia = criar_copia_imagem(*im);
	else if( op == 5 )
		salvar_imagem(*im_copia, "copia_imagem.txt");
	else if( op == 6 )
		mostrar_imagem( *im );

	printf("\n");

}
