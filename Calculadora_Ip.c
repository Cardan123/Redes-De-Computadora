#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main(void){
    unsigned char * string_ip;

    printf("Introduce tu ip\n");
    scanf("%s",string_ip);
    unsigned char  * primer_octeto = strtok(string_ip,".");
    unsigned short int  i=atoi(primer_octeto);
    if (i & 128) {
        if(i & 64){
            if(i & 32){
                if(i & 16){
                    printf("La ip es de clase E\n");
                }
                else
                    printf("La ip es de clase D\n");
            }
            else
                printf("La ip es de clase C\n");
        }
        else
            printf("La ip es de clase B\n");
    }
    else
        printf("La ip es de clase A\n");

    return 0;
}

