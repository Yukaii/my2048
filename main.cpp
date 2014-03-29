#include "grid.cpp"
#include <stdio.h>
#include <stdlib.h>
// POSIX headers
#include <termios.h>  // for tcxxxattr, ECHO, etc ..
#include <unistd.h>    // for STDIN_FILENO
#include <string.h>

int getch(void);

Board2048 board;

int main(int argc, char* argv[]){

	board.reset();
	system("clear");
	board.print();

	int key  = getch();
	while(key)
	{	
		key = getch();

		switch(key)
		{
			
			case 65:
				if(board.moveALL(UP)== false){
					cout << "end" << endl;
					getch();
				}
				break;
			case 66:
				if(board.moveALL(DOWN)== false){
					cout << "end" << endl;
					getch();

				}
				break;
			case 67:
				if(board.moveALL(RIGHT)== false){
					cout << "end" << endl;
					getch();
				}
				break;
			case 68:
				if(board.moveALL(LEFT)== false){
					cout << "end" << endl;
					getch();
				}
				break;	
			//backspace
			case 8:
				board.reset();
				break;

		}
		system("clear");
		board.print();
	}
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