/* Arquivo texto & matriz de caracteres */
/*
  Arquivo: arquivoTextoSudoku.c
  Autor: Lisbete Madsen Barbosa
  Date: 29/09/09 09:32
  Descrição: Leitura de um arquivo texto 
             e armazenamento em uma matriz de caracteres
*/


#include <stdio.h> // aqui encontram-se as funções de io para arquivos e também o NULL
#include <string.h> // aqui estão as funções do tipo string
#include "Booleano.h"

bool verificarRepetido(unsigned char geral[10][10]);

int main(){
    unsigned char geral[10][10]; // Matriz de duas dimensões - vou guardar uma matriz 9x9 de caracteres 
    unsigned char linha[20];     // o vetor linha tem espaço para 20 caracteres
    FILE *entrada;
    int i,lin,col,n,ok;
	entrada = fopen("SUDOKU.txt","r");
    if (entrada == NULL)  {
		printf("\n nao encontrado \n");
		ok = 0;
    }else {
        ok = 1;
		printf("arquivo txt encontrado - fscanf vai ler os caracteres \n\n");
             
        lin = 0;
        printf("  linha    Arquivo texto "); printf("   codigo ASCII \n"); 
             
        while(fscanf(entrada, "%20s", linha)==1){
        	
            lin = lin + 1;		//armazena a partir da linha 1
            
			// mostrando a linha que leu no arquivo
			printf("\n linha %d   ",lin);  printf(" %s   ",linha);
            
			n = strlen(linha); 	// n = tamanho da string = 9
            
            // mostrando os códigos ASCII dos caracteres de linha, inclusive o '/0'
            for(i=0;i<=n;i++)printf(" %d ",linha[i]); printf("\n");
			  
			// armazenando os caracteres nas linhas da matriz 
            for(i=0;i<=8;i++)geral[lin][i+1] = linha[i];	
			// linha e coluna começam em 1
			
        } // end while
             
       	fclose(entrada); // fechando o arquivo que já foi lido
    } //end else
    
   printf(" \n conteudo da matriz (formatacao c) \n\n"); 
   // se o arquivo não foi lido, vai mostrar o que está na memória
   
   for(lin=1; lin <= 9; lin++){
        for(col=1; col <= 9; col++){
            printf(" %c",geral[lin][col]); 
        } // end for col
       	printf("\n");
    }  // end for lin
	
	if(verificarRepetido(geral))
		printf("sim");
	else
		printf("nao");
		
	return 0;
}

bool verificarRepetido(unsigned char geral[10][10]){
	bool tem_duplicata;
	unsigned char i;
	unsigned char c;
	unsigned char l;
	unsigned char qntNum;
	
	tem_duplicata = FALSE;
	l = 1;
	c = 1;
	i = 1;
	
	while(l <= 9 && tem_duplicata != TRUE){
		while(c < 9 && tem_duplicata != TRUE){
			i = c  + 1;
			while(i <= 9 && tem_duplicata != TRUE){
				if(geral[l][c] == geral [l][i]){
						tem_duplicata = TRUE;
				} else {
					i = i + 1;
				}	
			}
			c = c + 1;
		}
		l = l + 1;
	}
	
	return tem_duplicata;
}
