#include <stdio.h>

int pilha[100];
int topo = -1;

void push(int x) {
    if (topo == 99) {
        printf("Overflow\n");
        return;
    }
    pilha[++topo] = x;
}

int pop(void) {
    if (topo == -1) {
        printf("Underflow\n");
        return -1;
    }
    return pilha[topo--];
}

int main(void) {
    push(2);
    push(7);
    push(9);
    printf("pop = %d\n", pop()); /* 9 */
    push(15);
    printf("topo = %d\n", pilha[topo]); /* 15 */
    printf("pilha: ");
    for (int i = 0; i <= topo; i++) printf("%d ", pilha[i]);
    printf("\n");
    return 0;
}
