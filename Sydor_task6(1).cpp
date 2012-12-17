// Sydor_task6(1).cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "Sydor_task6(1).h"

using namespace std;

char * Read(void);
void Check(char *p);

int _tmain(int argc, _TCHAR* argv[])
{
	char *p;
	p = Read();
	Check(p);
	system("pause");
	return 0;
}


char * Read(void)
{
	char *ptr = new char[10];
	printf("Enter your string of brackets(max 10 symbols) : ");
	scanf("%10s",ptr);
	return ptr;
}

void Check(char *pt)
{
	Stack st;
	const char b1 [] = {'(',')'};
	const char b2 [] = {'{','}'};
	const char b3 [] = {'[',']'};
	char tmp[2];
	for (char i=0; i<strlen(pt); i++)
	{
		if ((pt[i]=='[')||(pt[i]=='{')||(pt[i]=='('))
			st.Push(pt[i]);
		else if ((pt[i]==']')||(pt[i]=='}')||(pt[i]==')'))
		{
			tmp[0]=st.Pop();
			tmp[1]=pt[i];
			if (memcmp(b1,tmp,2)&&memcmp(b2,tmp,2)&&memcmp(b3,tmp,2))
			{
				cout<<"Wrong brackets "<<endl;
				return;
			}
		}
		else 
		{
			cout<<"Incorrect string "<<endl;
			return;
		}
	}
	if (!st.IsEmpty())
	{
		cout<<"Too many opening brackets !"<<endl;
		return;
	}
	cout<<"Vse pravulno "<<endl;
}

Stack::Stack()
{
	stck = (char*)malloc(SIZE_STACK);													//reserving memory for stack
	if (!stck)
	{
		cout<<"Not enought memory ";											//throw exception if not enought memory
	}
	tos = 0;																	//initializate the top of stack
}

void Stack::Push(char symb)
{
	if (tos==SIZE_STACK)																//checking if stack is full
	{
		cout<<"Stack overflow "<<endl;											//print message if yes
		return;
	}

	/* if length of string (symb) is more than free space in stack, push in stack inly free bytes */
	stck[tos]=symb;													//add symbol if stack in not full yet
	tos++;																	//increase the top of stack
}

char Stack::Pop(void)
{
	if (tos==0)																	//checking if stack is empty already
	{
		cout<<"Stack is empty "<<endl;
		return 0;
	}
	tos--;																		//decrease the top of stack
	return stck[tos];
}

void Stack::StackReset(void)
{
	tos=0;																		//set the top of stack into 0
	cout<<"Stack is empty "<<endl;
}

Stack::~Stack()
{
	free(stck);
}

bool Stack::IsEmpty(void)
{
	if (tos==0)																	//check if stack is empty
	{
		//cout<<"Stack is empty "<<endl;
		return true;
	}
	else
	{
			//cout<<"Stack is not empty "<<endl;
			return false;
	}
}