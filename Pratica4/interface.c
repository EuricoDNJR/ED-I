#include<stdio.h>
#include<stdlib.h>

#include"navio.h"
#include"container.h"
#include"carregar.h"
#include"score.h"
#include"interface.h"

struct container
{
//    ▪ Tamanho
    int tamanho;// 1 = grande (80 toneladas); 2 = médio (50toneladas); ou 3 = pequeno (35 toneladas).
    //<???>
    //▪ Tipo do Produto
    //<???>
    //▪ É perecível?
    int corozivo; //1 - sim, 0 - não
    //▪ É corrosivo?
    int perecivel; //1 - sim, 0 - não

};

struct lis_cont
{
    Container* info;
    struct lis_cont* prox; 
};

struct pil_cont
{
    Lis_Cont* topo;
};

struct navio
{
//▪ Capacidade em toneladas //máximo de 125 mínimo de 25
//deve-se usar um rand() para preenchimento obedecendo o
//intervalo acima.
    int capacidade;
//▪ Suporta cargas perecíveis?
    int sup_perecivel;//1 = sim, 0 = não
//▪ Suporta cargas corrosivas? //se suporta corrosivo não pode carregar perecível e vice-versa.
    int sup_corrozivo;//1 = sim, 0 = não
//▪ Containers * (inserir o(s) container(s) desde navio)
    Pil_Cont *c;
};

struct lista_nav
{
    Navio *info;
    struct lista_nav *prox;
};


struct fila_nav
{
    Lista_Nav* inicio;
    Lista_Nav* fim;
};


