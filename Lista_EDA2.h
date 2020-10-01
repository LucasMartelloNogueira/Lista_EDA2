#include <stdio.h>
#include <stdlib.h>

typedef struct ab{
    int info;
    struct ab *esq, *dir;
} TAB;

TAB* criar_arv(int n, TAB *filha_esq, TAB *filha_dir);

void imprimir_arv(TAB* arv);

TAB* copia(TAB *a);

TAB* espelho(TAB* a);

TAB* maior_nodulo(TAB *a, TAB* b);

TAB* maior(TAB *a);

TAB* menor_nodulo(TAB* a, TAB* b);

TAB* menor(TAB* a);

int igual(TAB* a1, TAB* a2);

TAB* retira_pares(TAB* arv);

typedef struct abc{
    int info;
    char* cor;
    struct abc *esq, *dir;
} TABC;

int altura_arv_bal(TABC* arv);

TABC* criar_arv_bal(int n , TABC* filha_esq, TABC* filha_dir);

void print_arv_bal(TABC* arv);

void colore(TABC** arv);

int ni(TAB* a);

int nf(TAB* a);