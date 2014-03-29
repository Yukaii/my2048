#pragma once
#include "grid.h"
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

bool Board2048::moveALL(dir where){

	dir FROM = where;
	dir TO;

	bool change_flag = false;

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
				//cout << "now = " << now << endl;
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
				change_flag = true;
			}

			else
			{
				if (neighbor->getValue() == now->getValue()){
					merge(now, neighbor);
					change_flag = true;
				}
			}
			now = neighbor;				
		}
	}

	if (change_flag) {
		generate();
		return true;
	}
	else if (isEnd()){
		return false;
	}
	return true;

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
			if (selectGrid(i, j)->getValue() == 0) cout << setw(2) << " □ ";
			else cout << setw(2) << selectGrid(i, j)->getValue() << " ";
		}
		cout << endl;
	}
	cout << endl;
}

bool Board2048::isEnd(){
	for(int j = 0; j < SIZE; j++){
	for(int i = 0; i < SIZE; i++){
		if(selectGrid(i, j)->getValue() == selectGrid(i, j)->getNeighbor(LEFT)->getValue())
			return false;
		if(selectGrid(i, j)->getValue() == selectGrid(i, j)->getNeighbor(RIGHT)->getValue())
			return false;
		if(selectGrid(i, j)->getValue() == selectGrid(i, j)->getNeighbor(UP)->getValue())
			return false;
		if(selectGrid(i, j)->getValue() == selectGrid(i, j)->getNeighbor(DOWN)->getValue())
			return false;					
		if(selectGrid(i, j)->getValue() == 0) return false;
	}
	}
	return true;
}

int twopower(int n){
	int two = 1;
	for (int i = 0;i < n; i++){
		two *= 2;
	}
	return two;
}

void Board2048::reset(){
	int array[SIZE * SIZE] = {0};

	srand(time(NULL));

	//3 to 6 filled grid
	int num = rand()%4 + 3;

	//fill theme
	for (int i = 0; i < num; i++){
		array[rand()%(SIZE*SIZE)] = twopower(rand()%4+1);
	}


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

bool Board2048::generate(){

	int k = 0;
	for (int j = 0; j < SIZE; j++){
	for (int i = 0; i < SIZE; i++){

		if (selectGrid(i, j)->getValue() == 0)
		{
			k++;
		}

	}
	}

	int which = rand()%k+1;
	k = 0;
	for (int j = 0; j < SIZE; j++){
	for (int i = 0; i < SIZE; i++){
		if (selectGrid(i, j)->getValue() == 0)
		{
			k++;
			if (which == k) 
			{
				selectGrid(i, j)->setValue(twopower(rand()%2+1));
				return true;
			}

		}

	}
	}

}

