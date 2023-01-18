#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *rlink;
    struct node *llink;
}NODE;

NODE *head=NULL;

NODE *create(int value)
{
    NODE *new=(NODE*)malloc(sizeof(NODE));
    new->data=value;
    new->rlink=NULL;
    new->llink=NULL;
    return new;
}

void insertinend(NODE *temp)
{
    NODE *cur=head;
    if(head==NULL)
    {
        head=temp;
    }
    else{
        while(cur->rlink!=NULL)
        {
            cur=cur->rlink;
        }
        cur->rlink=temp;
        temp->llink=cur;
    }
}

void insertinmiddle(NODE *temp,int ele)
{
    NODE *cur=head;
    while(cur->data!=ele){
        cur=cur->rlink;
    }
    temp->llink=cur;
    temp->rlink=(cur->rlink);
    (cur->rlink)->llink=temp;
    cur->rlink=temp;
}

void dequeue()
{
    NODE *temp=head;
    head=head->rlink;
    if(head!=NULL){
        head->llink=NULL;
    }
    printf("%d",temp->data);
    free(temp);
}

int search(int **buddy,NODE *cur,int index)
{
    int t,i;
    t=buddy[index][0];
    for(i=1;i<=t;i++)
    {
        if(buddy[index][i]==(cur->data))
        {
            return 1;   
        }
    }
    return 0;
}

void enqueue(int x,int **buddy,int k)
{
    int i,j,t,index=-1,f=0;
    for(i=0;i<k;i++)
    {
        t=buddy[i][0];
        for(j=1;j<=t;j++)
        {
            if(buddy[i][j]==x)
            {
                index=i;
                break;
            }
        } 
    }
    NODE *temp=create(x);
    NODE *cur=head;
    if(index==-1)
    {
        insertinend(temp);
    }
    else{
        while(cur!=NULL)
        {
        
            if((search(buddy,cur,index))&&(!(search(buddy,(cur->rlink),index))))
            {
                insertinmiddle(temp,cur->data);  
            }
            cur=cur->rlink;
        }    
    }
}

void main()
{
    
    int k,i,j,t,n;
    char ch,str[10];
    scanf("%d",&k);
    int **buddy=(int**)malloc(k * sizeof(int*));
    for (i=0; i<k; i++)
    {
        buddy[i] = (int*)malloc(1000 * sizeof(int));
    }
    
    
    for(i=0;i<k;i++)
    {
        scanf("%d",&t);
        buddy[i][0]=t;
        for(j=1;j<=t;j++)
        {
            scanf("%d",&buddy[i][j]);
        }
    }
    while(1){
        scanf("%s",str);
        ch=str[0];
        switch(ch)
        {
            case 'E':scanf("%d",&n);
                     enqueue(n,buddy,k);
                    break;
            case 'D':dequeue();
                    break;
            default:exit(0);
        
        }
    }
   
}