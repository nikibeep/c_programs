#include<stdio.h>
#include<conio.h>
int main()
{
    int marks;
    printf("Enter the Marks:");
    scanf("%d",&marks);
    if(marks>90)
    {
        printf("A");
    }
    else if(marks>70 && marks<90)
    {
        printf("B");
    }
    else if(marks>59 && marks<70)
    {
        printf("C");
    }
    else 
    printf("D");
    return 0;
}