#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 200

struct stud
{
    int id;
    char *name;
}*stud1, *stud3;

void display();
void create();
void update();

char * arrr = "E:\\record.txt";

FILE *fp, *fp1;
int count = 0;

void main()
{
    int i, n, ch;

    printf("1] Create a Record\n");
    printf("2] Display Records\n");
    printf("3] Update Records\n");
    printf("4] Exit");
    while (1)
    {
        printf("\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            fp = fopen(arrr, "a");
            create();
            break;
        case 2:
            fp1 = fopen(arrr,"rb");
            display();
            break;
        case 3:
            fp1 = fopen(arrr, "r+");
            update();
            break;
        case 4:
            exit(0);
        }
    }
}

/* To create an studloyee record */
void create()
{
    int i;
    char *p;

    stud1 = (struct stud *)malloc(sizeof(struct stud));
    stud1->name = (char *)malloc((size)*(sizeof(char)));
    printf("Enter name of student : ");
    scanf(" %[^\n]s", stud1->name);
    printf("Enter student id : ");
    scanf(" %d", &stud1->id);
    fwrite(&stud1->id, sizeof(stud1->id), 1, fp);
    fwrite(stud1->name, size, 1, fp);
    count++;   // count to number of entries of records
    fclose(fp);
}

/* Display the records in the file */
void display()
{
    stud3=(struct stud *)malloc(1*sizeof(struct stud));
    stud3->name=(char *)malloc(size*sizeof(char));
    int i = 1;

    if (fp1 == NULL)
        printf("\nFile not opened for reading");
    while (i <= count)
    {
        fread(&stud3->id, sizeof(stud3->id), 1, fp1);
        fread(stud3->name, size, 1, fp1);
        printf("\n%d %s",stud3->id,stud3->name);
        i++;
    }
    fclose(fp1);
    free(stud3->name);
    free(stud3);
}

void update()
{
    int id, flag = 0, i = 1;
    char s[size];

    if (fp1 == NULL)
    {
        printf("File cant be opened");
        return;
    }
    printf("Enter studloyee id to update : ");
    scanf("%d", &id);
    stud3 = (struct stud *)malloc(1*sizeof(struct stud));
        stud3->name=(char *)malloc(size*sizeof(char));
    while(i<=count)
    {
        fread(&stud3->id, sizeof(stud3->id), 1, fp1);
        fread(stud3->name,size,1,fp1);
        if (id == stud3->id)
        {
            printf("Enter new name of studlyee to update : ");
            scanf(" %[^\n]s", s);
            fseek(fp1, -204L, SEEK_CUR);
            fwrite(&stud3->id, sizeof(stud3->id), 1, fp1);
            fwrite(s, size, 1, fp1);
            flag = 1;
            break;
        }
        i++;
    }
    if (flag != 1)
    {
        printf("No student record found");
        flag = 0;
    }
    fclose(fp1);
    free(stud3->name);        /* to free allocated memory */
    free(stud3);
}