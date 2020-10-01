#include <stdio.h>
#include <stdlib.h>
#include "Lista_EDA2.h"

TAB* criar_arv(int n, TAB *filha_esq, TAB *filha_dir){
    TAB *nova_arv = (TAB*)malloc(sizeof(TAB));
    nova_arv->info = n;
    nova_arv->esq = filha_esq;
    nova_arv->dir = filha_dir;
}

void imprimir_arv(TAB* arv){
    if (arv != NULL){
        printf("numero arv: %d\n", arv->info);
        imprimir_arv(arv->esq);
        imprimir_arv(arv->dir);
    }
}

TAB* copia(TAB* a){
    if (a == NULL){
        return NULL;
    }
    else{
        TAB* nova_arv = (TAB*)malloc(sizeof(TAB));
        nova_arv->info = a->info;
        nova_arv->esq = copia(a->esq);
        nova_arv->dir = copia(a->dir);
        return nova_arv;
    }
}

TAB* espelho(TAB* a){
    if (a == NULL){
        return NULL;
    }
    else{
        TAB* nova_arv = (TAB*)malloc(sizeof(TAB));
        nova_arv->info = a->info;
        nova_arv->esq = espelho(a->dir);
        nova_arv->dir = espelho(a->esq);
        return nova_arv;
    }
}

TAB* maior_nodulo(TAB *a, TAB* b){
    if (a != NULL && b != NULL){
        if (a->info > b->info){
            return a;
        }
        return b;
    }
    
    else if (a != NULL && b == NULL){
        return a;
    }

    else if (a == NULL && b != NULL){
        return b;
    }

    else{
        return NULL;
    }
}

TAB* maior(TAB *a){
    if (a == NULL){
        return NULL;
    }
    else{
        TAB* comparacao_filhas = maior_nodulo(maior(a->esq), maior(a->dir));
        
        if (comparacao_filhas == NULL){
            return a;
        }
        else{
            return maior_nodulo(a, comparacao_filhas);
        }
    }
}

TAB* menor_nodulo(TAB* a, TAB* b){
    if (a != NULL && b != NULL){
        if (a->info < b->info){
            return a;
        }
        return b;
    }
    else if (a != NULL && b == NULL){
        return a;
    }
    else if (a == NULL && b != NULL){
        return b;
    }
    else{
        return NULL;
    }
}

TAB* menor(TAB* a){
    if (a == NULL){
        return NULL;
    }
    else{
        TAB* comparacao_filhas = menor_nodulo(menor(a->esq), menor(a->dir));

        if (comparacao_filhas == NULL){
            return a;
        }
        else{
            return menor_nodulo(a, comparacao_filhas);
        }
    }
}

int igual(TAB* a1, TAB* a2){
    if (a1 == NULL && a2 == NULL){
        return 1;
    }
    else if ((a1 != NULL && a2 == NULL) || (a1 == NULL && a2 != NULL)){
        return 0;
    }
    else{
        if (a1->info == a2->info){
            return (igual(a1->esq, a2->esq) && igual (a1->dir, a2->dir));
        }
        else{
            return 0;
        }
    }
}

TAB* retira_pares(TAB* arv){
    if (arv->esq == NULL && arv->dir == NULL){
        if (arv->info % 2 == 0){
            free(arv);
            return NULL;
        }
        else{
            return arv;
        }
    }
    else{
        if (arv->info % 2 == 0){
            if (arv->esq != NULL && arv->esq->info % 2 != 0){
                int temp = arv->info;
                arv->info = arv->esq->info;
                arv->esq->info = temp;
            }
            else if (arv->dir != NULL && arv->dir->info % 2 != 0){
                int temp = arv->info;
                arv->info = arv->dir->info;
                arv->dir->info = temp;
            }
        }
        
        arv->esq = retira_pares(arv->esq);
        arv->dir = retira_pares(arv->dir);

    }
}

int altura_arv_bal(TABC* arv){
    if (arv == NULL){
        return 0;
    }
    else{
        int altura = (int) ((1 + altura_arv_bal(arv->esq)) + (1 + altura_arv_bal(arv->dir))) / 2;
    }
}

TABC* criar_arv_bal(int n , TABC* filha_esq, TABC* filha_dir){
    TABC* novo_arv_bal = (TABC*)malloc(sizeof(TABC));
    novo_arv_bal->info = n;
    novo_arv_bal->esq = filha_esq;
    novo_arv_bal->dir = filha_dir;
    return novo_arv_bal;
}

void print_arv_bal(TABC* arv){
    if (arv != NULL){
        printf("info: %d\n", arv->info);
        printf("cor: %s\n", arv->cor);
        print_arv_bal(arv->esq);
        print_arv_bal(arv->dir);
    }
}

void colore(TABC** arv){
    TABC* temp = *arv;
    int altura_atual = altura_arv_bal(temp);

    if(altura_atual == 0){
        return;
    }
    else{
        if (altura_atual % 2 == 0){
            temp->cor = "vermelho";
        }
        else{
            temp->cor = "preto";
        }
        colore(&temp->esq);
        colore(&temp->dir);
    }
    
}

int ni(TAB* a){
    if (a == NULL){
        return 0;
    }
    else{
        return 1 + ni(a->esq) + ni(a->dir);
    }
}

int nf(TAB* a){
    if (a->esq == NULL && a->dir == NULL){
        return 1;
    }
    else{
        return nf(a->esq) + nf(a->dir);
    }
}