#include<stdio.h>
#include<stdlib.h>
#include<time.h>
    int display(int a[],int n)
    {int i;
        for(i=0;i<n;i++)
        {
            printf("%d ",a[i]);
        }
    }
    int bubble(int a[],int n)
    {int i,j,temp;
        for(i=0;i<n-1;i++)
        {
            for(j=0;j<n-i-1;j++)
            {
                if(a[j]>a[j+1])
                {
                    temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                }
            }
            printf("Steps: ",i+1);
            printf("\n",display(a,n));
        }
        printf("The sorted array is: ");
        for(i=0;i<n;i++)
        {
            printf("%d ",a[i]);
        }
    }
    int insertion(int a[],int n)
    {int i,j,temp;
        for(i=1;i<n;i++)
        {
            temp=a[i];
            j=i-1;
            while(j>=0 && a[j]>temp)
            {
                a[j+1]=a[j];
                j--;
            }
            a[j+1]=temp;
            printf("Steps: ",i+1);
            printf("\n",display(a,n));
        }
        printf("The sorted array is: ");
        for(i=0;i<n;i++)
        {
            printf("%d ",a[i]);
        }
    }
    int selection(int a[],int n)
    {int i,j,temp,min;
        for(i=0;i<n-1;i++)
        {
            min=i;
            for(j=i+1;j<n;j++)
            {
                if(a[j]<a[min])
                {
                    min=j;
                }
            }
            temp=a[i];
            a[i]=a[min];
            a[min]=temp;
            printf("Steps: ",i+1);
            printf("\n",display(a,n));
        }
        printf("The sorted array is: ");
        for(i=0;i<n;i++)
        {
            printf("%d ",a[i]);
        }
    }
void main()

{   
    int a[10],n,i,choice;
    printf("\nEnter the length of the array: \n");
    scanf("%d",&n);
    //menu driven program
    //generate random numbers
    for(i=0;i<n;i++)
    {
        a[i]=rand()%100;
    }
    printf("The array is before sorting: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\nEnter the choice of sorting algorithm: ");
    printf("1. Bubble sort  2. Insertion sort  3. Selection sort  4. Exit\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: bubble(a,n);
                break;
        case 2: insertion(a,n);
                break;
        case 3: selection(a,n);
                break;
        case 4: exit(0);
                break;
        default: printf("Invalid choice");
    }

}
   