#include<stdio.h>
int main()
{
        FILE *fp;
        char ch;

        fp=fopen("C:\\Users\\Documents\\file4.txt","w");
        printf("\nEnter the data to be stored in the file::\n");

        while((ch=getchar())!=EOF)
        putc(ch,fp);
        fclose(fp);

        printf("\nData is successfully written to the file.!!!\n ");

        return 0;
}