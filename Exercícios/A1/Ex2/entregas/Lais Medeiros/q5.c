#include <stdio.h>

void modificar(int *vetor, int tamanho){
    for(int i = 0; i < tamanho; i++){ 
        *(vetor + i) *= 2;  // Multiplica cada elemento por 2
    }
}

int main(){
    int v[5];

    // Leitura dos 5 valores
    for(int i = 0; i < 5; i++){ //loop até 5
        scanf("%d", &v[i]);
    }

    modificar(v, 5);  // Chamada da função

    // Impressão dos valores modificados
    for(int i = 0; i < 5; i++){
        printf("%d ", v[i]);
    }

    return 0;
}
