#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void tipo(unsigned char[],unsigned char);
void red(unsigned char[],unsigned char);
void broadcast(unsigned char[],unsigned char);
void rango(unsigned char[],unsigned char);


int main(void){
    unsigned char string_ip[15];
    unsigned char ip[4];
    unsigned char x = 0;

    printf("Introduce tu ip\n");
    scanf("%s",string_ip);
    
    unsigned char *aux = strtok(string_ip, ".");
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
            else{
                printf("La ip es de clase C\n");
                tipo(ip,3);
                red(ip,3);
                broadcast(ip,3);
                rango(ip,3);
                }
        }
        else{
            printf("La ip es de clase B\n");
            tipo(ip,2);
            red(ip,2);
            broadcast(ip,2);
            rango(ip,2);
            }
    }
    else{
        printf("La ip es de clase A\n");
        tipo(ip,1);
        red(ip,1);
        broadcast(ip,1);
        rango(ip,1);
    }
    return 0;
}

void tipo(unsigned char ip[],unsigned char clase){
        if (clase == 1){
          
            if((ip[1]&255)&(ip[2]&255)&(ip[3]&255)){
                printf("Tipo: Broadcast\n");
            }else if(!(ip[1]|0)&!(ip[2]|0)&!(ip[3]|0)){
                printf("Tipo: Red\n");
            }else 
                printf("Tipo: Host\n");
       
        } else if (clase == 2){
          
            if((ip[2]&255)&(ip[3]&255)){
                printf("Tipo: Broadcast\n");
            }else if(!(ip[2]|0)&!(ip[3]|0)){
                printf("Tipo: Red\n");
            }else 
                printf("Tipo: Host\n"); 
        
        } else if (clase == 3){
            
            if(ip[3]&255){
                printf("Tipo: Broadcast\n");
            }else if(!(ip[3]|0)){
                printf("Tipo: Red\n");
            }else 
                printf("Tipo: Host\n");
        }
    return;
}

void red(unsigned char ip[],unsigned char clase){
        if (clase == 1){
            printf("Direccion de red: %d.%d.%d.%d",ip[0]&255,ip[1]&0,ip[2]&0,ip[3]&0);
        } else if (clase == 2){
            printf("Direccion de red: %d.%d.%d.%d",ip[0]&255,ip[1]&255,ip[2]&0,ip[3]&0);
        } else if (clase == 3){
            printf("Direccion de red: %d.%d.%d.%d",ip[0]&255,ip[1]&255,ip[2]&255,ip[3]&0);
        }
    return;
}

void broadcast(unsigned char ip[],unsigned char clase){
    if (clase == 1){
            printf("\nDireccion de Broadcast: %d.%d.%d.%d",ip[0]|0,ip[1]|255,ip[2]|255,ip[3]|255);
        } else if (clase == 2){
            printf("\nDireccion de Broadcast: %d.%d.%d.%d",ip[0]|0,ip[1]|0,ip[2]|255,ip[3]|255);
        } else if (clase == 3){
            printf("\nDireccion de Broadcast: %d.%d.%d.%d",ip[0]|0,ip[1]|0,ip[2]|0,ip[3]|255);
        }
    return;
}

void rango(unsigned char ip[],unsigned char clase){
         if (clase == 1){
            printf("\nRango: %d.%d.%d.%d - %d.%d.%d.%d \n",ip[0]&255,ip[1]&0,ip[2]&0,(ip[3]&0)+1,ip[0]|0,ip[1]|255,ip[2]|255,(ip[3]|255)-1);
        } else if (clase == 2){
            printf("\nRango: %d.%d.%d.%d - %d.%d.%d.%d \n",ip[0]&255,ip[1]&255,ip[2]&0,(ip[3]&0)+1,ip[0]|0,ip[1]|0,ip[2]|255,(ip[3]|255)-1);
        } else if (clase == 3){
            printf("\nRango: %d.%d.%d.%d - %d.%d.%d.%d \n",ip[0]&255,ip[1]&255,ip[2]&255,(ip[3]&0)+1,ip[0]|0,ip[1]|0,ip[2]|0,(ip[3]|255)-1);
        }
    return;
}

