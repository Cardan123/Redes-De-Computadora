#include <stdio.h>


void tipo(unsigned char[],unsigned char);
void red(unsigned char[],unsigned char[]);
void broadcast(unsigned char[],unsigned char[]);
void rango(unsigned char[],unsigned char[]);


int main(){    
    unsigned char ip[4];
    unsigned char ip_m[4]={255,255,255,255};
	
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
            else{
                ip_m[0] = 255;
                ip_m[1] = 255;
                ip_m[2] = 255,
                ip_m[3] = 0;
                printf("La ip es de clase C\n");
		        printf("Mascara: %d.%d.%d.%d\n",ip_m[0],ip_m[1],ip_m[2],ip_m[3]);
                tipo(ip,3);
                red(ip,ip_m);
                broadcast(ip,ip_m);
                rango(ip,ip_m);
        }
                }
        else{
            ip_m[0] = 255;
            ip_m[1] = 255;
            ip_m[2] = 0,
            ip_m[3] = 0;
            printf("La ip es de clase B\n");
	        printf("Mascara: %d.%d.%d.%d\n",ip_m[0],ip_m[1],ip_m[2],ip_m[3]);
            tipo(ip,2);
            red(ip,ip_m);
            broadcast(ip,ip_m);
            rango(ip,ip_m);
            }
    }
    else{
        ip_m[0] = 255;
        ip_m[1] = 0;
        ip_m[2] = 0,
        ip_m[3] = 0;
        printf("La ip es de clase A\n");
	    printf("Mascara: %d.%d.%d.%d\n",ip_m[0],ip_m[1],ip_m[2],ip_m[3]);
        tipo(ip,1);
        red(ip,ip_m);
        broadcast(ip,ip_m);
        rango(ip,ip_m);
    }
    return 0;
}

void tipo(unsigned char ip[],unsigned char clase){
        
        if (clase == 1){
            if(((ip[3]&255) == 255)&((ip[2]&255) == 255)&((ip[3]&255) == 255)){
                printf("Tipo: Broadcast\n");
            }else if(!(ip[2]|0)&!(ip[3]|0)){
                printf("Tipo: Red\n");
            }else 
                printf("Tipo: Host\n"); 
        } else if (clase == 2){
          
            if(((ip[2]&255) == 255)&((ip[3]&255) == 255)){
                printf("Tipo: Broadcast\n");
            }else if(!(ip[2]|0)&!(ip[3]|0)){
                printf("Tipo: Red\n");
            }else 
                printf("Tipo: Host\n"); 
        
        } else if (clase == 3){
            
            if((ip[3]&255) == 255){
                printf("Tipo: Broadcast\n");
            }else if(!(ip[3]|0)){
                printf("Tipo: Red\n");
            }else 
                printf("Tipo: Host\n");
        }
    return;
}

void red(unsigned char ip[],unsigned char ip_m[]){
    printf("Direccion de red: %hhu.%hhu.%hhu.%hhu",ip[0]&ip_m[0],ip[1]&ip_m[1],ip[2]&ip_m[2],ip[3]&ip_m[3]);
    return;
}

void broadcast(unsigned char ip[],unsigned char ip_m[]){
    printf("\nDireccion de Broadcast: %hhu.%hhu.%hhu.%hhu",ip[0]|(ip_m[0]^(255)),ip[1]|(ip_m[1]^(255)),ip[2]|(ip_m[2]^(255)),ip[3]|(ip_m[3]^(255)));
    return;
}

void rango(unsigned char ip[],unsigned char ip_m[]){
    printf("\nRango: %hhu.%hhu.%hhu.%hhu - %hhu.%hhu.%hhu.%hhu \n",ip[0]&ip_m[0],ip[1]&ip_m[1],ip[2]&ip_m[2],(ip[3]&ip_m[3])+1,ip[0]|(ip_m[0]^(255)),ip[1]|(ip_m[1]^(255)),ip[2]|(ip_m[2]^(255)),(ip[3]|(ip_m[3]^(255)))-1);
}

