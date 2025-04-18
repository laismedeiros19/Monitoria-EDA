#include <stdio.h>

void dobra(int *n) { //funçao dobra com um ponteiro inteiro.
    *n = *n * 2;  // *n diz que o valor da variavel apontado multiplicará por 2.
  }
  
  int main() {
    int x = 4;
    dobra(&x); //A função é chamada e vai alterar o valor da variavel x.
    printf("%d\n", x); //sera impresso o valor 8
  
    return 0; 
  }