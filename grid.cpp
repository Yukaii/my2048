#pragma once
#include "grid.h"
#include <iostream>

using namespace std;

bool Board2048::moveALL(dir where){

	if (where == LEFT) {

		for(int j = 0; j < SIZE; j++)
		{
			Grid *now = selectGrid(0, j);
			Grid *neighbor;
			for (int i = 0; i < SIZE-1; i++){

				neighbor = now->getNeighbor(RIGHT);
				
				cout << "now = " << now << endl;
				cout << "neighbor = " << neighbor << endl;
				
				cout << "now value = " << now->getValue() << endl;
				cout << "neighbor value = " << neighbor->getValue() << endl;

				if (neighbor->canMove(LEFT))
				{
					move(now, neighbor);
					cout << "move!" << endl;
				}

				else
				{
					if (neighbor->getValue() == now->getValue()){
						if (merge(now, neighbor))
							cout << "merge!" << endl;
					}
				}
				now = neighbor;
				cout << endl << endl << endl;
				
			}
		}
	}
}  

bool Board2048::merge(Grid* here, Grid* there){
	if(here == NULL || there == NULL) 
		return false;
	else{
		here->setValue(here->getValue()*2);
		there->setValue(0);
		return true;
	}
}

bool Board2048::move(Grid* here, Grid* there){
	if(here == NULL || there == NULL) 
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