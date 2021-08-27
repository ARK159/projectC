#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
typedef struct{
char name[50];
int train_num;
int num_of_seats;
int ticket_no;
}pd;

void reservation(void);
void viewdetails(void);
void cancel(void);
void printticket(char name[],int,int,float,int);
void specifictrain(int);
float charge(int,int);
int login();
void VIEW();
void PASSWORDCHANGE()
{
    system("cls");
    printf("\n");
    char pass[15],confirm[15],ch;
int r,i,check;
FILE *fp;

    fflush(stdin);
        printf("\tENTER NEW PASSWORD:");
            gets(pass);
            fflush(stdin);
        printf("\n\tCONFIRM PASSWORD:");
           gets(confirm);
 if(strcmp(pass,confirm)==0)

         {

                fp=fopen("xyz","wb");
                if(fp==NULL)

                {
                    printf("\n\t\t  ERROR");
                    getch();
                    return ;
                }
                i=0;
                fprintf(fp,"%s",pass);
                fclose(fp);

            }
            else
            {
                printf("\n\tTHE NEW PASSWORD DOES NOT MATCH.");
            }
    printf("\n\n\tPASSWORD CHANGED...\n\n\tPRESS ANY KEY TO GO BACK...");
 getch();

}

int main()
{
    fclose(fopen("seats", "w"));
 
int k=login();
if(k){
int menu_choice,choice_return;
st:
system("cls");
printf("\n=================================\n");
printf(" TRAIN RESERVATION SYSTEM");
printf("\n=================================");
printf("\n1>> Reserve A Ticket");

printf("\n------------------------");
printf("\n2>> VIEW ALL AVAILABLE TRAINS");
printf("\n------------------------");
printf("\n3>> CANCEL RESERVATION");
printf("\n------------------------");
printf("\n4>>VIEW BOOKINGS");
printf("\n------------------------");
printf("\n5>>EDIT PASSWORD");
printf("\n------------------------");
printf("\n6>> Exit");
printf("\n------------------------");
printf("\n\n-->");
fflush(stdin);
scanf("%d",&menu_choice);
fflush(stdin);
switch(menu_choice)
{
case 1:
reservation();
break;
case 2:
viewdetails();
fflush(stdin);
getch();
break;

case 3:
cancel();
break;

case 4:
VIEW(); 
break;

case 5:
PASSWORDCHANGE();
break;

case 6:
return(0);

default:
printf("\nInvalid choice");
break;
}
goto st;
return(0);
}}

void viewdetails(void)
{
system("cls");

printf("-----------------------------------------------------------------------------");
printf("\nTr.No Name Destinations Charges Time\n");
printf("-----------------------------------------------------------------------------");
printf("\n1001\tKathmandu Express \tKathmandu to Pokhara \tRs.5000\t\t9am");
printf("\n1002\tKoshi Express \t\tBiratnagar To Lumbini\tRs.5000\t\t12pm");
printf("\n1003\tNepal Express \t\tKathmandu To Lumbini \tRs.4500\t\t8am");
printf("\n1004\tHi-Fi Express \t\tSarlahi To BIrgung \tRs.4500\t\t11am");
printf("\n1005\tSajha  Express \t\tShantinagar To Kalanki\tRs.3000\t\t7am");
printf("\n1006\tAvantika Express \tBirgunj To Mumbai \tRs.2000\t\t9.30am");
printf("\n1007\tFasttrack Express \tPokhara To Butwal \tRs.3500\t\t1pm");
printf("\n1008\tPython Express \t\tKalinchowk To Sindhuli \tRs.2000\t\t4pm");
printf("\n1009\tJava Express \t\tDelhi to Janakpur\tRs.6000\t\t3.35pm");
printf("\n1009\tFortran Express \tJhapa To Mahendranagar\tRs.6000\t\t4.15pm");
}

