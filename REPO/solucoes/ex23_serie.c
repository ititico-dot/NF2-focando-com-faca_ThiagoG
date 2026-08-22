/* Exercício 23 - TAD Série (Leibniz + Taylor e^x) */
#include <stdio.h>

typedef struct {
    int quantidade;
    double soma;
    double termos[1000];
} Serie;

void inicializar(Serie *s, int quantidade) {
    if (quantidade > 1000) quantidade = 1000;
    if (quantidade < 0) quantidade = 0;
    s->quantidade = quantidade;
    s->soma = 0.0;
    for (int i = 0; i < quantidade; i++) s->termos[i] = 0.0;
}

void calcularLeibniz(Serie *s) {
    s->soma = 0.0;
    for (int k = 0; k < s->quantidade; k++) {
        double sinal = (k % 2 == 0) ? 1.0 : -1.0;
        s->termos[k] = sinal / (2.0 * k + 1.0);
        s->soma += s->termos[k];
    }
}

double calcularPi(Serie *s) {
    return 4.0 * s->soma;
}

void imprimirSerie(Serie *s) {
    printf("Termos:\n");
    for (int i = 0; i < s->quantidade; i++)
        printf("%f\n", s->termos[i]);
}

/* e^x = sum x^k / k!  — cada termo a partir do anterior */
double calcularTaylor(Serie *s, double x) {
    s->soma = 0.0;
    double termo = 1.0;
    for (int k = 0; k < s->quantidade; k++) {
        s->termos[k] = termo;
        s->soma += termo;
        termo *= x / (k + 1);
    }
    return s->soma;
}

int main(void) {
    int n;
    printf("Quantidade de termos: ");
    if (scanf("%d", &n) != 1) return 1;
    Serie s;
    inicializar(&s, n);
    calcularLeibniz(&s);
    imprimirSerie(&s);
    printf("\nValor aproximado de PI:\n%f\n", calcularPi(&s));

    printf("\n(Desafio) e^1 com os mesmos n termos: %f\n", calcularTaylor(&s, 1.0));
    return 0;
}
