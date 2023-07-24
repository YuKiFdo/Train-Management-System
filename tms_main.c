// Created by Shehal.H on 2023-07-23 T21:00:00
// Admin Login: admin
// Admin Password: password

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct train_user {
	char f_name[20];
	char l_name[20];
	char age[20];
	char from[20];
	char to[20];
	char m_no[20];
}tu[100][100];

struct user {	
    char username[10];
	char pass[10];
}arr[100][100],a;


struct train {
	char train_name[20];
	char train_no[20];
	char charge[20];
	char from[20];
	char to[20];
	char status[20];	
}trr[200][200],ttt[200][200];


void welcometext();
void menu();
int quit();
void wrong();
void login();
void signup();
void administrator();

void administrator_menu();
void user_menu();

void des_page();
void ad_wrong_pass();
void wrong_pas();
void wrong_mob();
void verify();

void add_train();
void update_train();
void view_train_for_administrator();
void view_train_for_user();
void book_ticket();
void change();
void passenger_info();
void updates_in_train();
void update_train();
void t_update();
void cancle_updates();
void cancle_trains();
//int train_special_no=0;
void check();

//main function
void main() {
	welcometext();
	menu();
}

//main menu
void menu() {	
    char choice;

	printf("\n1.Signup\n2.Login \n3.Administrator\n4.Exit\n");
    printf("\n");
	printf("Enter your choice:- ");
	scanf("%s",&choice);
	
		switch(choice) {
			
			case '1' :
				signup();
				break;
					
			case '2' :
				login();
				break;
			
			case '3' :
				administrator();
				break;
			case '4' :
				quit();
				break;
				
			default :
				system("cls");
				printf("Please enter valid choice\n");
				menu();
				break;
		}
}

//change color of text
void change(){
	system("COLOR 2");
}

//welcome text
void welcometext() {
	change();
	printf("\n\n              _______________________Welcome to Train Management System_______________________\n\n");
}

//Create Account
void signup() {
	system("cls");
	FILE *fp;
	char value;
	fp=fopen("users.txt","ab+");
	if(fp==NULL) {
	printf("file not found");	
	}
	printf("\n\n\n               _______________________Create New User Account_______________________\n\n\n");
	int i, j ;
	for ( i=0;i<=0;i++) {
		for( j=0;j<=0;j++) {	
			printf("Enter your username - ");
			scanf("%s",&arr[i][j].username);
			printf("Enter your password - ");
			scanf("%s",&arr[i][j].pass);
			fwrite(&arr[i][j],sizeof(struct user),1,fp);
            printf("\n\n");
			printf("%s your account create successfully...\n\n\n",arr[i][j].username);
		}
	}
	fclose(fp);
	des_page();
}

//Choose Destination page
void des_page() {
		char choice;
		printf("Do you want to go login page y/n :- ");
		scanf("%s",&choice);
		choice=tolower(choice);
		switch(choice) {
			case 'y':
				system("cls");
				login();
				break;
			case 'n':
				system("cls");
				menu();
				break;
			default :
				printf("ERORR::: Enter valid choice\n");
				des_page();
				break;
		}
}

//Login page
void login() {
	system("cls");
	FILE *fp;
	struct user arr[100][100] ;
	char pass[20],username[20];
	int no=0;
	int count=49;
	fp=fopen("users.txt","ab+");
	if(fp==NULL) {
		printf("file not found");
	}
	printf("\n\n\n               _______________________Welcome to User Login Page_______________________\n\n\n");
	printf("Enter Username - ");
	scanf("%s",&username);
	printf("Enter Password - ");
	scanf("%s",&pass);
    int i, j ;
	for ( i=0;i<=count;i++) {
		for( j=0;j<=0;j++) {
			fread(&arr[i][j],sizeof(struct user),1,fp);
			if(strcmp(username,arr[i][j].username)==0 && strcmp(pass,arr[i][j].pass)==0 ) {
				system ("cls");
				printf("               ___________________ Welcome %s ___________________\n\n\n ",arr[i][j].username);
				user_menu();
			}else{
				no=no+1;
			}
		}		
	}
	if(no==50) {
		printf("%s your Username or Password is incorrect. Please try again..\n\n",username);
		wrong_pas();
	}
fclose(fp);
}