void inicializar()
{
    int op, op2, tamanho_container, corrozivo = 0, perecivel = 0;
    float score = 0;
    Pil_Cont *p1;
    Pil_Cont *p2;
    int rm, rm2;
    Container *cont_rm;
    Navio *n_rm;
    Fila_Nav *navios;
    Lista_Nav *aux;

    while(1){
        printf("===================================\n");
        printf("PORTO:\n");
        printf("1 - Criar o espaco PILHA\n");
        printf("2 - Abrir FILA de Navios\n");  
        printf("3 - Cadastrar_CONTAINER\n");
        printf("4 - Cadastrar_NAVIO\n");
        printf("5 - Remover\n");
        printf("6 - Mostar Containers na PILHA\n");
        printf("7 - Mostrar navios na FILA\n");
        printf("8 - Mostar os containes embarcados no NAVIOS\n");
        printf("9 - Carregar\n");
        printf("10 - Liberar FILA\n");
        printf("11 - Liberar PILHA\n");
        printf("12 - Sair\n");
        printf("==================================\n");
        printf("O que deseja fazer:");scanf("%d",&op);
        switch (op)
        {
        case 1:
            /* Criar o espaco PILHA */
            p1 = criaPilha();
            p2 = criaPilha();
            printf("==================================\n");
            printf("Pilha criada com sucesso!\n");
            printf("Precione uma tecla para continuar\n");
            printf("==================================\n");
            break;
        case 2:
            /* Abrir FILA de Navios */
            navios = criaFila();
            printf("FILA CRIADA COM SUCESSO!\n");
            break;
        case 3:
            /* Cadastrar_CONTAINER */
            printf("==================================\n");
            printf("Informe o tamanho\n");
            printf("1 - 80 TONELADAS\n");
            printf("2 - 50 TONELADAS\n");
            printf("3 - 35 TONELADAS\n");
            scanf("%d", &op2);
            if(op2 == 1){
                tamanho_container = 1;
                printf("Ele e perecivel?(0 - NAO, 1 - SIM)\n");
                scanf("%d", &perecivel);
                if (perecivel == 1)
                {
                    Cadastrar_Container(p1,tamanho_container,perecivel,0);
                    printf("CONTAINER QUE SUPORTA PERECIVEIS DE 80 TONELADAS CADASTRADO!\n");
                }else
                {
                    if (perecivel == 0)
                    {
                        printf("Ele e corrozivo?(0 - NAO, 1 - SIM)\n");
                        scanf("%d", &corrozivo);
                        if (corrozivo == 1)
                        {
                            Cadastrar_Container(p1,tamanho_container,perecivel,corrozivo);
                            printf("CONTAINER QUE SUPORTA CORROZIVOS DE 80 TONELADAS CADASTRADO!\n");
                        }else
                        {
                            if (corrozivo == 0)
                            {
                                Cadastrar_Container(p1,tamanho_container,perecivel,corrozivo);
                                printf("CONTAINER NORMAL DE 80 TONELADAS CADASTRADO!\n");
                            }
                            
                        } 
                        
                    }
                    
                } 
            }
            else if(op2 == 2){
                tamanho_container = 2;
                printf("Ele e perecivel?(0 - NAO, 1 - SIM)\n");
                scanf("%d", &perecivel);
                if (perecivel == 1)
                {
                    Cadastrar_Container(p1,tamanho_container,perecivel,0);
                    printf("CONTAINER QUE SUPORTA PERECIVEIS DE 50 TONELADAS CADASTRADO!\n");
                }else
                {
                    if (perecivel == 0)
                    {
                        printf("Ele e corrozivo?(0 - NAO, 1 - SIM)\n");
                        scanf("%d", &corrozivo);
                        if (corrozivo == 1)
                        {
                            Cadastrar_Container(p1,tamanho_container,perecivel,corrozivo);
                            printf("CONTAINER QUE SUPORTA CORROZIVOS DE 50 TONELADAS CADASTRADO!\n");
                        }else
                        {
                            if (corrozivo == 0)
                            {
                                Cadastrar_Container(p1,tamanho_container,perecivel,corrozivo);
                                printf("CONTAINER NORMAL DE 50 TONELADAS CADASTRADO!\n");
                            }
                        }
                            
                    }
                } 
            }
            else if(op2 == 3){
                tamanho_container = 3;
                printf("Ele e perecivel?(0 - NAO, 1 - SIM)\n");
                scanf("%d", &perecivel);
                if (perecivel == 1)
                {
                    Cadastrar_Container(p1,tamanho_container,perecivel,0);
                    printf("CONTAINER QUE SUPORTA PERECIVEIS DE 35 TONELADAS CADASTRADO!\n");
                }else
                {
                    if (perecivel == 0)
                    {
                        printf("Ele e corrozivo?(0 - NAO, 1 - SIM)\n");
                        scanf("%d", &corrozivo);
                        if (corrozivo == 1)
                        {
                            Cadastrar_Container(p1,tamanho_container,perecivel,corrozivo);
                            printf("CONTAINER QUE SUPORTA CORROZIVOS DE 35 TONELADAS CADASTRADO!\n");
                        }else
                        {
                            if (corrozivo == 0)
                            {
                                Cadastrar_Container(p1,tamanho_container,perecivel,corrozivo);
                                printf("CONTAINER NORMAL DE 35 TONELADAS CADASTRADO!\n");
                            }
                            
                        }
                    }
                }
            }
            else
            {
                printf("OPCAO INVALIDA!\n");
            }
            
            break;
        case 4:
            /* Cadastrar_NAVIO */
            printf("Navio suporta pereciveis?(0 - NAO, 1 - SIM)\n");
            scanf("%d", &perecivel);
            if (perecivel == 1)
            {
                Cadastrar_Navio(navios, perecivel, 0);
                printf("NAVIO QUE SUPORTA PERECIVEIS CADASTRADO!\n");
            }else
            {
                if (perecivel == 0)
                {
                    Cadastrar_Navio(navios, perecivel, 1);
                    printf("NAVIO QUE SUPORTA CORROZIVOS CADASTRADO!\n");
                }
                
            }
            
            break;
        case 5:
            /* Remover */
            printf("==================================\n");
            printf("Prentende remover um: \n");
            printf("Container da pilha(0)\n");
            printf("Navio da fila(1)");
            printf("Qual deseja:");scanf("%d",&rm);
            printf("==================================\n");
            switch (rm)
            {
                case 0:
                    printf("==================================\n");
                    printf("Deseja remover de qual pilha?\n");
                    printf("Pilha Principal(0).");
                    printf("Pilha Auxiliar(1).");
                    printf("Qual deseja:");scanf("%d",&rm2);
                    printf("==================================\n");
                    switch (rm2)
                    {
                    case 0:
                        
                        cont_rm = Remover_Pilha(p1);
                        printf("==================================\n");
                        printf("Pilha Principal:\n");
                        printf("Valor removido:\n");
                        _mostrar_container(cont_rm);
                        Mostra_Pilha(p1);
                        printf("==================================\n");
                        break;

                    case 1:
                        cont_rm = Remover_Pilha(p2);
                        printf("==================================\n");
                        printf("Pilha Auxiliar:\n");
                        printf("Valor removido:\n");
                        _mostrar_container(cont_rm);
                        Mostra_Pilha(p2);
                        printf("==================================\n");
                        break;
                    
                    default:
                        printf("Valor invalido!\n");
                        break;
                    }
                    break;    
                case 1:
                    
                    n_rm = Remover_Fila(navios);
                    printf("==================================\n");
                    printf("Valor removido:\n");
                    _mostrar_navio(n_rm);
                    printf("==================================\n");
                    break;

                default:
                    printf("Numero informado invalido");
                    break;
            }

            
            break;
        case 6:
            /**/
            
            
            printf("==================================\n");
            printf("Qual pilha deseja Mostrar:\n");
            printf("Pilha Principal(0).");
            printf("Pilha Auxiliar(1).");
            printf("Qual deseja:");scanf("%d",&rm);
            printf("==================================\n");
            switch (rm)
                    {
                    case 0:

                        printf("==================================\n");
                        printf("Pilha Principal:\n");
                        Mostra_Pilha(p1);
                        printf("==================================\n");
                        break;

                    case 1:

                        printf("==================================\n");
                        printf("Pilha Auxiliar:\n");
                        Mostra_Pilha(p1);
                        printf("==================================\n");
                        
                    break;
                    
                    default:
                        printf("Valor invalido!\n");
                        break;
                    }
            
            
            break;
        case 7: 
            printf("==================================\n");
            printf("Navios no porto:\n");
            Mostra_Fila(navios);
            printf("==================================\n");
            
           break;

        case 8:
            /* Mostar os containes embarcados no NAVIOS*/ 
            printf("==================================\n");
            printf("Navios no porto e seus containers:\n");
            aux = navios->inicio;
            while (aux!=NULL)
            {
                Mostra_containers_do_navio(aux->info);
                aux = aux->prox;
                printf("\n");
            }
            
            printf("==================================\n");
            
            break;
            
        case 9:
            /* CARREGAR*/
            carregar(p1, p2, navios, &score);
            printf("======================\n");
            printf("SCORE = %.2f\n",score);
            printf("======================\n");
            break;
        case 10:
            fila_libera(navios);
            break;
        case 11:
            pilha_libera(p1);
            pilha_libera(p2);
            break;
        case 12:
            return;
            break;
        default:
            printf("Numero informado invalido\n");
            
            break;
        }
    }
}
 
