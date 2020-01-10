//  Created by Tarek Abdelrahman on 2019-06-07.
//  Copyright © 2019 Tarek Abdelrahman. All rights reserved.

#include "tictactoe.h"
#include "gameState.h"
#include <iostream>
using namespace std;

//return the object's clicked Row
int gameState::get_clickedRow(){
	return this->clickedRow;
}

//return the object's clicked Column
int gameState::get_clickedColumn(){
	return this->clickedColumn;

}

//set clicked row as long as it the row clicked is valid
void gameState::set_clickedRow(int value){
    //if within the bounds
	if(value >=0 && value <= boardSize - 1){
		clickedRow = value;
	}else{
	//do nothing
	}
}

//set clicked column as long as it the column clicked is valid
void gameState::set_clickedColumn(int value){
    //if within the bounds
	if(value >= 0 && value <= boardSize -1){
		clickedColumn = value;
	}else{
	//do nothing
	}
}

//haven't checked for the validity of the clicked position till now



bool gameState::get_moveValid(){
    //if not occupied by another player
    return this-> moveValid;
	
}
void gameState::set_moveValid(bool value){
    //cout << "value passed to set_moveValid is" << value << endl;
    moveValid = value;
    
}

bool gameState::get_gameOver(){ 
    if (winCode == 0){
        bool over = true;
        //
        for(int i = 0; i < boardSize; i++){
            for(int j = 0; j < boardSize; j++){
                if(gameBoard[i][j] == 0){
                    over = false;
                    //cout << "over = " << over << endl;
                }
            }
        }
        //not gameOver if there's an empty tile
        gameOver = over;
    }else if(winCode != 0){
        gameOver = true;
    }
    return gameOver;
    cout << "gameOver" << gameOver << endl;
}
    
void gameState::set_gameOver(bool value){
 
	gameOver = value;
        //cout << "gameOver" << gameOver << endl;
}

int gameState::get_winCode(){
        //cout << "wincode:" << winCode << endl;
	return this-> winCode;
	//int winCode;
	//cin >> winCode;
	//return winCode;
}
void gameState::set_winCode(int value){
	winCode = value;
        //cout << "winCode = " << winCode << endl;
}

bool gameState::get_turn(){
    /*if(get_moveValid() == true){
        return turn;
    }else{
        return !turn;
    }*/
    return this -> turn;
}

void gameState::set_turn(bool value){
    //for the next player
    turn = value;
    //cout << "the turn is: " << turn << endl;
}

int gameState::get_gameBoard(int row, int column){
	return gameBoard[row][column];
}

void gameState::set_gameBoard(int row, int col, int value){
    if (get_moveValid() == true){
        if(row >= 0 && row <= boardSize - 1 && col >= 0 && col <= boardSize -1){
            if(gameBoard[row][col] != 1 && gameBoard[row][col] != -1){
                    //cout<<"gameboard value" << get_gameBoard(row,col) << endl;
                gameBoard[row][col] = value;
            }
        }
    }
}
