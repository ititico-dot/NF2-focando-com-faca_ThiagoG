/* Exercício 02 - Sistema de Produtos */
#include <stdio.h>

#define MAX 100

typedef struct {
    int codigo;
    char nome[50];
    float preco;
    int quantidade;
} Produto;

void cadastrar(Produto p[], int *n) {
    if (*n >= MAX) return;
    printf("Codigo: ");
    scanf("%d", &p[*n].codigo);
    printf("Nome: ");
    scanf(" %49[^\n]", p[*n].nome);
    printf("Preco: ");
    scanf("%f", &p[*n].preco);
    printf("Quantidade: ");
    scanf("%d", &p[*n].quantidade);
    (*n)++;
}

void listar(Produto p[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d | %s | R$ %.2f | qtd %d\n",
               p[i].codigo, p[i].nome, p[i].preco, p[i].quantidade);
}

void buscar(Produto p[], int n, int cod) {
    for (int i = 0; i < n; i++)
        if (p[i].codigo == cod) {
            printf("Achei: %s\n", p[i].nome);
            return;
        }
    printf("Nao encontrado.\n");
}

float totalEstoque(Produto p[], int n) {
    float t = 0;
    for (int i = 0; i < n; i++)
        t += p[i].preco * p[i].quantidade;
    return t;
}

int main(void) {
    Produto p[MAX];
    int n = 0, op, c;
    do {
        printf("\n1-Cad 2-Listar 3-Buscar 4-Total 0-Sair: ");
        scanf("%d", &op);
        if (op == 1) cadastrar(p, &n);
        else if (op == 2) listar(p, n);
        else if (op == 3) {
            printf("Codigo: ");
            scanf("%d", &c);
            buscar(p, n, c);
        } else if (op == 4)
            printf("Valor total do estoque: R$ %.2f\n", totalEstoque(p, n));
    } while (op != 0);
    return 0;
}
