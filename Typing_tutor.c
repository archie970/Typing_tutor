#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include<time.h>

int check_letter(char str1[], char str2[],int n)
{
    int i,count=0;
    for (i = 0; i < n; i++)
    {
        //printf("%c\t%c\t%d\n",str1[i],str2[i],count);
        if(str1[i]!=str2[i])
        {
            count++;
        }
    }
    printf("\nNumber of mistakes user did : \t%d\n", count);
    return count;
}

int check_word(char str1[], char str2[],int n)
{
    int i,count=0;
    for (i = 0; i < n-1; i++)
    {
        printf("%c\t%c\t%d\n",str1[i],str2[i],count);
        if(str1[i]!=str2[i])
        {
            count++;
        }
    }
    printf("\nNumber of mistakes user did : \t%d\n", count);
    return count;
}

double input_letter(int n, char a[])
{
    //counting seconds
    time_t t_initial,t_final;
    double time_elapsed;
    t_initial=time(NULL);

    for(int i=0;i<n;i++)
    {
        scanf("%c",&a[i]);
    }

    t_final=time(NULL);
    time_elapsed=(double)(t_final-t_initial);

    return time_elapsed;

}

double input_word(int n, char a[])
{
    //counting seconds
    time_t t_initial,t_final;
    double time_elapsed;
    t_initial=time(NULL);

    int t;
    scanf("%d",&t);
    for(int i=0;i<n;i++)
    {
        scanf("%c",&a[i]);
    }

    t_final=time(NULL);
    time_elapsed=(double)(t_final-t_initial);

    return time_elapsed;

}

void speed(double tim, int n,int count)
{
    int correct, raw_speed, accurate_speed;
    
    correct=(n-count);
    raw_speed= (int)(n/tim);
    accurate_speed= (int)(correct/tim);

    printf("\n\n Time user took %0.2f \n\n" , tim);

    //speed in secs
    printf("\n\nLetter per sec (RAW): %d \n\n", raw_speed);
    printf("\n\nLetter per sec (ACCURATE): %d\n\n", accurate_speed);

    //speed in minutes
    printf("\n\nEstimated Words per minute (RAW): %d\n\n", raw_speed*60);
    printf("\n\nEstimated Words per minute (ACCURATE): %d\n\n",((int)(correct/tim)) *60);

    double accuracy;
    accuracy=(correct*100)/n;
    printf("\n\nAccuracy of the user is %lf%%\n\n",accuracy);
}

void home_row(int n)
{
    char home[n+1];
    int i,count;

    //home row elements
    char hrow[9]={'a','s','d','f','g','h','j','k','l'};
   
    for ( i = 0; i < n; i++)
    {
        //inserting blank space after every 5 charecters
        if((i%6)==0 && (i!=0))
        {
            home[i]=' ';
        }

        //taking a random element from hrow array and adding it to home array.
        else
        {
            home[i]=hrow[rand()%9];
        }
    }
    home[i]='\0';
    printf("\n%s\n", home);

    //Reading string from user
    
    char user[n];
    //fgets(user,n,stdin); //Not working idk
    double time_elapsed;
    time_elapsed=input_letter(n,user);

    
    //check_letter function to calculate no. of occurences of undesired charecter.
    count=check_letter(user, home,n);

    //speed function calculating and printing user typing speed
    speed(time_elapsed,n,count);
    
}

void bottom_row(int n)
{
    char bottom[n+1];
    int i,count;
    char btrow[7]={'z','x','c','v','b','n','m'};
    for ( i = 0; i < n; i++)
    { 
        if((i%6)==0 && (i!=0))
        {
            bottom[i]=' ';
        } 
        else
        {
            bottom[i]=btrow[rand()%7];
        }
    }
    bottom[i]='\0';
    printf("\n%s\n", bottom);
    char user[n];
    
    double time_elapsed;
    time_elapsed=input_letter(n,user);

    count=check_letter(user, bottom,n);
    speed(time_elapsed,n,count);
}

void top_row(int n)
{
    char top[n+1];
    int i,count;
    char trow[10]={'q','w','e','r','t','y','u','i','o','p'};
    for ( i = 0; i < n; i++)
    {
        if((i%6)==0 && (i!=0))
        {
            top[i]=' ';
        }
        else
        {
            top[i]=trow[rand()%10];
        }
    }
    top[i]='\0';
    printf("\n%s\n", top);
    char user[n];
    
    double time_elapsed;
    time_elapsed=input_letter(n,user); 
    
    count=check_letter(user, top,n);
    speed(time_elapsed,n,count);
}

void number(int n)
{
    char num[n+1];
    int i,count;
    char number[10]={'0','1','2','3','4','5','6','7','8','9'};
    for ( i = 0; i < n; i++)
    {
        if((i%6)==0 && (i!=0))
        {
            num[i]=' ';
        }
        else
        {
            num[i]=number[rand()%10];
        }
    }
    num[i]='\0';
    printf("\n%s\n", num);
    char user[n];
   
    double time_elapsed;
    time_elapsed=input_letter(n,user);

    count=check_letter(user, num,n);
    speed(time_elapsed,n,count); 
}

