#include<stdio.h>
int fun(int a,int b)
{
    print("...");
    return 0;
}
main()
{   int a,b;
    int(*ptr)(int,int);
    ptr=fun;
    a=(*ptr)(100,200);
    b=(*ptr)(100,100);
    print(a,b);
}