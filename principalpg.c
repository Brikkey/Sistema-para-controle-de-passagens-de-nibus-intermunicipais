#define TamPilha 48
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct passagem{
		char nome[100];
		int cpf, telefone;
}pessoa;

typedef struct pilha {		//vai mudar pouca coisa para a outra pilha
	int topo;
	pessoa **passageiro;
	int tamElem;
}pilha_t;

typedef struct nodo
{
    int inf;
    struct nodo * next;
}NODO;

typedef struct
{
    NODO *INICIO;
    NODO *FIM;
}DESCRITOR;

typedef DESCRITOR * FILA_ENC;
void cria_fila (FILA_ENC *);
int eh_vazia (FILA_ENC);
void ins (FILA_ENC, int);
int cons (FILA_ENC);
void ret (FILA_ENC);
int cons_ret (FILA_ENC);
//
pilha_t *create(int tamElem);
void destroy(pilha_t *p);
int isFull(pilha_t *p);
int isEmpty(pilha_t *p);
int push (pilha_t *p, pessoa *Passageiro);
int pop (pilha_t *p, pessoa *Passageiro);
int top (pilha_t *p, pessoa *Passageiro);
int imprimir (pilha_t *p);


int main(){
	pilha_t *p1, *p2;
	
	p1 = create(48);
	p2 = create(48);
	
	pessoa passageiro;
	char tf;
    int gratuidade1 = 0;
    int gratuidade2 = 0;
    int menu = 0;
    int qtd = 0;
    int t = 0;
    int grts1 = 0;
    int bus = 0;
    int bus1 = 0;
    int bus1l = 0;
    int tot1= 0;
    int inte1 = 0 ;
    int meia1 = 0 ;
    int pas = 0 ;
    int bus2 = 0;
    int bus2l = 0;
    int tot2 = 0;
    int grts2 = 0;
    int inte2 = 0;
    int meia2 = 0;
	int assento =0;
    do{
        printf("\n      AED1 TRANSPORTES INTERMUNICIPAIS");
        printf("\n      TELEFONE: 4002 8922");
        printf("\n      AO INFINITO E ALEM!\n");
        printf("\n MENU ");
        printf("\n1-Vendas de Passagem");
        printf("\n2-Lista de Onibus");
        printf("\n3-Checagem de Vagas");
        printf("\n4-Reserva de Vagas");
		printf("\n5-Sair\n");
        printf("\nOpcao desejada: ");
        scanf("%d", &menu);
        system("cls");
 
        switch (menu){
            case 1:
			printf("\nVENDA DE PASSAGEM");
                printf("\n");
                printf("\nVALORES:");
                printf("\nCD |  ONIBUS   |    SAIDA     |         DESTINO          | VALOR");           
                printf("\n01 | Onibus 1  | Petrolina PE |       Sao Paulo SP       | R$450,00");                
                printf("\n02 | Onibus 2  | Juazeiro BA  |       Salvador BA        | R$120,00");
                printf("\n");
                printf("\n");
                printf("\nDigite o Codigo do Onibus: ");
                scanf("%d", &bus);
 
                switch(bus){
                    case 1:
                        bus1++;
                        printf("\nOnibus 1 - Petrolina PE para Sao Paulo SP");
                        printf("\nValor: R$450,00");
                        if (isFull(p1)) {
                        	printf("\nNAO HÁ VAGAS DISPONIVEIS PARA ESSE TRAJETO");
                        	break;
						}
        
                        printf("\n");
                        printf("\n1 - Passagem Inteira");
                        printf("\n2 - Passagem MEIA ");
                        printf("\nDigite o Tipo de Passagem: ");
                        scanf("%d", &pas);
                        switch(pas)
                        {
                            case 1:
                                
                                printf("\n___________________________________________________________");
                                printf("\n|           Onibus 1 - AED1 TRANSPORTES INTERMUNICIPAIS   |");
                                printf("\n|  Embarque: Petrolina - PE | Desembarque: Sao Paulo - SP |");   
								printf("\n| 			 Digite o nome do passageiro                |\n");
								scanf(" %[^\n]", passageiro.nome);
								printf("\n| 					 Digite o CPF                       |\n");  
								scanf("%d", &passageiro.cpf);
								printf("\n| 				   Digite o telefone                    |\n");  
								scanf("%d", &passageiro.telefone); 
								push(p1, &passageiro);                        
                                printf("\n|Valor: R$130,00                                          |");
                                printf("\n|Tipo de Passagem: INTEIRA                                |");
                                printf("\n-----------------------------------------------------------");
                                printf("\n");
                                inte1++;
                                break;
                            case 2:

                                printf("\n___________________________________________________________");
                                printf("\n|      Onibus 1 - AED1 TRANSPORTES INTERMUNICIPAIS        |");
                                printf("\n|   Embarque: Juazeiro - BA | Desembarque: Salvador - BA  |");  
								printf("\n| 			 Digite o nome do passageiro                |\n");
								scanf(" %[^\n]", passageiro.nome);
								printf("\n| 					 Digite o CPF                       |\n");  
								scanf("%d", &passageiro.cpf);
								printf("\n| 				   Digite o telefone                    |\n");  
								scanf("%d", &passageiro.telefone); 
								push(p1, &passageiro);                       
                                printf("\n|Valor: R$65,00                                           |");
                                printf("\n|Tipo de Passagem: MEIA - ESTUDANTE                       |");
                                printf("\n-----------------------------------------------------------");
                                meia1++;
                                break;
                                default:
          						printf("Valor invalido");
                        }
                        break;
                    
             	      		 case 2:
                       			bus2++;
                      			printf("\nOnibus 2 - Guanambi BA para Belo Horizonte MG");
                        		printf("\nValor: R$110,00");                  
                        		if (bus2>48) {
                        		printf("\nNao ha mais vagas para este onibus.");
                        		break;
                       			}

 
                      		printf("\n");
                      	   	printf("\n1 - Passagem Inteira");
                       		printf("\n2 - Passagem MEIA \n\n\n");
                       		scanf("%d", &pas);
			
                        switch(pas)
                        {
                            case 1:
                                inte2++;
                                printf("\n______________________________________________________________");
                                printf("\n|           Onibus 2 - VIACAO GUANAMBI TURISMO               |");
                                printf("\n|Embarque: Guanambi - Bahia | Desembarque: Belo Horizonte MG |"); 
								printf("\n| 			 Digite o nome do passageiro                |\n");
								scanf(" %[^\n]", passageiro.nome);
								printf("\n| 					 Digite o CPF                       |\n");  
								scanf("%d", &passageiro.cpf);
								printf("\n| 				   Digite o telefone                    |\n");  
								scanf("%d", &passageiro.telefone);  
								push(p2, &passageiro);                                                      
                                printf("\n|Valor: R$110,00                                             |");
                                printf("\n|Tipo de Passagem: INTEIRA                                   |");
                                printf("\n--------------------------------------------------------------");
                                 break;
                            case 2:
                                meia2++;
                                printf("\n______________________________________________________________");
                                printf("\n|           Onibus 2 - VIACAO GUANAMBI TURISMO               |");
                                printf("\n|Embarque: Guanambi - Bahia | Desembarque: Belo Horizonte MG |"); 
								printf("\n| 			 Digite o nome do passageiro                |\n");
								scanf(" %[^\n]", passageiro.nome);
								printf("\n| 					 Digite o CPF                       |\n");  
								scanf("%d", &passageiro.cpf);
								printf("\n| 				   Digite o telefone                    |\n");  
								scanf("%d", &passageiro.telefone); 
								push(p2, &passageiro);                                                       
                                printf("\n|Valor: R$55,00                                              |");
                                printf("\n|Tipo de Passagem: MEIA                                      |");
                                printf("\n--------------------------------------------------------------");
                                break;
                            default:
          						printf("Valor invalido");
                        }
            			break;
            			default:
          					printf("Valor invalido");	
    				}
            case 2:
                 printf("\nLISTA DE ONIBUS");
                 printf("\n");
                 printf("\n01 - Onibus 1 - INTERESTADUAL - Petrolina PE a Sao Paulo SP");                 
                 printf("\n02 - Onibus 2 - INTERESTADUAL - Juazeiro BA a Salvador BA \n\n\n");
                 
            case 3:
                 printf("\nCHECAGEM DE VAGAS\n");
                 printf("\nVALORES:");
                 printf("\nCD |  ONIBUS   |    SAIDA    | DESTINO");
                 printf("\n01 | Onibus 1  | Guanambi BA | Sao Paulo SP");                 
                 printf("\n02 | Onibus 2  | Guanambi BA | Belo Horizonte MG");
                 printf("\n");
                 printf("\n");
                 printf("\nDigite o Codigo do Onibus: ");
                 scanf("%d", &bus);
                 switch(bus)
                 {
                    case 01:
                        bus1l = bus1 - 48;
                        printf("\nAssentos vendidos e assentos disponiveis no Onibus 1:");
                        printf("\n");
                        printf("\nAssentos vendidos: %d", bus1);
                        printf("\nAssentos Livres: %d", -bus1l);
                        printf("\n");
                        printf("\nGostaria da lista de passageiros? Digite S para ter acesso: ");
                        scanf("%c", &tf);
                        if(tf == 'S'){
                        	while(1){
                        		imprimir(p1);
							}
						}
                    break;
                    case 02:
                        bus2l = bus2 - 48;
                        printf("\nAssentos vendidos e assentos disponiveis no Onibus 2:");
                        printf("\n");
                        printf("\nAssentos vendidos: %d", bus2);
                        printf("\nAssentos Livres: %d", -bus2l);
                        printf("\n");
                        printf("\nGostaria da lista de passageiros? Digite S para ter acesso: ");
                        scanf("%c", &tf);
                        if(tf == 'S'){
                        	while(1){
                        		imprimir(p2);
							}
						}
                    break;
                	default:
          				printf("Valor invalido");
                 }
            break;
            case 4:
            	printf("\n\nRESERVA DE PASSAGEM");
            	printf("\nCD |  ONIBUS   |    SAIDA     |         DESTINO          | VALOR");           
                printf("\n01 | Onibus 1  | Petrolina PE |       Sao Paulo SP       | R$450,00");                
                printf("\n02 | Onibus 2  | Juazeiro BA  |       Salvador BA        | R$120,00");
          	default:
          		printf("Valor invalido");
            printf("\nDigite o Codigo do Onibus: ");
                scanf("%d", &bus);
 
                switch(bus){
                    case 1:
                        bus1++;
                        printf("\nOnibus 1 - Petrolina PE para Sao Paulo SP");
                        printf("\nValor: R$450,00");
                        if (isFull(p1)) {
                        	printf("\nNAO HÁ VAGAS DISPONIVEIS PARA ESSE TRAJETO");
                        	break;
						}
        
                        printf("\n");
                        printf("\n1 - Passagem Inteira");
                        printf("\n2 - Passagem MEIA ");
                        printf("\nDigite o Tipo de Passagem: ");
                        scanf("%d", &pas);
                        switch(pas)
                        {
                            case 1:
                                
                                printf("\n___________________________________________________________");
                                printf("\n|           Onibus 1 - AED1 TRANSPORTES INTERMUNICIPAIS   |");
                                printf("\n|  Embarque: Petrolina - PE | Desembarque: Sao Paulo - SP |");   
								printf("\n| 			 Digite o nome do passageiro                |\n");
								scanf(" %[^\n]", passageiro.nome);
								printf("\n| 					 Digite o CPF                       |\n");  
								scanf("%d", &passageiro.cpf);
								printf("\n| 				   Digite o telefone                    |\n");  
								scanf("%d", &passageiro.telefone); 
								push(p1, &passageiro);                        
                                printf("\n|Valor: R$130,00                                          |");
                                printf("\n|Tipo de Passagem: INTEIRA                                |");
                                printf("\n-----------------------------------------------------------");
                                printf("\n");
                                inte1++;
                                
                                if (eh_vazia)
                                break;
                            case 2:

                                printf("\n___________________________________________________________");
                                printf("\n|      Onibus 1 - AED1 TRANSPORTES INTERMUNICIPAIS        |");
                                printf("\n|   Embarque: Petrolina - PE | Desembarque: Sao Paulo - SP|");  
								printf("\n| 			 Digite o nome do passageiro                |\n");
								scanf(" %[^\n]", passageiro.nome);
								printf("\n| 					 Digite o CPF                       |\n");  
								scanf("%d", &passageiro.cpf);
								printf("\n| 				   Digite o telefone                    |\n");  
								scanf("%d", &passageiro.telefone); 
								push(p1, &passageiro);                       
                                printf("\n|Valor: R$65,00                                           |");
                                printf("\n|Tipo de Passagem: MEIA - ESTUDANTE                       |");
                                printf("\n-----------------------------------------------------------");
                                meia1++;
                                break;
                                default:
          						printf("Valor invalido");
                        }
                        break;
                    
             	      		 case 2:
                       			bus2++;
                      			printf("\nOnibus 2 - Guanambi BA para Belo Horizonte MG");
                        		printf("\nValor: R$110,00");                  
                        		if (bus2>48) {
                        		printf("\nNao ha mais vagas para este onibus.");
                        		break;
                       			}

 
                      		printf("\n");
                      	   	printf("\n1 - Passagem Inteira");
                       		printf("\n2 - Passagem MEIA \n\n\n");
                       		scanf("%d", &pas);
			
                        switch(pas)
                        {
                            case 1:
                                inte2++;
                                printf("\n______________________________________________________________");
                                printf("\n|           Onibus 2 - AED1               |");
                                printf("\n|Embarque: Juazeiro - Bahia | Desembarque: Salvador - BA |"); 
								printf("\n| 			 Digite o nome do passageiro:                |");
								scanf(" %[^\n]", passageiro.nome);
								printf("\n| 					 Digite o CPF:                       |");  
								scanf("%d", &passageiro.cpf);
								printf("\n| 				   Digite o telefone:                    |");  
								scanf("%d", &passageiro.telefone);  
								push(p2, &passageiro);                                                      
                                printf("\n|Valor: R$110,00                                             |");
                                printf("\n|Tipo de Passagem: INTEIRA                                   |");
                                printf("\n--------------------------------------------------------------");
                                 break;
                            case 2:
                                meia2++;
                                printf("\n______________________________________________________________");
                                printf("\n|           Onibus 2 -  AED 1              |");
                                printf("\n|Embarque: Juazeiro - Bahia | Desembarque: Salvador - BA |"); 
								printf("\n| 			 Digite o nome do passageiro:                |");
								scanf(" %[^\n]", passageiro.nome);
								printf("\n| 					 Digite o CPF:                       |");  
								scanf("%d", &passageiro.cpf);
								printf("\n| 				   Digite o telefone:                    |");  
								scanf("%d", &passageiro.telefone); 
								push(p2, &passageiro);                                                       
                                printf("\n|Valor: R$55,00                                              |");
                                printf("\n|Tipo de Passagem: MEIA                                      |");
                                printf("\n--------------------------------------------------------------");
                                printf("\n\n\nDigite o numero do assento desejado: ENTRE 1 e 48");
                                scanf("%d", &assento);
                                if (assento==1);
                                break;
                            default:
          						printf("Valor invalido");
                        }
            			break;
            			default:
          					printf("Valor invalido");	
    				}
        }
    }while(menu != 5);
    	destroy(p1);
    	destroy(p2);
}


