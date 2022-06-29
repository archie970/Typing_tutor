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
        //printf("%c\t%c\t%d\n",str1[i],str2[i],count);
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
    int correct; double raw_speed, accurate_speed;
    
    correct=(n-count);
    raw_speed= (n/tim);
    accurate_speed= (correct/tim);

    printf("\n\n Time user took %0.2f \n\n" , tim);

    //speed in secs
    printf("\n\nLetter per sec (RAW): %0.2f \n\n", raw_speed);
    printf("\n\nLetter per sec (ACCURATE): %0.2f\n\n", accurate_speed);

    //speed in minutes
    printf("\n\nEstimated Words per minute (RAW): %0.0f\n\n", (n/tim)*12);
    printf("\n\nEstimated Words per minute (ACCURATE): %0.0f\n\n",((correct/tim)) *12);

    double accuracy;
    accuracy=(correct*100)/n;
    printf("\n\nAccuracy of the user is %0.2f%%\n\n",accuracy);
}

void speed_word(double tim, int n,int count,int num)
{
    int correct; double raw_speed, accurate_speed;
    
    correct=(n-count);
    raw_speed= (n/tim);
    accurate_speed= (correct/tim);

    printf("\n\n Time user took %0.2f \n\n" , tim);

    //speed in secs
    printf("\n\nLetter per sec (RAW): %0.2f \n\n", raw_speed);
    printf("\n\nLetter per sec (ACCURATE): %0.2f\n\n", accurate_speed);

    //speed in minutes
    printf("\n\nEstimated Words per minute (RAW): %0.0f\n\n", (n/(num*tim))*60);
    printf("\n\nEstimated Words per minute (ACCURATE): %0.0f\n\n",((correct/(num*tim)) *60));

    double accuracy;
    accuracy=(correct*100)/n;
    printf("\n\nAccuracy of the user is %0.2f%%\n\n",accuracy);
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
    system("clear");
    
    FILE* fp= fopen("words.txt", "r");
    char line[10000];
    char test[1000];
    if (fp==NULL)
    {
        printf("FIle not Opened");
    }
    else
    {
        fgets(line,10000,fp);

        char *temp=strtok(line," ");
        strcpy(test,temp);
        strcat(test," ");

        printf("\nEnter No. words you want to practice : ");
        int num,n;
        scanf("%d", &num);

        for (int i = 1; i < num; i++)
        {
            char *tmp=strtok(NULL," ");
            strcat(test,tmp);
            strcat(test," ");  
        }
        printf("\n");
        fputs(test,stdout);
        printf("\n\n");    
        n=strlen(test);
        char user[n];
        
        double time_elapsed;
        time_elapsed=input_word(n,user); 
        
        int count=check_word(user, test,n);
        speed_word(time_elapsed,n,count,num);
    }
}

void overwrite()
{
    FILE* fp= fopen("words.txt", "w");
    printf("The File has been overwritten.");
    printf("How many words you want to write : ");
    int n;
    scanf("%d",&n);
    char temp[20];

    for (int i = 0; i < n; i++)
    {
        scanf("%s",temp);
        fprintf(fp,"%s ", temp);

    }
    fclose(fp);
}

void add_words()
{
    FILE* fp= fopen("words.txt", "a");
    int n,i;
    char add[20];
    if (fp==NULL)
    {
        printf("Database not opened");
    }
    else
    {
        printf("How may new Words you Want to add\n");
        scanf("%d",&n);
        for ( i = 0; i < n; i++)
        {
            printf("\nEnter a new word : ");
            scanf("%s", add);
            fprintf(fp,"%s ",add);
        }
    }
    fclose(fp);
}

void proceed()
{
    int temp;
    printf("\nWhat do you want to do?");
    printf("\n1. Add Words to Database");
    printf("\n2. Overwrite the existing Database with a new one");
    printf("\nEnter Choice : ");
    scanf("%d",&temp);
    switch (temp)
    {
    case 1:
        int n;
        add_words();
        break;

    case 2:
        overwrite();
        break;
    
    default:
        break;
    }
}

