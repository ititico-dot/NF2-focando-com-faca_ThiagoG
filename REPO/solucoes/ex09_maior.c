#include <stdio.h>

int maior(int v[], int n) {
    int m = v[0];
    for (int i = 1; i < n; i++)
        if (v[i] > m) m = v[i];
    return m;
}

int main(void) {
    int v[] = {4, 9, 1, 15, 3};
    printf("Maior = %d\n", maior(v, 5));
    return 0;
}
