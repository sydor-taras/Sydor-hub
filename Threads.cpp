#include <iostream>
#include <Windows.h>

typedef unsigned short US;

#define COUNT 50

using namespace std;

US *val = new US [50];

void GetRand(US * pt);


DWORD WINAPI ThreadFunc(PVOID par)
{
	cout<<"\n"<<*((US*)par)<<" Thread \n";
	return 0;
}

int main()
{
	US *ptr;
	ptr = new US [COUNT];
	GetRand(ptr);
	for (US i = 0; i < COUNT; i++)
	cout<<ptr[i]<<"  ";
	HANDLE thr[COUNT];
	for (US i = 0; i < COUNT; i++)
	{
		val[i]=i;
		Sleep(1);
		thr[i]=(HANDLE)CreateThread(NULL,0,ThreadFunc,(PVOID)&val[i],CREATE_SUSPENDED,0);
	}
	for (US i = 0; i < COUNT; i++)
	{
		Sleep(20);
		ResumeThread(thr[ptr[i]]);
	}
	for (US i = 0; i < COUNT; i++)
		CloseHandle(thr[i]);
	delete[] ptr;
	ptr = nullptr;
	delete[] val;
	val = nullptr;
	system("pause");
}

void GetRand(US * pt)
{
	US j,n;
	for (US i = 0; i < COUNT; i++)
		pt[i] = i;
	for (US i = 0; i < COUNT; i++)
	{
	j=rand()%(COUNT-i)+i;
    n=pt[i];
    pt[i]=pt[j];
    pt[j]=n;
	}
}


