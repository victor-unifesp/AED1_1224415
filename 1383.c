/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Victor da Veiga Amaral Lopes
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1383
Data        : 23/08/2026
Objetivo    : Resolvedor de sudoku
Dificuldade : comparação 3x3
Uso de IA   : Não
-------------------------------------------------------------------------- */
#include <stdio.h>

int RESOLVER9X9(int matriz[9][9]){
    for (int x = 0; x<9; x++){
        for(int y = 0; y<9; y++){
            for(int i = 0; i<9; i++){
                if(i!=x){
                    if(matriz[x][y]==matriz[i][y]){
                        return 0;
                    }
                }
                if(i!=y){
                    if(matriz[x][y]==matriz[x][i]){
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}

int RESOLVER3X3(int matriz[9][9]){
    int c, l, i, j, bl, bc;
    for(bl=0; bl<9; bl+=3){
       for(bc=0;bc<9;bc+=3){
           for(l=bl;l<bl+3;l++){
               for(c=bc;c<bc+3;c++){
                    for(i=bl;i<bl+3;i++){
                        for(j=bc;j<bc+3;j++){
                            if((c!=j || l!=i) && matriz[l][c]==matriz[i][j]){
                                return 0;
                            }
                        }    
                    }        
               }
           }
       }
   }
	return 1;
}

int main() {
    int  n;
    int matriz[9][9];
    scanf("%d", &n);
    for(int x = 0; x < n; x++) {
        for(int i = 0 ; i < 9; i++) {
            for(int j = 0; j< 9; j++) {
                scanf("%d", &matriz[i][j]);
            }
        }
        if(RESOLVER3X3(matriz) && RESOLVER9X9(matriz)) {
            printf("Instancia %d\nSIM\n\n", x + 1);
        }
        else {
            printf("Instancia %d\nNAO\n\n", x + 1);
        }
    }
    return 0;
}
