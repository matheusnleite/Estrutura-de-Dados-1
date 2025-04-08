#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"



void ImpDado(TipoDado dado) {
    printf("%.2f ", dado);
}


TipoDado LeituraDado(void) {
    TipoDado dado;
    scanf("%f", &dado);
    return dado;
}


TipoCelula* InsFimL(TipoCelula* L, TipoDado dado) {
    TipoCelula *p, *novo;
    
    novo = (TipoCelula*)malloc(sizeof(TipoCelula));
    if(novo == NULL) {
        printf("Erro de alocacao!\n");
        exit(1);
    }
    novo->dado = dado;
    novo->seguinte = NULL;
    
    if(L == NULL) {
        
        return novo;
    }
    else {
        
        p = L;
        while(p->seguinte != NULL)
            p = p->seguinte;
        p->seguinte = novo;
        return L;
    }
}


TipoCelula* CriacaoLista(void) {
    TipoCelula *L = NULL;
    TipoDado dado;
    char escolha;
    
    printf("Deseja criar uma lista? (s/n)\n");
    escolha = getchar();
    getchar(); 
    
    while(escolha == 's') {
        printf("Fornecer um dado:\n");
        dado = LeituraDado();
        getchar(); 
        L = InsFimL(L, dado);
        printf("Inserir mais uma celula? (s/n)\n");
        escolha = getchar();
        getchar(); 
    }
    return L;
}


TipoCelula* RemocaoDadoL(TipoCelula* L, TipoDado dado) {
    TipoCelula *ant, *atual;
    ant = NULL;
    atual = L;

    while(atual != NULL && atual->dado != dado) {
        ant = atual;
        atual = atual->seguinte;
    }
    
    if(atual == NULL) {
        printf("Dado nao encontrado na lista.\n");
        return L;
    }
    

    if(ant == NULL)
        L = atual->seguinte;
    else
        ant->seguinte = atual->seguinte;
    
    free(atual);
    return L;
}


void ImprimeL(TipoCelula* L) {
    TipoCelula *p = L;
    while(p != NULL) {
        ImpDado(p->dado);
        p = p->seguinte;
    }
    printf("\n");
}


void LiberacaoL(TipoCelula **pL) {
    TipoCelula *p;
    while(*pL != NULL) {
        p = *pL;
        *pL = (*pL)->seguinte;
        free(p);
    }
    *pL = NULL;
}