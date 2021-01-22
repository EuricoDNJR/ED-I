#include <stdio.h>
#include <stdlib.h>

#include "cadastro.h"

int main(){
    Docente *d;
    Discente *di;
    int qnt_p = 0;
    int qnt_do = 0;
    int qnt_di = 0;


    d = criar_docente();
    di = criar_discente();
    char nome[] = {'c', 'a', 'r', 'l', 'o', 's'};

    qnt_p += 1;
    qnt_do += 1;
    cadastra_docente(d, &qnt_do, &qnt_p, nome, 30, 0, 0);
    
    qnt_di += 1;
    cadastrar_discente(di, d, &qnt_di, &qnt_do, &qnt_p, nome, 18, 1, nome, 123);


    return 0;
}