void security(char ques[50])
{
    jump:
    printf("\nSelect a Security question from below\n");
    printf("\n1. What was your first pet ?\n");
    printf("\n2. What is your Best Friend's name?\n");
    printf("\n3. Which is Your least Favorite subject?\n");
    printf("\n4. Morning or Night?\n");
    printf("\nYour Choice : ");
    int temp;
    
    scanf("%d",&temp);
    switch (temp)
    {
    case 1:
        strcpy(ques,"What was your first pet?");
        break;
    case 2:
        strcpy(ques,"What is your Best Friend's name?");
        break;
    case 3:
        strcpy(ques,"Which is Your least Favorite subject?");
        break;
    case 4:
        strcpy(ques,"Morning person or Night Owl?");
        break;
    
    default:
        printf("\nChoose a Valid Question!!\n");
        goto jump;
        break;
    } 
}

void sign_in()
{
    FILE *fp=fopen("user.txt","r");
    if (fp==NULL)
    {
        printf("\nNo Admins yet\n");
    }
    else
    {
        char username[20];
        char username_in_file[20];
        int flag_user=0;

        char password[20];
        char password_in_file[20];

        char security_ques_ans[20];
        char security_ques_in_file[20];

        char security_question[50];

        char line[500];
        username_wrong:

        printf("\n\t\t\tWelcome To Sign_in Page\n");
        printf("\n\t\t\tEnter Username : ");
        scanf("%s", username);
        rewind(fp);
        while (fgets(line,500,fp)!=NULL)
        {
            strcpy(username_in_file,strtok(line,"~"));
            if(strcmp(username_in_file,username)==0)
            {
                flag_user=1;
                strcpy(password_in_file,strtok(NULL,"~"));

                label:
                printf("\n\t\t\tEnter password : ");
                scanf("%s", password);
                if(strcmp(password_in_file,password)==0)
                {
                    proceed();
                    break;
                }

                else
                {
                    start:
                    int choice;
                    printf("\n\n\tIncorrect password!!\n");
                    printf("\n\t1. Retry password again\n");
                    printf("\n\t2. Try Security Question\n");
                    printf("\n\tEnter Your Choice : ");
                
                    scanf("%d",&choice);

                    switch (choice)
                    {
                    case 1:
                        goto label;
                        break;
                    case 2:
                        strcpy(security_question,strtok(NULL,"~"));
                        printf("\n");
                        fputs(security_question,stdout);
                        char temp;
                        
                        printf("\nYour Answer : ");
                        scanf("%c",&temp);
                        scanf("%s", security_ques_ans);
                        strcpy(security_ques_in_file,strtok(NULL,"~"));
                        printf("\n");
                        // printf("%s",security_ques_in_file);
                        // printf("%s",security_ques_ans);
                        if(strcmp(security_ques_in_file,security_ques_ans)==0)
                        {
                            proceed();
                            break;
                        }
                        else
                        {
                            goto start;
                        }
                        break;
                        
                    default:
                        printf("\n Wrong Choice!!\n");
                        goto start;
                        break;
                    }

                }
            }
            
        }
        if (flag_user==0)
        {
            printf("\nUser not found\n");
            goto username_wrong;
        }
        
    }
    fclose(fp);
    
}

void sign_up()
{
    FILE *fp=fopen("user.txt","a");
    if (fp==NULL)
    {
        printf("File not opened");
    }
    else
    {
        char username[20];
        char password[20];
        char secans[20];
        char securityques[50];
        
        printf("\nEnter Username : ");
        scanf("%s", username);
        printf("\nEnter Password : ");
        scanf("%s", password);
        security(securityques);
        printf("\nEnter your answer : ");
        scanf("%s", secans);    

        fprintf(fp,"%s~%s~%s~%s\n",username,password,securityques,secans);
        fclose(fp);
    }

    sign_in();
}

