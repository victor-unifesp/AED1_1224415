/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Victor da Veiga Amaral Lopes
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1200
Data        : 26/10/2026
Objetivo    : Escrever e fazer comandos em uma árvore
Dificuldade : impressão correta do output
Uso de IA   : Localização de erros
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cel {
    char valor;
    struct cel *dir;
    struct cel *esq;
} cel;

cel* CriaNovo(int valor) {
    cel *novo = (cel*)malloc(sizeof(cel));
    if (novo == NULL) exit(1);
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
    
    while ((p->dir != NULL && valor >= p->valor) || (p->esq != NULL && valor < p->valor)) {
        if (valor >= p->valor) {
            p = p->dir;
        } else {
            p = p->esq;
        }
    }
    
    if (valor >= p->valor) {
        p->dir = CriaNovo(valor);
    } else {
        p->esq = CriaNovo(valor);
    }
    return raiz;
}
int x;

void Erd(cel *r) {
    if (r != NULL) {
        Erd(r->esq);
        if (x==0) {
            printf(" ");
        }
        printf("%c", r->valor);
        x = 0;
        Erd(r->dir);
    }
}

void Red(cel *r) {
    if (r != NULL) {
        if (x==0) {
            printf(" ");
        }
        printf("%c", r->valor);
        x = 0;
        Red(r->esq);
        Red(r->dir);
    }
}

void Edr(cel *r) {
    if (r != NULL) {
        Edr(r->esq);
        Edr(r->dir);
        if (x==0) {
            printf(" ");
        }
        printf("%c", r->valor);
        x = 0;
    }
}

void LiberaArvore(cel *r) {
    if (r != NULL) {
        LiberaArvore(r->esq);
        LiberaArvore(r->dir);
        free(r);
    }
}

void Busca(char k, cel *r) {
    if (r == NULL) {
        printf("%c nao existe\n", k);
        return;
    }
    if (r->valor == k) {
        printf("%c existe\n", k);
        return;
    }
    if (r->valor > k) {
        return Busca(k, r->esq);
    } else {
        return Busca(k, r->dir);
    }
}

int main() {
    char Info[20], valor;
    cel *raiz = NULL;
    
    
    while (scanf("%s", Info) != EOF) {
        if (strcmp(Info, "I") == 0) {
            scanf(" %c", &valor);
            raiz = NovoItem(valor, raiz);
        }
        if (strcmp(Info, "PREFIXA") == 0) {
            x = 1;
            Red(raiz);
            printf("\n");
        }
        if (strcmp(Info, "INFIXA") == 0) {
            x=1;
            Erd(raiz);
            printf("\n");
        }
        if (strcmp(Info, "POSFIXA") == 0) {
            x=1;
            Edr(raiz);
            printf("\n");
        }
        if (strcmp(Info, "P") == 0) {
            scanf(" %c", &valor);
            Busca(valor, raiz);
        }
    }

    return 0;
}
