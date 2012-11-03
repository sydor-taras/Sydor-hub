/**
* header.h
* includes constants and declaration of a function
* Copyright 2012 by Sydor Taras
*/

#ifndef HEADER_H
#define HEADER_H

<<<<<<< HEAD
#define MASK_A 0xAAAAAAAA							//mask, which will delete unnecessary bits			
#define MASK_5 0x55555555
typedef unsigned long UL;							//my own name for unsigned long

UL MyFunc(UL a);									/**< this function performs exchange of neighboring bits of "a" */

UL Enter(void);										// reads a number from keyboard

#endif
=======
typedef unsigned long UL;							//my own name for unsigned long
typedef unsigned short US;

UL Exchange(UL a);									//reserving memory for Exchange()

UL Enter(void);

#endif 
>>>>>>> b9c560418e50983d7eebb37d56774aa841798b87
