#ifndef navio_h
#define navio_h

typedef struct navio Navio;

typedef struct lista_nav Lista_Nav;

typedef struct fila_nav Fila_Nav;

//criar fila navil
Fila_Nav *criaFila();

//inseriri navio na fila
void _insere_navio(Fila_Nav* fila, Navio *info);

//1 – Cadastro Navio
void Cadastrar_Navio(Fila_Nav* fila,int sup_perecivel, int sup_corrozivo);

//2 – Remover Navio
Navio* Remover_Fila(Fila_Nav *fila);



//Mostrar navio especifico
void _mostrar_navio(Navio *n);


//3 – Impressão Todos os navios
void Mostra_Fila(Fila_Nav *fila);

//*mostrar container nos navios
void Mostra_containers_do_navio(Navio *n);

//mostrar todos os navios com os containers
void Mostra_Fila_com_containers(Fila_Nav *fila);

//Verifica se tem navios na fila
int _filaVazia(Fila_Nav *fila);

//liberar fila
void fila_libera(Fila_Nav* f);

//liberar navio
void lista_liberada_navio(Navio* n);



#endif /* navio.h */