//wrong password - user
void wrong_pas() {
		char choice;
		printf("Do you want to go login again y/n :- ");
		scanf("%s",&choice);
		choice=tolower(choice);
		switch(choice){
			case 'y':
				login();
				break;
			case 'n':
				system("cls");
				menu();
				break;
			default :
				printf("ERORR::: Enter valid choice\n");
				wrong_pas();
				break;
		}	
}

//administrator login page
void administrator() {
	char u_name[20];
	char pass[20];
	char value;
	printf("\n\n\n               _______________________Welcome to Administrator Pannel_______________________\n\n\n");
	printf("Enter admin Username:- ");
	scanf("%s",&u_name);
	printf("Enter admin password:- ");
	scanf("%s",&pass);

	if ((strcmp(pass,"080-086-095")==0 )&& (strcmp(u_name,"KUDSE23.1F")==0)) {
		administrator_menu();
	} else {
	    system("cls");
	    printf("ERORR::: Please enter valid username or password \n\n");
	    ad_wrong_pass();
	}	
}

//wrong password - administrator
void ad_wrong_pass() {
		char choice;
		printf("Do you want to go administrator pannel again y/n :- ");
		scanf("%s",&choice);
		choice=tolower(choice);
		switch(choice) {
			case 'y':
				system("cls");
				administrator();
				break;
			case 'n':
				system("cls");
				menu();
				break;
			default :
				printf("ERORR::: Enter valid choice\n");
				ad_wrong_pass();
				break;
		}
}



//User menu
void user_menu() {
		char choice;
		printf("1.Book Ticket \n 2.Verify Bookings \n 3.View Train   \n 4.Quit  \n 5.Back \n");
        printf("\n");
		printf("Enter your choice - ");
		scanf("%s",&choice);
	
		switch (choice) {
			case '1' :
				book_ticket();			    
				break;
			case '2' :
				verify();   
				break;
			case '3' :
				view_train_for_user();
				break;
			case '4' :
				quit();
				break;
			case '5':
				menu();
				break;
			default:
				system("cls");
				printf("\nplease enter valid value\n\n");
				user_menu();
				break;
		}	
}

//administrator menu
void administrator_menu(){
	system("cls");
 
		char no;
		printf("\n\n           _______________________________welcome priyanshu sir_______________________________\n\n\n ");
		printf(" 1.add train \n 2.view all trains \n 3.passenger info \n 4.updates in train  \n 5.back   \n 6.quit \n");
		printf("enter your choice");
		scanf("%s",&no);
		
		switch (no){
			case '1' :
			    add_train();
				break;
			
			case '2' :
			    view_train_for_administrator();
				break;
			
			case '3' :
				passenger_info();      
				break;
			
			case '4':
			
				updates_in_train();
				break;
					
			
			case '5':
				system("cls");
				menu();
				break;
					
			case '6' :
				quit();
				break;
				
			default:
				system("cls");
				printf("please enter valid keyword\n\n");
				system("pause");
				administrator_menu();
				break;
		}	
}


//quit
int quit(){
	system("cls");
	exit(0);
	return 0;
}

//Train Booking
void book_ticket(){

	system("cls");
	FILE *fp;
	int p;
	
	fp = fopen("passengers.txt","ab+"); 
	if(fp==NULL)
	{
	printf("file not found");	
	}		
	printf("Enter Passengers Amount - ");
	scanf("%d",&p);
	int q=1;
	p=p-1;
	int i, j;
	for ( i=0;i<=p;i++) {
		for ( j=0;j<=0;j++) {
				printf("    \n\n%d Passenger Details   \n\n",q);
				printf("First name:- ");
				scanf("%s",&tu[i][j].f_name);

				printf("Last name:- ");
				scanf("%s",&tu[i][j].l_name);
				
				printf("Age:- ");
				scanf("%s",&tu[i][j].age);

				printf("From:- ");
				scanf("%s",&tu[i][j].from);
	
				printf("To:- ");
				scanf("%s",&tu[i][j].to);
				
				printf("Mobile no:- ");
				scanf("%s",&tu[i][j].m_no);
				printf("\n\n");
				q=q+1;
			fwrite(&tu[i][j],sizeof(struct train_user),1,fp);	
		}
	}
	fclose(fp);
	system("cls");
	user_menu();
	
}


