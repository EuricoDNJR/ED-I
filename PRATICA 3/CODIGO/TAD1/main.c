#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cadastro.h"

int main(){

	srand( time(NULL) );

	ListaDocente *ldo = criar_listaDocente();
	ListaDiscente *ldi = criar_listaDiscente();

	while( menu(&ldo, &ldi) );

}
