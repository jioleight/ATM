#include "ATM.H"
#include <conio.h>
#include <stdio.h>

accview();

main()
{
	int ch;
	clrscr();
	
	accview();
	
}
accview()
{
	gotoxy(30, 9);
	printf("===== USC BANKING SERVICE =====");
	gotoxy(30, 10);
	printf("Input Account No.: ");
	gotoxy(30, 11);
	printf("Input Access Code: ");
	gotoxy(30, 12);
	printf("===============================");
	
}