void reservation(void)
{
char confirm;
int i=0;
float charges;
pd passdetails;
FILE *fp;
fp=fopen("seats","a+");
system("cls");
printf("\nEnter Your Name:> ");
fflush(stdin);
gets(passdetails.name);
printf("\nEnter Number of seats:> ");
fflush(stdin);
scanf("%d",&passdetails.num_of_seats);
fflush(stdin);
printf("\n\n>>Press Enter To View Available Trains<< ");
getch();
system("cls");
viewdetails();
st1:
printf("\n\nEnter train number:> ");
fflush(stdin); 
scanf("%d",&passdetails.train_num);
fflush(stdin);
// FILE *fileptr;
// int count_lines = 0;
// char filechar[40], chr;
// fileptr = fopen("seats", "r");
// chr = getc(fileptr);
// while (chr != EOF)
// {
// if (chr == 'n')
// {
// count_lines = count_lines + 1;
// }
// chr = getc(fileptr);
// }
srand(time(NULL));
passdetails.ticket_no=rand();
//printf("\ndsdsddd\t===%d",count_lines);
if(passdetails.train_num>=1001 && passdetails.train_num<=1010)
{
 charges=charge(passdetails.train_num,passdetails.num_of_seats);
 printticket(passdetails.name,passdetails.num_of_seats,passdetails.train_num,charges,passdetails.ticket_no);
}
else
{
 printf("\nInvalid train Number! Enter again---> ");
 goto st1;
}
printf("\n\nConfirm Ticket (y/n):>");

start:
fflush(stdin);
scanf(" %c",&confirm);
fflush(stdin);
if(confirm == 'y' || confirm == 'Y')
{
    fwrite(&passdetails,sizeof(passdetails),1,fp);
    
//fprintf(fp,"%s\t\t%d\t\t%d\t\t%.2f\t\t%d\n",&passdetails.name,passdetails.num_of_seats,passdetails.train_num,charges,passdetails.ticket_no);
printf("==================");
printf("\n Reservation Done\n");
printf("==================");
printf("\nPress any key to go back to Main menu");
getch();
fclose(fp);
//fclose(fileptr);
return;
}
else
{
if(confirm=='n'|| confirm =='N'){
printf("\nReservation Not Done!\nPress any key to go back to Mainmenu!");
getch();
return;
}
else
{
printf("\nInvalid choice entered! Enter again-----> ");
goto start;
}
}
fclose(fp);
//fclose(fileptr);
getch();
}


float charge(int train_num,int num_of_seats)
{
if (train_num==1001)
{
return(5000.0*num_of_seats);
}
if (train_num==1002)

{
return(5000.0*num_of_seats);
}
if (train_num==1003)
{
return(4500.0*num_of_seats);
}
if (train_num==1004)
{
return(4500.0*num_of_seats);
}
if (train_num==1005)
{
return(3000.0*num_of_seats);
}
if (train_num==1006)
{
return(2000.0*num_of_seats);
}
if (train_num==1007)
{
return(3500.0*num_of_seats);
}
if (train_num==1008)
{
return(2000.0*num_of_seats);
}
if (train_num==1009)
{
return(6000.0*num_of_seats);
}
if (train_num==1010)
{
return(6000.0*num_of_seats);
}
}

void printticket(char name[],int num_of_seats,int train_num,float charges,int ticket_no)
{

printf("-------------------\n");
printf("\tTICKET\n");
printf("-------------------\n\n");
printf("Name:\t\t\t%s",name);
printf("\nNumber Of Seats:\t%d",num_of_seats);
printf("\nTrain Number:\t\t%d",train_num);
specifictrain(train_num);
printf("\nCharges:\t\t%.2f",charges);
printf("\nticket number:\t\t%d",ticket_no);
getch();

}

void specifictrain(int train_num){

{
if (train_num==1001)
{
printf("\nTrain:\t\t\tKathmandu Express");
printf("\nDestination:\t\tKathmandu to Pokhara");
printf("\nDeparture:\t\t9am ");
}
if (train_num==1002)
{
printf("\nTrain:\t\t\tKoshi Express");
printf("\nDestination:\t\tKathmandu To Biratnagar");
printf("\nDeparture:\t\t12pm");
}
if (train_num==1003)
{
printf("\nTrain:\t\t\tNepal Express");
printf("\nDestination:\t\tKathmandu To Lumbini");
printf("\nDeparture:\t\t8am");

}
if (train_num==1004)
{
printf("\nTrain:\t\t\tHi-Fi Express");
printf("\nDestination:\t\tSarlahi To Birgung");
printf("\nDeparture:\t\t11am ");
}
if (train_num==1005)
{
printf("\nTrain:\t\t\tSajha  Express");
printf("\nDestination:\t\tShantinagar To Kalanki");
printf("\nDeparture:\t\t7am");
}
if (train_num==1006)
{
printf("\ntrain:\t\t\tAvantika Express");
printf("\nDestination:\t\tBirgunj To Mumbai");
printf("\nDeparture:\t\t9.30am ");
}
if (train_num==1007)
{
printf("\ntrain:\t\t\tFasttrack Express");
printf("\nDestination:\t\tPokhara To Butwal");
printf("\nDeparture:\t\t1pm ");
}
if (train_num==1008)
{
printf("\ntrain:\t\t\tPython Express");
printf("\n Destination:\t\tKalinchowk To Sindhuli");
printf("\nDeparture:\t\t4pm ");
}
if (train_num==1009)
{
printf("\ntrain:\t\t\tJava Express");
printf("\nDestination:\t\tDelhi to Janakpur");
printf("\nDeparture:\t\t3.35pm ");

}
if (train_num==1010)
{
printf("\ntrain:\t\t\tFortran Express");
printf("\nDestination:\t\tJhapa To Mahendranagar");
printf("\nDeparture:\t\t1.15 ");
}
}}


