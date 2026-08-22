/* Exercício 06 - Agenda */
#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char nome[50];
    char telefone[20];
    char email[50];
} Contato;

void cadastrar(Contato c[], int *n) {
    if (*n >= MAX) return;
    printf("Nome: ");
    scanf(" %49[^\n]", c[*n].nome);
    printf("Telefone: ");
    scanf(" %19s", c[*n].telefone);
    printf("Email: ");
    scanf(" %49s", c[*n].email);
    (*n)++;
}

void buscar(Contato c[], int n, const char *nome) {
    for (int i = 0; i < n; i++)
        if (strcmp(c[i].nome, nome) == 0) {
            printf("%s | %s | %s\n", c[i].nome, c[i].telefone, c[i].email);
            return;
        }
    printf("Nao encontrado.\n");
}

void ordenar(Contato c[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++)
            if (strcmp(c[j].nome, c[j + 1].nome) > 0) {
                Contato t = c[j];
                c[j] = c[j + 1];
                c[j + 1] = t;
            }
}

void remover(Contato c[], int *n, const char *nome) {
    int i;
    for (i = 0; i < *n; i++)
        if (strcmp(c[i].nome, nome) == 0) break;
    if (i == *n) {
        printf("Nao encontrado.\n");
        return;
    }
    for (int j = i; j < *n - 1; j++) c[j] = c[j + 1];
    (*n)--;
}

int main(void) {
    Contato c[MAX];
    int n = 0, op;
    char nome[50];
    do {
        printf("\n1-Cad 2-Buscar 3-Ordenar 4-Remover 5-Listar 0-Sair: ");
        scanf("%d", &op);
        if (op == 1) cadastrar(c, &n);
        else if (op == 2) {
            printf("Nome: ");
            scanf(" %49[^\n]", nome);
            buscar(c, n, nome);
        } else if (op == 3) {
            ordenar(c, n);
            printf("Ordenado.\n");
        } else if (op == 4) {
            printf("Nome: ");
            scanf(" %49[^\n]", nome);
            remover(c, &n, nome);
        } else if (op == 5)
            for (int i = 0; i < n; i++)
                printf("%s | %s | %s\n", c[i].nome, c[i].telefone, c[i].email);
    } while (op != 0);
    return 0;
}
