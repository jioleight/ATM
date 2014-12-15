#include "ATM.H"
#include <conio.h>
#include <stdio.h>

accview();
int verify(char *acc, char *password);

main()
{
	int choice, res;
	char *acc[8], *password[4];
	clrscr();
	
	accview();
	
	gotoxy(43, 10);
	gets(&acc);
	
	gotoxy(43, 11);
	gets(&password);
	
	res = verify(acc, password);
	
	if(res == 1)
	{
		gotoxy(23, 15);
		printf("Does not meet requirements");
		sleep(2);
		main();
	}
	else
	{
	
	}
	getch();
	return 0;
}
accview()
{
	gotoxy(24, 9);
	printf("===== USC BANKING SERVICE =====");
	gotoxy(24, 10);
	printf("Input Account No.: ");
	gotoxy(24, 11);
	printf("Input Access Code: ");
	gotoxy(24, 12);
	printf("===============================");
	
}
int verify(char *acc, char *password)
{
	if(strlen(acc) != 8 || strlen(password) != 4)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}