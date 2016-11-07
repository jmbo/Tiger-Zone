#include "main.h"
#include "card.h"

Card::card(int x) {
	id = x;
	avail_top = '0';
	avail_bot = '0';
	avail_right = '0';
	avail_left = '0';
}

void Card::assignsides(char t, char b, char l, char r) {
	top = t;
	bot = b;
	left = l;
	right = r;
}

void Card::rotatecw() {
	char temp = right;
	right = top;
	top = left;
	left = bot;
	bot = temp;
}