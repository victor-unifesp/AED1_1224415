/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Victor da Veiga Amaral Lopes
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/2448
Data        : 01/10/2026
Objetivo    : Achar a ordem e o tempo que o carteiro vai entregar as cartas
Dificuldade : uso da busca binária
Uso de IA   : não
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

int BuscaBinaria(int vetor[], int tamanho, int obj) {
    int inicio = 0, fim = tamanho - 1;
    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;
        if (vetor[meio] == obj) return meio;
        if (obj < vetor[meio]) fim = meio - 1;
        else inicio = meio + 1;
    }
    return -1;
}

int main(void){
    int n, m, x[45000];
    
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d", &x[i]);
    }
    
    int pos_atual = 0;
    long long tempo = 0;
    int destino;
    for(int i=0; i<m; i++){
        scanf("%d", &destino);
        int pos_final=BuscaBinaria(x, n , destino);
        
        tempo+=abs(pos_atual - pos_final);
        
        pos_atual=pos_final;
    }
    printf("%lld\n", tempo);
    return 0;
}
