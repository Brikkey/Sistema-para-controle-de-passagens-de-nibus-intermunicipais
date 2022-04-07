#define TamPilha 100

typedef struct pilha pilha_t;

pilha_t *create(int tamElem);
void destroy(pilha_t *p);
int isFull(pilha_t *p);
int isEmpty(pilha_t *p);
int push (pilha_t *p, passagem *Passageiro);
int pop (pilha_t *p, passagem *Passageiro);
int top (pilha_t *p, passagem *Passageiro);



