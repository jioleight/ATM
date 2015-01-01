#include "ATM.H"
#include <stdio.h>
#include <conio.h>

float fast_cash(char *acc)
{       
        clrscr();
        int vAmount;
        int x=0;
        printf("\n");
        printf(" Please Select an Option \n");
		printf("1) -> P100.00 \n");
		printf("2) -> P200.00 \n");
		printf("3) -> P300.00 \n");
		printf("4) -> P400.00 \n");
		printf("5) -> P500.00 \n");
		printf("6) -> Back to Main Menu \n");
   
        printf("\n");
        scanf("%d", &x);
         
         
          
    //scanf("%d", &vType);
      switch(x)
	{
       
      case 1:
        if(*bal>100)
        { 
          *bal=*bal-100;
          }
          else if (*bal<100)
			{
               printf("There are insufficent funds to complete this transaction\n");
            }
        break;
      case 2:
        if(*bal>200)
        { 
          *bal=*bal-200;
			}
          else if (*bal<200)
			{
               printf("There are insufficent funds to complete this transaction\n");
            }
        break;
      case 3:
        if(*bal>300)
        { 
          *bal=*bal-300;
          }
          else if (*bal<300)
			{
               printf("There are insufficent funds to complete this transaction\n");
            }
        break;
      case 4:
        if(*bal>400)
        { 
          *bal=*bal-400;
          }
          else if (*bal<400)
			{
               printf("There are insufficent funds to complete this transaction\n");
            }
        break;
      case 5:
        if(*bal>500)
        { 
          *bal=*bal-500;
          }
          else if (*bal<500)
			{
               printf("There are insufficent funds to complete this transaction\n");
            }
        break;

    }
     
}