pilha_t *create(int tamElem){
	pilha_t *p = (pilha_t *)malloc(sizeof(pilha_t));
	assert(p != NULL);   //faz a mesma coisa que o if p == null; exit;
	
	p->passageiro = (pessoa**) malloc (sizeof(pessoa ) * TamPilha);
	assert(p->passageiro != NULL);
	
	p->topo = -1;
	p->tamElem = tamElem;
	return p;
}

void destroy(pilha_t *p){
	while(p->topo >= 0){
		free(p->passageiro);
		p->topo -= 1;
	}
	
	if(p->passageiro != NULL)
		free(p->passageiro);
	
	if (p != NULL);
		free(p);
		
	p = NULL;
}

int isFull(pilha_t *p){
	assert(p != NULL);
	if(p->topo == TamPilha - 1)
		return 1;
	else
		return 0;
}

int isEmpty(pilha_t *p){
	assert (p != NULL);
	
	if(p->topo == - 1)
		return 1;
	else
		return 0;
}

int push (pilha_t *p, pessoa *Passageiro){  //a função é int, porque quero retornar um codigo de erro, se n era void
	assert ( p != NULL);
	
	if(isFull(p) == 1){
		return -2;
	}
	p->topo = p->topo +1;
	p->passageiro[p->topo] = (pessoa*)malloc(sizeof(p->tamElem));
	assert( p->passageiro[p->topo] != NULL);
	memcpy(p->passageiro[p->topo], Passageiro, p->tamElem);

	return 1;
}

