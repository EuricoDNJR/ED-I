#ifndef navio_h
#define navio_h

typedef struct navio Navio;

typedef struct lista_nav Lista_Nav;

typedef struct fila_nav Fila_Nav;

//criar fila navil
Fila_Nav *criaFila();

//1 – Cadastro Navio
void Cadastrar_Navio(Fila_Nav* fila,int sup_perecivel, int sup_corrozivo);

//2 – Remover Navio
Navio* Remover_Fila(Fila_Nav *fila);


//3 – Impressão Todos os navios
void Mostra_Fila(Fila_Nav *fila);


//● Containers de um determinado navio


#endif /* navio.h */