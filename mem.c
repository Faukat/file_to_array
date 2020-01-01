#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char teste[] = "123456789";
    printf("%i\n\n", strlen(teste));   
    char *alo =  NULL;  //(char *)malloc(1);
    char *c = teste;
    char *temp = NULL; 
    int n_str = 0, m_size = 0;  
   do{
       m_size++;
       alo = (char *)realloc(alo, sizeof(char)  * m_size);
       alo[n_str] = *c;
       printf("m_size:%i\nn_str:%i\n", m_size, n_str);
       n_str++; 
       c++;
    } while (*c != '\0');
    alo = (char *)realloc(alo, sizeof(char)  * (m_size + 1));
    alo[n_str + 1] = '\0';
    
    *(alo + (n_str + 1))= '\0';  
    for(int i =0;i<n_str;i++){
        printf("%c", alo[i]);
    }
    printf("\n\ntamanho: %d\nstring: f%sf\n", strlen(alo), alo);
    
    return 0; 
}
