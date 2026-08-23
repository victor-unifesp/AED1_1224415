/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Victor da Veiga Amaral Lopes
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1080
Data        : 22/08/2026
Objetivo    : ler 100 valores e mostrar o maior e sua posição na ordem
Dificuldade : achar o valor inicial para comparação
Uso de IA   : Não
-------------------------------------------------------------------------- */
#include <stdio.h>

int main() {
    int n[100];
    int maior;
    int posicao;
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
    return 0;
}
