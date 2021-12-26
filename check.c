#include<stdio.h>
#include<ctype.h>
#include <string.h>
#include <unistd.h>
//int rank;
int check_password(/*char *password*/){
    int rank;
    do{
        //char password[30];
        char *password;
        password = getpass("Enter the passwd string:");
        //printf("Enter the passwd string:");
        //scanf("%s",password);
        int a=0,i=0,b=0,c=0,d=0;
        rank=9;
        if(strlen(password)<8){
            rank-=1;
            //return 0;
        }
        //rank+=1;
        while(password[i]){
            if(ispunct(password[i])!=0){
                a=1;
                break;
            }
            i+=1;
        }
        if(a==0)
            rank-=2;
            //return 0;
        //rank+=2;
        i=0;
        a=0;
        while(password[i]){
            if(isupper(password[i])!=0){
                a=1;
                break;
            }
            i+=1;
        }
        if(a==0)
            rank-=2;
            //return 0;
        //rank+=2;
        int count=0;
        i=0;
        while(password[i]){
            if(islower(password[i])!=0){
                count+=1;
            }
            i+=1;
        }
        if(count<3)
            rank-=1;
            //return 0;
        //rank+=1;
        i=0;
        a=0;
        count=0;
        while(password[i]){
            if(isdigit(password[i])!=0){
                a=password[i];
                count+=1;            
                if(isdigit(password[i+1])!=0){
                    b=password[i+1];
                    count+=1;
                    if(isdigit(password[i+2])!=0){
                        c=password[i+2];
                        count+=1;
                        if((b==a+1)&&(c==b+1)){
                            d=1;
                        }
                    }
                }

            }
            i+=1;
        }
        if(count<4)
            rank-=2;
            //return 9;
        else if(d==1)
            rank-=1;
        //else
            //rank-=3;
            //return 0;
        //printf("%d\n",rank);
        if(rank==0){
            printf("Weakest password\n");
            printf("Enter a strong password again\n");
    }
        else if(rank<3){
            printf("Weak password\n");
            printf("Enter a strong password again\n");
    }
        else if(rank<5){
            printf("Aveange password\n");
            printf("Enter a strong password again\n");
    }
        else if(rank<7){
            printf("Medium password\n");
            printf("Enter a strong password again\n");
    }
        else if(rank<9){
            printf("Strong password\n");
            printf("Enter a strong password again\n");
    }
        else
            printf("Strongest password\n");
    }while(rank<9);   
}
int main(){
    //char *getpass(const char *prompt);
    check_password();
    //printf("%d\n",check_password(passwd));
    //printf("%d\n",rank);
}
