/* Exercício 04 - Pilha de livros (LIFO com vetor) */
#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char livros[MAX][50];
    int topo;
} Pilha;

void init(Pilha *p) { p->topo = -1; }
int isEmpty(Pilha *p) { return p->topo == -1; }

void push(Pilha *p, const char *livro) {
    if (p->topo == MAX - 1) {
        printf("Pilha cheia.\n");
        return;
    }
    p->topo++;
    strncpy(p->livros[p->topo], livro, 49);
    p->livros[p->topo][49] = '\0';
}

void pop(Pilha *p) {
    if (isEmpty(p)) {
        printf("Pilha vazia.\n");
        return;
    }
    printf("Removido: %s\n", p->livros[p->topo]);
    p->topo--;
}

void top(Pilha *p) {
    if (isEmpty(p)) printf("Vazia.\n");
    else printf("Topo: %s\n", p->livros[p->topo]);
}

int main(void) {
    Pilha p;
    init(&p);
    char nome[50];
    int op;
    do {
        printf("\n1-push 2-pop 3-top 4-empty 0-sair: ");
        scanf("%d", &op);
        if (op == 1) {
            printf("Livro: ");
            scanf(" %49[^\n]", nome);
            push(&p, nome);
        } else if (op == 2) pop(&p);
        else if (op == 3) top(&p);
        else if (op == 4) printf(isEmpty(&p) ? "Vazia\n" : "Nao vazia\n");
    } while (op != 0);
    return 0;
}
