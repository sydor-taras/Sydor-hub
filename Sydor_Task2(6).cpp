/**
* Sydor_task2(6)
* includes constants code, which performs task 2 ¹6
* Copyright 2012 by Sydor Taras
*/
#include "stdafx.h"
#include "groups.h"
#include <iostream>
#include <conio.h>
#include <stdio.h>
using namespace std;
struct Groups														//structure of group
{
	char name[10];													//this field contains group name
	unsigned short kilk,exc,nothree,behind;
/* number of students in group, number of excelent students, number of students without '3'marks,
number of students, which are behind*/
	 float perc;											//percent of students without '3' in each group
} *p;															

short i = 0;														//contains a number of entered groups
int main()
{
	US what;														//reflects decision - what to do in program
	p =(Groups *)malloc(sizeof(Groups));							//reserving memory for 1 group
	if (!p) 
	{
		cout<<"No memory ";
		return 0;
	}
M1:	cout<<endl<<"Enter 0 to exit, 1 to enter new group, 2 to find the best group : ";
	cin>>what;
	fflush(stdin);													//clean input buffer						
	switch(what)													//solving what to do
	{
	case (1) :													//enter e new group

		add(i);
		print(i);
		i++;
		p=(Groups *)realloc(p,(i+1)*sizeof(Groups));				//reserving memory for a new group
		break;
	case(2) :														//fing the best group
		find(i);
	break;
	case(0) :														//exit
		free (p);
		return 0;
	default :														//print message end exit
		cout<<"Wrong number! ";
		getch();
	} 
	goto M1;
}

void add(US i)													//this function enters new group
{
	cout<<"Enter the group name (max 6 symbols): ";								//print message
	fgets( p[i].name,6,stdin);												//read a name from keyboard
	fflush(stdin);	
	do 
	{
			cout<<"Enter the number of students : ";
			p[i].kilk = Enter();
	} while (p[i].kilk<=0);
	do 
	{
			cout<<"Enter the number of excelent : ";
			p[i].exc=Enter();
	} while (p[i].exc>p[i].kilk);
	do 
	{
			cout<<"Enter the number of students, which don't have 3 : ";
			p[i].nothree=Enter();
	} while (p[i].nothree>p[i].kilk);
	do
	{
			cout<<"Enter the number of students, which are behind  : ";
			p[i].behind=Enter();
	} while (p[i].behind>p[i].kilk);
		p[i].perc=(float)p[i].nothree/p[i].kilk;
}

void find(US i)										//this function finds which group has more students, which study without 3
{
	US a=0;
	if (i == 0)											//if you haven't entered still no group
	{
	cout<<"No groups are still entered";				
	return;
	}
	
	for (US j = 0;j<i;j++)
	{
		if (p[j].perc>p[a].perc)
			a=j;
	}
	cout<<"The best group is : "<<p[a].name;
	getch();
	return;
}
		
void print(US i)												// this function prints table of entered groups
{
	Groups all;													//creating a summary copy of all groups 
	all.kilk=0;all.exc=0;all.nothree=0;all.behind=0;
	cout<<"Name"<<"\t"<<"Stud"<<" \t"<<"Only 5"<<" \t"<<"No '3'"<<" \t"<<"Debtors"<<endl;		//print table
	for (US b=0;b<=i;b++)
	{
		cout<<p[b].name<<"\t"<<p[b].kilk<<"\t"<<p[b].exc<<"\t"<<p[b].nothree<<"\t"<<p[b].behind<<endl;
		all.kilk+=p[b].kilk;										//summarizing all entered groups
		all.exc+=p[b].exc;
		all.nothree+=p[b].nothree;
		all.behind+=p[b].behind;
	}
	cout<<"All :"<<"\t"<<all.kilk<<"\t"<<all.exc<<"\t"<<all.nothree<<"\t"<<all.behind<<endl;
}

US Enter(void)
{
	char *ptr = (char *)malloc(10*sizeof(char));
	if(!ptr) 
	{
		cout<<"No memory";
		return 0;
	}
	bool flag;																// flag shows is entered string a number,or no
M2:	scanf("%10s",ptr);														//read 10 sybmols from keyboard
	flag=true;
	for (UC i=0;i<strlen(ptr);i++)
	{
		if ((ptr[i]<'0') || (ptr[i]>'9'))										//checking if all entered sybmols are digits
		{
			cout<<"Wrong number !"<<endl<<"Enter the correct one : ";
			flag=false;
			break;															//if at least 1 symbol is not a digit,stop cheking
		}
	}
	if (flag) 
		{
				US k = atoi(ptr);												//converts entered string to number
				free(ptr);
				return k;													//returns entered number
		}
	else goto M2;
}


