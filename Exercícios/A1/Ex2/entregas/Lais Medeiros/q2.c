#include <stdio.h>

void soma(int *a, int *b, int *resultado){
    *resultado = *a + *b;  // Soma os valores apontados por a e b, e guarda o resultado no local apontado por resultado
}

int main(){
    int x = 16, y = 24, res;

    soma(&x, &y, &res); // Chama a função passando os endereços de x, y e res

    printf("Resultado da soma: %d\n", res);

    return 0;
}
