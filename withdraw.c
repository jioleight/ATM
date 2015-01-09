#include"ATM.H"
#include<stdio.h>
#include <stdlib.h>
#include<dos.h>

float withdraw(char *acc)
{
	float wd, bal;
	int day, mon, yr, hr, min, sec;
	char *name;
	FILE *f;
	struct time t;
	struct date d;

	f=fopen("manage.txt","a");
	gettime(&t);
	getdate(&d);
	fprintf(f,"%02d / %02d / %04d\n",d.da_mon,d.da_day,d.da_year);
	fprintf(f,"%02d : %02d : %02d\n",t.ti_hour,t.ti_min,t.ti_sec);
	fprintf(f,"%s",acc);
	fprintf(f,"\n%s",name);
	fprintf(f,"\n%.2f",bal);
	fprintf(f,"\n");
	fclose(f);
	
	f=fopen("manage.txt","r");
	fscanf(f,"%d / %d / %d\n",&mon,&day,&yr);
	fscanf(f,"%d : %d : %d\n",&hr,&min,&sec);	
	fscanf(f,"%s \n",acc);
	fscanf(f,"%[^\n]\ns \n",name);
	fscanf(f,"%f \n",&bal);
	fclose(f);

	clrscr();

	printf("=====WITHDRAWAL=====");
	printf("\nDate: %d / %d / %d",mon,day,yr);
	printf("\nTime: %d / %d / %d",hr,min,sec);
	printf("\nName: %s",name);
	printf("\nAccount Number: %s",acc);
	printf("\nCurrent Balance: %.2f",bal);
	printf("\nWithdrawal Amount: Php ");
	scanf("%f",&wd);
	if(bal>=wd)
	{
		bal=bal-wd;
		printf("\n\nPhp %.2f was deducted",wd);
	}
	else
	{
		printf("\n\nInsufficient Funds!!! Press a key to continue....");
	}
	printf("\nRemaining Balance: Php %.2f",bal);
	printf("\nAgain [y/n]? ");
	
	f=fopen("manage.txt","a");
	gettime(&t);
	getdate(&d);
	fprintf(f,"%02d / %02d / %04d\n",d.da_mon,d.da_day,d.da_year);
	fprintf(f,"%02d : %02d : %02d\n",t.ti_hour,t.ti_min,t.ti_sec);
	fprintf(f,"\n%s",name);
	fprintf(f,"\n%s",acc);
	fprintf(f,"\n%f",bal);
	fprintf(f,"\n");
	fclose(f);
}
