#include<stdio.h>
int main()
{
    int n,i;
    printf("Enter the number: ");
    scanf("%d",&n);
    int a=0;
    int b=1;
    int roll= a+b;
    for(i=2;i<=n;++i)
    {
        a=b;
        b=roll;
        roll=a+b;
    }
    printf("fibanocci:%d",roll);
}