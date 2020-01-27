#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main(void){
    unsigned char string_ip[12];

    printf("Introduce tu ip\n");
    scanf("%s",&string_ip);
    unsigned char  * primer_octeto = strtok(string_ip,".");

    if (atoi(primer_octeto) & 128) {
        if(atoi(primer_octeto) & 64){
            if(atoi(primer_octeto) & 32){
                if(atoi(primer_octeto) & 16){
                    printf("La ip es de clase E");
                }
                else
                    printf("La ip es de clase D");
            }
            else
                printf("La ip es de clase C");
        }
        else
            printf("La ip es de clase B");
    }
    else
        printf("La ip es de clase A");

    return 0;
}

