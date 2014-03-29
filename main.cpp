#include "grid.cpp"
#include <stdio.h>

int main(int argc, char* argv[]){
	int array[SIZE * SIZE] = 
		{2, 2, 0, 2,
		 0, 2, 2, 0,
		 0, 0, 0, 0,
		 0, 0, 2, 2};	
	
	Board2048 *board = new Board2048(array);
	board->print();

	board->moveALL(UP);
	board->print();
}