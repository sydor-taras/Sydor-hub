#ifndef STACKDLL_H
#define STACKDLL_H
#ifdef STACKDLL_EXPORTS
#define STACKDLL_API __declspec(dllexport)
#else
#define STACKDLL_API __declspec(dllimport)
#endif

#define STACK_SIZE 15


typedef unsigned char UC;
// this class exports from dll
class STACKDLL_API Stack {
public:
	Stack();						// reserve SIZE bytes for stack.if failed - throws an exception "error"
	void Push(char *symb);			//add symbol(UC symb) to stack
	UC Pop(void);					//takes 1 element from stack, returns taken element,of 1 if stack is empty
	bool IsEmpty(void);				//checks if stack is empty, if yes - returns true,else - false
	unsigned short GetTos(void);	//returns top of stack(first free element)
	void StackReset(void);			//cleans stack
	~Stack();
private:
	unsigned short tos;				//top of stack
	UC *stck;						//a pointer to stack
};

/*
extern STACKDLL_API int nStackDLL;

STACKDLL_API int fnStackDLL(void);
*/

#endif