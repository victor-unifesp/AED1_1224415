/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Victor da Veiga Amaral Lopes
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1068
Data        : 01/09/2026
Objetivo    : Ver se os "()" da expressão estão corretos
Dificuldade : uso da pilha
Uso de IA   : Localização de erros
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cel{
    int valor;
    struct cel *prox;
};
typedef struct cel cel;

void InsereFim(cel* cabeca, int valor){
    
    cel *novo = (cel*)malloc(sizeof(cel));
    
    novo->valor= valor;
    novo->prox= NULL;
    
    cel *atual=cabeca;
    while(atual->prox!=NULL){
        atual=atual->prox;
    }
    
    atual->prox=novo;
}

void Libera(cel* cabeca){
    
    cel* atual=cabeca->prox;

    cel* liberado;
    
    while(atual!=NULL){
        liberado=atual;
        atual=atual->prox;
        free(liberado);
    }
    
    cabeca->prox=NULL;
    
}

int Elimina(cel* cabeca){
    cel* atual;
    cel* liberado;
    cel* aux;
    
    if(cabeca->prox==NULL){
        printf("incorrect\n");
        return 1;
    }
    else{
        atual=cabeca->prox;
    }
    while(atual->prox!=NULL){
        atual=atual->prox;
    }
    if(cabeca->prox==atual){
        cabeca->prox=NULL;
        free(atual);
    }
    else{
        aux=cabeca->prox;
        while(aux->prox!=atual){
            aux=aux->prox;
        }
        free(atual);
        aux->prox=NULL;
    }
    return 0;
}

void Analisa(cel* cabeca, int n){
    if(cabeca->prox==NULL && n!=1){
        printf("correct\n");
    }
    else if(n!=1){
        printf("incorrect\n");
    }
}

int main(){
    cel cabeca;
    cabeca.prox=NULL;
    int n;

    char vetor[1001];
    
    while (scanf("%s", vetor) != EOF) {
        for(int i = 0; i<strlen(vetor);i++){
            n=0;
            if(vetor[i]=='(') InsereFim(&cabeca, vetor[i]);
            if(vetor[i]==')'){
                n = Elimina(&cabeca);
                if(n == 1){
                    break;
                }
            }
            
        }
        Analisa(&cabeca, n);
        Libera(&cabeca);
    }

    return 0;
}
