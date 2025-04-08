#include <stdio.h>
#include <stdlib.h>
 
typedef float TipoDado;
 
typedef struct Cell {
  TipoDado dado;
  struct Cell *seguinte;
} TipoCelula;
 
void ImpDado(TipoDado dado){
  printf("%.2f\n", dado);
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
 

 
int main(void) {
  TipoCelula *L1;
 
  printf("Criando a  lista (L1):\n");
  L1 = CriacaoListaInvertida();
  ImprimeL(L1);
 
  
 
  // Liberar memória
  TipoCelula *p, *temp;
    p = L1;
    while (p != NULL) {
        temp = p;
        p = p->seguinte;
        free(temp);
    }
 
  return 0;
}