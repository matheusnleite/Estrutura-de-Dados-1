#ifndef LISTA_H
#define LISTA_H

typedef float TipoDado;

typedef struct Cell
{
    TipoDado dado;
    struct Cell *seguinte;
} TipoCelula;

TipoCelula *CriacaoLista(void);
TipoCelula *InsFimL(TipoCelula *L, TipoDado dado);
TipoCelula *RemocaoDadoL(TipoCelula *L, TipoDado dado);
void ImprimeL(TipoCelula *L);
void ImpDado(TipoDado dado);
TipoDado LeituraDado(void);
void LiberacaoL(TipoCelula **pL);

#endif