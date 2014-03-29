#include "grid.cpp"
#include <stdio.h>

int main(int argc, char* argv[]){
	int array[SIZE * SIZE] = 
		{2, 2, 0, 0,
		 0, 0, 0, 0,
		 0, 0, 0, 0,
		 0, 0, 0, 0};	
	
	Board2048 *board = new Board2048(array);
	board->print();

	board->moveALL(LEFT);
	board->print();


}