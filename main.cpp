/**
* main.cpp
* includes executive code, that performs task �6
* Copyright 2012 by Sydor Taras
*/
#include <iostream>
#include <conio.h>
#include "header.h"

using namespace std;
															

void main(void)
{
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





