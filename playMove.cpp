//
//  
//  Updated by Tarek Abdelrahman on 2019-06-07.
//  Created by Tarek Abdelrahman on 2018-05-15.
//  Copyright © 2018-2019 Tarek Abdelrahman. All rights reserved.
#include <iostream>
#include "tictactoe.h"
#include "gameState.h"
using namespace std;
//only one object and the object will be changed as the player plays
void playMove(gameState& game_state) {
    
    int player;
    
    //setting the players to X and O
    if(game_state.get_turn() == true){
        player = X;
    }
    
    if(game_state.get_turn() == false){
        player = O;
    }
       
    //set the clickedRow and clickedColumn values
    game_state.set_clickedRow(game_state.get_clickedRow());
    game_state.set_clickedColumn(game_state.get_clickedColumn());
    
    //set the gameBoard
    
    //cout << "row" << game_state.get_clickedRow() << endl;
    //cout << "col" << game_state.get_clickedColumn() << endl;
    
    //setmoveValid...
    if(game_state.get_gameBoard(game_state.get_clickedRow(),game_state.get_clickedColumn()) != -1 && game_state.get_gameBoard(game_state.get_clickedRow(),game_state.get_clickedColumn()) != 1){
        game_state.set_moveValid(true);
    }else{
        game_state.set_moveValid(false);
    }
    
    
    //if the move is valid
    if(game_state.get_moveValid() == true){
        //set the gameboard according to the move
        game_state.set_gameBoard(game_state.get_clickedRow(),game_state.get_clickedColumn(),player);
	/*no longer needed since updated in set_turn
     
     if(game_state.turn == true){
		game_state.turn = false;
	}*/
        
    //check to see if anyone's won
        
        if(game_state.get_gameBoard(0,0) == game_state.get_gameBoard(0,1) && game_state.get_gameBoard(0,1) == game_state.get_gameBoard(0,2)){
            
            if(game_state.get_gameBoard(0,0)!= 0){
                //cout << game_state.get_gameBoard(0,0) << endl;
                //cout<<"wincoding 1" << endl;
                game_state.set_winCode(1);
                //return;
            }
        }
                    
        if(game_state.get_gameBoard(1,0) == game_state.get_gameBoard(1,1) && game_state.get_gameBoard(1,1) == game_state.get_gameBoard(1,2)){
            //cout << "checking wincode2 condition" << endl;
            if(game_state.get_gameBoard(1,0)!= 0){
                //cout<<"wincoding 2" << endl;
                game_state.set_winCode(2);
                //return;
            }
        }
            //return;
        if(game_state.get_gameBoard(2,0) == game_state.get_gameBoard(2,1) && game_state.get_gameBoard(2,1) == game_state.get_gameBoard(2,2)){
           
            if(game_state.get_gameBoard(2,0)!= 0){
                //cout<<"wincoding 3" << endl;
                game_state.set_winCode(3);
                //return;
            }
            //return;
        }
        if(game_state.get_gameBoard(0,0) == game_state.get_gameBoard(1,0) && game_state.get_gameBoard(1,0) == game_state.get_gameBoard(2,0)){
            
            if(game_state.get_gameBoard(0,0)!= 0){
                //cout<<"wincoding 4" << endl;
                game_state.set_winCode(4);
                //return;
            }
            //return;
        }
        if(game_state.get_gameBoard(0,1) == game_state.get_gameBoard(1,1) && game_state.get_gameBoard(1,1) == game_state.get_gameBoard(2,1)){
            
            if(game_state.get_gameBoard(0,1)!= 0){
                //cout<<"wincoding 5" << endl;
                game_state.set_winCode(5);
                //return;
            }
            //return;
        }
        if(game_state.get_gameBoard(0,2) == game_state.get_gameBoard(1,2) && game_state.get_gameBoard(1,2) == game_state.get_gameBoard(2,2)){
            
            if(game_state.get_gameBoard(0,2)!= 0){
                //cout<<"wincoding 6" << endl;
                game_state.set_winCode(6);
                //return;
            }
           // return;
        }
        if(game_state.get_gameBoard(0,0) == game_state.get_gameBoard(1,1) && game_state.get_gameBoard(1,1) == game_state.get_gameBoard(2,2)){
            
            if(game_state.get_gameBoard(0,0)!= 0){
                //cout<<"wincoding 7" << endl;
                game_state.set_winCode(7);
                //return;
            }
            //return;
        }
        if(game_state.get_gameBoard(0,2) == game_state.get_gameBoard(1,1) && game_state.get_gameBoard(1,1) == game_state.get_gameBoard(2,0)){
            
            if(game_state.get_gameBoard(0,2)!= 0){
                //cout<<"wincoding 8" << endl;
                game_state.set_winCode(8);
                //return;
            }
            //return;
        }
        
        //no need to explicity set to 0 because initialized as 0
        /*else{
            game_state.set_winCode(0);
        }*/
        
        //cout << game_state.get_winCode() << endl;
        
        //set gameOver
        game_state.set_gameOver(game_state.get_gameOver()); 
        

        //alternate the players
        if(game_state.get_moveValid() == true){
            //cout << "true" << endl;
            game_state.set_turn(!game_state.get_turn());
        }else{
            //if invalid move, stay as same player until they place it on valid tile
            game_state.set_turn(game_state.get_turn());
            //replay
            return;
        }
         
    }
   
}

