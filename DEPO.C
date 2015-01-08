/*******************************
Name: Paul Albert Tapayan
Project: ATM
Date: 1/1/2015
********************************/


#include "ATM.H"
#include <stdio.h>
#include <conio.h>

float deposit(char *acc)
{
 auto int acc_no;
   float add_money;

   printf("Enter account number you want to deposit money:");
   scanf("%d",&acc_no);
   printf("\nThe current balance for account %d is %f \n",
   acc_no, account[acc_no-1].available_balance);
   printf("\nEnter money you want to deposit :  ");
   scanf("%f",&add_money);

   while (acc_no=account[acc_no-1].acc_number)
   {
         account[acc_no-1].available_balance=
         account[acc_no-1].available_balance+add_money;
         printf("\nThe New balance for account %d is %f \n",
         acc_no, account[acc_no-1].available_balance);
         break;
   }acc_no++;
}