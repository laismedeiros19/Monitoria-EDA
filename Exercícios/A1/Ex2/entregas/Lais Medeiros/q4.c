#include <stdio.h>

void verificar(int *ptr){
    if(ptr != NULL){
        *ptr = *ptr * 2;  // Dobra o valor apontado
    }
}

int main(){
    int x = 7;
    int *p1 = NULL;
    int *p2 = &x;

    verificar(p1); // Ponteiro nulo
    verificar(p2); // Ponteiro válido

    printf("x = %d\n", x); // Mostra o valor final de x

    return 0;
}
