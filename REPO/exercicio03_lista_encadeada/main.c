/* Exercício 03 - Lista de compras (lista encadeada) */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char produto[50];
    int quantidade;
    struct No *prox;
} No;

void inserir(No **inicio, const char *nome, int qtd) {
    No *novo = malloc(sizeof(No));
    if (!novo) return;
    strncpy(novo->produto, nome, 49);
    novo->produto[49] = '\0';
    novo->quantidade = qtd;
    novo->prox = *inicio;
    *inicio = novo;
}

void remover(No **inicio, const char *nome) {
    No *ant = NULL, *at = *inicio;
    while (at && strcmp(at->produto, nome) != 0) {
        ant = at;
        at = at->prox;
    }
    if (!at) {
        printf("Item nao encontrado.\n");
        return;
    }
    if (!ant) *inicio = at->prox;
    else ant->prox = at->prox;
    free(at);
}

No *buscar(No *inicio, const char *nome) {
    for (No *p = inicio; p; p = p->prox)
        if (strcmp(p->produto, nome) == 0) return p;
    return NULL;
}

void listar(No *inicio) {
    if (!inicio) {
        printf("Lista vazia.\n");
        return;
    }
    for (No *p = inicio; p; p = p->prox)
        printf("- %s (%d)\n", p->produto, p->quantidade);
}

void liberar(No *inicio) {
    while (inicio) {
        No *t = inicio->prox;
        free(inicio);
        inicio = t;
    }
}

int main(void) {
    No *lista = NULL;
    int op, qtd;
    char nome[50];
    do {
        printf("\n1-Inserir 2-Remover 3-Buscar 4-Listar 0-Sair: ");
        scanf("%d", &op);
        if (op == 1) {
            printf("Produto e quantidade: ");
            scanf(" %49s %d", nome, &qtd);
            inserir(&lista, nome, qtd);
        } else if (op == 2) {
            printf("Produto: ");
            scanf(" %49s", nome);
            remover(&lista, nome);
        } else if (op == 3) {
            printf("Produto: ");
            scanf(" %49s", nome);
            No *r = buscar(lista, nome);
            printf(r ? "Achei, qtd=%d\n" : "Nao achei.\n", r ? r->quantidade : 0);
        } else if (op == 4) listar(lista);
    } while (op != 0);
    liberar(lista);
    return 0;
}
