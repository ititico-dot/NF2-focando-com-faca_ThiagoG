/* Exercício 07 - Controle de notas */
#include <stdio.h>

int main(void) {
    int n;
    printf("Quantidade de alunos: ");
    scanf("%d", &n);
    if (n <= 0) return 0;
    float nota, soma = 0, maior, menor;
    int aprov = 0;
    for (int i = 0; i < n; i++) {
        printf("Nota %d: ", i + 1);
        scanf("%f", &nota);
        soma += nota;
        if (i == 0 || nota > maior) maior = nota;
        if (i == 0 || nota < menor) menor = nota;
        if (nota >= 7.0f) aprov++;
    }
    printf("Media: %.2f\nMaior: %.2f\nMenor: %.2f\nAprovados: %d\n",
           soma / n, maior, menor, aprov);
    return 0;
}
