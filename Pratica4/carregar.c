#include<stdio.h>
#include<stdlib.h>

#include"navio.h"
#include"container.h"
#include"carregar.h"
#include"score.h"

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

//*Desempilhar
void desempilhar(Pil_Cont *pil_origem,Pil_Cont *pil_destino)
{
    Container *valor;
    valor = Remover_Pilha(pil_origem);
    _inserir_conteiner(pil_destino,valor);
}

//*Desenfileirar
void desenfilerar(Fila_Nav *f)
{
    Navio *valor; 
    valor = Remover_Fila(f);
    _insere_navio(f,valor);
    
}

int retorna_tamanho_container(Container *c)
{

    switch (c->tamanho)
    {
        case 1:
            return 80;
        case 2:
            return 50;
        case 3:
            return 35;
        default:
            printf("Tamanho informado Invalido!\n");
            printf("Conteiner não pode sair do porto!\n");
            return 200;
    }

}

//*Saber se o navio tem espaço
int nav_tem_espaco(Navio *n, Container *c)
{
    
    Lis_Cont *aux;
    aux = n->c->topo;
    int i;
    int soma=0;
    int num;
    
    while (aux != NULL)
    {
        
        num = retorna_tamanho_container(aux->info);
        soma = soma + num;
        aux = aux->prox;
        
    }

    if (retorna_tamanho_container(c) <= (n->capacidade - soma))
    {
        return 1;
    }
    
    return 0;
    
}


//*Compara o topo da pilha com inicio da fila
int comp_topo_cont_nav(Pil_Cont *pi_cont, Navio *n)
{
    if((pi_cont->topo->info->perecivel == n->sup_perecivel)||(pi_cont->topo->info->corozivo == n->sup_corrozivo))
    {
        if(nav_tem_espaco(n, pi_cont->topo->info)){
            return 1;
        }else
        {
            return 0;
        }
        
    }else
    {
        return 0;
    }
    
}

//TA ERRADO
int _tem_cont_perecivel(Pil_Cont *p1)
{
    Lis_Cont *aux;
    aux = p1->topo;
    
    while(1)
    {
        if(aux == NULL)
        {
            return 0;
        }
        if(aux->info->perecivel==1)
        {
            return 1;
        }
        aux = aux->prox;
        
        
    } 
    
}

//retorna um container com as caracteristicas desejadas
Container* _retorna_container(Pil_Cont *p1,int perecivel,int corrosivo)
{
    Lis_Cont *aux;
    aux = p1->topo;
    if (perecivel == 1)
    {
        while(aux != NULL){
            if(aux->info->perecivel == 1){
                return aux->info;
            }
            aux = aux->prox;
        }
    }else
    {
        if (corrosivo == 1)
        {
            while(aux != NULL){
                if(aux->info->corozivo == 1){
                    return aux->info;
                }
                aux = aux->prox;
            }
        }else
        {
            while(aux != NULL){
                if(aux->info->corozivo == 0 && aux->info->perecivel == 0){
                    return aux->info;
                }
                aux = aux->prox;
            }
        }
    }
    
    return NULL;
}

//da prioridade aos containes pereciveis
int _prioridade_perecivel(Fila_Nav *n, Pil_Cont *p1, Pil_Cont *p2, float *score)
{
    Container *c;
    
    int s_p = n->inicio->info->sup_perecivel;

    
    if(s_p == 1)
    {
        
        if(_tem_cont_perecivel(p1))
        {
              
            c = _retorna_container(p1,1,0);
            
            if(nav_tem_espaco(n->inicio->info,c))
            {

                while(p1->topo->info->perecivel != 1 ){
                    score_desempilhagem(p1->topo->info,score);
                    desempilhar(p1,p2);

                }
                
                desempilhar(p1,n->inicio->info->c);

                return 1;

            }else
            {
                return 0;
            }
        }else
        {
            
            if(_tem_cont_perecivel(p2))
            {
                c = _retorna_container(p2,1,0);
                if(nav_tem_espaco(n->inicio->info,c))
                {
                    while(p2->topo->info->perecivel != 1 ){
                        
                        score_desempilhagem(p1->topo->info,score);
                        desempilhar(p2,p1);

                    }
                    desempilhar(p2,n->inicio->info->c);
                    return 1;
                }else
                {
                    return 0;
                }
            }else
            {
                return 0;
            }
        }
    }else
    {
        return 0;
    }
}

