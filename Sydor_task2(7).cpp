/**
* Sydor_task2(7)
* includes constants code, which performs task 2 ¹7
* Copyright 2012 by Sydor Taras
*/

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include "koord.h"
using namespace std;
struct Polygon														//structure of group
{
	UC name;														//this field contains group name
	short x,y,z;
	float dist;
/* number of students in group, number of excelent students, number of students without '3'marks,
number of students, which are behind*/											
} *p;															

unsigned short i = 0;												//contains a number of entered Polygon
int main()
{
	US what;														//reflects decision - what to do in program
	p =(Polygon *)malloc(sizeof(Polygon));							//reserving memory for 1 group
	if (!p) 
	{
		cout<<"No memory ";
		return 0;
	}
M1:		cout<<endl<<"Enter 0 to exit, 1 to enter new point, 2 to know is there at least 3 points with same z : ";
		cin>>what;
		fflush(stdin);												//clean input buffer						
	switch(what)													//solving what to do
	{
	case (1) :													//enter e new group

		add(i);
		print(i);
		i++;
		p=(Polygon *)realloc(p,(i+1)*sizeof(Polygon));				//reserving memory for a new group
		break;
	case(2) :														//fing the best group
		if (find(i)) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	break;
	case(0) :														//exit
		free (p);
		return 0;
	default :														//print message end exit
		cout<<"Wrong number! ";
	}
			goto M1;
}

void add(US i)													//this function enters new group
{
	cout<<"Enter the point name : ";								//print message
	cin>>p[i].name;													//read a name from keyboard
	fflush(stdin);	
	cout<<"Enter x : ";
	p[i].x=Enter();
	cout<<"Enter y : ";
	p[i].y=Enter();
	fflush(stdin);
	cout<<"Enter z : ";
	p[i].z=Enter();
	p[i].dist=sqrt((float)(p[i].x*p[i].x+p[i].y*p[i].y+p[i].z*p[i].z));  //calculating distance from '[0,0,0]'
}

bool find(US i)										//this function finds which group has more students, which study without 3
{
	if (i == 0)											//if you haven't entered still no group
	{
	cout<<"No points are still entered";				
	return 0;
	}
	char count=0;
	for (UC j=0;j<=i;j++)
	{
		count = 0;
		for (UC k=0;k<=i;k++)
		{
			if (p[j].z==p[k].z)count++;
			if (count==3) return true;
		}
	}
	return false;
}
void print(US i)												// this function prints table of sorted entered Polygon
{
	Polygon temp;
	UC j=0;
	for (UC m=0;m<=i;m++)
	{
		temp=p[m];
		j=m-1;
		while ((j>=0)&&(p[j].dist>temp.dist))
		{
			p[j+1]=p[j];
			j=j-1;
			p[j+1]=temp;
		}
	}
	cout<<"Name"<<"\t"<<"X"<<" \t"<<"Y"<<" \t"<<"Z"<<" \t"<<"Distance"<<endl;		//print table
	for (UC h=0;h<=i;h++)
		cout<<p[h].name<<"\t"<<p[h].x<<"\t"<<p[h].y<<"\t"<<p[h].z<<" \t"<<p[h].dist<<endl;

}

short Enter(void)
{
	char *p = (char *)malloc(10*sizeof(char));
	if(!p) 
	{
		cout<<"No memory";
		return 0;
	}
	bool flag;																// flag shows is entered string a number,or no
M1: scanf("%10s",p);														//read 10 sybmols from keyboard
	flag=true;
	for (unsigned char i=0;i<strlen(p);i++)
	{
		if ((p[i]<'0') || (p[i]>'9'))										//checking if all entered sybmols are digits
		{
			cout<<"Wrong number !"<<endl<<"Enter the correct one : ";
			flag=false;
			break;															//if at least 1 symbol is not a digit,stop cheking
		}
	}
	if (flag) 
		{
				short k = atoi(p);												//converts entered string to number
				free(p);
				return k;													//returns entered number
		}
	else goto M1;
}