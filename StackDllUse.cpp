// StackDllUse.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "StackDLL.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;


int main()
{
	/*******************************************************************************************/
	HINSTANCE mydll;
    mydll = LoadLibrary(TEXT("StackDLL.dll"));										//loading dynamic library
	if(mydll == NULL)
	{
		cout << ".DLL load FAILED!!!" << endl;
		return 0;
	}
	void (Stack::*pConstructor)();													//creating a pointer to method of dll-class
	(FARPROC &)pConstructor = GetProcAddress(mydll, "??0Stack@@QAE@XZ");			//initializate a pointer with method address
	Stack *st1 = (Stack *)malloc(sizeof(Stack));									//reserving memory for imported class
	(st1->*pConstructor)();															//calling constructor of imported class
	/*******************************************************************************************/
	void (Stack::*pPush)(char*);
	(FARPROC &)pPush = GetProcAddress(mydll, "?Push@Stack@@QAEXPAD@Z");

	UC (Stack::*pPop)(void);
	(FARPROC &)pPop = GetProcAddress(mydll, "?Pop@Stack@@QAEEXZ");

	void (Stack::*pStackReset)(void);
	(FARPROC &)pStackReset = GetProcAddress(mydll, "?StackReset@Stack@@QAEXXZ");

	unsigned short (Stack::*pGetTos)(void);
	(FARPROC &)pGetTos = GetProcAddress(mydll, "?GetTos@Stack@@QAEGXZ");

	void (Stack::*pIsEmpty)(void);
	(FARPROC &)pIsEmpty = GetProcAddress(mydll, "?IsEmpty@Stack@@QAE_NXZ");

	void (Stack::*pDestructor)();
	(FARPROC &)pDestructor = GetProcAddress(mydll, "??1Stack@@QAE@XZ");
	/*********************************************************************************/
	char *p = (char*) malloc(STACK_SIZE);
	if (!p)
	{
		cout<<"No memory ";
		return 0;
	}
	UC what;
M1:	cout<<endl<<" What do you want to do?"<<endl<<"1. Add to the stack "<<endl<<"2. Take from stack "<<endl<<"3. Clear stack "<<endl
		<<"4. Get top of stack"<<endl<<"5. Stack is emty? "<<endl<<"6. Exit "<<endl;
	cin>>what;
	switch(what)													//solving what to do
	{
	case ('1') :
		cout<<"Enter symbol or word (max "<<STACK_SIZE<<" elements) :";
		scanf("%15s",p);
		fflush(stdin);
		(st1->*pPush)(p);
		goto M1;													//go back to know the new decision
		break;
	case('2') :
		cout<<"Taken symbol : "<<(st1->*pPop)();
		goto M1;
		break;
	case('3') :
		(st1->*pStackReset)();
		goto M1;													//go back to know the new decision
		break;
	case ('4') :
		cout<<"Top of stack = "<<(st1->*pGetTos)()<<endl;
		goto M1;													//go back to know the new decision
		break;
	case ('5') :
		(st1->*pIsEmpty)();
		goto M1;													//go back to know the new decision
		break;
	case ('6') :
		(st1->*pDestructor)();
		free(st1);
		free(p);
		FreeLibrary(mydll);
		return 0;
	default :														//print message and move to the start
		cout<<"Wrong number! "<<endl;
		goto M1;
	}
}