int login()
{
	int a=0,i=0;
    char username[10]; 
    char password[10];
    char user[10]="arjun";
    char pass[10];
    FILE *FEP;
    
    FEP=fopen("xyz","r+");
    // fprintf(FEP,"pass");
    // fclose(FEP);
    if(FEP==NULL){
        printf("FILE CANNOT OPEN");
    }else{
               // fscanf(FEP,"%s",pass);
        
            fscanf(FEP,"%s",pass);
           
             
    }
   //pass[i]='\0';
    printf("%s",pass);
    do
{
	
    printf("\n  ####################### PLEASE LOGIN ############################# ");
    printf(" \n                       ENTER USERNAME:-");
	scanf("%s", &username); 
	printf(" \n                       ENTER PASSWORD:-");
	 i=0;
	scanf("%s",password); 
		if(strcmp(username,"user")==0 && strcmp(password,pass)==0)
	{
	printf("  \n\n\nWELCOME TO RAILWAY TICKET MANAGEMENT SYSTEM\n!!!! LOGIN IS SUCCESSFUL");
	    printf("\n LOADING PLEASE WAIT... \n");
    for(i=0; i<3 ;i++)
    {
        printf(".");
       sleep(3);
    }
	printf("\n\n\n\t\t\t\tPress any key to continue...");
	getch();//holds the screen
    return 1;
	
	}
	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;
		getch();//holds the screen	
	}
}
	while(a<=4);
	if (a>4)
	{
		printf(" \nSorry you have entered the wrong username and password for four time!!!!TRY AGAIN LATER");
		getch();
        return 0;
		}
		system("cls");	
}
void cancel(void)
{
system("cls");
int lno, ctr = 0;
char ch;
pd p;
FILE *fptr1, *fptr2;
char fname[100];
char str[100], temp[] = "tempT";

fptr1 = fopen("seats", "r+");
fptr2 = fopen("tempT", "wb");
printf("-----------------------\n");
printf("Enter the ticket number:\n");
printf("-----------------------\n");
fflush(stdin);
printf("\t\t\t");
scanf("%d", &lno);

fflush(stdin);
 while(fread(&p,sizeof(p),1,fptr1)==1){

     if(p.ticket_no!=lno){
                    fwrite(&p,sizeof(p),1,fptr2);
                     
     }
     else{
         ctr++;
     }
 }
 
fclose(fptr1);
fclose(fptr2);
remove("seats");
rename("tempT", "seats");
        if(ctr>0){printf("\t\t RECORD DELETED");
        getch();
        printf("\n\t\tPRESS ANY KEY TO CONTINUE");}
            else{printf("\t\tNO RECORDS DELETED");
fflush(stdin);            getch();
            printf("\n\t\tPRESS ANY KEY TO CONTINUE");}
 }
 void VIEW( )
{
    FILE *fpte ;
    system("cls");
    pd l ;
    
    int ch;
    printf("\n\n\t\t#############################:::\n");
    printf("\t\t\t: VIEWING MENU :");
    printf("\n\t\t#############################:::\n\n");
   // while(1)
   // {
        
        fpte = fopen ("seats", "r" ) ;
        if ( fpte == NULL )
        {
            puts ( "\nTHE RECORD DOES NOT EXIST...\n" ) ;
            printf("PRESS ANY KEY TO EXIT...");
            getch();
            return ;
        }
        // system("cls");
        printf("\n\tENTER ticket NUMBER:\n");
          fflush(stdin);
        scanf("%d",&ch);
        printf("\t");
         fflush(stdin);
float charges;
        int c=0,m;
     
           //  rewind(fpte);
            while ( fread ( &l, sizeof (l), 1, fpte ) == 1 )
            { 
                     if(l.ticket_no==ch){
        
                    charges=charge(l.train_num,l.num_of_seats);
                     printticket(l.name,l.num_of_seats,l.train_num,charges,l.ticket_no);
                     printf("\n");
                     c++;
                     }
            }
            fclose(fpte);
        if(c==0){
            printf("\n\t\tNO SUCH BOOKING HAS BEEN DONE");
            fflush(stdin);
            getch();
            fflush(stdin);
           return;
        }
            
            
        
       
    //}
    
   
    return ;
}