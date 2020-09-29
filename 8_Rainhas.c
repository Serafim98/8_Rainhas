// Bruna Bravin Bueno, Luis Fernando da Silva Serafim

#include <stdio.h>

   
int Ameacada(int Tabuleiro[8][8], int lin, int col){ //Função que verifica se a Rainha coloca na posição está ameaçada  
    int i, j, PosicaoValida = 1;
    i = lin - 1;
    while (i >= 0 && PosicaoValida){
       	PosicaoValida = !Tabuleiro[i][col];
        i = i - 1;
       }
    i = lin - 1;
    j = col + 1;
    while (i >= 0 && j < 8 && PosicaoValida){
        PosicaoValida = !Tabuleiro[i][j];
        i = i - 1;
        j = j + 1;
       }
    i = lin - 1;
    j = col - 1;
    while (i >= 0 && j >= 0 && PosicaoValida){
        PosicaoValida = !Tabuleiro[i][j];
        i = i - 1;
        j = j - 1;
    }
       return (PosicaoValida);
}
   
int PoeRainhaPosicao(int Tabuleiro[8][8], int lin){    //Funcao que atribui a Rainha a uma posição
       int col = 0, PosicaoValida = 0;
    
	   if (lin >= 8) return (1);
       else{
        	while (col < 8 && PosicaoValida==0){
            		Tabuleiro[lin][col] = 1;
            		if (Ameacada(Tabuleiro,lin,col))
                		PosicaoValida = PoeRainhaPosicao(Tabuleiro,lin + 1);
            		if (PosicaoValida==0){
                		Tabuleiro[lin][col] = 0;
                		col = col + 1;
            		}
        	}
           return (PosicaoValida);
       }
}

void ImprimeSolucao(int tabuleiro[8][8]){ //Função que imprime as posições da rainha de acordo com o mapeamento realizado.
    int i, j;
    
    for (i = 0; i < 8; i++){
    	printf("\n");
        for (j = 0; j < 8; j++){
            if (tabuleiro[i][j]) printf("  #   ");
            else printf("  0   ");    	 
           }
           printf("\n\n");
       }
   }
   
int main(void){
    int i, j, k=0, Tabuleiro[8][8];
    for (i = 0; i < 8; i = i + 1)   
        for (j = 0; j < 8; j = j + 1) 
			Tabuleiro[i][j] = 0;      //Colocando 0 em todas posições
    	
	PoeRainhaPosicao(Tabuleiro, k);
	ImprimeSolucao(Tabuleiro);
	k++;
	printf("\n\n");
	
    return (1);
  }