int pop (pilha_t *p, pessoa *Passageiro){
	assert (p != NULL);
	
	if (isEmpty(p) == -1){
		printf("Não contem passagens compradas");
		return -2;
	}
	
	memcpy(p->passageiro[p->topo], Passageiro, p->tamElem);
	free(p->passageiro[p->topo]);
	Passageiro = p->passageiro[p->topo];
	p->topo -= 1;
	
	return 1;
}

int top (pilha_t *p, pessoa *Passageiro){ // consulta do valor do topo da pilha
	assert (p != NULL);
	
	if (isEmpty(p) == -1){
		printf("Não contem passagens compradas");
		return -2;
	}
	
	Passageiro = p->passageiro[p->topo];
	
	memcpy(p->passageiro[p->topo], Passageiro, p->tamElem);
	
	return 1;
}


// procedimento para imprimir toda a pilha

int imprimir(pilha_t *p){
	int i;
	for (i=p->tamElem-1; i>=0; i--) {
		printf("\npassageiro: %s", p->passageiro);
	}
}
void cria_fila (FILA_ENC *pf)
{
    *pf=(DESCRITOR *) malloc (sizeof(DESCRITOR));
    if (!pf)
    {
        printf("\nERRO! Memoria insuficiente!\n");
        exit(1);
    }
    (*pf)->INICIO=(*pf)->FIM=NULL;
}

