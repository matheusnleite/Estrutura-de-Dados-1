#include <stdio.h>
#include <stdlib.h>
 
typedef float TipoDado;
 
typedef struct Cell {
  TipoDado dado;
  struct Cell *seguinte;
} TipoCelula;
 
void ImpDado(TipoDado dado){
  printf("%f\n", dado);
}
 
TipoDado LeituraDado(void){
  TipoDado dado;
  scanf("%f",&dado);
  return dado;
}
 
TipoCelula *InsCabl(TipoCelula *antigal, TipoDado dado) {
  TipoCelula *novaL = (TipoCelula *)malloc(sizeof(TipoCelula));
  novaL->dado = dado;
  novaL->seguinte = antigal;
  return novaL;
}
 
TipoCelula *CriacaoListaInvertida() {
  char escolha;
  TipoCelula *L= NULL;
  TipoDado dado;
  puts("Deseja criar uma lista? (s/n)");
  escolha = getchar();
  getchar();
  while (escolha == 's') {
    puts("Fornecer um dado!");
    dado = LeituraDado();
    getchar();
    L= InsCabl(L, dado); //inserção na cabela da lista
    puts("Inserir mais uma celula na frente da lista? (s/n)");
    escolha = getchar();
    getchar();
  }
  return L;
}
 
void ImprimeL(TipoCelula *L) {
  TipoCelula *p = L; //aponta para a primeira celula da lista
  while (p != NULL) {
   ImpDado(p->dado);
   p = p->seguinte;
  }
  puts("");
}
 
TipoCelula *Concatenacao2L(TipoCelula *L1, TipoCelula *L2) {
    if (L1 == NULL) {
        return L2;
    }
    if (L2 == NULL) {
        return L1;
    }
 
    TipoCelula *p = L1;
    while (p->seguinte != NULL) {
        p = p->seguinte;
    }
    p->seguinte = L2;
    return L1;
}
 
int main(void) {
  TipoCelula *L1, *L2, *LConcatenada;
 
  printf("Criando a primeira lista (L1):\n");
  L1 = CriacaoListaInvertida();
  ImprimeL(L1);
 
  printf("Criando a segunda lista (L2):\n");
  L2 = CriacaoListaInvertida();
  ImprimeL(L2);
 
  LConcatenada = Concatenacao2L(L1, L2);
  printf("Lista concatenada:\n");
  ImprimeL(LConcatenada);
 
  // Liberar memória
  TipoCelula *p, *temp;
    p = LConcatenada;
    while (p != NULL) {
        temp = p;
        p = p->seguinte;
        free(temp);
    }
 
  return 0;
}