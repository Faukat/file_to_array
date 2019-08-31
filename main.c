#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(){
	FILE * fp = fopen("texto", "r");
	fseek(fp, 0L, SEEK_END);
	int len = ftell(fp);
	rewind(fp);
	char cont[len];
	fread(cont, sizeof(char), len, fp );
	char *pon = cont; // ponteiro para varer a string. 
	int pcon = 0; // variavel para contar char. 
	int nl = 0; // Numero de linhas
	int nlt = 0; // variavel temporaria para conta linha.
	char **final;
	// Contando o numero de linhas.
	while(*pon != '\0'){
		if(*pon == ';'){
			nl++;
			pcon = 0;
			pon = pon + 2;
		}
		else{
			pcon++;
			pon++;
		}
	}
	// Alocando cada linha. 
	final = (char **)malloc((nl + 1) * sizeof(char*));
	pon = cont;
	pcon = 0;
	int m1[nl]; 
	// Contando cada linha. 
	while(*pon != '\0'){
		if(*pon == ';'){
			m1[nlt] = pcon;
			pcon = 0;
			pon = pon + 2;
			nlt++;
		}
		else{
			pcon++;
			pon++;
		}
	}
	printf("numero de linhas: %i\n", nl );
	printf("Numero de cada linha: " );
	for(int i=0;i<=nl;i++){printf("%i ", m1[i] );}
	printf("\n");
	//Alocando o tamanho de cada linha. 
	for(int i = 0; i<nl;i++){
		final[i] = (char *)malloc( m1[i] * sizeof(char) + 1);
	}
	pon = cont;
	pcon = 0;
	int coni = 0;
	int conj = 0;
	// Colocando o valor de cada char em seu respectivo lugar. 
	while(*pon != '\0'){
		if(*pon == ';' ){
			final[coni][conj] = '\0';
			pon = pon + 2;
			conj= 0;
			coni++;
		}
		else {
			final[coni][conj] = *pon;
			pon++;
			conj++;
		}
	}
		
	// Imprimindo informações. 
	for(int i=0;i<nl;i++){
		printf("%s\n", final[i] );
		free(final[i]);

	}
	free(final);
	fclose(fp); 	
	return 0;
}