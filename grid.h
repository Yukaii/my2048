#pragma once
#define SIZE 4
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

//list four dirctions for accessing
enum dir{
	RIGHT =  0,
	LEFT  =  1,
	UP    =  2,
	DOWN  =  3,
	TOTAL =  4
};

class Grid {
public:
	//return grid saved value
	int getValue(){
		return value;
	}

	//set value to n
	void setValue(int n){
		value = n;
	}

	//return neighbor 
	Grid* getNeighbor(dir where){
		return neighbors[where];
	}

	bool setNeighbor(dir where, Grid* neighbor){
		neighbors[where] = neighbor;
		return true;
	}

	bool canMove(dir where){
		if (neighbors[where] == NULL) return false;
		if (neighbors[where]->getValue() == 0)
			return true;
		else return false;
	}

	//initialize Grid class
	Grid(){
		for(int i = 0; i < TOTAL; i++){
			neighbors[i] = NULL;
		}
		value = 0;
	}

	~Grid(){
		delete[] neighbors;
	}

private:
	Grid* neighbors[TOTAL];
	int value;

};

class Board2048 {
public:
	bool moveALL(dir where);
	void print();
	Board2048(int array[]);

private:
	Grid *selectGrid(int x, int y){
		return &(board[x + y*SIZE]);
	}

	bool merge(Grid* here, Grid* there);

	bool move(Grid* here, Grid* there);
	//delete this grid
	//maybe useless
	bool del(int x, int y);

	Grid board[SIZE * SIZE];

};