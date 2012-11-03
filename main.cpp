/**
* main.cpp
<<<<<<< HEAD
* includes executive code, that performs task ¹ 7
=======
* includes executive code, that performs task ¹6
>>>>>>> b9c560418e50983d7eebb37d56774aa841798b87
* Copyright 2012 by Sydor Taras
*/
#include <iostream>
#include <conio.h>
#include "header.h"

using namespace std;
															

void main(void)
{
<<<<<<< HEAD
UL s;		
s = Enter();
cout<<"Binary : ";
for (char i=sizeof(UL)*8-1;i>=0;i--)					//print a binary code of a number
	{
		cout<<((s>>i)&1);
	}
s=MyFunc(s);										//call MyFunc
cout<<endl<<"The number after MyFunc : "<<s<<endl;
cout<<"Binary : ";
for (char i=sizeof(UL)*8-1;i>=0;i--)					//print a binary code of a number
	{
		cout<<((s>>i)&1);
	}
getch();
}

UL MyFunc(UL a)										/**< this function performs exchange of neighboring bits of "a" */
{
	UL k=a>>1;										//shift rigth 
	a=a<<1;											//shift left
	a=a&MASK_A;										//delete unnecessary bits
	k=k&MASK_5;
	a=a|k;											//make exchange
	return a;										//returning changed number
=======
	UL s; 
	s=Enter();													//reading a number from keyboard
	cout<<"Binary : ";
	for (char i=sizeof(UL)*8-1;i>=0;i--)							//print a binary code of a number
		{
			cout<<((s>>i)&1);
		}
	s=Exchange(s);													//call Exchange
	cout<<endl<<"The number after MyFunc : "<<s<<endl;
	cout<<"Binary : ";
	for (char i=sizeof(UL)*8-1;i>=0;i--)							//print a binary code of a number
	{
		cout<<((s>>i)&1);
	}
	getch();
}

UL Exchange(UL a)											//this function makes all bits '0',except the younger one 
{
	return a&(~(a-1));										//returning changed number
>>>>>>> b9c560418e50983d7eebb37d56774aa841798b87
}

UL Enter(void)
{
	char *p = (char *)malloc(10*sizeof(char));
	if(!p) 
	{
		cout<<"No memory";
		return 0;
	}
	bool flag;																// flag shows is entered string a number,or no
M1:	cout<<"Enter the number (max 10 symbols) : ";							//print message
	scanf("%10s",p);														//read 10 sybmols from keyboard
	flag=true;
	for (unsigned char i=0;i<strlen(p);i++)
	{
		if ((p[i]<'0') || (p[i]>'9'))										//checking if all entered sybmols are digits
		{
			cout<<"Wrong number !"<<endl;
			flag=false;
			break;															//if at least 1 symbol is not a digit,stop cheking
		}
	}
	if (flag) 
		{
				UL k = atoi(p);												//converts entered string to number
				free(p);
				return k;													//returns entered number
		}
	else goto M1;
}


<<<<<<< HEAD
=======



>>>>>>> b9c560418e50983d7eebb37d56774aa841798b87
