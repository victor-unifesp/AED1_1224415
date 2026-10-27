/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Victor da Veiga Amaral Lopes
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1200
Data        : 27/10/2026
Objetivo    : Imprimir uma árvore por largura
Dificuldade : impressão correta do output
Uso de IA   : Localização de erros, aprendizado da função PorNivel
-------------------------------------------------------------------------- */
#include <stdlib.h>
#include <stdio.h>

typedef struct cel{
    int valor;
    struct cel *dir;
    struct cel *esq;
} cel;

int primeiro;

cel* CriaNovo(int valor){
    cel *novo = (cel*)malloc(sizeof(cel));
    if(novo==NULL) exit(1);
    novo->valor = valor;
    novo->dir = NULL;
    novo->esq = NULL;
    return novo;
}

cel* NovoItem(int valor, cel* raiz) {
    
    if (raiz == NULL) {
        return CriaNovo(valor);
    }
    
    cel* p = raiz;
    
    while(p->dir != NULL && valor>=p->valor || p->esq != NULL && valor<p->valor){
        
        if(valor>=p->valor){
            p = p->dir;
        }
        else{
            p = p->esq;
        }
    }
    
    if(valor>=p->valor){
        p->dir = CriaNovo(valor);
    }
    else{
        p->esq = CriaNovo(valor);
    }
    return raiz;
}

void PorNivel(cel *raiz) {
    if (raiz == NULL) return;
    
    cel* fila[550];
    int inicio = 0;
    int fim = 0;

    fila[fim++] = raiz;

    int primeiro = 1;
    
    while (inicio < fim) {
        cel *atual = fila[inicio++];
        if (!primeiro) {
            printf(" ");
        }
        printf("%d", atual->valor);
        primeiro = 0;
        if (atual->esq != NULL) {
            fila[fim++] = atual->esq;
        }
        if (atual->dir != NULL) {
            fila[fim++] = atual->dir;
        }
    }
    printf("\n");
}

void LiberaArvore(cel *r) {
    if (r != NULL) {
        LiberaArvore(r->esq);
        LiberaArvore(r->dir);
        free(r);
    }
}

int main (){
    int c, x, y;
    scanf("%d", &c);
    cel *raiz = (cel*)malloc(sizeof(cel));
    if(raiz==NULL) exit(1);
    raiz = NULL;
    for(int i = 0; i<c; i++){
        scanf("%d", &x);
        for(int j = 0; j<x; j++){
            scanf("%d", &y);
            raiz = NovoItem(y, raiz);
        }
        printf("Case %d:\n", i+1);
        primeiro = 1;
        PorNivel(raiz);
        printf("\n");
        LiberaArvore(raiz);
        raiz = NULL;
    }
}
