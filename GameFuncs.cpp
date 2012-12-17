#include <iostream>
#include <stdio.h>
#include <winsock2.h>
#include <windows.h>
#include "head.h"

#define MY_PORT 666

unsigned char arr_[9];

using namespace std;

void Go(void)
{
	char buff[200];
	unsigned char a;
	char b;
	for (unsigned short i = 0;i<9;i++)												//making a game field
		{
			arr_[i]=i+ASCII_1;															//convert i to ascii code if digit
		}
	
	if (WSAStartup(0x0202,(WSADATA *) &buff[0])) 
	{
		printf("Error WSAStartup %d\n",WSAGetLastError());
		return;
	}
	SOCKET my_sock;
	if ((my_sock=socket(AF_INET,SOCK_STREAM,0))<0)
	{
		printf("Error socket %d\n",WSAGetLastError());
		WSACleanup();
		return;
	}
	sockaddr_in local_addr;
	local_addr.sin_family = AF_INET;
	local_addr.sin_port = htons(MY_PORT);
	local_addr.sin_addr.s_addr = 0;
	if (bind(my_sock,(sockaddr *)&local_addr,sizeof(local_addr)))
	{
		printf("Error bind %d\n",WSAGetLastError());
		closesocket(my_sock); // закрываем сокет!
		WSACleanup();
		return;
	}
	listen(my_sock,0x5);
	SOCKET cl_sock;
	sockaddr_in cl_addr;
	int addrlen = sizeof(cl_addr);
	cl_sock = accept(my_sock,(sockaddr*)&cl_addr,&addrlen);
	printf("Connected player \n");
	char buf[] = "You are connected \n";
	send(cl_sock,&buf[0],strlen(buf),0);
	a='X';
	print();
	b = player_move(a);
	send(cl_sock,&b,1,0);
	print();
	for (unsigned char i = 0;i<3;i++)
	{
		recv(cl_sock,&b,1,0);
		arr_[b]='0';
		print();
		if (check('0',0))
		{
			b = 'w';
			send(cl_sock,&b,1,0);
			break;
		}
		b = player_move(a);
		if (check('X'))
		{
			b = 'l';
			send(cl_sock,&b,1,0);
			break;
		}
		send(cl_sock,&b,1,0);
		print();
	}
	closesocket(my_sock);
	WSACleanup();
	system("pause");
}

void print()
{
	cout << "-" << arr_[0] << "-" << '|' << "-" << arr_[1] << "-" << '|' << "-" << arr_[2] << "-" << endl;
	cout << "-" << arr_[3] << "-" << '|' << "-" << arr_[4] << "-" << '|' << "-" << arr_[5] << "-" << endl;
	cout << "-" << arr_[6] << "-" << '|' << "-" << arr_[7] << "-" << '|' << "-" << arr_[8] << "-" << "\n" << endl;
}

char player_move(unsigned char x_0)
{
	unsigned char move;
M2:	cout<<"Enter where to put "<<x_0<<" (1..9): ";
	cin>>move;
	fflush(stdin);
	if ((move > '9' )||(move<='0'))
	{
		cout<<"Wrong number !"<<endl;
		goto M2;
	}
	move=move-'0';
	if (arr_[move-1]=='X'||arr_[move-1]=='0')
	{
		cout<<"This move was already done! try again "<<endl;
		goto M2;
	}
	arr_[move-1]=x_0;
	return (move-1);
}

bool check(unsigned char mv,bool who)
{
if    ((arr_[0]==mv)&&(arr_[1]==mv)&&(arr_[2]==mv)||(arr_[3]==mv)&&(arr_[4]==mv)&&(arr_[5]==mv)
	|| (arr_[6]==mv)&&(arr_[7]==mv)&&(arr_[8]==mv)||(arr_[0]==mv)&&(arr_[4]==mv)&&(arr_[8]==mv)
	|| (arr_[2]==mv)&&(arr_[4]==mv)&&(arr_[6]==mv)||(arr_[0]==mv)&&(arr_[3]==mv)&&(arr_[6]==mv)
	|| (arr_[1]==mv)&&(arr_[4]==mv)&&(arr_[7]==mv)||(arr_[2]==mv)&&(arr_[5]==mv)&&(arr_[8]==mv))
			{
				if(who)
				{
				cout<<"You won !!!"<<endl;
				return true;
				}
				else 
				{
					cout<<"You lose!!!"<<endl;
					return true;
				}
			}
	else return false;
}