#include <stdio.h> 
union Data {
   int a,b,c;
};
 
int main(){

   union Data data;        
   printf("enter the numbers: ");
   scanf("%d %d %d",&data.a,&data.b,&data.c);
   if(data.a>data.b && data.a>data.c){
    printf("%d is greater",data.a);
   }else if(data.b>data.a && data.b>data.c){
    printf("%d is greater",data.b);
   }else
   printf("%d is greater",data.c);
   return 0;
}