//verifica se tem conteiners compativel com a fila
int _pilha_comp_fila(Pil_Cont *p, Fila_Nav *c)
{
    if (_pilhaVazia(p))
    {
        return 0;
    }
    Lis_Cont *aux_c;
    aux_c = p->topo;
    Lista_Nav *aux_n;
    aux_n = c->inicio;
    
    //contar os containers de cada tipo
    while(aux_n!=NULL)
    {
        if(comp_topo_cont_nav(p,aux_n->info))
        {
            
            return 1;
        }
        aux_n = aux_n->prox;
        
    }
    return 0;

    

}

int nav_comp_pilha(Pil_Cont *p,Navio *n)
{
    
    int flag = 0;

    Lis_Cont *aux_c;
    aux_c = p->topo;
    Lista_Nav *aux_n;
    
    
    while(aux_c!=NULL)
    {
        if(aux_c->info->perecivel == n->sup_perecivel)
        {
            
            if(aux_c->info->corozivo == n->sup_corrozivo)
            {
                if(nav_tem_espaco(n,aux_c->info))
                {
                    flag = 1;
                    break;
                }
            }
        }
        aux_c = aux_c->prox;
    }

    if(flag == 1)
    {
        return 1;
    }
    return 0;
    
}

int espaco_disponievl(Navio *n)
{
    Lis_Cont *aux;
    aux = n->c->topo;
    int soma=0;
    
    
    while(aux != NULL)
    {
        soma = soma + aux->info->tamanho;
        aux = aux->prox;
    }

    return n->capacidade - soma;
}

int espaco_usado(Navio *n)
{
    Lis_Cont *aux;
    aux = n->c->topo;
    int soma=0;
    

    while(aux != NULL)
    {
        soma = soma + aux->info->tamanho;
        aux = aux->prox;
    }

    
    return soma;
}


