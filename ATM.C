#include "ATM.H"
#include <conio.h>
#include <stdio.h>

struct userdb{
	char accdb;
	int passdb; 
};
accview();
menu();
int req(char *acc, int *password);
main(){
	struct userdb udb1, udb2, udb3,udb4,udb5;
	int choice, res;
	char *acc[8];
	int *password[4];
	clrscr();
	
	strcpy(udb1.accdb, "09303470");
	strcpy(udb1.passdb, "1234");
	
	accview();
	
	gotoxy(43, 10);
	gets(&acc);
	
	gotoxy(43, 11);
	gets(&password);
	
	res = req(acc, password);
	
	if(res == 1)
	{
		gotoxy(23, 15);
		printf("Does not meet requirements");
		sleep(2);
		main();
	}
	else if(res == 0)/*login*/
	{
		if(strcmp(udb1.accdb, acc) == 1)
		{
			puts("success");
		}
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
menu()
{
}
int req(char *acc, int *password)
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