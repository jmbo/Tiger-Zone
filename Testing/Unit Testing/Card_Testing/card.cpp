#include <iostream>
#include "card.h"
using namespace std;


Card::Card() {
    id = -1;            // set id = -1, this card is an instance of open space on the board
   
    top = 'n';         // filler cards do not have true tblr values. Sides = "null".
    bot = 'n';
    left = 'n';
    right = 'n';

	a_top = 'o';		// filler sides are open
	a_bot = 'o';
	a_left = 'o';
	a_right = 'o';

    isfiller = true;	// Card initialized without id is a filler card
}

Card::Card(int id) {
    this->id = id;          // set this cards id
    assignSides(id);        // set default sides corresponding to this card type
    isfiller = false;		// Card initialized with id is a real card
}

void Card::rotate() {   // rotate card 90 degrees clockwise
    char temp = right;
    right = top;
    top = left;
    left = bot;
    bot = temp;
}

void Card::printCard() {
    cout << "Card id = " << id << endl;
    // ---------------------------------
    cout << " "  << top << " " << endl;
    cout << left << " " << right << endl;
    cout << " "  << bot << " " << endl;
}


// Kurt -probably going to have to change this if he doesn't give us a list of cards
// Great for right now though, let's keep it
void Card::assignSides(int id) {
    
    // mark top of card depending on card id
    if(id == 17 || id == 2 || id == 1 || 
    	id == 23 || id == 10 || id == 13) {          				// card with field top
        top = 'f';
    }
    else if (id == 7 || id == 16) {                  				// card with road top
        top = 'r';
    }
    else {                                           				// card with city top
        top = 'c';
    }
    
    // mark right of card depending on card id
    if(id == 18 || id == 5 || id == 19 
    	|| id == 9 || id == 20 || id == 1 || id == 23) {        	// card with city right
        right = 'c';
    }
    else if (id == 15 || id == 22 || 
    			id == 14 || id == 0 || id == 3) {                   // card with road right
        right = 'r';
    }
    else {                                                          // card with field right
        right = 'f';
    }
    
    // mark bot of card depending on card id
    if(id == 18 || id == 6) {                                       // card with city bot
        bot = 'c';
    }
    else if (id == 17 || id == 5 || id == 19 || id == 12 || id == 21 || id == 1
             || id == 23 || id == 4 || id == 8 || id == 3) {        // card with field bot
        bot = 'f';
    }
    else {                                                          // card with road bot
        bot = 'r';
    }
    
    // mark left of card depending on card id
    if(id == 18 || id == 5 || id == 19 || id == 9 
    	|| id == 20 || id == 12 || id == 21 || id == 15 
    	|| id == 22 || id == 1 || id == 23 || id == 4) {          	// card with city left
        left = 'c';
    }
    else if (id == 11 || id == 0 || id == 3 || id == 10 
    			|| id == 13 || id == 16) {    						// card with road left
        left = 'r';
    }
    else {                                                          // card with field left
        left = 'f';
    }
    
   	a_top = 'n';		// filler sides do not exist
	a_bot = 'n';
	a_left = 'n';
	a_right = 'n';
}

char Card::getTop() {
    return top;
}
char Card::getBot() {
    return bot;
}
char Card::getRight() {
    return right;
}
char Card::getLeft() {
    return left;
}
int Card::getId() {
    return id;
}

