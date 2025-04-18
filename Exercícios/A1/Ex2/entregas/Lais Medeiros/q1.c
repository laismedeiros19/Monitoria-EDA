#include <stdio.h>

int main(){
    int x = 42;    
    int *p;          

    p = &x;          

    
    printf("Valor de x: %d\n", x); // Mostra o valor armazenado em x
    printf("Endereco de x: %p\n", &x); // Mostra o endereço de memória onde está armazenado o x
    printf("Valor de p: %p\n", p); // Mostra o valor de p 
    printf("Valor apontado por p: %d\n", *p); // Mostra o valor armazenado no endereço apontado por p

    return 0;
}
