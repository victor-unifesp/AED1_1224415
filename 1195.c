/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Victor da Veiga Amaral Lopes
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1195
Data        : 22/10/2026
Objetivo    : Escrever a árvore de maneira pre in e post
Dificuldade : Aprender como a árvore funciona
Uso de IA   : Localização de erros
-------------------------------------------------------------------------- */
#include <stdlib.h>
#include <stdio.h>

typedef struct cel{
    int valor;
    struct cel *dir;
    struct cel *esq;
} cel;

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

void Erd (cel *r) {
    if (r != NULL) {
        Erd (r->esq);
        printf (" %d", r->valor);
        Erd (r->dir);
    }
}

void Red (cel *r) {
    if (r != NULL) {
        printf (" %d", r->valor);
        Red (r->esq);
        Red (r->dir);
    }
}

void Edr (cel *r) {
    if (r != NULL) {
        Edr (r->esq);
        Edr (r->dir);
        printf (" %d", r->valor);
    }
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
        printf("Pre.:");
        Red(raiz);
        printf("\n");
        printf("In..:");
        Erd(raiz);
        printf("\n");
        printf("Post:");
        Edr(raiz);
        printf("\n");
        printf("\n");
        LiberaArvore(raiz);
        raiz = NULL;
    }
}
