#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "pilha.h"

typedef struct{
		char nome[100];
	int cpf, telefone;
}passagem;

struct pilha {		//vai mudar pouca coisa para a outra pilha
	int topo;
	void **itens;
	int tamElem;
};

pilha_t *create(int tamElem){
	pilha_t *p = (pilha_t *)malloc(sizeof(pilha_t));
	assert(p != NULL);   //faz a mesma coisa que o if p == null; exit;
	
	p->itens = (void **) malloc (sizeof(void* ) * TamPilha);
	assert(p->itens != NULL);
	
	p->topo = -1;
	p->tamElem = tamElem;
	return p;
}

void destroy(pilha_t *p){
	while(p->topo >= 0){
		free(p->itens[p->topo]);
		p->topo -= 1;
	}
	
	if(p->itens != NULL)
		free(p->itens);
	
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

int push (pilha_t *p, passagem *Passageiro){  //a função é int, porque quero retornar um codigo de erro, se n era void
	assert ( p != NULL);
	
	if(isFull(p) == 1){
		return -2;
	}
	p->topo = p->topo +1;
	p->itens[p->topo] = (passagem*)malloc(sizeof(p->tamElem));
	assert( p->itens[p->topo] != NULL);
	memcpy(p->itens[p->topo], Passageiro, p->tamElem);

	
	return 1;
}

int pop (pilha_t *p, passagem *Passageiro){
	assert (p != NULL);
	
	if (isEmpty(p) == -1){
		return -2;
	}
	
	memcpy(p->itens[p->topo], Passageiro, p->tamElem);
	free(p->itens[p->topo]);
	x = p->itens[p->topo];
	p->topo -= 1;
	
	return 1;
}

int top (pilha_t *p, passagem *Passageiro){ // consulta do valor do topo da pilha
	assert (p != NULL);
	
	if (isEmpty(p) == -1){
		return -2;
	}
	
	x = p->itens[p->topo];
	
	memcpy(p->itens[p->topo], x, p->tamElem);
	
	return 1;
}
