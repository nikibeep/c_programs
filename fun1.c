#include<stdio.h>
void fun1(void (*ptr)(int,int),int a,int b)
{
    (*ptr)(a,b);
}
void fun2(int a,int b)
{
    int c;
    c=a+b;
    printf(c);
}
main()
{
    fun1(fun2,12,14);
}