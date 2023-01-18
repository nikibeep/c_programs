#include<stdio.h>
#include<conio.h>
int main()
{
 int num,sum=0,rev=0,d;
 printf("Enter the number: ");
 scanf("%d",&num);

do{
  d=num%10;
  rev=rev*10+d;
  sum=sum+d;
  num=num/10;
}while(num>0);

printf("Sumof digits = %d",sum);
printf("\nReverse of the number = %d",rev);
return 0;
}