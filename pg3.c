#include<stdio.h>

int login_hour, login_minute, logout_hour, logout_minute, time_mins1, time_mins2;
int time_hour, time_minute, difference_min, choice, choice1;

void read_login_time() //function to read login time
{
    printf("\nEnter the login hour:");
    scanf("%02d",&login_hour);
    printf("\nEnter the login minute:");
    scanf("%02d",&login_minute);
    printf("\nThe login time is: %02d : %02d",login_hour,login_minute);
}

void read_logout_time() //function to read logout time
{
    printf("\nEnter the logout hour:");
    scanf("%02d",&logout_hour);
    printf("\nEnter the logout minute:");
    scanf("%02d",&logout_minute);
    printf("\nThe logout time is: %02d : %02d",logout_hour,logout_minute);
}

void difference() //function to find difference between login time
                  //and logout time
{ 
    time_mins1=(login_hour*60)+login_minute;
    time_mins2=(logout_hour*60)+logout_minute;
    if (time_mins2<time_mins1)
        {
        time_mins2+=(24*60);} //offset clock by 24 hours
    difference_min=time_mins2-time_mins1;
    
    time_hour=difference_min/60; //dividend is the number of hours
    time_minute=difference_min%60; //remainder is the number of minutes
    
    printf("\nThe difference between end time and start time is: %02d : %02d",time_hour,time_minute);
    
}

void convert_hm_m() //function to convert difference to minutes
{
    difference();
    printf("\nThe time in minutes is: %03d",difference_min);
}

void convert_m_hm() //function to convert difference to hh:mm format
{
    difference();
    
}
int main()
{
    printf("Welcome! What would you like to do today?\n");
    printf("1) Read login time (hour and minutes format)\n");
    printf("2) Read log out time (hour and minutes format)\n");
    printf("3) Convert the time in hh and mm format to minutes\n");
    printf("4) Convert the minutes into hh and mm format\n");
    printf("5) Display the difference between end time and start time (hour and minute format)\n");
    printf("6) Exit\n");
    
    printf("Select an option (1/2/3/4/5/6): ");
    scanf("\n%d",&choice);
    
    switch(choice){
        
        case 1:
            {
                read_login_time();
                printf("\nWould you like to continue? (1/0): ");
                scanf("%d",&choice1);
                
                if (choice1==1)
                {main();} //if user wishes to continue, go back to main function
                else
                printf("\nSee you soon!");
                break;
            }
            
        case 2:
            {
                read_logout_time();
                printf("\nWould you like to continue? (1/0): ");
                scanf("%d",&choice1);
                
                if (choice1==1)
                {main();}
                else
                printf("\nSee you soon!");
                break;
            }
            
        case 3:
            {
                read_login_time();
                read_logout_time();
                //read login time, logout time, and convert difference to hh:mm
                convert_hm_m(); 
                printf("\nWould you like to continue? (1/0): ");
                scanf("%d",&choice1);
                
                if (choice1==1)
                {main();}
                else
                printf("\nSee you soon!");
                break;
            }
            
        case 4:
            {
                read_login_time();
                read_logout_time();
                //read login time, logout time, and convert difference to minutes
                convert_m_hm();
                printf("\nWould you like to continue? (1/0): ");
                scanf("%d",&choice1);
                
                if (choice1==1)
                {main();}
                else
                printf("\nSee you soon!");
                break;
            }
        case 5:
            {
                read_login_time();
                read_logout_time();
                //read login time, logout time, and find difference
                difference();
                printf("\nWould you like to continue? (1/0): ");
                scanf("%d",&choice1);
                
                if (choice1==1)
                {main();}
                else
                printf("\nSee you soon!");
                break;
            }
        case 6:
            {
                printf("\nSee you soon!");
                break;
            }
        default:
            {
                printf("\nEnter a valid choice.");
                printf("\nWould you like to continue? (1/0): ");
                scanf("%d",&choice1);
                
                if (choice1==1)
                {main();}
                else
                printf("\nSee you soon!");
                break;
            }
    }
    return 0;
}


