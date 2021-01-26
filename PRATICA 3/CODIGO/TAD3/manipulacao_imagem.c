#include <stdio.h>
#include <stdlib.h>
#include "manipulacao_imagem.h"
#include "math.h"


//FUNÇÕES ADICIONAIS
int decimal( int *v, int tam ){

	if( tam == 1 )
		return v[tam-1] * pow( 2, tam-1 );

	return  ( v[tam-1] * pow( 2, tam-1 ) ) + decimal( v, tam-1 );

}

int media( int *v, int tam ){

	int i, cont=0, soma=0;

	for( i=0; i<tam; i++ ){

		if( v[i] != -1 ){
			cont++;
			soma += v[i];
		}

	}

	return soma / cont;

}

int mediana( int *v, int tam ){

	int i, j, aux, cont=0;

	for( i=1; i<tam; i++ ){
		for( j=0; j<tam-i; j++ ){
			if( v[j] > v[j + 1] ){
				aux = v[j];
				v[j] = v[j + 1];
				v[j + 1] = aux;
			}
		}
	}

	for(i=0; i<tam; i++){

		if( v[i] != -1 )
			cont++;//Quantas posições tem numeros
		
	}

	aux = 9 - cont;//Quantas posições não tem numeros
	if( cont % 2 == 0 )
		return ( v[ aux + (cont/2) ] + v[ aux + ((cont/2) - 1) ] ) / 2;
	else
		return v[ aux + (cont/2) ];

}

//MANIPULACAO IMAGENS
//Maximo e minimo valor retornam X e Y, que foi considerado o Inverso que j k
int maximo_valor_imagem( Imagem *i, int *x, int *y ){

	int j, k, max = valor_pixel( pixel_do_indice(i, 0, 0) );


	for( j=0; j<altura_imagem(i); j++ ){
		for( k=0; k<largura_imagem(i); k++ ){
			if( max < valor_pixel( pixel_do_indice(i, j, k) ) ){
				max = valor_pixel( pixel_do_indice(i, j, k) );
				if( x )
					*x = k;
				if( y )
					*y = j;
			}
		}
	}

	return max;

}

int minimo_valor_imagem( Imagem *i, int *x, int *y ){

	int j, k, min = valor_pixel( pixel_do_indice(i, 0, 0) );

	for( j=0; j<altura_imagem(i); j++ ){
		for( k=0; k<largura_imagem(i); k++ ){
			if( min > valor_pixel( pixel_do_indice(i, j, k) ) ){
				min = valor_pixel( pixel_do_indice(i, j, k) );
				if( x )
					*x = k;
				if( y )
					*y = j;
			}
		}
	}

	return min;

}

float distancia_euclidian( int p1_x,int p1_y, int p2_x, int p2_y ){

	int x = pow( p1_x - p2_x, 2 ),
		y = pow( p1_y - p2_y, 2 );

	return sqrt( x + y );

}

float distancia_manhattan( int p1_x,int p1_y, int p2_x, int p2_y){


	int x = abs( p1_x - p2_x ),
		y = abs( p1_y - p2_y );

	return x + y;

}

Imagem *Local_Binary_Pattern( Imagem *i ){

	int j, k, l, v[8], centro;
	Imagem *im = declarar_imagem( largura_imagem(i), altura_imagem(i) );

	for( j=0; j<altura_imagem(i); j++ ){
		for( k=0; k<largura_imagem(i); k++ ){

			centro = valor_pixel( pixel_do_indice( i, j, k ) );
			
			if( 0 <= j - 1 && 0 <= k - 1 )
				v[7] = valor_pixel( pixel_do_indice( i, j-1, k-1 ) );
			else
				v[7] = -1;

			if( 0 <= j - 1 )
				v[6] = valor_pixel( pixel_do_indice( i, j-1, k ) );
			else
				v[6] = -1;

			if( 0 <= j - 1  && k + 1 < largura_imagem(i) )
				v[5] = valor_pixel( pixel_do_indice( i, j-1, k+1 ) );
			else
				v[5] = -1;

			if( k + 1 < largura_imagem(i) )
				v[4] = valor_pixel( pixel_do_indice( i, j, k+1 ) );
			else
				v[4] = -1;

			if( j + 1< altura_imagem(i) && k + 1 < largura_imagem(i) )
				v[3] = valor_pixel( pixel_do_indice( i, j+1, k+1 ) );
			else
				v[3] = -1;

			if( j + 1 < altura_imagem(i) )
				v[2] = valor_pixel( pixel_do_indice( i, j+1, k ) );
			else
				v[2] = -1;

			if( j + 1 < altura_imagem(i) && 0 <= k - 1 )
				v[1] = valor_pixel( pixel_do_indice( i, j+1, k-1 ) );
			else
				v[1] = -1;

			if( 0 <= k - 1 )
				v[0] = valor_pixel( pixel_do_indice( i, j, k-1 ) );
			else
				v[0] = -1;


			for( l=0; l<8; l++ ){

				if( v[l] < centro )
					v[l] = 0;
				else
					v[l] = 1;
				
			}

			alterar_pixel( pixel_do_indice( im, j, k ), decimal( v, 8 ) );

		}
	}

	return im;

}

