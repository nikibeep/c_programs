#include <stdio.h>
#include <stdlib.h>

int A[20],n;

void readArray()
{
    int i,sum=0;
    printf("Enter size of array:\n");
    scanf("%d",&n);
    printf("Enter array elements: \n");
    for(i=0;i<n;i++)
    scanf("%d",&A[i]);
    
}

void displayarray()
{
    int i;
    
    for(i=0;i<n;i++)
    {
    printf("%d\n",A[i]);
    }
    
}

int highestnumber()
{
    int max = A[0],i;
    for(i=1;i<n;i++)
    if(A[i]>max)
    max = A[i];
    return max;
}

int smallestnumber()
{
    int min = A[0],i;
    for(i=1;i<n;i++)
    if(A[i]<min)
    min = A[i];
    return min;
}

int repeatednumbers(int a)
{
    int count = 0,i;
    for(i=0;i<n;i++)
    if(A[i] == a)
    count++;
    if(count>1)
    return 1;
    else
    return 0;
}

int repeatedelementcount(int a)
{
    int count = 0,i;
    for(i=0;i<n;i++)
    if(A[i] == a)
    count++;
    return count;
}

void showrepeatednumbers()
{
    int i,j,a,count;
    for(j=0;j<n;j++)
    {
        count=0;
        a = A[j];
        for(i=0;i<n;i++)
        {
            if(A[i] == a)
            count++;
        }
        if(count>1)
        printf("%d repeated %d times\n",a,count);
    }

}

void main()
{
    int choice,a;
    
    while(1)
    {
    printf("1. Read array\n");
    printf("2. Display Array\n");
    printf("3. Largest number\n");
    printf("4. Smallest number\n");
    printf("5. Repeated number\n");
    printf("6. Repeated element count\n");
    printf("7. Repeated number along with count\n");
    printf("Enter your choice...(any other number to exit): ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: readArray();
            break;

        case 2: displayarray();
            break;
        case 3: printf("Largest number = %d\n",highestnumber());
            break;
        case 4: printf("Smallest number = %d\n",smallestnumber());
            break;
        case 5: printf("Enter the number to be checked for: ");
                scanf("%d",&a);
                printf("1 if \"%d\" is repeated else 0\n",a);
                printf("Output: %d\n",repeatednumbers(a));
            break;
        case 6: printf("Enter the number to be checked for: ");
                scanf("%d",&a);
                printf("\"%d\" is repeated %d times.\n",a,repeatedelementcount(a));
                break;
        case 7: showrepeatednumbers();
                break;
        default:printf("Exiting...");
                exit(1);
    }
    }
}
