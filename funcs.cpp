#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include "checkers.h"

using namespace std;


bool desk::CreateDesk(void)
{
	UC tmp = -1;
	field = new char[FIELD_SIZE];
	if ( !field ) 
	{
		return false;
	}
	for (UC i = 0; i <= 63; i=i+2)
	{
		tmp++;
		if (tmp == 4)
		{
			++i;
		}
		if (tmp == 8)
		{
			--i;
			tmp = 0;
		}
		if ( i > 24 && i < 41 )
		{
		field[i] = '+';
		}
		else if ( i < 24 )
		{
		field[i] = 'W' ;
		}
		else 
		{
			field [i] = 'B';
	}
	}
	tmp = -1;

	for (UC i = 1; i <= 63; i=i+2)
		{
		tmp++;
		if (tmp == 4)
		{
			--i;
		}
		if (tmp == 8)
		{
			++i;
			tmp = 0;
		}
		field[i] = '-';
		}
	return true;
}

US GetPos( void )
{
	US x,y;
	cout<<"x (0 - 7) : ";
	x = Enter();
	fflush(stdin);
	cout<<"y (0 - 7) : ";
	y = Enter();
	fflush(stdin);
	return (8 * y + x );
}

bool desk::CheckPos ( US currpos, US destpos, UC clr )
{
	if (clr == 'W') 
	{
	if ( (field[destpos] != '+') || (field[currpos] != clr))
		return false;
	else if ((destpos == currpos+7) || (destpos == currpos+9) || (destpos == currpos-7) || (destpos == currpos-9))
		return true;
	else if (destpos == currpos)
		return false;
	else if (destpos == currpos+14)
	{
		if (field[currpos+7] == 'B')
		{
			Bcnt--;
			field[currpos+7]='+';
			return true;
		}
	}
		else if (destpos == currpos+18)
	{
		if (field[currpos+9] == 'B')
		{
			Bcnt--;
			field[currpos+9]='+';
			return true;
		}
	}
		else if (destpos == currpos-14)
	{
		if (field[currpos-7] == 'B')
		{
			Bcnt--;
			field[currpos-7]='+';
			return true;
		}
	}
			else if (destpos == currpos-18)
	{
		if (field[currpos-9] == 'B')
		{
			Bcnt--;
			field[currpos-9]='+';
			return true;
		}
	}
	else return false;
	}
	else
	{
		if ( (field[destpos] != '+') || (field[currpos] != clr))
		return false;
	else if ((destpos == currpos+7) || (destpos == currpos+9) || (destpos == currpos-7) || (destpos == currpos-9))
		return true;
	else if (destpos == currpos)
		return false;
	else if (destpos == currpos+14)
	{
		if (field[currpos+7] == 'W')
		{
			Wcnt--;
			field[currpos+7]='+';
			return true;
		}
	}
		else if (destpos == currpos+18)
	{
		if (field[currpos+9] == 'W')
		{
			Wcnt--;
			field[currpos+9]='+';
			return true;
		}
	}
		else if (destpos == currpos-14)
	{
		if (field[currpos-7] == 'W')
		{
			Wcnt--;
			field[currpos-7]='+';
			return true;
		}
	}
			else if (destpos == currpos-18)
	{
		if (field[currpos-9] == 'W')
		{
			Wcnt--;
			field[currpos-9]='+';
			return true;
		}
	}
	else return false;
	}
}


void desk::print( void )
{
	UC tmp = 1;
	cout<<" ";
	for (UC i = 0; i<8; i++)
	{
		cout<<" "<<(short)i<<" ";
	}
	for (UC i = 0; i<FIELD_SIZE; i++)
	{

		if (!(i%8))
		{
			cout<<"\n";
			cout<<(short)(tmp-1);
			tmp++;
		}
		cout<<" "<<field[i]<<" ";
	}
	cout<<"\n\n"<<"White checkers left : "<<Wcnt<<endl<<"Black checkers left : "<<Bcnt<<"\n\n";
}

void desk::move ( UC clr )
{
	US currpos,destpos;
	if (clr == 'B')
		cout<<"Black move : \n";
	else cout<<"White move : \n";
M1:	cout<<"\n Choose checker's position :\n ";
	currpos = GetPos();
	cout<<"\n Choose the destination :\n ";
	destpos = GetPos();
	if (CheckPos(currpos,destpos,clr))
	{
	field[destpos] = field[currpos];
	field[currpos] = '+';
	} 
	else
	{
		cout<<"Bad position, try again \n";
		goto M1;
	}

}

void Go ( void ) 
{
	UC color;
	desk* ptr = new desk();
	ptr->CreateDesk();
	ptr->print();
	do {
	cout<<"What color do you choose ? W or B : ";
	do
	{
		color = getch();
	} while ((color != 'B') && (color != 'W'));
	ptr->move(color);
	ptr->print();
	} while (ptr->Getcnt());
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
M1: scanf("%5s",p);														//read 10 sybmols from keyboard
	fflush(stdin);
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