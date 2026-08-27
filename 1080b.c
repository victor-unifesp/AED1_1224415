/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Victor da Veiga Amaral Lopes
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1080
Data        : 27/08/2026
Objetivo    : achar o maior de 100 números com locação dinâmica
Dificuldade : uso da locação dinâmica
Uso de IA   : Não
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>

int main() {
    int j = 100;
    int *n= (int *) malloc(j * sizeof(int));
    if (n == NULL) return 1;
    int maior;
    int posicao=0;
    scanf("%d", &n[0]);
    maior = n[0];
    for(int i = 1; i<100; i++) {
        scanf("%d", &n[i]);
        if(n[i] > maior){
            maior = n[i];
            posicao = i+1;
        }
    }
    printf("%d\n%d\n", maior, posicao);
    free(n);
    return 0;
}
