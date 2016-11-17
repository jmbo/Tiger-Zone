#ifndef board_h
#define board_h

#include <stdio.h>
#include "card.h"
#include "deck.h"


// Kurt - These values should not be hardcoded, and should rely on maximum card count
#define ROWS  11 //MAXCARDS*2+1
#define COLS  11 //MAXCARDS*2+1

class Board {
    
    public:
        Board();                           					// board constructor
        void printBoard();                  				// print the state of the board
        bool checkIfFits(int i, int j, Card * card );    	// check if a given card fits at a given location
        void markavail(int xcoord, int ycoord, Card* card); // Marks available tile
        bool placeCard(int i, int j, Card * card);      	// place a card onto the board
        Deck * getDeck();
    
    private:
        Card ** board;                    // will point to 2D array of Cards a.k.a. the board
};





#endif /* board_hpp */
