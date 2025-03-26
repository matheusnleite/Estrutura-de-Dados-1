#include <stdio.h>
#include <stdlib.h>

int Particionamento(int *T, int imin, int imax){
    int v,i,j,temp;
    v = T[imax]; //pivo
    i = imin;
    j = imax-1;

    while(i<=j){
        while(i<imax && T[i]<=v){
            i++;
        }
        while (j>=imin && T[j]>= v){
            j--;
        }
        if(i<j){ //troca
            temp = T[i];
            T[i]=T[j];
            T[j]=temp;
        }
    }

    T[imax] = T[i];
    T[i] = v;
    return i;    
}

void ClassifRapid(int *T, int imin, int imax){
    int i;
    if (imin<imax){
        i = Particionamento(T, imin, imax);
        ClassifRapid(T, imin, i-1); //ordena parte esquerda
        ClassifRapid(T, i+1, imax); //ordena parte direita
    }
}

void QuickSort(int *T, int n){
    ClassifRapid(T, 0, n-1);
}

int main(){
    int T[] = {5, 2, 8, 3, 1, 7, 6, 4};
    int n = 8;

    printf("Vetor original: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", T[i]);
    }

    QuickSort(T, n);
    printf("\nVetor ordenado: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", T[i]);
    }
}