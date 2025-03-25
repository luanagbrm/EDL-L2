/* Atividade L2 */
/*
  Arquivo: Grazielle_AlmeidaATL2.c
  Autor: Geovanna Cristina Brenzinger
		 Grazielle Batista de Almeida
  		 Isabela Nunes dos Santos
  		 Luana Gabrielle Rodrigues Macedo
  Data: 29/09/09
  Descrição: Verificar existência de duplicatas em uma matriz do pequeno sudoko
*/


#include <stdio.h> 
#include <string.h> 
#include "Booleano.h"

bool verificarRepetido(unsigned char geral[10][10]);

int main(){
    unsigned char geral[10][10]; 
    unsigned char linha[20];     
    FILE *entrada;
    int i,lin,col,n,ok;
	entrada = fopen("SUDOKUCerto.txt","r");
    if (entrada == NULL)  {
		printf("\n nao encontrado \n");
		ok = 0;
    }else {
        ok = 1;
		printf("arquivo txt encontrado - fscanf vai ler os caracteres \n\n");
             
        lin = 0;
        printf("  linha    Arquivo texto "); printf("   codigo ASCII \n"); 
             
        while(fscanf(entrada, "%20s", linha)==1){
        	
            lin = lin + 1;		
            
			
			printf("\n linha %d   ",lin);  printf(" %s   ",linha);
            
			n = strlen(linha); 	
            
           
            for(i=0;i<=n;i++)printf(" %d ",linha[i]); printf("\n");
			  
			
            for(i=0;i<=8;i++)geral[lin][i+1] = linha[i];	
			
			
        } 
             
       	fclose(entrada); 
    } 
    
   printf(" \n conteudo da matriz (formatacao c) \n\n"); 
   
   
   for(lin=1; lin <= 9; lin++){
        for(col=1; col <= 9; col++){
            printf(" %c",geral[lin][col]); 
        } 
       	printf("\n");
    }  
	
	if(verificarRepetido(geral))
		printf("INCORRETO");
	else
		printf("CORRETO");
		
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
	
	while(l <= 9 && tem_duplicata != TRUE){
		c = 1;
		while(c < 9 && tem_duplicata != TRUE){
			i = c + 1;
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
	c = 1;

	while(c <= 9 && tem_duplicata != TRUE){
		l = 1;
		while(l < 9 && tem_duplicata != TRUE){
			i = l + 1;
			while(i <= 9 && tem_duplicata!= TRUE){
				if(geral[l][c] == geral[i][c]){
					tem_duplicata = TRUE;
				}else{
					i = i + 1;
				}
			}
			l = l + 1;
		}
		c = c+ 1;
	}
	
	
	return tem_duplicata;
}