void adminmode()
{
    int choice;
    up:
    printf("\n\t\t\tWhat discribes you best\n");
    printf("\n\t\t\t1. New User\n");
    printf("\n\t\t\t2. Existing User\n");
    printf("\n\t\t\tYour Choice : ");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        sign_up();
        break;
    case 2:
        sign_in();
        break;
    
    default:
        goto up;
        break;
    }
}

void template()
{
        printf("\n\t\t\t\t\t\t\t What do you want to Practice\n\n");
        printf("\n\t\t\t\t\t\t\t 1. User guide to Touch Typing\n\n");
        printf("\n\t\t\t\t\t\t\t 2. Letter Mode\n\n");
        printf("\n\t\t\t\t\t\t\t 3. Word Mode\n\n");
        printf("\n\t\t\t\t\t\t\t 4. Admin Mode\n\n");
        printf("\n\t\t\t\t\t\t\t 5. Exit \n\n");
        printf("\n\t\t\t\t\t\t\t Your Choice :  ");
}

void horizontal_rule()
{
    printf("\n\n\n\t\t\t\t\t------------------------------------------------------------------------------\n\n\n");
}

void template_letter_mode()
{
    printf("\n\t\t\t\t\t\t\t What do you want to Practice in letter Mode\n");
    printf("\n\t\t\t\t\t\t\t 1. Home Row\n");
    printf("\n\t\t\t\t\t\t\t 2. Top Row\n");
    printf("\n\t\t\t\t\t\t\t 3. bottom Row\n");
    printf("\n\t\t\t\t\t\t\t 4. Number Keys\n");
    printf("\n\t\t\t\t\t\t\t 5. Special Keys \n");
    printf("\n\t\t\t\t\t\t\t 6. Exit Letter Mode\n\n");
    printf("\n\t\t\t\t\t\t\t Your Choice :  ");
}

int main()
{
    int ch,flag_program=1;
    char temp;
    printf("\n\t\t\t\t\t\t\t\t  Hello User\n");

    while (flag_program)
    {
        template();
        
        scanf("%d",&ch);
        scanf("%c",&temp);
        
        horizontal_rule();

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
                    
                    
                    template_letter_mode();
                    
                    
                    scanf("%d",&letter);
                    scanf("%c",&temp);

                    switch (letter)
                    {
                        case 1:
                        printf("\nHow many Letters?\n");
                        scanf("%d", &n);
                        scanf("%c",&temp);
                        home_row(n);
                        break;

                        case 2:
                        printf("\nHow many Letters?\n");
                        scanf("%d", &n);
                        scanf("%c",&temp);
                        top_row(n);
                        
                        break;

                        case 3:
                        printf("\nHow many Letters?\n");
                        scanf("%d", &n);
                        scanf("%c",&temp);
                        bottom_row(n);
                        break;

                        case 4:
                        printf("\nHow many Letters?\n");
                        scanf("%d", &n);
                        scanf("%c",&temp);
                        number(n);
                        break;

                        case 5:
                        printf("\nHow many Letters?\n");
                        scanf("%d", &n);
                        scanf("%c",&temp);
                        special_keys(n);
                        break;

                        case 6:
                        printf("\n\t\t\t\t\t\t\t\t Thank You\n");
                        flag_letter_mode=0;
                        break;

                        default:
                        printf("\nInvalid choice\n");
                        break;
                    }
                
                    horizontal_rule();
                }
            }
            break;
            
            case 3:
            printf("\nWelcome to Word Mode !!\n");
            wordmode();
            break;

            case 4:
            printf("\nWelcome to Admin Mode !!\n");
            adminmode();
            break;

            case 5:
            flag_program=0;
            break;

            default:
            printf("\nInvalid Choice\n");
            break;
        }
    }
    return 0;
}