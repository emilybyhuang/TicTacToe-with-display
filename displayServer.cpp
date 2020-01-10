//
//  displayServer.cpp
//  TicTacTo
//
//  Created by Tarek Abdelrahman on 2019-06-07.
//  Copyright © 2019 Tarek Abdelrahman. All rights reserved.
//

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using namespace std;
using namespace sf;

#include "tictactoe.h"
#include "gameState.h"

// Function prototype for playMove
void playMove(gameState&);

// The display server function
int displayServer() {
    int row, col, xPosition,yPosition,playerRow = 3, playerCol = 3;
    /************************************************************************************************************/
    /* Insert code that loads the various images used by the game and creates the sprites                       */
    /* ECE244 Student: The loading of the X image is shown. Repreat for the rest of the images                  */
    /************************************************************************************************************/

    
    // Get the X image
    sf::Texture xTexture;
    if (!xTexture.loadFromFile("/share/copy/ece244f/lab2/data/X.jpg")) {
    return EXIT_FAILURE;
    }
    sf::Sprite xSprite(xTexture);
    
    // Get the O image
    sf::Texture oTexture;
    if (!oTexture.loadFromFile("/share/copy/ece244f/lab2/data/O.jpg")) {
    return EXIT_FAILURE;
    }
    sf::Sprite oSprite(oTexture);
    
    // Get the blank image
    sf::Texture bTexture;
    if (!bTexture.loadFromFile("/share/copy/ece244f/lab2/data/B.jpg")) {
    return EXIT_FAILURE;
    }
    sf::Sprite bSprite(bTexture);
    
    
    // First, we find the sizes of the images so we can determine the size of the window we must create
    // The images (X, O and Black) are assumed to be square are are all of the same size
    // Thus, we just find the size of one of them
    // The tile size is the size of the images
    const int tileSize = oTexture.getSize().x;
    
    // The cell borders (thick lines) are rectangles
    // The size of these rectangles is 1/20th of the size of the tile by 3 
    const int barWidth = tileSize/20;
    const int barHeight = boardSize*tileSize + (boardSize-1)*barWidth;
    
    // The size of the window in pixels can now be calculated
    const int windowSize = boardSize*tileSize + (boardSize-1)*barWidth;
    
    // Create the main window: it has a title bar and a close button, but is not resizable
    // ECE244 Student: you should replace ECE244 in the title of the window by your login ID
    //sf::RenderWindow myFirstWindow(VideoMode(windowSize,windowSize ), "ECE244 Window",Style::Titlebar | Style::Close);

   
    sf::RenderWindow window(sf::VideoMode(windowSize, windowSize), "Tic-Tac_Toe (Huangba9 Display Server)", sf::Style::Titlebar | sf::Style::Close);
    
    // Set the Icon that appears in the task bar when the window is minimized
    // ECE244 Student: add your code here
     
 
    sf::Image myFirstWindowIcon;
    if (!myFirstWindowIcon.loadFromFile("/share/copy/ece244f/lab2/data/icon.jpg")) {
        return EXIT_FAILURE;
    }
    window.setIcon(myFirstWindowIcon.getSize().x,myFirstWindowIcon.getSize().y,myFirstWindowIcon.getPixelsPtr());
    //window.display();
    
    
    // Create the horizonal (vertical) borders as rectangles of sizes barWidth and barHeight (berHeight and barWidth)
    // ECE244 Student: insert your code here

    //1st vertical bar
    /*sf::RectangleShape border1(sf::Vector2f(barWidth, barHeight));
    border1.setPosition(tileSize, 0);
    window.draw(border1);
    
    //1st horizontal bar
    sf::RectangleShape border2(sf::Vector2f(barWidth, barHeight));
    border2.setPosition(0, tileSize+barWidth);
    border2.rotate(-90);
    window.draw(border2);
    
    //2nd vertical bar
    sf::RectangleShape border3(sf::Vector2f(barWidth, barHeight));
    border3.setPosition(tileSize* 2 + barWidth,0);
    border3.rotate(90);
    window.draw(border3);
    
    sf::RectangleShape border4(sf::Vector2f(barWidth, barHeight));
    border4.setPosition(0, (tileSize+barWidth) * 2);
    border4.rotate(-90);
    window.draw(border4);*/
    
           
    
    /************************************************************************************************************/
    /* Create and initialize the game state object                                                              */
    /************************************************************************************************************/
    gameState game_state;

    game_state.set_clickedRow(0);
    game_state.set_clickedColumn(0);
    game_state.set_moveValid(true); // This must start out as true
    game_state.set_gameOver(false);
    game_state.set_winCode(0);
    game_state.set_turn(true);  // X always plays first
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            game_state.set_gameBoard(i,j,Empty);
            //cout << game_state.get_gameBoard(i,j);
        }
    }
    //game_state.set_gameBoard(0,0,Empty);
    
    
    /************************************************************************************************************/
    /* This is the main event loop of the code                                                                  */
    /************************************************************************************************************/
    //for the first loop such that o is not placed
    
    // Start the game loop that runs as long as the window is open
    //flag for ignoring the initialized placement for O because everything is initialized to 0
    bool flag = false;
    while (window.isOpen()) {
        // The event
        sf::Event event;
        
        
        // Process the events
        while (window.pollEvent(event)) {
            
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            
            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
            
            
                
            
            
            // Left mouse button pressed: get the click position and update the game
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && !game_state.get_gameOver()) {
                // left mouse button is pressed: get the coordinates in pixels
                // ECE244 Student: Insert your code to get the coordinates here
                sf::Vector2i localPosition = Mouse::getPosition(window);
                    xPosition = localPosition.x;
                    yPosition = localPosition.y;
                    // left mouse button is pressed
                    // Get the coordinates in pixels.
                    
                    // The Vector2i is a type defined in SFML that defines a
                    // two element integer vector (x,y). This is how the
                    // elements of the vector are accessed
                    
                    // Important to keep in mind that the x axis is the
                    // horizontal one (i.e., columns) while the y axis is
                    // the vertical one (i.e., rows)
                   
                   
                
                
               
                // Convert the pixel coordinates into game board rows and columns
                // Just divide by tileSize
                // Observe that the x axis is the rows and the y axis is the columns
                // Also make sure that row and column values are valid
                // ECE244 Student: Insert your code below
                if(xPosition <= 3*tileSize && xPosition >= 0 && yPosition <= 3*tileSize && yPosition >= 0){
                    
                    
                    row = yPosition/tileSize;
                    //cout << "row:" << row << endl;
                    col = xPosition/tileSize;
                    //cout << "col:" << col << endl;
                }
                
                // Update the game state object with the coordinates
                // ECE244 Student: insert code to update the object game_state here
                if(row >= 0 && row <=2 && col >= 0 && col <= 2){
                    game_state.set_clickedRow(row);
                    game_state.set_clickedColumn(col); 
                }
                
                    //cout << "clickedrow=" << game_state.get_clickedRow() << endl;
                    //cout << "clickedcol= "<< game_state.get_clickedColumn() << endl;
                // Update the game with the new move
                // ECE244 Student: invoke the playMove function here
                playMove(game_state);
            }
        }

        // If the move is invalid, go to next event
        if (!game_state.get_moveValid()) continue;
                
        
        // Insert code to draw the tiles using the sprites created earlier
        // You must determine the position of each cell on the grid, taking into account the width of
        // the border and then position the sprite there and draw it.
        // Draw the entire board, cell borders included,
        
                if(game_state.get_gameBoard(0,0) == 0){
                    
                    bSprite.setPosition(0,0);
                    window.draw(bSprite);
                    
                }
                
                if(game_state.get_gameBoard(0,1) == 0){
                    bSprite.setPosition(tileSize+barWidth,0);
                    //bSprite.rotate(-90);
                    window.draw(bSprite);
                }

                if(game_state.get_gameBoard(0,2) == 0){
                    bSprite.setPosition(2*(tileSize+barWidth),0);
                    window.draw(bSprite);
                }
                
                
                if(game_state.get_gameBoard(1,0) == 0){    
                    bSprite.setPosition(0,tileSize + barWidth);
                    window.draw(bSprite);
                }
                
                if(game_state.get_gameBoard(1,1) == 0){  
                    bSprite.setPosition(tileSize+barWidth, tileSize+barWidth);
                    window.draw(bSprite);
                }

                if(game_state.get_gameBoard(1,2) == 0){
                    bSprite.setPosition(2*(tileSize+barWidth),tileSize+barWidth);
                    //bSprite.rotate(90);
                    window.draw(bSprite);
                }
                
                if(game_state.get_gameBoard(2,0) == 0){
                    bSprite.setPosition(0,2*(tileSize+barWidth));
                    window.draw(bSprite);
                }

                if(game_state.get_gameBoard(2,1) == 0){
                    bSprite.setPosition(tileSize+barWidth,2*(tileSize+barWidth));
                    //bSprite.rotate(-90);
                    window.draw(bSprite);
                }

                if(game_state.get_gameBoard(2,2) == 0){
                    bSprite.setPosition(2*(tileSize+barWidth),2*(tileSize+barWidth));
                    //bSprite.rotate(90);
                    window.draw(bSprite);
                }
                   
           
        // reflecting any move that has just happened (check the gameBoard array)
        
        //for set position
        
        switch(game_state.get_clickedRow()){
            case 0:
                playerRow = 0;
                //cout << "player row" << playerRow << endl; 
                break;
            case 1:
                playerRow = tileSize + barWidth;
                //cout << "player row" << playerRow << endl; 
                break;
            case 2:
                playerRow = 2*(tileSize + barWidth);
                //cout << "player row" << playerRow << endl; 
                break;
            default:
                break;
        }
       
        switch(game_state.get_clickedColumn()){
            case 0:
                playerCol = 0;
                //cout << "player col" << playerCol << endl; 
                break;
            case 1:
                playerCol = tileSize + barWidth;
                //cout << "player col" << playerCol << endl; 
                break;
            case 2:
                playerCol = 2*(tileSize + barWidth);
                //cout << "player col" << playerCol << endl; 
                break;
            default:
                break;
        }
        
        //if the player clicks on valid tile
        //if(playerRow >=0 && playerRow <= 2 && playerCol >= 0 && playerCol <= 2){
            //update the board display
            //for X player
        //cout<<"playerrow" << playerRow << endl;
        //cout<<"playerCol" << playerCol << endl;
        
        
        //playerCol and playerRow are swapped because playerCol is the x position whereas playerRow is the y position
            if(game_state.get_turn() == false){
                //now set the flag to true such that O player can play next time
                flag = true;
            
                xSprite.setPosition(playerCol,playerRow);
                window.draw(xSprite);
            }else if(game_state.get_turn() == true){
                
                if(flag == true){
                    oSprite.setPosition(playerCol, playerRow);
                    window.draw(oSprite);
                }
                
            }
        
        //cout << game_state.get_winCode() << endl;
        // Further, if the game is over and one player wins, you must create and draw a rectangle of
        // windowSize width and 10 pixels height to indicate the winning marks
        // The fill of this rectangle should be white
        //cout << "tileSize= " << tileSize << endl;
        switch(game_state.get_winCode()){
            ///cout << "in wincode" << endl;
            //cout<< game_state.get_winCode() << endl;
            
            case 1:
            {sf::RectangleShape winRectangle1(sf::Vector2f(windowSize, 10));
                winRectangle1.setPosition(0, 79);
                //winRectangle.rotate(45);
                window.draw(winRectangle1);
                break;}
            
            case 2:
            {sf::RectangleShape winRectangle2(sf::Vector2f(windowSize, 10));
                winRectangle2.setPosition(0, tileSize + 79 + barWidth);
                //winRectangle.rotate(45);
                window.draw(winRectangle2);
                break;}
            
            case 3:
            {sf::RectangleShape winRectangle3(sf::Vector2f(windowSize, 10));
                winRectangle3.setPosition(0, (barWidth+tileSize)*2 + 79);
                //winRectangle.rotate(45);
                window.draw(winRectangle3);
                break;}
            
            case 4:
            {sf::RectangleShape winRectangle4(sf::Vector2f(10, windowSize));
                winRectangle4.setPosition(79,0);
                //winRectangle.rotate(45);
                window.draw(winRectangle4);
                break;}
            
            case 5:
            {sf::RectangleShape winRectangle5(sf::Vector2f(10, windowSize));
                winRectangle5.setPosition(tileSize+79+barWidth,0);
                //winRectangle.rotate(45);
                window.draw(winRectangle5);
                break;}
            
            case 6:
            {sf::RectangleShape winRectangle6(sf::Vector2f(10, windowSize));
                winRectangle6.setPosition((barWidth+tileSize)*2 + 79,0);
                //winRectangle.rotate(45);
                window.draw(winRectangle6);
                break;}
            
            case 7:
            {sf::RectangleShape winRectangle7(sf::Vector2f(windowSize * 2, 10));
                winRectangle7.setPosition(0 + 10,0);
                winRectangle7.rotate(45);
                window.draw(winRectangle7);
                break;}
            case 8:
            {sf::RectangleShape winRectangle8(sf::Vector2f(3*windowSize + 5, 10));
                winRectangle8.setPosition(-10,3*tileSize + 18);
                winRectangle8.rotate(-45);
                window.draw(winRectangle8);
                break;}
                
              
                
        }

        // ECE244 Student: insert your code here
        
       //Display to the window
       window.display();
      //loop ++; 
    }
    
            
    return EXIT_SUCCESS;
}
