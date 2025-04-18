#include <stdio.h>

void trocar(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main(){
    int a = 5, b = 10;

    // Antes da troca
    printf("a = %d, b = %d\n", a, b);

    // Troca os valores de a e b
    trocar(&a, &b); 

    // Depois da troca
    printf("a = %d, b = %d\n", a, b);

    return 0;
}
