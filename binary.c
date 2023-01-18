#include <stdio.h>

//Binary Addition

int badd(int a,int b)
{
      int c; //c
      while (b != 0) {
              c = (a & b) << 1;
              
              a=a^b;
              b=c;
      }
      return a;
}

//Binary Subtraction

int bsub(int a, int b)
{
      int c;
      b = badd(~b, 1);

      while (b != 0) {
              c = (a & b) << 1;
              a = a ^ b;
              b = c;
      }
      return a;
}


int main()
{
    int num1, num2, add, sub;

    printf("first integer value: ");
    scanf("%d",&num1);

    printf("second integer value: ");
    scanf("%d",&num2);

    add=badd(num1,num2);
    sub=bsub(num1,num2);

    printf("Binary Sum: %d\n",add);
    printf("Binary Difference: %d\n",sub);

    return 0;

}