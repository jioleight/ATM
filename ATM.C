#include "ATM.H"
#include <conio.h>
#include <stdio.h>

struct userdb{
	char accdb[9];
	char passdb[5]; 
};


accview();
int req(char *acc, char *password);
char quit(char *acc);

main()
{
	struct userdb udb[5] = {{"09303470", "1234"},{"09303358", "1234"},{"09305169", "1234"},{"09300717", "1234"},{"09301780", "1234"}};
	int choice, res, i;
	char *acc[8];
	char *password[4];
	FILE *db;
	
	clrscr();
	
	accview();
	
	gotoxy(43, 10);
	gets(&acc);
	
	gotoxy(43, 11);
	gets(&password);
	
	res = req(acc, password);

	
	if(res == 1)/*check fields*/
	{
		gotoxy(23, 15);
		printf("Does not meet requirements");
		sleep(2);
		main();
	}
	else if(res == 0)/*login*/
	{
		for(i = 0; i < 5; i++)
		{
			if(strcmp(acc, udb[i].accdb) == 0)
			{	
				/*
				gotoxy(1, 22);
				puts("correct acc");
				printf("%s - %s", udb[i].accdb, acc);
				*/
				
				if(strcmp(password, udb[i].passdb) == 0)
				{
					sleep(1);
					menu(udb[i].accdb);
					/*
					gotoxy(1, 24);
					puts("correct pass");
					printf("%s - %s", udb[i].passdb, password);
					*/
				}
				else
				{
					gotoxy(28, 15);
					puts("Sorry, invalid password");
					sleep(2);
					main();
				}
				res = 0;
				break;
			}
			/*
			else if(i == 5 || strcmp(acc, udb[5-i].accdb) != 0)
			{
				gotoxy(20, 15);
				printf("Sorry, account # %s is not existing", acc);
			}
			*/
			else
			{
				res = 1;
			}
		}
		if(res == 1)
		{
			gotoxy(20, 15);
			printf("Sorry, account # %s is not existing", acc);
			sleep(2);
			main();
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
menu(char *acc)
{
	int choice;
	char *accm[8];
	clrscr();
	
	strcpy(accm, acc);
	
	gotoxy(24, 7);
	printf("========== MAIN MENU ==========");
	gotoxy(24, 8);
	printf("[1] Inquire");
	gotoxy(24, 9);
	printf("[2] Withdraw");
	gotoxy(24, 10);
	printf("[3] Deposit");
	gotoxy(24, 11);
	printf("[4] Fast Cash");
	gotoxy(24, 12);
	printf("[5] History");
	gotoxy(24, 13);
	printf("[6] Exit");
	gotoxy(24, 14);
	printf("Choice? ");
	gotoxy(24, 15);
	printf("===============================");
	
	
	gotoxy(33, 14);
	scanf("%i", &choice);
	
	switch(choice)
	{
		case 1:
			inquire(accm);
			break;
		case 2:
			withdraw(accm);
			break;
		case 3:
			/*deposit(acc);*/
			break;
		case 4:
			/*fast_cash(acc);*/
			break;
		case 5:
			history(accm);
			break;
		case 6:
			quit(accm);
			sleep(2);
			return 0;
			break;
		default:	
			gotoxy(24, 18);
			printf("Invalid input!!!");
			sleep(1);
			menu(accm);
			break;
	}
	
}
char quit(char *acc)
{	
	char *accq[8];
	clrscr();
	strcpy(accq, acc);
	gotoxy(24, 10);
	printf("Thank you for Bbanking with us");
	gotoxy(24, 11);
	printf("Have a nice day %s ", accq);
	gotoxy(24, 12);
	printf("Good bye!");
}
int req(char *acc, char *password)
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