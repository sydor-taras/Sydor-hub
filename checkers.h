#define FIELD_SIZE 64
#define CHECKERS_COUNT 12
typedef unsigned char UC;
typedef unsigned short US;

class desk
{
	char * field;
	US Bcnt, Wcnt;
public :
	desk() : field(nullptr), Bcnt(CHECKERS_COUNT), Wcnt(CHECKERS_COUNT) {}
	bool CreateDesk ( void );
	void print ( void );
	void move ( UC clr );
	bool CheckPos( US currpos, US destpos, UC clr = 'B' );
	bool Getcnt() { if (Bcnt == 0 || Wcnt == 0) return false; else return true; }

};

void Go ( void );

short Enter(void);