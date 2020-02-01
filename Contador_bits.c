#include <stdio.h>

int main(void){
unsigned char i = 128;
unsigned char letra;
unsigned char x;
unsigned char contador = 0 ;
scanf("%c",&letra);
for(x = 128 ;x > 0 ; x >>= 1){
   if (letra & i){
	contador++;
   }
i = i >>= 1;
}
printf("Numero de bits encendidos: %d \n",contador);
}
