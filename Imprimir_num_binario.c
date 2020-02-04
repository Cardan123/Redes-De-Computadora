#include<stdio.h>
#include<stdlib.h>


void print_binint(unsigned char numero)
{
   unsigned char i;
   for(i=128;i>0;i>>=1){
      if(numero&i)
         printf("1");
      else 
         printf("0");
   }
}


int main()
{
    unsigned char num[10];
    printf("introduzca un numero entero:");
    scanf("%s",num);
    printf("Numero binario\n");
    print_binint(atoi(num));
    return 0;
}