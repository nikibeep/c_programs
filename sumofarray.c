#include<stdio.h>
#include<conio.h>
int add(int b[],int len)
{
    int sum=0,i;
    for(i=0;i<len;i++)
    sum+=b[i];
    return sum;
}

int main()
{
    int a[4]={1,2,3,4};
    int len=(sizeof (a))/(sizeof (a[0]));
    printf("size of array:%d\n",len);
    printf("sum of array: %d\n",add(0,len));
}