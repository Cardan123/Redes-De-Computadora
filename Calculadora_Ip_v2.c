#include <stdio.h>


void red(unsigned char[],unsigned char[]);
void broadcast(unsigned char[],unsigned char[]);
void rango(unsigned char[],unsigned char[]);
unsigned char i,x;


int main(){    
    unsigned char ip[4];
    unsigned char ip_m[4]={255,255,255,255};
	
    printf("Introduce tu ip\n");
    scanf("%hhu.%hhu.%hhu.%hhu",&ip[0],&ip[1],&ip[2],&ip[3]);
 
    if (ip[0] & 128) {
        if(ip[0] & 64){
            if(ip[0] & 32){
                if(ip[0] & 16){
                    printf("Clase: E\n");
                }
                else
                    printf("Clase: D\n");
            }
            else{
                ip_m[0] = 255;
                ip_m[1] = 255;
                ip_m[2] = 255,
                ip_m[3] = 0;
                
                printf("Clase: C\n");
		        printf("Mascara: %d.%d.%d.%d\n",ip_m[0],ip_m[1],ip_m[2],ip_m[3]);
                
                if(ip[3] == 255){
                    printf("Tipo: Broadcast\n");
                }else if(ip[3] == 0){
                    printf("Tipo: Red\n");
                }else 
                    printf("Tipo: Host\n");

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

            printf("Clase: B\n");
	        printf("Mascara: %d.%d.%d.%d\n",ip_m[0],ip_m[1],ip_m[2],ip_m[3]);
           
            if((ip[2] == 255)&(ip[3] == 255)){
                printf("Tipo: Broadcast\n");
            }else if((ip[2] == 0)&(ip[3] == 0)){
                printf("Tipo: Red\n");
            }else 
                printf("Tipo: Host\n"); 

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

        printf("Clase: A\n");
	    printf("Mascara: %d.%d.%d.%d\n",ip_m[0],ip_m[1],ip_m[2],ip_m[3]);


        if((ip[1] == 255)&(ip[2] == 255)&(ip[3] == 255)){
            printf("Tipo: Broadcast\n");
         }else if((ip[1] == 0)&(ip[2] == 0)&(ip[3] == 0)){
            printf("Tipo: Red\n");
        }else 
            printf("Tipo: Host\n"); 

        red(ip,ip_m);
        broadcast(ip,ip_m);
        rango(ip,ip_m);
    }
    return 0;
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
    printf("\nRango: %hhu.%hhu.%hhu.%hhu - %hhu.%hhu.%hhu.%hhu \n",ip[0]&ip_m[0],ip[1]&ip_m[1],ip[2]&ip_m[2],(ip[3]&ip_m[3])+1,ip[0]|(ip_m[0]^(255)),ip[1]|(ip_m[1]^(255)),ip[2]|(ip_m[2]^(255)),(ip[3]|(ip_m[3]^255))-1);
    return;
}