void carregar(Pil_Cont *p1, Pil_Cont *p2, Fila_Nav *n, float *score)
{
    //variaveis:
    Pil_Cont *aux_1,*aux_2,*aux_3 = NULL;
    Navio *aux_n;
    Lista_Nav *aux_l_n;
    Lis_Cont *aux_l_c;
    aux_1 = p1;
    aux_2 = p2;
    Navio *valor;

    while(1)
    {
        if(_filaVazia(n))
        {
            printf("Navios acabaram!\n");
            break;
        }else
        {
            if(_pilhaVazia(p1))
            {
                if(_pilhaVazia(p2))
                {
                    printf("Containers acabaram!\n");
                    while(n->inicio != NULL){

                        Mostra_containers_do_navio(n->inicio->info);    
                        printf("Navio acabou de zarpar\n");
                        printf("\n");
                        score_tonelada(n->inicio->info,score);
                        score_espa_vazio(n->inicio->info,score);
                        valor=Remover_Fila(n);
                        lista_liberada_navio(valor);

                    }
                    break;
                }else
                {
                    if (_prioridade_perecivel(n,p1,p2,score))
                    {
                    }else
                    {
                        if(comp_topo_cont_nav(p2,n->inicio->info))
                        {
                            desempilhar(p2,n->inicio->info->c);
                        }else
                        {
                            if(_pilha_comp_fila(p1,n)== 1  || _pilha_comp_fila(p2,n) == 1)
                            {
                                if(nav_comp_pilha(p2,n->inicio->info))
                                {
                                    while(_pilhaVazia(p2) != 1)
                                    {
                                        if(comp_topo_cont_nav(p2,n->inicio->info))
                                        {
                                            desempilhar(p2,n->inicio->info->c);
                                            break;
                                        }
                                        score_desempilhagem(p2->topo->info,score);
                                        desempilhar(p2,p1);
                                    }

                                }else
                                {
                                    if(nav_comp_pilha(p1,n->inicio->info))
                                    {
                                        while(_pilhaVazia(p1) != 1)
                                        {
                                            if(comp_topo_cont_nav(p1,n->inicio->info))
                                            {
                                                desempilhar(p1,n->inicio->info->c);
                                                break;
                                            }

                                            score_desempilhagem(p1->topo->info,score);

                                            desempilhar(p1,p2);
                                        }

                                    }else
                                    {
                                        printf("MOSTRANDO CONTAINERS DO NAVIO QUE VAI ZARPAR!\n");
                                        Mostra_containers_do_navio(n->inicio->info);    
                                        printf("Navio acabou de zarpar\n");
                                        printf("\n");
                                        score_tonelada(n->inicio->info,score);
                                        score_espa_vazio(n->inicio->info,score);
                                        valor=Remover_Fila(n);
                                        lista_liberada_navio(valor);
                                    }
                                    
                                }
                                
                            }else
                            {
                                printf("*Não tem navio compativel e container compativel\n");
                                printf("MOSTRANDO CONTAINERS DO NAVIO QUE VAO ZARPAR!\n");
                                while(n->inicio != NULL){

                                    Mostra_containers_do_navio(n->inicio->info);    
                                    printf("Navio acabou de zarpar\n");
                                    printf("\n");
                                    score_tonelada(n->inicio->info,score);
                                    score_espa_vazio(n->inicio->info,score);
                                    valor=Remover_Fila(n);
                                    lista_liberada_navio(valor);

                                }
                                break;
                            }
                           
                        }
                        
                    }
                }
            }else
            {
                if (_prioridade_perecivel(n,p1,p2,score))
                {
                }else
                {
                    if(comp_topo_cont_nav(p1,n->inicio->info))
                    {
                        desempilhar(p1,n->inicio->info->c);
                    }else
                    {
                        
                        if((_pilha_comp_fila(p1,n)==1)||(_pilha_comp_fila(p2,n)==1))
                        {
                            if(nav_comp_pilha(p1,n->inicio->info))
                                {
                                    while(_pilhaVazia(p1) != 1)
                                    {
                                        if(comp_topo_cont_nav(p1,n->inicio->info))
                                        {
                                            desempilhar(p1,n->inicio->info->c);
                                            break;
                                        }

                                        score_desempilhagem(p1->topo->info,score);
                                        desempilhar(p1,p2);
                                    }

                                }else
                                {
                                    if(nav_comp_pilha(p2,n->inicio->info))
                                    {
                                        while(_pilhaVazia(p2) != 1)
                                        {
                                            if(comp_topo_cont_nav(p2,n->inicio->info))
                                            {
                                                desempilhar(p2,n->inicio->info->c);
                                                break;
                                            }
                                            
                                            score_desempilhagem(p2->topo->info,score);
                                            desempilhar(p2,p1);
                                           
                                        }
                                    }else
                                    {
                                        printf("MOSTRANDO CONTAINERS DO NAVIO QUE VAO ZARPAR!\n");
                                        while(n->inicio != NULL){

                                            Mostra_containers_do_navio(n->inicio->info);    
                                            printf("Navio acabou de zarpar\n");
                                            printf("\n");
                                            score_tonelada(n->inicio->info,score);
                                            score_espa_vazio(n->inicio->info,score);
                                            valor=Remover_Fila(n);
                                            lista_liberada_navio(valor);

                                        }
                                        break;
                                    }
                                    
                                }
                        }else
                        {
                            break;
                        }                        
                    }
                    

                }
                

            }
            
        }
    }
    
}
