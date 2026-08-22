/* Exercício 05 - Fila de atendimento (FIFO) */
#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char clientes[MAX][50];
    int inicio;
    int fim;
} Fila;

void init(Fila *f) { f->inicio = 0; f->fim = 0; }
int vazia(Fila *f) { return f->inicio == f->fim; }
int cheia(Fila *f) { return f->fim == MAX; }

void enfileirar(Fila *f, const char *nome) {
    if (cheia(f)) {
        printf("Fila cheia.\n");
        return;
    }
    strncpy(f->clientes[f->fim], nome, 49);
    f->clientes[f->fim][49] = '\0';
    f->fim++;
}

void desenfileirar(Fila *f) {
    if (vazia(f)) {
        printf("Fila vazia.\n");
        return;
    }
    printf("Atendendo: %s\n", f->clientes[f->inicio]);
    f->inicio++;
}

void frente(Fila *f) {
    if (vazia(f)) printf("Vazia.\n");
    else printf("Proximo: %s\n", f->clientes[f->inicio]);
}

void listar(Fila *f) {
    if (vazia(f)) {
        printf("Ninguem na fila.\n");
        return;
    }
    for (int i = f->inicio; i < f->fim; i++)
        printf("%d. %s\n", i - f->inicio + 1, f->clientes[i]);
}

int main(void) {
    Fila f;
    init(&f);
    int op;
    char nome[50];
    do {
        printf("\n1-Enfileirar 2-Atender 3-Frente 4-Listar 0-Sair: ");
        scanf("%d", &op);
        if (op == 1) {
            printf("Nome: ");
            scanf(" %49[^\n]", nome);
            enfileirar(&f, nome);
        } else if (op == 2) desenfileirar(&f);
        else if (op == 3) frente(&f);
        else if (op == 4) listar(&f);
    } while (op != 0);
    return 0;
}
