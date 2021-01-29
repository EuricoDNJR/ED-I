#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cadastro.h"
#include "manipulacao_imagem.h"

int main(){

	srand( time(NULL) );

	int op;

	ListaDocente *ldo = criar_listaDocente();
	ListaDiscente *ldi = criar_listaDiscente();
	
	Imagem *im = criar_imagem(),
		   *copia_im = criar_imagem();

	do{

		printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
		printf("1 - Cadastro\n" );
		printf("2 - Imagem\n");
		printf("3 - Manipulacao da imagem\n");
		printf("4 - Sair\n");
		printf("\n");
		printf("Opcao: "); scanf("%d", &op);
		printf("\n\n");

		if( op == 1 ){
			menu_cadastro( &ldo, &ldi );
		}else if( op == 2 ){
			if( login(ldo, ldi) )
				menu_imagem( &im, &copia_im );
		}else if( op == 3 ){
			if( login(ldo, ldi) )
				menu_manipulacao_imagem( &im );
		}

	}while( op != 4 );

	liberar_listaDocente(ldo);
	liberar_listaDiscente(ldi);
	liberar_imagem(im);
	liberar_imagem(copia_im);
	
}

