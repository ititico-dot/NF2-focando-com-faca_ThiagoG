/* Exercício 01 - Cadastro de Alunos
 * Vetor de structs: cadastrar, listar, buscar por matrícula, maior nota. */
#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    int matricula;
    char nome[50];
    int idade;
    float nota;
} Aluno;

void cadastrar(Aluno a[], int *n) {
    if (*n >= MAX) {
        printf("Turma cheia.\n");
        return;
    }
    printf("Matricula: ");
    scanf("%d", &a[*n].matricula);
    printf("Nome: ");
    scanf(" %49[^\n]", a[*n].nome);
    printf("Idade: ");
    scanf("%d", &a[*n].idade);
    printf("Nota: ");
    scanf("%f", &a[*n].nota);
    (*n)++;
}

void listar(Aluno a[], int n) {
    if (n == 0) {
        printf("Nenhum aluno.\n");
        return;
    }
    for (int i = 0; i < n; i++)
        printf("%d | %s | %d anos | nota %.2f\n",
               a[i].matricula, a[i].nome, a[i].idade, a[i].nota);
}

void buscar(Aluno a[], int n, int mat) {
    for (int i = 0; i < n; i++) {
        if (a[i].matricula == mat) {
            printf("Encontrado: %s (nota %.2f)\n", a[i].nome, a[i].nota);
            return;
        }
    }
    printf("Matricula %d nao encontrada.\n", mat);
}

void maiorNota(Aluno a[], int n) {
    if (n == 0) return;
    int iMax = 0;
    for (int i = 1; i < n; i++)
        if (a[i].nota > a[iMax].nota) iMax = i;
    printf("Maior nota: %s (%.2f)\n", a[iMax].nome, a[iMax].nota);
}

int main(void) {
    Aluno alunos[MAX];
    int n = 0, op, mat;
    do {
        printf("\n1-Cadastrar 2-Listar 3-Buscar 4-Maior nota 0-Sair: ");
        scanf("%d", &op);
        if (op == 1) cadastrar(alunos, &n);
        else if (op == 2) listar(alunos, n);
        else if (op == 3) {
            printf("Matricula: ");
            scanf("%d", &mat);
            buscar(alunos, n, mat);
        } else if (op == 4) maiorNota(alunos, n);
    } while (op != 0);
    return 0;
}
