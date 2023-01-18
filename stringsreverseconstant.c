#include <stdio.h>
#include<string.h>
void reverseString(char* str)
{
    int l, i;
    char *begin_ptr, *end_ptr, ch;
 
    // Get the length of the string
    l = strlen(str);
 
    // Set the begin_ptr and end_ptr
    // initially to start of string
    begin_ptr = str;
    end_ptr = str;
 
    // Move the end_ptr to the last character
    for (i = 0; i < l - 1; i++)
        end_ptr++;
 
    // Swap the char from start and end
    // index using begin_ptr and end_ptr
    for (i = 0; i < l / 2; i++) {
 
        // swap character
        ch = *end_ptr;
        *end_ptr = *begin_ptr;
        *begin_ptr = ch;
 
        // update pointers positions
        begin_ptr++;
        end_ptr--;
    }
}
int main()
{
    char str[100];
    char *ptr;
    int  cntV,cntC;
     
    printf("Enter a string: ");
    gets(str);
     
    //assign address of str to ptr
    ptr=str;
     
    cntV=cntC=0;
    while(*ptr!='\0')
    {
        if(*ptr=='A' ||*ptr=='E' ||*ptr=='I' ||*ptr=='O' ||*ptr=='U' ||*ptr=='a' ||*ptr=='e' ||*ptr=='i' ||*ptr=='o' ||*ptr=='u')
            cntV++;
        else
            cntC++;
        //increase the pointer, to point next character
        ptr++;
    }
     
    printf("Total number of VOWELS: %d, CONSONANT: %d\n",cntV,cntC);    
    reverseString(str);
        printf("Reverse of the string: %s\n", str);
    return 0;
}