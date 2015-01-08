#include "ATM.H"
#include <stdio.h>
#include <conio.h>

float deposit(char *acc)
{
 auto int acc;
   float add_money;

   printf("Enter account number you want to deposit money:");
   scanf("%d",&acc);
   printf("\nThe current balance for account %d is %f \n",
   acc, acc.available_balance);
   printf("\nEnter money you want to deposit :  ");
   scanf("%f",&add_money);

   while (acc=acc.acc_number)
   {
         acc.available_balance = acc.available_balance+add_money;
         printf("\nThe New balance for account %d is %f \n",
         acc, acc.available_balance);
         break;
   }acc++;
}