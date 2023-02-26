#include <stdio.h>  
  
int main( )  
{  
int a = 5;  
int *b;  
b = &a;  
//print value of a
printf ("value of a = %d\n", a);  

//print value of a using pointer
printf ("value of a = %d\n", *(&a));  

//print value of a using pointer
printf ("value of a = %d\n", *b);  

printf("value of a = %d", *a); //error

//print address of a
printf ("address of a = %u\n", &a);  

//print address of a using pointer
printf ("address of a = %d\n", b);  

//print address of b
printf ("address of b = %u\n", &b); 

//print value of b
printf ("value of b = address of a = %u\n", b);  

//print value of b using pointer
printf ("value of b = address of a = %u", *(&b));
return 0;  
}  