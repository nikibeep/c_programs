#include <stdio.h>
int operate(int array[], int N)
{
	int sum = 0, index = 0;
label:
	sum += array[index++];
	if (index < N) {
		goto label;
	}
	return sum;
}
int digSum(int Number)
{
    int add = 0;
    while( Number > 0 || add > 9 )
    { 
      if(Number == 0)
       { 
	    Number=add;
   	    add = 0;
	   }
	    add +=Number % 10;
        Number /= 10;
	}
	return add;
}
int main()
{
	int N = 5, sum = 0 ,roll ;
    int count = 0;
	int array[] = { 11, 22, 33, 44, 55 };
	sum = operate(array, N);
	printf("\n %d is the sum of integers", sum);  
    int Number = sum;
	printf("\n %d is the sum of digits",digSum(Number));
    return 0;
}