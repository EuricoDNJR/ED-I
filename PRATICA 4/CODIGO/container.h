#ifndef container_h
#define container_h

typedef struct container Container;

typedef struct pil_cont Pil_Cont;

typedef struct lis_cont Lis_Cont;

//cirar pilha
Pil_Cont* criaPilha();


//1 – Cadastro
void Cadastrar_Container(Pil_Cont *pilha,int tamanho,int perecivel,int corrosivo);

//2 – Remover
Container* Remover_Pilha(Pil_Cont *pilha);

//3 – Impressão
void Mostra_Pilha(Pil_Cont *pilha);
    

#endif /* container.h */