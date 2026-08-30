/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Victor da Veiga Amaral Lopes
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1110
Data        : 30/08/2026
Objetivo    : Pilha de n cartas em que era necessário encontrar a última restante
Dificuldade : uso de ponteiros de lista
Uso de IA   : Localização de erros
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>

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

void Imprime(cel* cabeca){
    cel *item=cabeca->prox;
    while(item!=NULL){
        if(item->prox!=NULL){
        printf(" %d,", item->valor);
        }
        else{
            printf(" %d\n", item->valor);
        }
        item=item->prox;
    }
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

void RetiraEnfia(cel* cabeca, cel* cabeca2){
    cel* atual;
    cel* resto;
    cel* liberado;
    
    atual=cabeca->prox;
    InsereFim(cabeca2, atual->valor);
    
    liberado=atual;
    atual=atual->prox;
    free(liberado);
    
    resto=atual;
    
    while(resto->prox!=NULL){
        resto=resto->prox;
    }
    
    resto->prox=atual;
    
    if(atual->prox!=NULL){
        cabeca->prox=atual->prox;
    }
    else{
        cabeca->prox=atual;
    }
    atual->prox=NULL;
    
}

int main(){
    cel cabeca;
    cel cabeca2;
    cabeca.prox=NULL;
    cabeca2.prox=NULL;
    int n;
    scanf("%d", &n);
    while(n!=0){
        for(int i=1; i<n+1; i++){
            InsereFim(&cabeca, i);
        }
        for(int i=0; i<n-1; i++){
            RetiraEnfia(&cabeca,&cabeca2);
        }
        if(n!=1){
            printf("Discarded cards:");
            Imprime(&cabeca2);
        }
        printf("Remaining card:");
        Imprime(&cabeca);
        Libera(&cabeca);
        Libera(&cabeca2);
        scanf("%d", &n);
    }
    
    return 0;
}
