#include<stdio.h>
struct information
{
    char name[30];
    char gender[10];
    char email[20];
    int age;
    int phone;
    char address[30];
    char date_of_birth[20];
};
void pattern();


void doctorConsultation()
{

}
void vaccination(struct information si)
{
   char y[] = "Yes";
   char y1[5],*ptr1,*ptr2;
   char pre;
   int count = 0,vacnum,pregnum;
   printf("Are you vaccinated? \nType Yes/No\n");
   scanf("%s",y1);
   ptr1 = y1;
   ptr2 = y;
   while(*ptr1==*ptr2)
   {
     if(*ptr1=='\0' && *ptr2=='\0'){
        count = 1;
     }
     ptr1++;
     ptr2++;
   }
  char y2[5];
   if(count ==1){
    printf("Did you also give booster dose?\n");
    scanf("%s",y2);
       if(strcmp(y2,y)==0)
       {
           printf("Congratulations! You are done with vaccination");
       }
       else
       {
          printf("Which dose you want to receive?\n1.Pfizer\n2.Moderna\nType 1 or 2 to select\n");
          scanf("%d",&vacnum);
          if(vacnum == 1 && si.age>=12 && si.age<50)
          {
             infoBooster1();

          }
           else if(vacnum == 1 && si.age>=50)
           {
             infoBooster2();
           }
           else if(vacnum == 2 && si.age>=50)
           {
             infoBooster2();
           }
           else if(vacnum == 2 && si.age>=18 && si.age<50)
           {
             infoBooster1();
           }
       }

   }
    else
   {
       fflush(stdin);
       printf("Which dose you want to receive?\n1.Pfizer\n2.Moderna\nType 1 or 2 to select\n");
       scanf("%d",&vacnum);
    if(strcmp(si.gender,"Male")==0)
    {
        if(vacnum == 1)
        {
           if(si.age>=12 && si.age<70)
            {
            printf("You are eligible for Pfizer dose");
            }
           else
            {
            printf("You are not eligible for Pfizer dose");
            }
        }
        else
        {
            if(si.age >=18 && si.age<70)
            {
            printf("You are eligible for Moderna dose");
            }
            else{
                printf("You are not eligible for Moderna dose");
            }
        }

    }
    else
    {
        fflush(stdin);
        printf("Do you have pregnancy?\nType Y/N\n");
        scanf("%c",&pre);
        if(pre == 'Y')
        {
            fflush(stdin);
            printf("How many weeks are running of your pregnancy?");
            scanf("%d",&pregnum);
            if(pregnum <= 20)
            {
                printf("You are safe for vaccination.\nNo possibility of miscarage");
            }
            else{
                printf("You are not safe for vaccination.\nThere is a huge possibility of miscarage");
            }
        }
        else
        {
          if(vacnum == 1)
          {
           if(si.age>=18 && si.age<70)
            {
            printf("You are eligible for Pfizer dose");
            }
           else
            {
            printf("You are not eligible for Pfizer dose");
            }
          }
          else{
            if(si.age >=18 && si.age<70)
            {
            printf("You are eligible for Moderna dose");
            }
            else{
                printf("You are not eligible for Moderna dose");
            }
          }

        }
    }
   }

}
void infoBooster1()
{   int month;
    printf("How many months ago you have completed your primary COVID-19 vaccination series?\n");
          scanf("%d",&month);
    switch(month)
             {
             case 1 ... 4:
                printf("You are not eligible for Booster dose");
                break;
                case 5 ... 12:
                printf("Congratulations! You are eligible for Booster dose.\nBut you are only allowed for the first booster dose.");
                break;
             default :
                printf("ERROR!");
                break;
             }
}
void infoBooster2()
{   int month;
    printf("How many months ago you have completed your primary COVID-19 vaccination series?\n");
          scanf("%d",&month);
    switch(month)
             {
             case 1 ... 4:
                printf("You are not eligible for Booster dose");
                break;
                case 5 ... 12:
                printf("Congratulations! You are eligible for Booster dose.\nAnd you are also allowed for the second booster dose.");
                break;
             default :
                printf("ERROR!");
                break;
             }
}
void hospitalBooking()
{

}

