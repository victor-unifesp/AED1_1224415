/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Victor da Veiga Amaral Lopes
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1077
Data        : 10/10/2026
Objetivo    : passar infixa pra posfixa
Dificuldade : organizar a entrada e saída da pilha
Uso de IA   : encontrar erros no código
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cel {
	char valor;
	struct cel *prox;
};
typedef struct cel cel;

void Inserecomeco(cel *cabeca, char c) {

    cel* novo = (cel*)malloc(sizeof(cel));
    novo->valor = c;
    novo->prox = cabeca->prox;
    cabeca->prox = novo;

}

void Desempilha(cel *cabeca) {
    if(cabeca->prox==NULL){
        return;
    }
    cel* atual = cabeca->prox;
    printf("%c", atual->valor);
    cabeca->prox = atual->prox;
    free(atual);
    
}

int peso (char c){
    if (c=='^'){
        return 3;
    }
    else if(c == '*' || c == '/'){
        return 2;
    }
    else if(c == '+' || c == '-'){
        return 1;
    }
    else return 0;
}
char BuscaUltimoValor(cel *cabeca){
    cel *atual = cabeca;
        while(atual->prox!=NULL) {
		atual = atual->prox;
	}
	return atual->valor;
}
int main()
{
	int n;
	char c = '\0';
	cel *cabeca = (cel*) malloc(sizeof(cel));
	cabeca->prox=NULL;
	int j=0;
	int f =  0;
	scanf("%d", &n);
	getchar();
	for(n; n>0; n--) {
		while ((c = getchar()) != '\n' && c != EOF && j < 1000) {
            if (c == ' ' || c == '\t') {
                continue;
            }
			if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
                while (cabeca->prox != NULL && peso(cabeca->prox->valor) >= peso(c)) {
                    Desempilha(cabeca);
                }
                Inserecomeco(cabeca, c);
			}
			else if(c == '(') {
			    Inserecomeco(cabeca, c);
			}
			else if (c == ')') {
                while (cabeca->prox != NULL && cabeca->prox->valor != '(') {
                    Desempilha(cabeca);
                }
                
                if (cabeca->prox != NULL && cabeca->prox->valor == '(') {
                    cel *temp = cabeca->prox;
                    cabeca->prox = temp->prox;
                    free(temp);
                }
			}
			else {
				printf("%c", c);
			}
		}
        while (cabeca->prox != NULL) {
            Desempilha(cabeca);
        }
        printf("\n"); 
	}
}
