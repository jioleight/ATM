#include"ATM.H"
#include<stdio.h>
#include <stdlib.h>
#include<dos.h>

float inquire(char *acc)
{
	float bal;
	int day, mon, yr, hr, min, sec;
	char *name, *acci[8];
	FILE *f;
	struct time t;
	struct date d;
	
	f=fopen("manage.txt","r");
	fscanf(f,"%d / %d / %d\n",&mon,&day,&yr);
	fscanf(f,"%d : %d : %d\n",&hr,&min,&sec);	
	fscanf(f,"%s \n",acc);
	fscanf(f,"%[^\n]\ns \n",name);
	fscanf(f,"%f \n",&bal);
	fclose(f);

	clrscr();
	
	strcpy(acci, acc);

	printf("=====BALANCE INQUIRY=====");
	printf("\nDate: %d / %d / %d",mon,day,yr);
	printf("\nTime: %d / %d / %d",hr,min,sec);
	printf("\nName: %s",name);
	printf("\nAccount Number: %s",acci);
	printf("\nCurrent Balance: %.2f",bal);
	printf("\nPress any key to return to main menu");
	getch();
	menu(acci);
}
