#include <stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<unistd.h>
const char* user(char a);
void menu2();
void start();
void login();
void work();
int add(char id[]);
void menu();
void choose(char a,char id[]);
int view(char id[]);
int edit(char id[]);
int ask();
void empty(char arr[], int f);
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	char choice,id1[20];int b=1;
	start();
	sleep(3);
	system("cls");
	login();
	choice=getch();
	const char *id=user(choice);
	strcpy(id1,id);
	sleep(1);
	work();
	choice=getch();
	choose(choice,id1);
	return 0;
}
const char* user(char a){
	int i=0,j=0,b=0,flag=0,nf=0,total=0;
	float income=0.0;
	char ch='\0',password[8]={'\0'},sen[20],tid[20],tpas[8],password1[8],temp[8],incometype[20],file[20];
	static char ID3[20];
	empty(password,8);empty(sen,20);empty(tid,20);empty(password1,8);empty(ID3,20);empty(temp,8);empty(file,20);empty(incometype,20);
	system("cls");
	switch(a){
		case '1':
			FILE *ptr;
			while(nf==0){
				printf("\n\n\n\n\n");
				printf("\t\t\t\t\tEnter your ID: ");
				gets(ID3);
				printf("\n\n\t\t\t\t\t");
				printf("Enter the password <any 8 characters>: ");
				for(i=0;i<8;i++){
					if(i<0){
 						i=0;
					}
		  			ch = getch();
   					if(ch!=13){
						if(ch == 8){
 	          				putch('\b');
    	       				putch(NULL);
	        	  	 		putch('\b');
  	      	  		 		password[--i] = '\0';
    	       				i--;
     	  					continue;
       					}
       					password[i] = ch;
       					putch('*');
       				}
  					else{
  						--i;
					}
 				}
 				password[i] =' ';
 				ptr=fopen("user.txt","r");
 				fscanf(ptr,"%[^\n]%*c",sen);
 				flag=0;
	 			while(!feof(ptr)&&flag==0){
					 j=0;
					while(sen[j]!='*'){
						tid[j]=sen[j];
						j++;
					}
					for(int k=j+1,c=0;k<=j+8;k++,c++){
						tpas[c]=sen[k];
					}
					b=strcmp(tid,ID3);
					if(b==0){
						b=strncmp(tpas,password,8);
						if(b==0){
							printf("\n\n\t\t\t\t\tSIGN-IN SUCCESSFULL");
							flag=1;
							return ID3;
						}
					}
					memset(tid,0,strlen(tid));
					memset(tpas,0,strlen(tpas));
					fscanf(ptr,"%[^\n]%*c",sen);
				}
				fclose(ptr);
				if(flag==1){
					nf=1;
				}
				else{
					printf("\n\n\t\t\t\t\tInvlaid ID or Password\n\t\t\t\t\tTryAgain");
				}
			}
			break;
		case '2':
			FILE *ptr1;
			memset(temp,0,strlen(temp));
			ptr=fopen("user.txt","r");
			while(nf==0){
				ptr=fopen("user.txt","r");
				fgets(sen,100,ptr);
				printf("\n\n\t\t\t\t\t");
				printf("Enter your ID: ");
				scanf("%s",ID3);
				flag=0;
				while(!feof(ptr)&&flag==0){
					j=0;
					while(sen[j]!='*'){
						tid[j]=sen[j];
						j++;
					}
					b=strcmp(tid,ID3);
					if(b==0){
						printf("\n\n\t\t\t\t\tID already exist\n\t\t\t\t\tEnter new ID");
						flag=1;
					}
					fgets(sen,100,ptr);
				}
				if(flag==0){
					nf=1;
				}
				fclose(ptr);
			}
			flag=0;
			ch='\0';
			while(flag==0){
				memset(password,0,strlen(password));
				printf("\n\n\t\t\t\t\tEnter your password<8 charachters>: ");
				for(i=0;i<8;i++){	
 					if(i<0){
 						i=0;
			 		}
  					ch = getch();
   					if(ch!=13){
						if(ch == 8){
 	          				putch('\b');
    	       				putch(NULL);
	        	  	 		putch('\b');
  	      	  		 		password[--i] = '\0';
    	       				i--;
     	  					continue;
       					}
	       				password[i] = ch;
    	   				putch('*');
       				}
       				else{
       					--i;
				   	}	
 				}
 				strncpy(temp,password,8);
	 			memset(password,0,strlen(password));
 				strncpy(password,temp,8);
 				password[i] =' ';
	 			printf("\n\n\t\t\t\t\tRe-enter your password<8 charachters>: ");
				for(i=0;i<8;i++){
 					if(i<0){
 						i=0;
					}
	  				ch = getch();
   					if(ch!=13){
						if(ch == 8){
 	          				putch('\b');
    	       				putch(NULL);
	        	  	 		putch('\b');
  	      	  		 		password1[--i] = '\0';
    	       				i--;
     	  					continue;
       					}
       					password1[i] = ch;
       					putch('*');
       				}
  					else{
  						--i;
				  	}
 				}
 				password1[i] =' ';
				b=strncmp(password1,password,8);
 				if(b==0){
 					flag=1;
				}
				else{
					printf("\n\n\t\t\t\t\tPassword not matches\n\t\t\t\t\tRe-enterpassword\n");
				}
			}
			strcpy(file,ID3);
			strcat(file,".txt");
			flag=1;
			ptr1=fopen(file,"a");
			while(flag==1){
				printf("\n\n\t\t\t\t\tEnter your incomes and income types");
				printf("\n\t\t\t\t\t");
				scanf("%f",&income);
				total+=income;
				printf("\t\t\t\t\t");
				scanf("%s",incometype);
				incometype[0]=toupper(incometype[0]);
				fprintf(ptr1,"%s %.2f\n",incometype,income);
				printf("\n\n\t\t\t\t\tDo you want to add more?\n\t\t\t\t\tPress 1 for Yes\n\t\t\t\t\tPress 0 for No\n\t\t\t\t\t");
				scanf("%d",&flag);
			}
			fprintf(ptr1,"total %d",total);
			ptr=fopen("user.txt","a");
			fprintf(ptr,"%s*%s\n",ID3,password);
			fclose(ptr);
			fclose(ptr1);
			printf("\n\n\t\t\t\t\tSIGN-UP SUCCESSFULL");
			return ID3;
			break;
		default:
			printf("\n\n\t\t\t\t\tInvalid choice");
			sleep(1);
			system("cls");
			login();
			ch=getch();
			user(ch);
	}
}
void start(){
	printf("\n\n\n\n");
	printf("\t\t\t\t\t\t       _______   __    __  _______    ______   ________  ________     \n");
	printf("\t\t\t\t\t\t      /       \\ /  |  /  |/       \\  /      \\ /        |/        |    \n");
	printf("\t\t\t\t\t\t      $$$$$$$  |$$ |  $$ |$$$$$$$  |/$$$$$$  |$$$$$$$$/ $$$$$$$$/     \n");
	printf("\t\t\t\t\t\t      $$ |__$$ |$$ |  $$ |$$ |  $$ |$$ | _$$/ $$ |__       $$ |       \n");
	printf("\t\t\t\t\t\t      $$    $$< $$ |  $$ |$$ |  $$ |$$ |/    |$$    |      $$ |       \n");
	printf("\t\t\t\t\t\t      $$$$$$$  |$$ |  $$ |$$ |  $$ |$$ |$$$$ |$$$$$/       $$ |       \n");
	printf("\t\t\t\t\t\t      $$ |__$$ |$$ \\__$$ |$$ |__$$ |$$ \\__$$ |$$ |_____    $$ |       \n");
	printf("\t\t\t\t\t\t      $$    $$/ $$    $$/ $$    $$/ $$    $$/ $$       |   $$ |       \n");
	printf("\t\t\t\t\t\t      $$$$$$$/   $$$$$$/  $$$$$$$/   $$$$$$/  $$$$$$$$/    $$/        \n");
	printf("\t\t\t\t\t\t ________  _______    ______    ______   __    __  ________  _______  \n");
	printf("\t\t\t\t\t\t/        |/       \\  /      \\  /      \\ /  |  /  |/        |/       \\ \n");
	printf("\t\t\t\t\t\t$$$$$$$$/ $$$$$$$  |/$$$$$$  |/$$$$$$  |$$ | /$$/ $$$$$$$$/ $$$$$$$  |\n");
	printf("\t\t\t\t\t\t   $$ |   $$ |__$$ |$$ |__$$ |$$ |  $$/ $$ |/$$/  $$ |__    $$ |__$$ |\n");
	printf("\t\t\t\t\t\t   $$ |   $$    $$< $$    $$ |$$ |      $$  $$<   $$    |   $$    $$< \n");
	printf("\t\t\t\t\t\t   $$ |   $$$$$$$  |$$$$$$$$ |$$ |   __ $$$$$  \\  $$$$$/    $$$$$$$  |\n");
	printf("\t\t\t\t\t\t   $$ |   $$ |  $$ |$$ |  $$ |$$ \\__/  |$$ |$$  \\ $$ |_____ $$ |  $$ |\n");
	printf("\t\t\t\t\t\t   $$ |   $$ |  $$ |$$ |  $$ |$$    $$/ $$ | $$  |$$       |$$ |  $$ |\n");
	printf("\t\t\t\t\t\t   $$/    $$/   $$/ $$/   $$/  $$$$$$/  $$/   $$/ $$$$$$$$/ $$/   $$/ \n");
	
}
void login(){
	printf("\n\n\n\n");
	printf("\t\t\t\t\t\t    .--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--.\n");
	printf("\t\t\t\t\t\t   / .. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\\n");
	printf("\t\t\t\t\t\t   \\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/ /\n");
	printf("\t\t\t\t\t\t    \\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\n");
	printf("\t\t\t\t\t\t    / /\\/ /`' /`' /`' /`' /`' /`' /`' /`' /`' /`' /`' /`' /`' /\\/ /\\\n");
	printf("\t\t\t\t\t\t   / /\\ \\/`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'\\ \\/\\ \\\n");
	printf("\t\t\t\t\t\t   \\ \\/\\ \\                                                    /\\ \\/ /\n");
	printf("\t\t\t\t\t\t    \\/ /\\ \\                                                  / /\\/ /\n");
	printf("\t\t\t\t\t\t    / /\\/ /            WELCOME TO BUDGET TRACKER             \\ \\/ /\\\n");
	printf("\t\t\t\t\t\t   / /\\ \\/                                                    \\ \\/\\ \\\n");
	printf("\t\t\t\t\t\t   \\ \\/\\ \\                FOR SIGN IN PRESS 1                 /\\ \\/ /\n");
	printf("\t\t\t\t\t\t    \\/ /\\ \\                                                  / /\\/ /\n");
	printf("\t\t\t\t\t\t    / /\\/ /               FOR SIGN UP PRESS 2                \\ \\/ /\\\n");
	printf("\t\t\t\t\t\t   / /\\ \\/                                                    \\ \\/\\ \\\n");
	printf("\t\t\t\t\t\t   \\ \\/\\ \\.--..--..--..--..--..--..--..--..--..--..--..--..--./\\ \\/ /\n");
	printf("\t\t\t\t\t\t    \\/ /\\/ ../ ../ ../ ../ ../ ../ ../ ../ ../ ../ ../ ../ ../ /\\/ /\n");
	printf("\t\t\t\t\t\t    / /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\/ /\\\n");
	printf("\t\t\t\t\t\t   / /\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\/\\ \\\n");
	printf("\t\t\t\t\t\t   \\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `' /\n");
	printf("\t\t\t\t\t\t    `--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'\n");

}
void work(){
	system("cls");
	printf("\n\n\n\n");
	printf("\t\t\t\t\t\t.-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-.\n");
	printf("\t\t\t\t\t\t|                                                                       |\n");
	printf("\t\t\t\t\t\t|                       FOR ADD RECORD PRESS 1                          |\n");
	printf("\t\t\t\t\t\t!                                                                       !\n");
	printf("\t\t\t\t\t\t:          	 	                                                :\n");
	printf("\t\t\t\t\t\t:                       TO VIEW RECORD PRESS 2                          :\n");
	printf("\t\t\t\t\t\t.                                                                       .\n");
	printf("\t\t\t\t\t\t.                                                                       .\n");
	printf("\t\t\t\t\t\t:                       TO EDIT INCOME PRESS 3                          :\n");
	printf("\t\t\t\t\t\t:                 	                                                :\n");
	printf("\t\t\t\t\t\t!                                                                       !\n");
	printf("\t\t\t\t\t\t|                           FOR EXIT PRESS 4                            |\n");
	printf("\t\t\t\t\t\t|                                                                       |\n");
	printf("\t\t\t\t\t\t`-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-'\n");
}
int add(char id[]){
	FILE *ptr,*ptr1,*ftemp;
	int flag=0,count=1,i=0,j=0,k=0,c=0,b=1;
	char month[10],file[20],file2[20],ch,billname[20],sen[30],money[20],word[20];
	float tax,transport,other,food,bill,total[6]={0.0};
	system("cls");
	printf("\n\n\t\t\t\t\tEnter month name: ");
	scanf("%s",month);
	strlwr(month);
	strcpy(file,id);
	strcat(file,month);
	strcat(file,".txt");
	strcpy(file2,id);
	strcat(file2,".txt");
	ptr1=fopen(file2,"r");
	fscanf(ptr1,"%[^\n]%*c",sen);
	while(!feof(ptr1)&&flag==0){
		if(strncmp(sen,month,strlen(month))==0){
			flag=1;
			break;
		}
		fscanf(ptr1,"%[^\n]%*c",sen);
		count++;
	}
	if(flag==1){
		for(i=count+1,c=0;i<count+7;i++,c++){
			fscanf(ptr1,"%[^\n]%*c",sen);
			j=0;k=0;
			while(sen[j]!=' '){
				j++;
			}
			j++;
			while(sen[j]!=' '&&sen[j]!='\0'){
				money[k]=sen[j];
				k++;j++;
			}
			total[c]=atof(money);
		}
	}
	fclose(ptr1);
	if(flag==0){
		ptr1=fopen(file2,"a");
		fprintf(ptr1,"%s\n",month);
		fclose(ptr1);
	}
	menu();
	ch=getch();
	switch(ch){
		case '1':
			printf("\n\n\t\t\t\t\tEnter amount of tax: ");
			scanf("%f",&tax);
			ptr=fopen(file,"a");
			fprintf(ptr,"tax %.2f\n",tax);
			fclose(ptr);
			total[0]+=tax;
			total[5]+=tax;
			break;
		case '2':
			printf("\n\n\t\t\t\t\tEnter name of bill: ");
			scanf("%s",billname);
			printf("\t\t\t\t\tEnter amount of %s bill: ",billname);
			scanf("%f",&bill);
			ptr=fopen(file,"a");
			fprintf(ptr,"bill %.2f %s\n",bill,billname);
			fclose(ptr);
			total[1]+=bill;
			total[5]+=bill;
			break;
		case '3':
			printf("\n\n\t\t\t\t\tEnter amount of food: ");
			scanf("%f",&food);
			ptr=fopen(file,"a");
			fprintf(ptr,"food %.2f\n",food);
			fclose(ptr);
			total[2]+=food;
			total[5]+=food;
			break;
		case '4':
			printf("\n\n\t\t\t\t\tEnter amount of transport: ");
			scanf("%f",&transport);
			ptr=fopen(file,"a");
			fprintf(ptr,"transport %.2f\n",transport);
			fclose(ptr);
			total[3]+=transport;
			total[5]+=transport;
			break;
		case '5':
			printf("\n\n\t\t\t\t\tEnter amount: ");
			scanf("%f",&other);
			ptr=fopen(file,"a");
			fprintf(ptr,"Other %.2f\n",other);
			fclose(ptr);
			total[4]+=other;
			total[5]+=other;
			break;
		case '6':
			work();
			ch=getch();
			choose(ch,id);
			break;
		default:
			printf("\n\n\t\t\t\t\tInvalid choice");
			sleep(1);
			system("cls");
			menu();
			ch=getch();
			choose(ch,id);
	}
	if(flag==0){
		ptr1=fopen(file2,"a");
		fprintf(ptr1,"TotalTaxes %.2f\n",total[0]);
		fprintf(ptr1,"TotalBill %.2f\n",total[1]);
		fprintf(ptr1,"TotalFood %.2f\n",total[2]);
		fprintf(ptr1,"TotalTransport %.2f\n",total[3]);
		fprintf(ptr1,"TotalOther %.2f\n",total[4]);
		fprintf(ptr1,"TotalAmount %.2f\n",total[5]);
		fclose(ptr1);
	}
	memset(sen,0,sizeof(sen));
	if(flag==1){
		count=1;i=0;j=0;flag=0;
		ptr1=fopen(file2,"r");
		ftemp=fopen("t1.tmp","w");
		fscanf(ptr1,"%[^\n]%*c",sen);
		while(!feof(ptr1)){
			if(strcmp(sen,month)==0){
				fprintf(ftemp,"%s\n",sen);
				flag=1;
			}
			if(flag==1){
				for(i=count+1,c=0;i<count+7;c++,i++){
					fscanf(ptr1,"%[^\n]%*c",sen);
					j=0;
					memset(word,0,sizeof(word));
					while(sen[j]!=' '){
						word[j]=sen[j];
						j++;
					}
					fprintf(ftemp,"%s %.2f\n",word,total[c]);
				}
			}
			if(flag==0){
				fprintf(ftemp,"%s\n",sen);
			}
			if(i==(count+7)){
				flag=0;
			}
			fscanf(ptr1,"%[^\n]%*c",sen);
			count++;
		}
		fclose(ftemp);
		fclose(ptr1);
		remove(file2);
		rename("t1.tmp",file2);
	}
	if(ch!='6'){
		c=ask();
	}
	else{
		c=2;
	}
	return c;
}
void menu(){
	printf("\n\n\n\n");
	printf("\t\t\t\t\t\t.-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-.\n");
	printf("\t\t\t\t\t\t|                                                   |\n");
	printf("\t\t\t\t\t\t|        					    |\n");
	printf("\t\t\t\t\t\t!       CHOOSE FROM THE FOLLOWING CATOEGORIES       !\n");
	printf("\t\t\t\t\t\t:       1. TAX         	    	                    :\n");
	printf("\t\t\t\t\t\t:       2. BILLS                                    :\n");
	printf("\t\t\t\t\t\t.       3. FOOD                                     .\n");
	printf("\t\t\t\t\t\t:       4. TRANSPORT                                :\n");
	printf("\t\t\t\t\t\t:       5. OTHER       		                    :\n");
	printf("\t\t\t\t\t\t!       6. GO BACK                                  !\n");
	printf("\t\t\t\t\t\t|                                                   |\n");
	printf("\t\t\t\t\t\t|                                                   |\n");
	printf("\t\t\t\t\t\t`-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-'\n");
}
void empty(char arr[], int f){
	for(int i=0;i<f;i++){
		arr[i]='\0';
	}
}
int view(char id[]){
	FILE *ptr,*ptr1;
	int c=0,i=0,count=1,flag=0,nf=0,j=0,a=0,k=0;
	float total=0.0,total1=0.0,per=0.0,totall[12][6],small[6]={50000.0,50000.0,50000.0,50000.0,50000.0,0.0};
	char month[10],file[20],file2[20],ch,sen[30],word[10];
	char m[12][10]={"january","february","april","march","may","june","july","august","september","october","november","december"};
	system("cls");
	strcpy(file2,id);
	strcat(file2,".txt");
	menu2();
	ch=getch();
	switch(ch){
		case '1':
			printf("\n\n\t\t\t\t\tEnter month name: ");
			scanf("%s",month);
			strlwr(month);
			strcpy(file,id);
			strcat(file,month);
			strcat(file,".txt");
			ptr=fopen(file,"r");
			if(ptr==NULL){
				printf("\n\n\t\t\t\t\tNo data for this month");
			}
			else{
				sleep(2);
				system("cls");
				printf("\n\n\n\n\t\t\t\t\t");
				for(i=0;i<67;i++){
					printf("*");
				}
				fscanf(ptr,"%[^\n]%*c",sen);
				while(!feof(ptr)){
					printf("\n\t\t\t\t\t* %-25s	",sen);
					fscanf(ptr,"%[^\n]%*c",sen);
					if(feof(ptr)){
						printf("\t\t\t\t  *");
						break;
					}
					else{
						printf("	%-25s *",sen);
					}
					fscanf(ptr,"%[^\n]%*c",sen);
				}
				printf("\n\t\t\t\t\t");
				for(i=0;i<67;i++){
					printf("*");
				}
				fclose(ptr);
				memset(sen,0,sizeof(sen));
				printf("\n\n\t\t\t\t\t");
				for(i=0;i<29;i++){
					printf("*");
				}
				memset(sen,0,sizeof(sen));
				nf=0;
				ptr1=fopen(file2,"r");
				fscanf(ptr1,"%[^\n]%*c",sen);
				while(!feof(ptr1)){
					for(i=0;i<5;i++){
						word[i]=sen[i];
					}
					if(strcmp(word,"total")==0&&(nf==0)){
						i++;c=0;
						memset(word,0,sizeof(word));
						while(sen[i]!='\0'){
							word[c]=sen[i];
							i++;c++;
						}
						nf=1;
						total1=atof(word);
					}
					if(strcmp(sen,month)==0){
						flag=1;
					}
					if(flag==1){
						for(i=count+1,c=0;i<count+7;c++,i++){
							fscanf(ptr1,"%[^\n]%*c",sen);
							printf("\n\t\t\t\t\t* %-25s *",sen);
							if(i==(count+6)){
								j=0;i=0;
								memset(word,0,sizeof(word));
								while(sen[j]!=' '){;
									j++;
								}
								for(i=(j+1),c=0;sen[i]!='\0';i++,c++){
									word[c]=sen[i];
								}
								total=atof(word);
							}
						}
						break;
					}
					fscanf(ptr1,"%[^\n]%*c",sen);
					count++;
				}
				printf("\n\t\t\t\t\t*\t\t\t    *");
				per=(total/total1)*100;
				if(per<10){
					printf("\n\t\t\t\t\t* %.2f%% Budget is consumed  *",per);
				}
				else{
					printf("\n\t\t\t\t\t* %.2f%% Budget is consumed *",per);
				}
				printf("\n\t\t\t\t\t");
				for(i=0;i<29;i++){
					printf("*");
				}
				fclose(ptr1);
			}
			break;
		case '3':
			work();
			ch=getch();
			choose(ch,id);
			break;
		case '2':
			memset(sen,0,sizeof(sen));
			count=1;i=0;flag=0;j=0;
			ptr1=fopen(file2,"r");
			fscanf(ptr1,"%[^\n]%*c",sen);
			while(!feof(ptr1)){
				flag=0;
				for(i=0;i<12;i++){
					memset(word,0,sizeof(word));
					strcpy(word,m[i]);
					if(strcmp(sen,word)==0){
						flag=1;
						break;
					}
				}
				if(flag==1){
					for(a=count+1;a<count+7;a++){
						fscanf(ptr1,"%[^\n]%*c",sen);
						j=0;c=0;k=0;
						memset(word,0,sizeof(word));
						while(sen[j]!=' '){
							j++;
						}
						for(k=j+1,c=0;sen[k]!='\0';k++,c++){
							word[c]=sen[k];
						}
						totall[i][a-(count+1)]=atof(word);
					}
				}
				fscanf(ptr1,"%[^\n]%*c",sen);
				count++;
			}
			for(i=0;i<12;i++){
				if(totall[i][0]<small[0]){
					small[0]=totall[i][0];
				}
				if(totall[i][1]<small[1]){
					small[1]=totall[i][1];
				}
				if(totall[i][2]<small[2]){
					small[2]=totall[i][2];
				}
				if(totall[i][3]<small[3]){
					small[3]=totall[i][3];
				}
				if(totall[i][4]<small[4]){
					small[4]=totall[i][4];
				}
				small[5]=small[0]+small[1]+small[2]+small[3]+small[4];
			}
			system("cls");
			printf("\n\n\n\n\n\t\t\t\t\t");
			for(i=0;i<30;i++){
				printf("*");
			}
			printf("\n\t\t\t\t\t* BEST BUDGET 		     *");
			printf("\n\t\t\t\t\t* Total Taxes: %.2f 	     *",small[0]);
			printf("\n\t\t\t\t\t* Total Bill: %.2f         *",small[1]);
			printf("\n\t\t\t\t\t* Total Food: %.2f 	     *",small[2]);
			printf("\n\t\t\t\t\t* Total Transport: %.2f   *",small[3]);
			printf("\n\t\t\t\t\t* Total Other: %.2f        *",small[4]);
			printf("\n\t\t\t\t\t* Total Amount: %.2f      *",small[5]);
			printf("\n\t\t\t\t\t");
			for(i=0;i<30;i++){
				printf("*");
			}
			break;
		default:
			printf("\n\n\t\t\t\t\tInvalid choice");
			sleep(1);
			system("cls");
			menu2();
			ch=getch();
			choose(ch,id);
	}
	if(ch!='3'){
		c=ask();
	}
	else{
		c=3;
	}
	return c;
}
void choose(char a,char id[]){
	int b=1;
	char ch;
	switch(a){
		case '1':
			while(b==1){
				b=add(id);
			}
			break;
		case '2':
			while(b==1){
				b=view(id);
			}
			break;
		case '3':
			while(b==1){
				b=edit(id);
			}
			break;
		case '4':
			break;
		default:
			printf("\n\n\t\t\t\t\tInvalid choice");
			sleep(1);
			work();
			ch=getch();
			choose(ch,id);
	}
}
int ask(){
	int b;
	printf("\n\n\t\t\t\t\tDo you want to continue?\n\t\t\t\t\tPress 1 If yes\n\t\t\t\t\tPress 2 for exit\n\t\t\t\t\t");
	scanf("%d",&b);
	return b;
}
void menu2(){
	printf("\n\n\n\n");
	printf("\t\t\t\t\t\t.-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-.\n");
	printf("\t\t\t\t\t\t|                                                   |\n");
	printf("\t\t\t\t\t\t|        					    |\n");
	printf("\t\t\t\t\t\t!       CHOOSE FROM THE FOLLOWING CATOEGORIES       !\n");
	printf("\t\t\t\t\t\t:                 	                            :\n");
	printf("\t\t\t\t\t\t:       1. VIEW RECORD OF A MONTH                   :\n");
	printf("\t\t\t\t\t\t.                                                   .\n");
	printf("\t\t\t\t\t\t:       2. VIEW BEST BUDGET                         :\n");
	printf("\t\t\t\t\t\t:       	      		                    :\n");
	printf("\t\t\t\t\t\t!       3. GO BACK                                  !\n");
	printf("\t\t\t\t\t\t|                                                   |\n");
	printf("\t\t\t\t\t\t|                                                   |\n");
	printf("\t\t\t\t\t\t`-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-'\n");
}
void menu3(){
	printf("\n\n\n\n");
	printf("\t\t\t\t\t\t.-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-.\n");
	printf("\t\t\t\t\t\t|                                                   |\n");
	printf("\t\t\t\t\t\t!       CHOOSE FROM THE FOLLOWING CATOEGORIES       !\n");
	printf("\t\t\t\t\t\t:                 	                            :\n");
	printf("\t\t\t\t\t\t:       1. ADD MORE INCOME                          :\n");
	printf("\t\t\t\t\t\t.                                                   .\n");
	printf("\t\t\t\t\t\t:       2. EDIT INCOME                              :\n");
	printf("\t\t\t\t\t\t:       	      		                    :\n");
	printf("\t\t\t\t\t\t!       3. GO BACK                                  !\n");
	printf("\t\t\t\t\t\t|                                                   |\n");
	printf("\t\t\t\t\t\t`-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-'\n");
}
int edit(char id[]){
	FILE *ptr,*ftemp;
	int c=0,i=0,count=1,nf=0,k=0;
	float income=0.0,total1=0.0,temp=0.0;
	char ch,incometype[20],file2[20],sen[20],word[20],word2[20];
	system("cls");
	strcpy(file2,id);
	strcat(file2,".txt");
	menu3();
	ch=getch();
	switch(ch){
		case '1':
			printf("\n\n\t\t\t\t\tEnter income type: ");
			scanf("%s",incometype);
			incometype[0]=toupper(incometype[0]);
			printf("\t\t\t\t\tEnter income amount: ");
			scanf("%f",&income);
			ptr=fopen(file2,"r");
			ftemp=fopen("t1.tmp","w");
			fscanf(ptr,"%[^\n]%*c",sen);
			while(!feof(ptr)){
				for(i=0;i<5;i++){
						word[i]=sen[i];
				}
				if((strcmp(word,"total")==0)&&(nf==0)){
					i++;c=0;
					memset(word,0,sizeof(word));
					while(sen[i]!='\0'){
						word[c]=sen[i];
						i++;c++;
					}
					nf=1;
					total1=atof(word);
					total1+=income;
					fprintf(ftemp,"%s %.2f\n",incometype,income);
					fprintf(ftemp,"total %.2f\n",total1);
				}
				if(nf==0){
					fprintf(ftemp,"%s\n",sen);
				}
				if(nf==1){
					nf=0;
				}
				fscanf(ptr,"%[^\n]%*c",sen);	
			}
			fclose(ftemp);
			fclose(ptr);
			remove(file2);
			rename("t1.tmp",file2);
			break;
		case '2':
			printf("\n\n\t\t\t\t\tEnter income type to be edit: ");
			scanf("%s",incometype);
			incometype[0]=toupper(incometype[0]);
			printf("%s",incometype);
			printf("\t\t\t\t\tEnter new amount: ");
			scanf("%f",&income);
			ptr=fopen(file2,"r");
			ftemp=fopen("t1.tmp","w");
			fscanf(ptr,"%[^\n]%*c",sen);
			while(!feof(ptr)){
				memset(word,0,sizeof(word));
				for(i=0;i<strlen(incometype);i++){
						word[i]=sen[i];
				}
				if(strcmp(word,incometype)==0){
					k=i+1;c=0;
					memset(word,0,sizeof(word));
					while(sen[k]!='\0'){
						word[c]=sen[k];
						k++;c++;
					}
					temp=atof(word);
					fprintf(ftemp,"%s %.2f\n",incometype,income);
					fscanf(ptr,"%[^\n]%*c",sen);
					continue;
				}
				for(i=0;i<5;i++){
					word2[i]=sen[i];
				}
				if(strcmp(word2,"total")==0){
					k=i+1;c=0;
					memset(word2,0,sizeof(word));
					while(sen[i]!='\0'){
						word2[c]=sen[i];
						i++;c++;
					}
					total1=atof(word2);
					total1=total1-temp;
					total1=total1+income;
					fprintf(ftemp,"total %.2f\n",total1);
					fscanf(ptr,"%[^\n]%*c",sen);
					continue;
				}
				fprintf(ftemp,"%s\n",sen);
				fscanf(ptr,"%[^\n]%*c",sen);
			}
			fclose(ptr);
			fclose(ftemp);
			remove(file2);
			rename("t1.tmp",file2);
			break;
		case '3':
			work();
			ch=getch();
			choose(ch,id);
			break;
		default:
			printf("\n\n\t\t\t\t\tInvalid choice");
			sleep(1);
			system("cls");
			menu3();
			ch=getch();
			choose(ch,id);
	}
	if(ch!='3'){
		c=ask();
	}
	else{
		c=3;
	}
	return c;
}