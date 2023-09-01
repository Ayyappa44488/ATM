#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<conio.h>
#include<string.h>
#include<time.h>
int ayyappa();
void printstar(char cha,int z);
void writefile();
void readfile();
void statement();
char name1[30];
int x,y,i,total,n,a,enter=8,count=0,s,b,q=0,r,p=-1,c=0;
char name[30],pass[5],pass1[5],ch,o;
int main()
{
	char name2[20];
	q=0;
	time_t givemetime=time(NULL);
	printstar('=',120);
	printstar('=',120);
	printf("\n");
	printstar(' ',43);
	printf("||       WELCOME TO BANK OF INDIA       ||");
	printstar(' ',43);
	printf("\n");
	printstar('=',120);
	printstar('=',120);
	system("color 71");
	printf("\n\t\t\t\t\t\t\t\t\t\t\t   %s",ctime(&givemetime));
	printf("\nenter account holder name:");
	if(b==1)
	printf("%s",name);
	else
    scanf("%s",name);
    if(c==0||b==2)
    readfile();
    printf("\n\n\n");
    printstar('*',60);
    printf("\n\nenter your pin=");
	count=ayyappa();
	if(count!=0)
	{
		for(r=2;r>0;r--)
		{
			if(count==0)
			break;
		    printf("password is incorrect.you have another %d chances\n",r);
		    count=ayyappa();
	    }
	}
	system("cls");
	system("color 7D");
	if(count!=0)
	{
		printf("your password is incorrect\ntry again");
		exit(0);
	}
	printf("\n1. for credit\n2. for debit\n3. for change pin\n4.for balance enquiry\n5.bank statement\n");
	if(count==0)
	{
	printf("\nenter your choice:");
	scanf("%d",&a);
	system("cls");
	system("color 7A");
    }
	switch(a)
	{
	case 1:
		{
			printf("\namount to be credited:");
			scanf("%d",&y);
			total=total+y;
			system("cls");
			printf("%d is credited to your account",y);
			printf("\nnew account balance=%d",total);
			statement();
			break;
		}
	case 2:
	{
		printf("\namount to be debited:");
		scanf("%d",&y);
		if(total>=y)
		{
	    total=total-y;
	    p=0;
	    }
	    else
	    p=1;
		system("cls");
	    if(p==0)
	    {
	    printf("%d is debited from your account",y);
	    printf("\nremaining account balance=%d",total);
	    }
	    else
	    {
	    printf("insufficient balance");
	    printf("\nthank you\nvisit again");
	    }
	    statement();
	    break;
		}	
	case 3:
		printf("enter password:");
	count=ayyappa();
	if(count!=0)
	{
		for(r=2;r>0;r--)
		{
			if(count==0)
			break;
		printf("your password is incorrect.you have another %d chances\n",r);
		count=ayyappa();
	}
	if(count!=0)
	{
		printf("your password is incorrect\ntry again");
		exit(0);
	}
	}
		if(count==0)
		{
		printf("\nenter your new pin:");
		for(i=0;i<4;i++)
	{
		ch=getch();
		pass1[i]=ch;
		ch='*';
		printf("%c",ch);
		if(ch==8)
		break;
	}
		system("cls");
		printf("\n your pin has been changed successfully");
        }
        else
        	printf("\nyour entered pin is incorrect");
        	break;
    case 4:
    	printf("your account balance:");
    	if(s==0||q==1)
    	printf("%d",total);
    	else
    	printf("%d",total);
    	break;
    case 5:
    printstar('=',120);
    printf("mode   \t\t\t\tamount\t\t\ttotal\t\t\ttime\n");
    printstar('=',120);
    FILE* ptr;
    char ch;
    strcpy(name2,name);
    strcat(name2,"stat.txt");
    ptr = fopen(name2, "r");
    if (NULL == ptr) {
    	printf("\n\n");
    	printstar('*',50);
        printf("no transactions made");
        printstar('*',50);
    }
    do {
        ch = fgetc(ptr);
        printf("%c",ch);
    } while (ch != EOF);
    fclose(ptr);
    printf("\n");
    printstar('=',120);
	break;	
    }
    writefile();
    system("color 7C");
        if(a<=2)
		{
        printf("\nyour transaction has been completed successfully");
        printf("\n*thank you*\n*visit again*");
        }
        else
        printf("\n*thank you*\n*visit again*");
    printf("\npress 1 to continue");
    o=getch();
    s++;
    system("cls");
    if(o=='1')
    {
    	printf("1.login to your account\n2.login to another account\n3.for exit\nenter your choice:");
    	scanf("%d",&b);
	}
    switch(b)
    {
    case 1:
    {
    system("cls");
    main();
    break;
    }
    case 2:
    	{
    		system("cls");
    		main();
    		break;
		}
	case 3:
		{
			system("cls");
			printf("THANK YOU");
			exit(0);
		}
    }
}
    int ayyappa()
    {
    int i,ch,pass[30];
    for(i=0;i<4;i++)
	{
		ch=getch();
		pass[i]=ch;
		ch='*';
		printf("%c",ch);
		if(ch==8)
		break;
	}
	system("cls");
	system("color 7D");
	if(pass[0]!=pass1[0])
	return 1;
    else if(pass[1]!=pass1[1])
    return 1;
	else if(pass[2]!=pass1[2])
	return 1;
	else if(pass[3]!=pass1[3])
	return 1;
	return 0;
	}
	void printstar(char cha,int z)
	{
		for(i=0;i<z;i++)
		{
			printf("%c",cha);
		}
	}
	void statement()
	{
	char name1[20];
		FILE *fptr;
		strcpy(name1,name);
		strcat(name1,"stat.txt");
		fptr=fopen(name1,"a");
		if(fptr==NULL)
		{
			printf("error");
			exit(1);
		}
		if(a==1)
		{
			fprintf(fptr,"credited");
			fprintf(fptr,"\t\t\t%d",y);
		}
		else if(a==2)
		{
			fprintf(fptr,"debited ");
			fprintf(fptr,"\t\t\t%d",y);
		}
		fprintf(fptr,"\t\t\t%d",total);
		time_t my_time = time(NULL);
		fprintf(fptr,"\t\t\t%s\n",ctime(&my_time));
		fclose(fptr);	
	}
	
	void writefile()
	{
		char name1[20];
		FILE *fptr;
		strcpy(name1,name);
		strcat(name1,".txt");
		fptr=fopen(name1,"w");
		if(fptr==NULL)
		{
			printf("error");
			exit(1);
		}
		for(i=0;i<4;i++)
		fprintf(fptr,"%c",pass1[i]);
		fprintf(fptr,"\n%d",total);
		fclose(fptr);	
	}
	void readfile()
	{
		char name1[20],i;
		FILE *fptr;
		strcpy(name1,name);
		strcat(name1,".txt");
		fptr=fopen(name1,"r");
		if(fptr==NULL)
		{
		printstar('*',60);
		printf("\nyou don't have an account\n\n1.create an account\n2.login to other account\nenter choice:");
		scanf("%d",&i);
		if(i==1)
		{
			printf("enter password(4 digit pin):");
			scanf("%s",pass1);
			printf("initial amount to be credited:");
			scanf("%d",&total);
			writefile();
			printf("new account created");
			printf("\npress any key to continue");
			getch();
			system("cls");
			main();
		}
		else
		{
			system("cls");
			main();
		}
		}
		for(i=0;i<4;i++)
		fscanf(fptr,"%c",&pass1[i]);
		fscanf(fptr,"%d",&total);
		fclose(fptr);	
	}
