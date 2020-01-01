#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE* fp = fopen("file", "r");
    fseek(fp, 0L, SEEK_END);
    int len = ftell(fp);
    rewind(fp);
    char cont[len];
    fread(cont, sizeof(char) , len, fp); 
    printf("%i,%c\n", len -3, cont[len - 3]);
    printf("%i,%c\n", len -2, cont[len - 2]);
    printf("%i,%c", len -1, cont[len - 1]);
    printf("%i,%c", len, cont[len]); 

    printf("\nTamanho da string: %i\nString: \n%s", sizeof(cont), cont); 
    
   char c;
   int n_count = 0; 
   for(int i = 0; i<len;i++){
       printf("%c", cont[i]);
       if(cont[i] == '\n'){
            n_count++; 
       }
    }   
    
    printf("numero de quebra de linhas: %i\n", n_count);

}