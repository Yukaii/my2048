#pragma once
#include "grid.h"
#include <iostream>

using namespace std;

bool Board2048::moveALL(dir where){

	if (where == LEFT) {

		for(int j = 0; j < SIZE; j++)
		{
			Grid *now = selectGrid(0, j);
			Grid *neighbor = now->getNeighbor(RIGHT);
			for(int i = 0; i < 4; i++){

				neighbor = now->getNeighbor(RIGHT);

				if(!(neighbor->canMove(LEFT)) )
				{
					if (neighbor->getValue() == now->getValue()){
						merge(now, neighbor);
						now = neighbor;
					}
				}
				else if(neighbor->canMove(LEFT))
				{
					move(now, neighbor);
					now = neighbor;
				}
			}
		}
	}
}  

bool Board2048::merge(Grid* here, Grid* there){
	if(here != NULL || there == NULL) 
		return false;
	else{
		here->setValue(here->getValue()*2);
		there->setValue(0);
		return true;
	}
}

bool Board2048::move(Grid* here, Grid* there){
	if(here != NULL || there == NULL) 
		return false;
	else{
		here->setValue(there->getValue());
		there->setValue(0);
	}	
}

void Board2048::print(){
	for (int j = 0; j < SIZE; j++){
		for (int i = 0; i < SIZE; i++){
		cout << selectGrid(i, j)->getValue() << " ";
		}
		cout << endl;
	}
	cout << endl;
}

Board2048::Board2048(int array[]){
	for (int j = 0; j < SIZE; j++){
	for (int i = 0; i < SIZE; i++){
		selectGrid(i, j)->setValue(array[i + j*SIZE]);
		
		
		//set up neighbors
		if (i+1 < SIZE)
			selectGrid(i, j)->setNeighbor(RIGHT, selectGrid(i+1, j));
		if (i-1 >= 0) 
			selectGrid(i, j)->setNeighbor(LEFT , selectGrid(i-1, j));
		if (j+1 < SIZE) 
			selectGrid(i, j)->setNeighbor(UP   , selectGrid(i, j+1));		
		if (j-1 >= 0) 
			selectGrid(i, j)->setNeighbor(DOWN , selectGrid(i, j-1));


	}
	}
}