void write(struct information si)
{
    FILE *f1;
    f1 = fopen("information.txt","w");
    if(f1==NULL)
    {
        printf("File error!");
    }
    else
    {
        fprintf(f1,"Name : %s \nAge : %d \nGender : %s \nDate of Birth : %s \nPhone : %d \nAddress : %s \nEmail : %s",si.name,si.age,si.gender,si.date_of_birth,si.phone,si.address,si.email);
    }
    fclose(f1);
}
int main()
{
    struct information si;
    printf("************** WELCOME TO THE COVID APP **************\n\n");
    printf("************* YOU NEED TO SIGN UP FIRST *************\n\n");
    fflush(stdin);
    printf("NAME : ");
    scanf("%[^\n]s",si.name);
   // printf("%s\n",si.name);
    fflush(stdin);
    printf("AGE : ");
    scanf("%d",&si.age);
     //printf("%d\n",si.age);
    fflush(stdin);
    printf("GENDER : ");
    scanf("%s",si.gender);
    // printf(%s\n",si.gender);

    fflush(stdin);
    printf("PHONE NUMBER : ");
    scanf("%d",&si.phone);
    fflush(stdin);
    printf("DATE OF BIRTH : ");
    scanf("%[^\n]s",si.date_of_birth);

    fflush(stdin);
    printf("ADDRESS : ");
    scanf("%s",si.address);
    fflush(stdin);
    printf("EMAIL : ");
    scanf("%s",si.email);
    printf("********* Sign Up Successful *********\n");
    pattern();
    write(si);

    printf("Now choose the numbers to get into our services : \n1.Doctor COnsultation\n2.Vaccination\n3.Hospital Booking\n4.Covid Info\n");
    int n;
    scanf("%d",&n);
    switch(n)
    {
    case 1 :
         doctorConsultation();
         break;
    case 2 :
         vaccination(si);
         break;
    case 3 :
         hospitalBooking();
         break;
   default :
    {
        printf("****** ERROR! ******");
    }

    }


    getch();

}
void pattern()
{

printf("======================================================================================\n");
    int i,j,n=4;
    for(i=1;i<n;i++)
    {  for(j=1;j<=n-i;j++)
       {
           printf("  ");
       }
       for(j=1;j<=6;j++)
       {
           if(j==1||i==1)
           {
               printf(" @");
           }
           else
           {
               printf("  ");
           }
       }
       for(j=1;j<=n-i;j++)
       {
           printf("  ");
       }
       for(j=1;j<=i;j++)
       {
           if(j==i)
           {
               printf(" @");
           }
           else
           {
               printf("  ");
           }
       }
       for(j=1;j<=3;j++)
       {
           if(i==1)
           {
               printf(" @");
           }
           else
           {
               printf("  ");
           }
       }
       for(j=1;j<=2*i-1;j++)
       {
           if(j==2*i-1 )
           {
               printf(" @");
           }
           else
           {
               printf("  ");
           }
       }
       for(j=1;j<=6;j++)
       {
           if(j==4)
           {
               printf(" @");
           }
           else
           {
               printf("  ");
           }
       }
       for(j=1;j<=n-i;j++)
       {
           printf("  ");
       }
       for(j=1;j<=4;j++)
       {
           printf("  ");
       }
       for(j=1;j<=n-i;j++)
       {
        if(j==n-i)
        {
            printf(" @");
        }
        else
            printf("  ");
       }
     for(j=1;j<=2;j++)
     {
         printf("  ");
     }
     for(j=1;j<=i;j++)
     {
         printf("  ");
     }
     for(j=1;j<=1;j++)
     {
         printf(" @");
     }
      for(j=1;j<=4;j++)
      {   if(j==4)
          {printf(" @");
          }
          else
          {
              printf("  ");
          }
      }
      for(j=1;j<=i;j++)
      {   if(j==i)
         {printf(" @");
         }
         else
         {
             printf("  ");
         }
      }


     printf("\n");
    }

    for(i=n;i>=1;i--)
    {  for(j=1;j<=n-i;j++)
       {
           printf("  ");
       }
       for(j=1;j<=6;j++)
       {
           if(j==1||i==1)
           {
               printf(" @");
           }
           else
           {
               printf("  ");
           }
       }
       for(j=1;j<=n-i;j++)
       {
           printf("  ");
       }
       for(j=1;j<=i;j++)
       {
           if(j==i)
           {
               printf(" @");
           }
           else
           {
               printf("  ");
           }
       }
       for(j=1;j<=3;j++)
       {
           if(i==1)
           {
               printf(" @");
           }
           else
           {
               printf("  ");
           }
       }
       for(j=1;j<=2*i-1;j++)
       {
           if(j==2*i-1 )
           {
               printf(" @");
           }
           else
           {
               printf("  ");
           }
       }

    for(j=1;j<4;j++)
    {
        printf("  ");
    }
    for( j=1;j<=n-i;j++)
    {
        printf("  ");
    }

for( j=1;j<=n-i;j++)
    {
        printf("  ");
    }
    for(j=1;j<=i;j++)
    { if(j==1)
        {printf(" @");
        }
        else
        {
            printf("  ");
        }
    }
    for(j=1;j<i;j++)
    {   if(j==i-1)
        {printf(" @");
        }
        else
        {
            printf("  ");
        }
    }
    for(j=1;j<=n-i;j++)
    {
        printf("  ");
    }
    for(j=1;j<=6;j++)
    {
        printf("  ");
    }
     for(j=1;j<=1;j++)
     {
         printf(" @");
     }
     for(j=1;j<=4;j++)
      {   if(j==4)
          {printf(" @");
          }
          else
          {
              printf("  ");
          }
      }
      for(j=1;j<=i;j++)
      {   if(j==i)
         {printf(" @");
         }
         else
         {
             printf("  ");
         }
      }



    printf("\n");

}
{
 printf("                                                              \n");
 printf("                           @        @ @ @ @ @     @ @ @ @ @    \n");
 printf("                          @ @       @         @   @         @   \n");
 printf("                         @   @      @ @ @ @ @     @ @ @ @ @      \n");
 printf("                        @ @ @ @     @             @               \n");
 printf("                       @        @   @             @                \n");
 printf("                      @          @  @             @                 \n");
 printf("                     @            @ @             @                  \n");
 printf("======================================================================================");
}

}

