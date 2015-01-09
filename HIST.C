
/* * * * * * * * * * * * * * * * * * *
* Name:        Gerald Kim Ico			 *
* Project:     ATM    					 *
* File:        HIST.C	   		    *
* Description: displays transaction  *
*              history of the user	 *
* Date:        1/10/15			  	    *
 * * * * * * * * * * * * * * * * * * */
#include "ATM.H"
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>

struct atm
{
	char acc[30],ln[30],fn[30];
	float bal;
	int yr,mo,day,hr,min,sec;
};

void history(char *acc) 
{
	int i=0,h=1,x,y,sm,sd,sy,em,ed,ey,id=0,rs=0,prntH;
	long SD,ED,TD,dd;
	float debit,credit,pbal=0;
	char *buf=" ",k=' ',*mmm,seD[17]="mmddyyyymmddyyyy ",cd[17],r=' ', *acch[8];
	FILE *f;
	struct atm a,tmp,m;
	struct date d;
	struct time t;
	sprintf(cd,seD); 
	strcpy(m.ln,"   ");
	strcpy(m.fn,"   ");
	strcpy(acch, acc);
	pbal=0;
	while(h!=0)
	{
		while(!kbhit())
		{	clrscr(); prntH=0;
					 
			gettime(&t);
			getdate(&d);
			printf("\n\t\t\t=====HISTORY=====\n");
			printf("\t\t\tDate: %02d/%02d/%d\n",d.da_mon,d.da_day,d.da_year);
			printf("\t\t\tTime: %02d:%02d:%02d\n",t.ti_hour,t.ti_min,t.ti_sec);
			printf("\t\t\tName: %s, %s\n",m.ln,m.fn);
			printf("\t\t\tAccount Number: %s\n", acch);
			printf("\t\t\tCurrent Balance: PHP%.2f\n",pbal);
			printf("\t\t\t===OPTION===\n");
			printf("\t\t\t[1] Current Month");
			printf("\n\t\t\t[2] Inclusive Dates");
			printf("\n\t\t\tchoice? %c",k);
			switch(k)
			{
				case '1': rs=1; 			
					switch(d.da_mon)
					{
						case 1: mmm="Jan"; break;
						case 2: mmm="Feb"; break;
						case 3: mmm="Mar"; break;
						case 4: mmm="Apr"; break;
						case 5: mmm="May"; break;
						case 6: mmm="Jun"; break;
						case 7: mmm="Jul"; break;
						case 8: mmm="Aug"; break;
						case 9: mmm="Sep"; break;
						case 10: mmm="Oct"; break;
						case 11: mmm="Nov"; break;
						case 12: mmm="Dec"; break;
						default: break;
					}
					printf("\n\n\tCURRENT MONTH: %s 01 to %02d\n",mmm,d.da_day);
					sprintf(buf,"%d%02d01",d.da_year,d.da_mon); SD=atol(buf);
					sprintf(buf,"%d%02d%02d",d.da_year,d.da_mon,d.da_day); ED=atol(buf);
					printf("\t=======================================================\n");
					printf("\tDATE\t\tTIME\t\tDebit\t\tCredit\n"); 
					prntH=1; y=17;
					break;
				case '2': id=1; rs=0;
					printf("\n\n\tSTART DATE?: %c%c/%c%c/%c%c%c%c",seD[0],seD[1],seD[2],seD[3],seD[4],seD[5],seD[6],seD[7]); 
					printf("\n\tEND DATE?  : %c%c/%c%c/%c%c%c%c",seD[8],seD[9],seD[10],seD[11],seD[12],seD[13],seD[14],seD[15]);
					switch(i)
					{
						case 0: x=22; y=13; break;
						case 1: x=23; y=13; break; 
						case 2: x=25; y=13; break;
						case 3: x=26; y=13; break;
						case 4: x=28; y=13; break;
						case 5: x=29; y=13; break;
						case 6: x=30; y=13; break;
						case 7: x=31; y=13; break;
						case 8: x=22; y=14; break;
						case 9: x=23; y=14; break;
						case 10: x=25; y=14; break;
						case 11: x=26; y=14; break;
						case 12: x=28; y=14; break;
						case 13: x=29; y=14; break;
						case 14: x=30; y=14; break;
						case 15: x=31; y=14; break;
						case 16: x=32; y=14; printf("\n\tpress enter to continue..."); break;
						case 17: id=0; rs=1;
							sprintf(buf,"%c%c",seD[0],seD[1]); sm=atoi(buf);
							sprintf(buf,"%c%c",seD[2],seD[3]); sd=atoi(buf);
							sprintf(buf,"%c%c%c%c",seD[4],seD[5],seD[6],seD[7]); sy=atoi(buf);
							sprintf(buf,"%c%c",seD[8],seD[9]); em=atoi(buf);
							sprintf(buf,"%c%c",seD[10],seD[11]); ed=atoi(buf);
							sprintf(buf,"%c%c%c%c",seD[12],seD[13],seD[14],seD[15]); ey=atoi(buf);
							printf("\n\t=======================================================\n");
							printf("\tDATE\t\tTIME\t\tDebit\t\tCredit\n");
							sprintf(buf,"%d%02d%02d",sy,sm,sd); SD=atol(buf);
							sprintf(buf,"%d%02d%02d",ey,em,ed); ED=atol(buf);
							if(SD>ED)
							{
								TD=SD; SD=ED; ED=TD;
							}
							prntH=1; y=18;
							break;
						default: break;
					}
					if(i!=17) gotoxy(x,y); break;
				case ' ': break;
				default: printf("\n\n\t\tInvalid Input!!! Press a key to continue..."); break;
			}
			pbal=0;				
			f=fopen("hist.dat","a+");
			while((fscanf(f,"%d / ",&a.mo))!=EOF)
			{
				fscanf(f,"%d / %d\n",&a.day,&a.yr);
				fscanf(f,"%d : %d : %d\n",&a.hr,&a.min,&a.sec);	
				fscanf(f,"%[^\n]\ns\n",a.acc);
				fscanf(f,"%[^\n]\ns\n",a.ln);
				fscanf(f,"%[^\n]\ns\n",a.fn); 
				fscanf(f,"%f\n\n",&a.bal);
				sprintf(buf,"%d%02d%02d",a.yr,a.mo,a.day); dd=atol(buf);
				if(SD<=dd&&ED>=dd&&(!strcmp(a.acc,*acc))&&prntH==1)
				{
					if(pbal>a.bal){credit=0; debit=pbal-a.bal;}
					else{credit=a.bal-pbal; debit=0;}
					printf("\n\t%02d/%02d/%d\t%02d:%02d:%02d\t%.2f\t\t",a.mo,a.day,a.yr,a.hr,a.min,a.sec,debit);
					gotoxy(57,y); printf("%.2f",credit); y++;
				}
				if(!strcmp(*acc,a.acc))
				{
					pbal=a.bal;
					strcpy(m.ln,a.ln);
					strcpy(m.fn,a.fn);
				}
			}	fclose(f);
			if(h==2) printf("\n\n\tInvalid Input!!! Press a key to continue...");
			if(rs==1) printf("\n\n\tAgain [y/n]? %c",r); 
			sleep(1);
		}		
		if(rs==1)
		{
			r=getche();
			if(r=='y') 
			{
				i=0; h=1; id=0; rs=0; k=' '; r=' ';
				sprintf(seD,"mmddyyyymmddyyyy "); 
			}
			else if(r=='n') h=0;
			else h=2;
		}
		else if(id==0) k=getche();
		else if(id==1)
		{
			seD[i]=getch();
			if(seD[i]==127||seD[i]==8)
			{
				seD[i]=cd[i];
				i--;
				seD[i]=cd[i];
			}
			else 
			{
				if(i==16)
				{
					if(seD[i]!=13) i--;
				}
				i++;
			}
		}		
		if(i>17) i=17; if(i<0) i=0;		
	}
	menu(acc);
}
