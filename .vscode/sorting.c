#include<stdio.h>
#include<stdlib.h>
#include<time.h>
    int display(int a[],int n)
    {
        int i;
        for(i=0;i<n;i++)
        {
            printf("%d ",a[i]);
        }
    }
    int bubble(int a[],int n)
    {
        int i,j,temp;
        printf("Bubble sort\n");
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
            printf("Steps: ",i+1);
            printf("\n",display(a,n));
            }
        }
        printf("The sorted array is: ");
        for(i=0;i<n;i++)
        {
            printf("%d ",a[i]);
        }
    }
    int insertion(int a[],int n)
    {
        int i,j,temp;
        printf("Insertion sort\n");
        for(i=1;i<n;i++)
        {
            temp=a[i];
            j=i-1;
            while(j>=0 && a[j]>temp)
            {
                a[j+1]=a[j];
                j--;
                printf("Steps: ",i+1);
                printf("\n",display(a,n));
            }
            a[j+1]=temp;

        }
        printf("The sorted array is: ");
        for(i=0;i<n;i++)
        {
            printf("%d ",a[i]);
        }
    }
    int selection(int a[],int n)
    {
        int i,j,temp,min;
        printf("Selection sort\n");
        for(i=0;i<n-1;i++)
        {
            min=i;
            for(j=i+1;j<n;j++)
            {
                if(a[j]<a[min])
                {
                    min=j;
                }
            printf("Steps: ",i+1);
            printf("\n",display(a,n));
            }
            temp=a[i];
            a[i]=a[min];
            a[min]=temp;

        }
        printf("The sorted array is: ");
        for(i=0;i<n;i++)
        {
            printf("%d ",a[i]);
        }
    }
    //Merge sort with steps
    int merge(int a[],int l,int m,int r)
    {
        int i,j,k;
        int n1=m-l+1;
        int n2=r-m;
        int L[n1],R[n2];
        for(i=0;i<n1;i++)
        {
            L[i]=a[l+i];
        }
        for(j=0;j<n2;j++)
        {
            R[j]=a[m+1+j];
        }
        i=0;
        j=0;
        k=l;
        while(i<n1 && j<n2)
        {
            if(L[i]<=R[j])
            {
                a[k]=L[i];
                i++;
            }
            else
            {
                a[k]=R[j];
                j++;
            }
            k++;
        }
        while(i<n1)
        {
            a[k]=L[i];
            i++;
            k++;
        }
        while(j<n2)
        {
            a[k]=R[j];
            j++;
            k++;
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
        case 4: merge(a,0,n/2,n-1);
                break;
        case 5: exit(0);
                break;
        default: printf("Invalid choice");
    }

}
   