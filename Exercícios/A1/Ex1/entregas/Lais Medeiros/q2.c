#include <stdio.h>

void trocar(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 10, y = 20;
    trocar(x, y);
    printf("x = %d, y = %d\n", x, y);
    return 0;
}