void special_keys(int n)
{
    char keys[n];
    int i,count;
    char special[20]={'!','@','#','$','%','^','&','*','(',')', '[',']','{','}', ';',':','<','>','.','?' };                             
   
    for ( i = 0; i < n; i++)
    {
        if((i%3)==0 && (i!=0))
        {
            keys[i]=' ';
        }
        else
        {
            keys[i]=special[rand()%20];
        }
    }
    keys[i]='\0';
    printf("\n%s\n", keys);
    char user[n];
   
    double time_elapsed;
    time_elapsed=input_letter(n,user);

    count=check_letter(user, keys,n);
    speed(time_elapsed,n,count);  
}

void wordmode()
{
    
    FILE* fp= fopen("temp.txt", "r");
    char line[10000];
    char test[1000];
    
    fgets(line,10000,fp);

    char *temp=strtok(line," ");
    strcpy(test,temp);
    strcat(test," ");

    printf("Enter No. words");
    int n;
    scanf("%d", &n);

    for (int i = 1; i < n; i++)
    {
        char *tmp=strtok(NULL," ");
        strcat(test,tmp);
        strcat(test," ");  
    }
    
    fputs(test,stdout);
    printf("\n\n");    
    n=strlen(test);
    char user[n];
    
    double time_elapsed;
    time_elapsed=input_word(n,user); 
    
    int count=check_word(user, test,n);
}

int main()
{
    int ch,flag_program=1;
    char temp;
    printf("\n\t\t\t\t\t\t\t\t\t  Hello User\n");

    while (flag_program)
    {
        printf("\n\t\t\t\t\t\t\t\t What do you want to Practice\n\n");
        printf("\n\t\t\t\t\t\t\t\t 1. User guide to Touch Typing\n\n");
        printf("\n\t\t\t\t\t\t\t\t 2. Letter Mode\n\n");
        printf("\n\t\t\t\t\t\t\t\t 3. Word Mode\n\n");
        printf("\n\t\t\t\t\t\t\t\t 4. Exit \n\n");
        printf("\n\t\t\t\t\t\t\t\t Your Choice :  ");
        scanf("%d",&ch);
        scanf("%c",&temp);
        printf("\n\n\n\t\t\t\t\t\t------------------------------------------------------------------------------\n\n\n");

        switch(ch) 
        {
            case 1:
            printf("\n\nTouch typing is typing without looking at the keyboard. The fundamental idea is that each finger is given its own section of the keyboard and your fingers learn the location of the keyboard through practicing regularly and gaining muscle memory to eventually build up speed whilst typing. \n\n");
            break;


            case 2:
            {
                int flag_letter_mode=1,letter,n;
                while (flag_letter_mode)
                {
                    
                    printf("\n\t\t\t\t\t\t\t What do you want to Practice in letter Mode\n");
                    printf("\n\t\t\t\t\t\t\t 1. Home Row\n");
                    printf("\n\t\t\t\t\t\t\t 2. Top Row\n");
                    printf("\n\t\t\t\t\t\t\t 3. bottom Row\n");
                    printf("\n\t\t\t\t\t\t\t 4. Number Keys\n");
                    printf("\n\t\t\t\t\t\t\t 5. Special Keys \n");
                    printf("\n\t\t\t\t\t\t\t 6. Exit Letter Mode \n\n\t\t\t\t\t\t\t");
                    printf("\n\t\t\t\t\t\t\t Your Choice :  ");
                    scanf("%d",&letter);
                    scanf("%c",&temp);

                    switch (letter)
                    {
                        case 1:
                        printf("How many Letters?");
                        scanf("%d", &n);
                        scanf("%c",&temp);
                        home_row(n);
                        break;

                        case 2:
                        printf("How many Letters?");
                        scanf("%d", &n);
                        scanf("%c",&temp);
                        top_row(n);
                        
                        break;

                        case 3:
                        printf("How many Letters?");
                        scanf("%d", &n);
                        scanf("%c",&temp);
                        bottom_row(n);
                        break;

                        case 4:
                        printf("How many Letters?");
                        scanf("%d", &n);
                        scanf("%c",&temp);
                        number(n);
                        break;

                        case 5:
                        printf("How many Letters?");
                        scanf("%d", &n);
                        scanf("%c",&temp);
                        special_keys(n);
                        break;

                        case 6:
                        printf("\n\t\t\t\t\t\t\t\t\t Thank You\n");
                        flag_letter_mode=0;
                        break;

                        default:
                        printf("Invalid choice");
                        break;
                    }
                
                    printf("\n\n\n\t\t\t\t\t-----------------------------------------------------------------------------------------------\n\n\n");
                }
            }
            
            case 3:
            wordmode();
            break;

            case 4:
            flag_program=0;
            break;

            default:
            printf("Invalid Choice");
            break;
        }
    }
    return 0;
}