int eh_vazia (FILA_ENC f)
{
    return (f->INICIO == NULL);
}

void ins (FILA_ENC f, int passageiro)
{
    NODO *novo;
    novo = (NODO *) malloc (sizeof(NODO));
    if (!novo)
    {
        printf("\nERRO! Memoria insuficiente");
        exit(1);
    }
    novo->inf = passageiro;
    novo->next = NULL;
    if (eh_vazia(f))
        f->INICIO  = novo;
    else
        f->FIM->next = novo;
    f->FIM = novo;
}

int cons (FILA_ENC f)
{
    if (eh_vazia(f))
    {
        printf("\nERRO! Consulta em fila vazia!\n");
        exit(2);
    }
    else
        return(f->INICIO->inf);
}

void ret (FILA_ENC f)
{
    if (eh_vazia(f))
    {
        printf("\nERRO! Retirada em fila vazia!\n");
        exit(3);
    }
    else
    {
        NODO *aux = f->INICIO;
        f->INICIO = f->INICIO->next;
        if (!f->INICIO)
            f->FIM=NULL;
        free (aux);
    }
}

int cons_ret (FILA_ENC f)
{
    if(eh_vazia(f))
    {
        printf("\nERRO! Consulta e retirada em fila vazia!\n");
        exit(4);
    }
    else
    {
        int v = f->INICIO->inf;
        NODO *aux = f->INICIO;
        f->INICIO = f->INICIO->next;
        if(!f->INICIO)
            f->FIM=NULL;
        free(aux);
        return (v);
    }
}

void reserva_por_fila (FILA_ENC *pf){
	int assento;
	FILA_ENC reservada;
	if (eh_vazia(reservada))
	cria_fila(&reservada);
		
		while(!eh_vazia)
		ins(reservada, assento);
			
}
