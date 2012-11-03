/**
* Sydor_task3(6)
* includes constants code, which performs checking if entered string is hex-code
* Copyright 2012 by Sydor Taras
*/

#include "stdafx.h"
#include "hex.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector <char *> MyVec;						// contain pointers to entered Hex-codes

int _tmain(int argc, _TCHAR* argv[])
{
	UC what;														//contains decision that to do in program
M1:	cout<<" What do you want to do? 1-enter new number; 2-print entered numbers; 3-exit : ";
	cin>>what;
	switch(what)													//solving what to do
	{
		case ('1') :												//enter e new hex-code
		Add();
		goto M1;													//go back to know the new decision
		break;
	case('2') :														
		Vuvid();													//printf all entered strings
		goto M1;
	break;
	case('3') :														//exit
		return 0;
	default :														//print message and move to the start
		cout<<"Wrong number! "<<endl;
		goto M1;
	}
}

void Add(void)
{
	const char *hex_code="0x";
	char *err="Wrong Hex-code ";
	char *str;														//pointer to first element of entered hex-code													
	char *p;														//pointer for parcing entered string
	bool sign=false;												//is it correct hex-code
	str = (char *)malloc(sizeof(char));
	if (!str)
	{
		cout<<"Memory not enought ! ";
		return;
	}
	cout<<"Enter hex-code format : 0xcode(only big letters),or 1 to go back : ";
	cin>>str;
	if(*str=='1')
	{
		return;
	}
	if(!memcmp(str,hex_code,2))										//compare "0x" to first 2 symbols of entered string
		{
	p=str+2;
	for(UC i=1;i<(strlen(str)-1);i++)								//parsing entered string
	{
		if((*p>='0')&&(*p<='9')||(*p>='A')&&(*p<='F'))				//cheking correctness of hex-code
		{
			sign=true;
		}
		else 
		{
			sign=false;
			break;
		}
		p++;
	}
	}
	if (sign) MyVec.push_back(str);										//if hex-code is correct,add pointer to it
	else MyVec.push_back(err);											//if incorrect, add pointer to error message

}


void Vuvid(void)
{
	cout<<"Hex-code if correct, error message if incorrect :"<<endl;
	for (UC i=0;i<MyVec.size();i++)
		cout<<MyVec[i]<<endl;											
}