int **Matriz_de_Coocorrencia( Imagem *im, int dist, int angulo ){

	int i, j, k, l, aux_linha, aux_coluna, cont, 
		fim = maximo_valor_imagem(im, NULL, NULL) + 1, 
		**m = (int **)malloc( sizeof(int *) * fim );

	for( i=0; i<fim; i++ )
		*(m + i) =  (int *)malloc( sizeof(int) * fim );


	if( angulo == 0 ){
		aux_linha = 0;
		aux_coluna = dist ;
	}else if( angulo == 45 ){
		aux_linha = dist * -1;
		aux_coluna = dist ;
	}else if( angulo == 90 ){
		aux_linha = dist * -1;
		aux_coluna = 0;
	}else if( angulo == 135 ){
		aux_linha = dist * -1;
		aux_coluna = dist * -1;
	}


	for( i=0; i<fim; i++ ){
		for( j=0; j<fim; j++ ){

			cont = 0;

			for( k=0; k<altura_imagem(im); k++ ){
				for( l=0; l<largura_imagem(im); l++ ){

					if( valor_pixel(pixel_do_indice(im, k, l)) == i ){

						if( 0 <= k + aux_linha && k + aux_linha < altura_imagem(im) && 0 <= l + aux_coluna && l + aux_coluna < largura_imagem(im) ){

							if( valor_pixel( pixel_do_indice(im, k + aux_linha, l + aux_coluna) ) == j )
								cont++;

						}

					}

				}
			}

			m[i][j] = cont;

		}
	}

	return m;

}

Imagem *Filtro_da_media( Imagem *i ){

	int j, k, l, v[9];
	Imagem *im = declarar_imagem( largura_imagem(i), altura_imagem(i) );

	for( j=0; j<altura_imagem(i); j++ ){
		for( k=0; k<largura_imagem(i); k++ ){

			v[8] = valor_pixel( pixel_do_indice( i, j, k ) );
			
			if( 0 <= j - 1 && 0 <= k - 1 )
				v[7] = valor_pixel( pixel_do_indice( i, j-1, k-1 ) );
			else
				v[7] = -1;

			if( 0 <= j - 1 )
				v[6] = valor_pixel( pixel_do_indice( i, j-1, k ) );
			else
				v[6] = -1;

			if( 0 <= j - 1  && k + 1 < largura_imagem(i) )
				v[5] = valor_pixel( pixel_do_indice( i, j-1, k+1 ) );
			else
				v[5] = -1;

			if( k + 1 < largura_imagem(i) )
				v[4] = valor_pixel( pixel_do_indice( i, j, k+1 ) );
			else
				v[4] = -1;

			if( j + 1< altura_imagem(i) && k + 1 < largura_imagem(i) )
				v[3] = valor_pixel( pixel_do_indice( i, j+1, k+1 ) );
			else
				v[3] = -1;

			if( j + 1 < altura_imagem(i) )
				v[2] = valor_pixel( pixel_do_indice( i, j+1, k ) );
			else
				v[2] = -1;

			if( j + 1 < altura_imagem(i) && 0 <= k - 1 )
				v[1] = valor_pixel( pixel_do_indice( i, j+1, k-1 ) );
			else
				v[1] = -1;

			if( 0 <= k - 1 )
				v[0] = valor_pixel( pixel_do_indice( i, j, k-1 ) );
			else
				v[0] = -1;

			alterar_pixel( pixel_do_indice( im, j, k ), media( v, 9 ) );

		}
	}

	return im;

}

Imagem *Filtro_da_mediana( Imagem *i ){

	int j, k, l, v[9];
	Imagem *im = declarar_imagem( largura_imagem(i), altura_imagem(i) );

	for( j=0; j<altura_imagem(i); j++ ){
		for( k=0; k<largura_imagem(i); k++ ){

			v[8] = valor_pixel( pixel_do_indice( i, j, k ) );
			
			if( 0 <= j - 1 && 0 <= k - 1 )
				v[7] = valor_pixel( pixel_do_indice( i, j-1, k-1 ) );
			else
				v[7] = -1;

			if( 0 <= j - 1 )
				v[6] = valor_pixel( pixel_do_indice( i, j-1, k ) );
			else
				v[6] = -1;

			if( 0 <= j - 1  && k + 1 < largura_imagem(i) )
				v[5] = valor_pixel( pixel_do_indice( i, j-1, k+1 ) );
			else
				v[5] = -1;

			if( k + 1 < largura_imagem(i) )
				v[4] = valor_pixel( pixel_do_indice( i, j, k+1 ) );
			else
				v[4] = -1;

			if( j + 1< altura_imagem(i) && k + 1 < largura_imagem(i) )
				v[3] = valor_pixel( pixel_do_indice( i, j+1, k+1 ) );
			else
				v[3] = -1;

			if( j + 1 < altura_imagem(i) )
				v[2] = valor_pixel( pixel_do_indice( i, j+1, k ) );
			else
				v[2] = -1;

			if( j + 1 < altura_imagem(i) && 0 <= k - 1 )
				v[1] = valor_pixel( pixel_do_indice( i, j+1, k-1 ) );
			else
				v[1] = -1;

			if( 0 <= k - 1 )
				v[0] = valor_pixel( pixel_do_indice( i, j, k-1 ) );
			else
				v[0] = -1;

			alterar_pixel( pixel_do_indice( im, j, k ), mediana( v, 9 ) );

		}
	}

	return im;

}
	