//verify booking
void verify(){
	system("cls");
	FILE *fp;
	int p=1;
	int count=0;
	int no=9;
	char mob[20];
	fp = fopen("passengers.txt","ab+"); 
	if(fp==NULL) {
	printf("file not found");	
	}
	printf("Enter mobile no :- ");
	scanf("%s",&mob);
    int i, j;
	for ( i=0;i<=no;i++){
		for ( j=0;j<=0;j++){
			fread(&tu[i][j],sizeof(struct train_user),1,fp);
				if ((strcmp(mob,tu[i][j].m_no)==0)){
				    printf("%dst user\n\n",p);
				    printf("First name:- %s\n",tu[i][j].f_name);
				    printf("Last name:- %s\n",tu[i][j].l_name);
				    printf("Age:- %s\n",tu[i][j].age);
				    printf("From:- %s\n",tu[i][j].from);
				    printf("To:- %s\n",tu[i][j].to);
			    	p=p+1;
				    printf("\n\n\n");
				}else{
					count=count+1;
				}
			}		
		}
	if(count==10) {
		printf("Your Mobile Number was Incorrect\n\n");
		wrong_mob();
	}
fclose(fp);
system("pause");
system("cls");
user_menu();
}

//Wrong mobile number
void wrong_mob(){
		char choice;
		printf("Do you want to go try again y/n :- ");
		scanf("%s",&choice);
		choice=tolower(choice);
		switch(choice) {
			case 'y':
				system("cls");
				verify();
				break;
			case 'n':
				system("cls");
				user_menu();
				break;
			default :
				printf("ERORR::: Enter valid value\n");
				wrong_mob();
				break;
		}	
}






void add_train(){
	system("cls");
	FILE *fp;
	//struct train trr[200][200] ;
	int a;
	fp = fopen("trains.txt","ab");
	
	if(fp==NULL)
	{
	printf("file not found");
	}
	printf("how many trains you wants to add");
	scanf("%d",&a);
	a=a-1;
	int train_special_no=0;
    int i, j;
	for ( i=0;i<=a;i++){
		for ( j=0;j<=0;j++){
			
			printf("\n\n");
			printf("enter train no:- ");
			scanf("%s",&trr[i][j].train_no );

			printf("enter train name:- ");
			scanf("%s",&trr[i][j].train_name );

			printf("from:- ");
			scanf("%s",&trr[i][j].from );
			
			printf("to:- ");
			scanf("%s",&trr[i][j].to);

			printf("charge:- ");
			scanf("%s",&trr[i][j].charge);
			
			printf("status:- ");
			scanf("%s",&trr[i][j].status);
			train_special_no=train_special_no+1;
			fwrite(&trr[i][j],sizeof(struct train),1,fp);
			
		}
	}
fclose(fp);

system("pause");
administrator_menu();

}


void passenger_info(){
	system("cls");
	FILE *fp;
	int p;
	fp = fopen("passengers.txt","rb"); 
	if(fp==NULL)
	{
	printf("file not found");	
	}
	printf("first name\t\tlast name\t\tage\t\tfrom\t\t to\t\t mobile no\n");
    int i, j;
	for ( i=0;i<=10;i++){
		for ( j=0;j<=0;j++){
				fread(&tu[i][j],sizeof(struct train_user),1,fp);
				printf("%s %20s %20s %20s %20s %20s\n",tu[i][j].f_name ,tu[i][j].l_name ,tu[i][j].age , tu[i][j].from , tu[i][j].to, tu[i][j].m_no);		
		}
	}
	fclose(fp);
	system("pause");
	administrator_menu();
}



void view_train_for_user(){
	system("cls");
	FILE *fp;
	int p;
	fp = fopen("trains.txt","ab+"); 
	if(fp==NULL)
	{
	printf("file not found");	
	}
	printf("                             _______________trains_________________\n\n\n\n");
	printf("train_name   \t\t train_no \t\t from \t\t to \t\t charge\n");
    int i, j;
	for ( i=0;i<10;i++){
		for ( j=0;j<=0;j++){                                         
				fread(&trr[i][j],sizeof(struct train),1,fp);
				 
				printf("%1s %20s %20s %20s %20s\n",trr[i][j].train_name,trr[i][j].train_no,trr[i][j].from,trr[i][j].to,trr[i][j].charge);
				//printf("train_no:-%s\n",trr[i][j].train_no);
				//printf("from:-%s\n",trr[i][j].from);                                                                                      
				//printf("to:-%s\n",trr[i][j].to);
				//printf("charge:-%s\n",trr[i][j].charge);
			
		}
	}
	char a;
	fclose(fp);
	printf("                                 _______________updates_________________\n\n\n\n");
	t_update();
	system("pause");
	system ("cls");
	user_menu();
}



