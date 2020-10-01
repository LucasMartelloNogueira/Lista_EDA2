#include <stdio.h>
#include <stdlib.h>
#include "Lista_EDA2.h"

void questao_1(){
    // criando a funcao "copia" que retorna uma copia da arvore fornecida
    TAB* b = criar_arv(3, NULL, NULL);
    TAB* c = criar_arv(4, NULL, NULL);
    TAB* a = criar_arv(5, b, c);

    TAB* arv_copia = copia(a);
    
    printf("Arvore antiga: \n");
    imprimir_arv(a);
    printf("-------------\n");
    printf("arvore nova: \n");
    imprimir_arv(arv_copia);
}

void questao_2(){
    // criando a funcao "espelho" que retorna o espelho da arvore fornecida
    TAB* b = criar_arv(2, NULL, NULL);
    TAB* c = criar_arv(3, NULL, NULL);
    TAB* a = criar_arv(1, b, c);

    TAB* arv_espelho = espelho(a);
    
    printf("Arvore antiga: \n");
    imprimir_arv(a);
    printf("-------------\n");
    printf("arvore nova: \n");
    imprimir_arv(arv_espelho);
}

void questao_3(){
    // criando a funcao "maior" que retorna o maior nodulo da arvore
    TAB* b = criar_arv(2, NULL, NULL);
    
    TAB* d = criar_arv(4, NULL, NULL);
    TAB* e = criar_arv(5, NULL, NULL);
    
    TAB* c = criar_arv(3, d, e);
    
    TAB* a = criar_arv(1, b, c);
    
    TAB* maior_nodulo = maior(a);
    
    printf("o maior nodulo tem valor: %d\n", maior_nodulo->info);
}

void questao_4(){
    // criando a funcao "menor" que retorna o menor nodulo da arvore
    TAB* b = criar_arv(2, NULL, NULL);
    
    TAB* d = criar_arv(4, NULL, NULL);
    TAB* e = criar_arv(5, NULL, NULL);
    
    TAB* c = criar_arv(3, d, e);
    
    TAB* a = criar_arv(1, b, c);
    
    TAB* menor_nodulo = menor(a);
    
    printf("o menor nodulo tem valor: %d\n", menor_nodulo->info);
}

void questao_5(){
    // criando a funcao "igual" que analisa duas arvores:
    // retorna 1, se as arvores sao iguais
    // retorna 0, se as arvores sao diferentes

    TAB* b1 = criar_arv(2, NULL, NULL);
    TAB* c1 = criar_arv(3, NULL, NULL);
    TAB* a1 = criar_arv(1, b1, c1);

    TAB* b2 = criar_arv(2, NULL, NULL);
    TAB* c2 = criar_arv(4, NULL, NULL);
    TAB* a2 = criar_arv(1, b2, c2);

    int resultado_comparacao = igual(a1, a2);

    if (resultado_comparacao == 1){
        printf("as arvores sao iguais\n");
    }
    else{
        printf("as arvores sao diferentes\n");
    }
}

void questao_6(){
    TAB* b = criar_arv(2, NULL, NULL);
    TAB* d = criar_arv(4, NULL, NULL);
    TAB* e = criar_arv(5, NULL, NULL);
    TAB* c = criar_arv(3, d, e);
    TAB* a = criar_arv(1, b, c);

    printf("arvore antes: \n");
    imprimir_arv(a);

    a = retira_pares(a);

    printf("arvore depois: \n");
    imprimir_arv(a);
}

void questao_7(){
    // criando a funcao "colore" que colore alternadamente os nodulos da arvore
    // ta meio bugada, dependendo do tamanho a raiz comeca com uma cor diferente
    TABC* d = criar_arv_bal(4, NULL, NULL);
    TABC* e = criar_arv_bal(5, NULL, NULL);
    TABC* b = criar_arv_bal(2, d, e);
    
    TABC* f = criar_arv_bal(6, NULL, NULL);
    TABC* g = criar_arv_bal(7, NULL, NULL);
    TABC* c = criar_arv_bal(3, f, g);
    
    TABC* a = criar_arv_bal(1, b, c);
    
    colore(&a);

    print_arv_bal(a);
}

void questao_8(){
    // criando a funcao "ni" que retorna a qnt de nos internos de uma arvore
    TAB* b = criar_arv(2, NULL, NULL);
    TAB* d = criar_arv(4, NULL, NULL);
    TAB* e = criar_arv(5, NULL, NULL);
    TAB* c = criar_arv(3, d, e);
    TAB* a = criar_arv(1, b, c);

    int qnt_nos = ni(a);
    printf("a arvore tem %d nos\n", qnt_nos);

}

void questao_9(){
    // criando a funcao "ni" que retorna a qnt de nos folha de uma arvore binaria
    TAB* b = criar_arv(2, NULL, NULL);
    TAB* d = criar_arv(4, NULL, NULL);
    TAB* e = criar_arv(5, NULL, NULL);
    TAB* c = criar_arv(3, d, e);
    TAB* a = criar_arv(1, b, c);

    int qnt_folhas = nf(a);
    printf("a qnt de folhas eh: %d\n", qnt_folhas);
}

int main(void){
    
    //questao_1();
    //questao_2();
    //questao_3();
    //questao_4();
    //questao_5();
    //questao_6();
    //questao_7();
    //questao_8();
    //questao_9();

    return 0;
}
