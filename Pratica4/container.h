#ifndef container_h
#define container_h

typedef struct container Container;

typedef struct pil_cont Pil_Cont;

typedef struct lis_cont Lis_Cont;

//cirar pilha
Pil_Cont* criaPilha();

//inserir
void _inserir_conteiner(Pil_Cont *pilha, Container *info);


//1 – Cadastro
void Cadastrar_Container(Pil_Cont *pilha,int tamanho,int perecivel,int corrosivo);

//2 – Remover
Container* Remover_Pilha(Pil_Cont *pilha);

//*Verifica de tem container nas filas
int _pilhaVazia(Pil_Cont *pilha);

//3 – Impressão
void Mostra_Pilha(Pil_Cont *pilha);
    
void _mostrar_container(Container *c);

void pilha_libera (Pil_Cont* p_c);




#endif /* container.h */