#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main(void){
    unsigned char string_ip[15];
    unsigned char ip[4];
    unsigned char x = 0;

    printf("Introduce tu ip\n");
    scanf("%s",string_ip);
    
    unsigned char * aux = strtok(string_ip, ".");
	while(aux != NULL)
	{
        ip[x] = atoi(aux);
	aux = strtok(NULL, ".");
        x ++;
	}


    if (ip[0] & 128) {
        if(ip[0] & 64){
            if(ip[0] & 32){
                if(ip[0] & 16){
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

