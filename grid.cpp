#pragma once
#include "grid.h"
#include <iostream>

using namespace std;

bool Board2048::moveALL(dir where){

	dir FROM = where;
	dir TO;

	if (where ==  LEFT) TO = RIGHT;
	if (where == RIGHT) TO =  LEFT;
	if (where ==    UP) TO =  DOWN;
	if (where ==  DOWN) TO =    UP;

	for(int k = 0; k < SIZE; k++)
	{
		Grid *now, *neighbor;

		if (where ==  LEFT) now = selectGrid(     0, k);
		if (where == RIGHT) now = selectGrid(SIZE-1, k);
		if (where ==    UP) now = selectGrid(k     , 0);
		if (where ==  DOWN) now = selectGrid(k     , SIZE-1);
				
		while(1){
			neighbor = now->getNeighbor(TO);
			if (!neighbor) {
				cout << "now = " << now << endl;
				break;
			}

			//////TEST USE
			/*
			cout << "now = " << now << endl;
			cout << "neighbor = " << neighbor << endl;
			
			cout << "now value = " << now->getValue() << endl;
			cout << "neighbor value = " << neighbor->getValue() << endl;
			*/
			//////////////
			
			if (neighbor->canMove(FROM))
			{
				move(now, neighbor);
			}

			else
			{
				if (neighbor->getValue() == now->getValue()){
					merge(now, neighbor);
				}
			}
			now = neighbor;				
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
		if (j-1 >= 0) 
			selectGrid(i, j)->setNeighbor(UP   , selectGrid(i, j-1));		
		if (j+1 < SIZE) 
			selectGrid(i, j)->setNeighbor(DOWN , selectGrid(i, j+1));


	}
	}
}