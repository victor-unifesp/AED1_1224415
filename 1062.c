/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Victor da Veiga Amaral Lopes
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1062
Data        : 14/10/2026
Objetivo    : Verificar se os números que chegam em ordem crescente podem desempilhar da forma escrita
Dificuldade : organização dos valores
Uso de IA   : Localização de erros
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>

struct cel {
    int valor;
    struct cel *prox;
};

typedef struct cel cel;

void Push(cel *cabeca, int valor) {
    cel *novo = (cel*)malloc(sizeof(cel));
    novo->valor = valor;
    novo->prox = cabeca->prox;
    cabeca->prox = novo;
}


void Pop(cel *cabeca) {
    if (cabeca->prox == NULL) return;
    cel *liberado = cabeca->prox;
    cabeca->prox = liberado->prox;
    free(liberado);
}


int Top(cel *cabeca) {
    if (cabeca->prox == NULL) return -1;
    return cabeca->prox->valor;
}

void Limpa(cel *cabeca) {
    cel *atual = cabeca->prox;
    cel *liberado;
    while (atual != NULL) {
        liberado = atual;
        atual = atual->prox;
        free(liberado);
    }
    cabeca->prox = NULL;
}

int main() {
    int quantidade;
    int numeros[1001];

    cel *cabeca = (cel*)malloc(sizeof(cel));
    cabeca->prox = NULL;

    cel *cabeca2 = (cel*)malloc(sizeof(cel));
    cabeca2->prox = NULL;

    while (scanf("%d", &quantidade) == 1 && quantidade != 0) {
        while (1) {
            int Primeirovalor;
            
            scanf("%d", &Primeirovalor);
            if (Primeirovalor == 0) {
                break;
            }
            
            numeros[quantidade - 1] = Primeirovalor;
            for (int i = quantidade - 2; i >= 0; i--) {
                scanf("%d", &numeros[i]);
            }
            
            int esperado = quantidade;
            
            for (int i = 0; i < quantidade; i++) {
                Push(cabeca, numeros[i]);
                
                while (cabeca->prox != NULL && Top(cabeca) == esperado) {
                    Push(cabeca2, Top(cabeca));
                    Pop(cabeca);
                    esperado--;
                }
            }
            if (esperado == 0) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
            Limpa(cabeca);
            Limpa(cabeca2);
        }
        printf("\n");
    }

    free(cabeca);
    free(cabeca2);
    return 0;
}
