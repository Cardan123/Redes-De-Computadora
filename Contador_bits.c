#include <stdio.h>

int main(void){
unsigned char i = 128;
unsigned char letra;
unsigned short int contador = 0 , x = 0;
scanf("%c",&letra);
for(x = 0;x < 8;x++){
   if (letra & i){
	contador++;
   }
i = i >>= 1;
}
printf("Numero de bits encendidos: %d \n",contador);
}
