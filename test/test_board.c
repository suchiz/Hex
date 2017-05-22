#include "../lib/board.h"

int main()
{
	for (int i=0; i<15; i++)
	{
		board b = createBoard(i);
		if((&b.brd) == NULL)
		{
			printf("Failed test\n");
		}
		displayBoard(&b);
	}
	return OK;
}
