/* Exercícios 14 e 15 - inserção início e fim */
#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
} No;

void inserirInicio(No **ini, int x) {
    No *novo = malloc(sizeof(No));
    novo->valor = x;
    novo->prox = *ini;
    *ini = novo;
}

void inserirFim(No **ini, int x) {
    No *novo = malloc(sizeof(No));
    novo->valor = x;
    novo->prox = NULL;
    if (!*ini) {
        *ini = novo;
        return;
    }
    No *p = *ini;
    while (p->prox) p = p->prox;
    p->prox = novo;
}

void imprimir(No *p) {
    while (p) {
        printf("%d → ", p->valor);
        p = p->prox;
    }
    printf("NULL\n");
}

int main(void) {
    No *l = NULL;
    inserirFim(&l, 12);
    inserirFim(&l, 18);
    inserirFim(&l, 25);
    printf("Antes: ");
    imprimir(l);
    inserirInicio(&l, 8);
    printf("Ex14:  ");
    imprimir(l);

    No *l2 = NULL;
    inserirFim(&l2, 5);
    inserirFim(&l2, 10);
    inserirFim(&l2, 15);
    inserirFim(&l2, 20);
    printf("Ex15:  ");
    imprimir(l2);
    return 0;
}