void view_train_for_administrator(){
	system("cls");
	FILE *fp,*fp1;
	int p;
	fp = fopen("trains.txt","ab+"); 
	
	if(fp==NULL)
	{
	printf("file not found");	
	}
	printf("                             _______________trains_________________\n\n\n\n");
	printf("train_name   \t\t train_no \t\t from \t\t to \t\t charge\n");
    int i,j ;
	for ( i=0;i<10;i++){
		for ( j=0;j<=0;j++){                                         
				fread(&trr[i][j],sizeof(struct train),1,fp);
				 
				printf("%1s %20s %20s %20s %20s\n",trr[i][j].train_name,trr[i][j].train_no,trr[i][j].from,trr[i][j].to,trr[i][j].charge);
				//printf("train_no:-%s\n",trr[i][j].train_no);
				//printf("from:-%s\n",trr[i][j].from);                                                                                      
				//printf("to:-%s\n",trr[i][j].to);
				//printf("charge:-%s\n",trr[i][j].charge);
			
		}
	}
	fclose(fp);
	char a;
	printf("                             _______________updates_________________\n\n\n\n");	
	check();
	system("pause");
	system ("cls");
	administrator_menu();
}


void check(){
 FILE *fp1;  
 fp1=fopen("update_trains.txt","rb");
		if (fp1!=NULL){        
			t_update();
	}
	else if(fp1==NULL){
		
		printf("no updates avilable\n\n");
	}
	system("pause");
	system ("cls");
	administrator_menu();
	fclose(fp1);
}


void updates_in_train(){
	system("cls");
	char u_i_t;
		printf("\n\n1.update train \n2.cancle all updates \n3. cancle trains \n4. back \n");
		printf("enter your choice");
		scanf("%s",&u_i_t);
	
		switch (u_i_t){
			case '1' :
			
				update_train();			    
				break;
			
			
			case '2' :
		
				cancle_updates();
				   
				break;
			case '3':
				cancle_trains();
			
			case '4' :
				administrator_menu();
				break;
			
			default:
				
				printf("not ok");
				break;
		}	
}


void t_update(){
	FILE *fp1;
	fp1 = fopen("update_trains.txt","ab+"); 
		if(fp1==NULL)             
		{    
			printf("file not found");	
		}
		printf("train_name   \t\t train_no \t\t from \t\t to \t\t charge \t\t status\n");
		int i,j;
		for ( i=0;i<=10;i++){
			for ( j=0;j<=0;j++){
			fread(&ttt[i][j],sizeof(struct train),1,fp1);
			
				printf("%1s %20s %20s %20s %20s %20s \n",ttt[i][j].train_name,ttt[i][j].train_no,ttt[i][j].from,ttt[i][j].to,ttt[i][j].charge,ttt[i][j].status);
			
			}
		}
 fclose(fp1);
}

void update_train(){

	FILE *fp,*fp1;
	fp = fopen("trains.txt","ab+");
	fp1 = fopen("update_trains.txt","ab+");
	if(fp == NULL){
        printf("Error opening file");
    }
	char value[20];
	printf("enter train no :-");
	scanf("%s",&value);
    int i,j;
	for ( i=0;i<=10;i++){
		for ( j=0;j<=0;j++){
			//printf("error");
			fread(&trr[i][j],sizeof(struct train),1,fp);
			if ((strcmp(value,trr[i][j].train_no)==0))
			{
							printf("\n\nenter train status cancle/running\n\n");
							scanf("%s",trr[i][j].status);
							
							fwrite(&trr[i][j],sizeof(struct train),1,fp1);
							printf("update successfully....\n");          
								fclose(fp1);
								fclose(fp); 
							system("pause");
							administrator_menu(); 	
			}
		}
	}

}
   //error
   
void cancle_updates()
{
	if( remove("update_trains.txt")== 0){
        printf("successfully deleted\n");
        system("pause");
        administrator_menu();
    }

    else{
    	
    	printf("\n\nerror\n\n");
    	system("pause");
    	administrator_menu();
	}

}

void cancle_trains()
{
	FILE *fp,*fp1;
	fp = fopen("trains.txt","w");
	fp1= fopen("update_trains.txt","w");
	if(fp == NULL){
        printf("Error opening file 1");
    }
    if(fp1 == NULL){
        printf("Error opening file 2");
    }

    printf("sucessfully cancaled\n");
    system("pause");
	administrator_menu();
	fclose(fp);
	fclose(fp1);
}

