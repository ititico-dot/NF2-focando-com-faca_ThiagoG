/* Exercício 08 - Busca linear O(n) vs binária O(log n) */
#include <stdio.h>

int buscaLinear(int v[], int n, int x) {
    for (int i = 0; i < n; i++)
        if (v[i] == x) return i;
    return -1;
}

int buscaBinaria(int v[], int n, int x) {
    int ini = 0, fim = n - 1;
    while (ini <= fim) {
        int meio = ini + (fim - ini) / 2;
        if (v[meio] == x) return meio;
        if (v[meio] < x) ini = meio + 1;
        else fim = meio - 1;
    }
    return -1;
}

int main(void) {
    int v[] = {1, 3, 5, 7, 9, 11, 13};
    int n = 7, x = 7;
    printf("Linear: indice %d (O(n))\n", buscaLinear(v, n, x));
    printf("Binaria: indice %d (O(log n), vetor ordenado)\n", buscaBinaria(v, n, x));
    return 0;
}
