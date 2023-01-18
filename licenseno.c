#include <stdio.h>
struct student {
    char firstName[50];
    int roll;
    float marks;
    int aadhar;
    int license;
    char gender[20];
} s[10];

int main() {
    int i;
    printf("Enter information of students:\n");

    for (i = 0; i < 2; ++i) {
        s[i].roll = i + 1;
        printf("\nFor roll number%d,\n", s[i].roll);
        printf("Enter first name: ");
        scanf("%s", s[i].firstName);
        printf("Enter marks: ");
        scanf("%f", &s[i].marks);
        printf("Enter aadhar:");
        scanf("%d",&s[i].aadhar);
        printf("Enter license no:");
        scanf("%d",&s[i].license);
        printf("Sex:");
        scanf("%s",&s[i].gender);   
    }
    printf("Displaying Information:\n\n");

    
    for (i = 0; i < 2; ++i) {
        printf("-----------Marks card-----------");
        printf("\nRoll number: %d\n", i + 1);
        printf("First name: ");
        puts(s[i].firstName);
        printf("Marks: %.1f\n", s[i].marks);
        printf("Aadhar: ");
        if(s[i].aadhar==0){
                printf("foriegner\n");
                }
                else
                printf("citizen\n");
        printf("License Number: ");
        if(s[i].license==0){
                printf("not licensed\n");
                }
                else
                printf("licensed\n");
        printf("Sex: ");
        puts(s[i].gender);
        printf("\n");
    }
    return 0;
}