#pragma once
#define SIZE 4

//list four dirctions for accessing
enum dir{
	RIGHT = 0,
	LEFT  = 1,
	UP    = 2,
	DOWN  = 3,
	TOTAL = 4
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

	//initialize Grid class
	Grid::Grid(){
		for(int i = 0; i < TOTAL; i++){
			neighbors[i] = NULL;
		}
		value = 0;
	}

	Grid::~Grid(){
		delete[] neighbors;
	}

private:
	Grid* neighbors[TOTAL];
	int value;

};

class Board2048 {
public:
	move(dir where){

	}                                                                                                                                                                                                                                                                                                                     

private:
	//
	merge(int x, int y, dir where);

	//delete this grid
	//maybe useless
	del(int x, int y);


};

