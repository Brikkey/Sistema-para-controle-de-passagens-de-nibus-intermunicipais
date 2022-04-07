#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "pilha.h"



int main(){
	pilha_t *p1, *p2 ;
	passagem Passageiro;
	
	p1 = create(48);
	p2 = create(48);
	

    int gratuidade1 = 0;
    int gratuidade2 = 0;
	int i = 0;
    int menu = 0;
    int qtd = 0;
    int t = 0;
    int grts1 = 0;
    int op = 0;
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
    int assent1 = 0;
    int assent2 = 0;
    int 

    while (menu!=4){
        printf("\n      AED1 TRANSPORTES INTERMUNICIPAIS");
        printf("\n      TELEFONE: 4002 8922");
        printf("\n      AO INFINITO E ALEM!\n");
        printf("\n MENU ");
        printf("\n1-Vendas de Passagem");
        printf("\n2-Lista de Onibus");
        printf("\n3-Checagem de Vagas");
        printf("\n4-Sair\n");
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
                        printf("\nValor: R$450,00\nAssento:");                  
                        scanf("%d", &assent1);
                        if (isFull(p)) {
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
								printf("\n| 			 Digite o nome do passageiro                |");
								scanf(" %[^\n]", Passageiro.nome);
								printf("\n| 					 Digite o CPF                       |");  
								scanf("%d", &Passageiro.CPF);
								printf("\n| 				   Digite o telefone                    |");  
								scanf("%d", &Passageiro.telefone);                         
                                printf("\n|Valor: R$130,00                                          |");
                                printf("\n|Tipo de Passagem: INTEIRA                                |");
                                printf("\n-----------------------------------------------------------");
                                printf("\n");
                                printf("\nDigite 1 para imprimir passagem e voltar ao menu principal: ");
                                scanf("%d", &op);
                                inte1++;
                                break;
                            case 2:

                                printf("\n___________________________________________________________");
                                printf("\n|      Onibus 1 - AED1 TRANSPORTES INTERMUNICIPAIS        |");
                                printf("\n|   Embarque: Juazeiro - BA | Desembarque: Salvador - BA  |");  
								printf("\n| 			 Digite o nome do passageiro                |");
								scanf(" %[^\n]", Passageiro.nome);
								printf("\n| 					 Digite o CPF                       |");  
								scanf("%d", & Passageiro.CPF);
								printf("\n| 				   Digite o telefone                    |");  
								scanf("%d", &Passageiro.telefone);                         
                                printf("\n|Valor: R$65,00                                           |");
                                printf("\n|Tipo de Passagem: MEIA - ESTUDANTE                       |");
                                printf("\n-----------------------------------------------------------");
                                printf("\nDigite 1 para imprimir passagem e voltar ao menu principal: ");
                                scanf("%d", &op);
                                meia1++;
                                break;
                        }
                        i++;
                        break;
                    
             	      		 case 2:
                       			bus2++;
                      			printf("\nOnibus 2 - Guanambi BA para Belo Horizonte MG");
                        		printf("\nValor: R$110,00");                  
                     		    printf("\nAssento: ");
                    		    scanf("%d", &assent2);
                        		if (bus2>48) {
                        		printf("\nNao ha mais vagas para este onibus.");
                        		break;
                        }

 
                      		printf("\n");
                      	   	printf("\n1 - Passagem Inteira");
                       		printf("\n2 - Passagem MEIA ");
			
                        switch(pas)
                        {
                            case 1:
                                inte2++;
                                printf("\n______________________________________________________________");
                                printf("\n|           Onibus 2 - VIACAO GUANAMBI TURISMO               |");
                                printf("\n|Embarque: Guanambi - Bahia | Desembarque: Belo Horizonte MG |"); 
								printf("\n| 			 Digite o nome do passageiro                |");
								scanf(" %[^\n]", Passageiro.nome);
								printf("\n| 					 Digite o CPF                       |");  
								scanf("%d", &Passageiro.CPF);
								printf("\n| 				   Digite o telefone                    |");  
								scanf("%d", &Passageiro.telefone);                                                        
                                printf("\n|Valor: R$110,00                                             |");
                                printf("\n|Tipo de Passagem: INTEIRA                                   |");
                                printf("\n--------------------------------------------------------------");
                                printf("\n");
                                printf("\nDigite 1 para imprimir passagem e voltar ao menu principal: ");
                                scanf("%d", &op);
                                 break;
                            case 2:
                                meia2++;
                                printf("\n______________________________________________________________");
                                printf("\n|           Onibus 2 - VIACAO GUANAMBI TURISMO               |");
                                printf("\n|Embarque: Guanambi - Bahia | Desembarque: Belo Horizonte MG |"); 
								printf("\n| 			 Digite o nome do passageiro                |");
								scanf(" %[^\n]", Passageiro.nome);
								printf("\n| 					 Digite o CPF                       |");  
								scanf("%d", &Passageiro.CPF);
								printf("\n| 				   Digite o telefone                    |");  
								scanf("%d", &Passageiro.telefone);                                                        
                                printf("\n|Valor: R$55,00                                              |");
                                printf("\n|Tipo de Passagem: MEIA                                      |");
                                printf("\n--------------------------------------------------------------");
                                printf("\nDigite 1 para imprimir passagem e voltar ao menu principal: ");
                                scanf("%d", &op);
                                break;
                        }
            
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
                        printf("\nAssentos Livres: %d", bus1l);
                        printf("\n");
                    break;
                    case 02:
                        bus2l = bus2 - 48;
                        printf("\nAssentos vendidos e assentos disponiveis no Onibus 2:");
                        printf("\n");
                        printf("\nAssentos vendidos: %d", bus2);
                        printf("\nAssentos Livres: %d", bus2l);
                        printf("\n");
                    break;
                 }
            break;
            case 4:
              break;
            
        }
    }
    	destroy(p);
}
