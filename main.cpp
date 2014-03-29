#include "grid.cpp"
#include <stdio.h>
#include <stdlib.h>
// POSIX headers
#include <termios.h>  // for tcxxxattr, ECHO, etc ..
#include <unistd.h>    // for STDIN_FILENO
#include <string.h>

int getch(void);

int main(int argc, char* argv[]){
	int array[SIZE * SIZE] = 
		{2, 2, 0, 2,
		 0, 2, 2, 0,
		 0, 4, 0, 0,
		 0, 0, 2, 2};	

	
	Board2048 *board = new Board2048(array);
	system("clear");
	board->print();

	int key  = getch();
	while(key)
	{
		key = getch();

		switch(key)
		{
			case 65:
				board->moveALL(UP);
				break;
			case 66:
				board->moveALL(DOWN);
				break;
			case 67:
				board->moveALL(RIGHT);
				break;
			case 68:
				board->moveALL(LEFT);
				break;			
		}
		system("clear");
		board->print();
	}

	board->moveALL(UP);
	board->print();

	board->moveALL(LEFT);
	board->print();	
}

 
int getch (void)
{
    int ch;
    struct termios oldt, newt;
 
    tcgetattr(STDIN_FILENO, &oldt);
    memcpy(&newt, &oldt, sizeof(newt));
    newt.c_lflag &= ~( ECHO | ICANON | ECHOE | ECHOK |
                       ECHONL | ECHOPRT | ECHOKE | ICRNL);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
 
    return ch;
}