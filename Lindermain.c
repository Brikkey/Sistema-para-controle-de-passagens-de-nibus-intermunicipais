#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no{
    int codigo;
    int assentos[48];
    bool cheio;
    struct no *proximo;
}No;

typedef struct{
    No *inicio;
    No *fim;
    int tam;
}Lista;

void criar_lista(Lista *lista){
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tam = 0;
}

// procedimento para inserir no início
int inserir_no_inicio(Lista *lista, int num, int indice){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->assentos[indice] = num;
        novo->proximo = lista->inicio;
        lista->inicio = novo;
        if(lista->fim == NULL)
            lista->fim = novo;
        lista->fim->proximo = lista->inicio;
        lista->tam++;
    }
    else
        printf("Erro ao alocar memoria!\n");
    return 0;
	}

// procedimento para inserir no fim
int inserir_no_fim(Lista *lista, int num, int indice){
    No *aux, *novo = (No*) malloc (sizeof(No));

    if(novo){
        novo->assentos[indice] = num;

        // é o primeiro?
        if(lista->inicio == NULL){
            lista->inicio = novo;
            lista->fim = novo;
            lista->fim->proximo = lista->inicio;
        }
        else{
            lista->fim->proximo = novo;
            lista->fim = novo;
            // as duas linhas a seguir são sinônimas. Escolha a que achar mais fácil compreender
            //lista->fim->proximo = lista->inicio;
            novo->proximo = lista->inicio;
        }
        lista->tam++;
    }
    else
        printf("Erro ao alocar memoria!\n");
    return 0;
}

// procedimento para inserir ordenado
int inserir_ordenado(Lista *lista, int num, int indice){
    No *aux, *novo = malloc(sizeof(No));

    if(novo){
        novo->assentos[indice] = num;
        if(lista->inicio == NULL){
            inserir_no_inicio(lista, num, indice);
        }
        else if(novo->assentos[indice]< lista->inicio->assentos[indice]){
            inserir_no_inicio(lista, num, indice);
        }
        else{
            aux = lista->inicio;
            while(aux->proximo != lista->inicio && novo->assentos[indice] > aux->proximo->assentos[indice])
                aux = aux->proximo;
            if(aux->proximo == lista->inicio)
                inserir_no_fim(lista, num, indice);
            else{
                novo->proximo = aux->proximo;
                aux->proximo = novo;
                lista->tam++;
            }
        }
    }
    else
        printf("Erro ao alocar memoria!\n");
    return 0;
}

// função para remover um nó
No* remover(Lista *lista, int num, int indice){
    No *aux, *remover = NULL;

    if(lista->inicio){
        if(lista->inicio == lista->fim && lista->inicio->assentos[indice] == num){
            remover = lista->inicio;
            lista->inicio = NULL;
            lista->fim = NULL;
            lista->tam--;
        }
        else if(lista->inicio-> assentos[indice] == num){
            remover = lista->inicio;
            lista->inicio = remover->proximo;
            lista->fim->proximo = lista->inicio;
            lista->tam--;
        }
        else{
            aux = lista->inicio;
            while(aux->proximo != lista->inicio && aux->proximo->assentos[indice] != num)
                aux = aux->proximo;
            if(aux->proximo->assentos[indice] == num){
                if(lista->fim == aux->proximo){
                    remover = aux->proximo;
                    aux->proximo = remover->proximo;
                    lista->fim = aux;
                }
                else{
                    remover = aux->proximo;
                    aux->proximo = remover->proximo;
                }
                lista->tam--;
            }
        }
    }

    return remover;
}

// função para buscar um valor
No* buscar(Lista *lista, int num, int indice){
    No *aux = lista->inicio;

    if(aux){
        do{
            if(aux->assentos[indice] == num)
                return aux;
            aux = aux->proximo;
        }while(aux != lista->inicio);
    }
    return NULL;
}

// procedimento para imprimir a lista circular
void imprimir(Lista lista){
    No *no = lista.inicio;
    int i;
    printf("\n\tLista tam %d: ", lista.tam);
    if(no){
        do{
        	for(i = 0; i < 48; i++){
			printf("%d ", no->assentos[i]);
        }
			no = no->proximo;
        }while(no != lista.inicio);
        	for(i = 0; i < 48; i++){
			printf("%d ", no->assentos[i]);
    }
    printf("\n\n");
}

int main(){

    int opcao, valor = 0, anterior, i;
    //No *lista = NULL;
    Lista lista;
    No *removido;

    criar_lista(&lista);

    do{
        printf("\n\t0 - Sair\n\t1 - InserirI\n\t2 - inserirF\n\t3 - InserirO\n\t4 - Remover\n\t5 - Imprimir\n\t6 - Buscar\n");
        scanf("%d", &opcao);

        switch(opcao){
        case 1:
        	if (buscar(&lista, valor, i) != NULL)
        		continue;
        	else{
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir_no_inicio(&lista, valor, i);
            break;
        }
        case 2:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir_no_fim(&lista, valor, i);
            break;
        case 3:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir_ordenado(&lista, valor, i);
            break;
        case 4:
            printf("Digite um valor a ser removido: ");
            scanf("%d", &valor);
            removido = remover(&lista, valor, i);
            if(removido){
                printf("Elemento removido: %d\n", removido->assentos[i]);
                free(removido);
            }
            else
                printf("elemento inesistente!\n");
            break;
        case 5:
            imprimir(lista);
            break;
        case 6:
            printf("Digite um valor a ser buscado: ");
            scanf("%d", &valor);
            removido = buscar(&lista, valor, i);
            if(removido)
                printf("Valor encontrado: %d\n", removido->assentos[i]);
            else
                printf("Valor nao encontrado!\n");
            break;
        default:
            if(opcao != 0)
                printf("Opcao invalida!\n");
        }

    }while(opcao != 0);

    return 0;
}
