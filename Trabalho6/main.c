#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

int main(void) {
    TipoCelula *L = NULL;
    TipoDado dado;
    
   
    L = CriacaoLista();
    
    printf("Lista criada:\n");
    ImprimeL(L);
    
    
    printf("Digite o dado que deseja remover:\n");
    dado = LeituraDado();
    getchar();
    
    L = RemocaoDadoL(L, dado);
    
    printf("Lista apos remocao:\n");
    ImprimeL(L);
    
    LiberacaoL(&L);
    
    return 0;
}
