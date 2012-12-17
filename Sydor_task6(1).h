#define SIZE_STACK 20

// this class exports from dll
class Stack {
public:
	Stack();					// reserve SIZE bytes for stack.if failed - throws an exception "error"
	void Push(char symb);			//add symbol(UC symb) to stack
	char Pop(void);					//takes 1 element from stack, returns taken element,of 1 if stack is empty
	void StackReset(void);			//cleans stack
	bool Stack::IsEmpty(void);
	~Stack();
private:
	unsigned short tos;				//top of stack
	char *stck;
};