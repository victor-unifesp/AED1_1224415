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

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int destino;
    struct No *prox;
} No;

No *grafo[10001];
int cor[10001];

int dfs(int u) {
    cor[u] = 1;

    No *atual = grafo[u];

    while (atual != NULL) {
        int v = atual->destino;

        if (cor[v] == 1)
            return 1;

        if (cor[v] == 0) {
            if (dfs(v))
                return 1;
        }

        atual = atual->prox;
    }

    cor[u] = 2;
    return 0;
}

int main() {
    int t, n, m;

    scanf("%d", &t);

    while (t--) {
        scanf("%d %d", &n, &m);

        for (int i = 1; i <= n; i++) {
            grafo[i] = NULL;
            cor[i] = 0;
        }

        for (int i = 0; i < m; i++) {
            int a, b;
            scanf("%d %d", &a, &b);

            No *novo = malloc(sizeof(No));
            novo->destino = b;
            novo->prox = grafo[a];
            grafo[a] = novo;
        }

        int ciclo = 0;

        for (int i = 1; i <= n; i++) {
            if (cor[i] == 0) {
                if (dfs(i)) {
                    ciclo = 1;
                    break;
                }
            }
        }

        if (ciclo)
            printf("SIM\n");
        else
            printf("NAO\n");

        for (int i = 1; i <= n; i++) {
            No *atual = grafo[i];

            while (atual != NULL) {
                No *temp = atual;
                atual = atual->prox;
                free(temp);
            }
        }
    }

    return 0;
}
