#include <stdio.h>




int main(void){
    unsigned char ip[4];
	
    printf("Introduce tu ip\n");
    scanf("%d.%d.%d.%d",&ip[0],&ip[1],&ip[2],&ip[3]);


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

