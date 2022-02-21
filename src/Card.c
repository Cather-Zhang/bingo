/*
 * Card.c
 *
 *  Created on: Jan 27, 2020
 *      Author: Therese
 */
#include "Card.h"

void initSpace(int howManyRows)
{
	for(int row = 0; row< howManyRows; row++)
	{
		for(int col = 0; col < howManyRows; col++)
		{
			char letter = (char)(rand() % 26 + 65);
			char digit = (char)(rand() % 10 + 48);
			set(row, col, letter, digit);
		}
	}
}

void set(int row, int col, char letter, char digit) {
	cardCellContent* x = (cardCellContent*) malloc (sizeof(cardCellContent)); //reserve a cardCell on heap
	x->row = row;
	x->col = col;
	x->letter = letter;
	x->digit = digit;
	x->isChecked = false;
	cardCellContent**  thatCellP = theSpaceP + row*5 + col;
	*thatCellP = x; //put its address into bingo card space
}


bool isWin() {   //I did not really use this function because I want the player to see how they won
	bool win = rowWin()||colWin()||diaWin();
	return win;
}

bool rowWin() {
	bool isRow;
	for (int row = 0; row < 5; row++) {
		isRow = true;
		for(int col = 0; col < 5; col++) {
			cardCellContent* cell = (*(theSpaceP + row*5 + col));
			if (!(cell->isChecked)) {
				isRow = false;
			}
		}
		if (isRow) {
			return isRow;
		}
	}
	return isRow;
}


bool colWin() {
	bool isCol;
	for (int col = 0; col < 5; col++) {
		isCol = true;
		for(int row = 0; row < 5; row++) {
			cardCellContent* cell = (*(theSpaceP + row*5 + col));
			if (!(cell->isChecked)) {
				isCol = false;
			}
		}
		if (isCol) {
			return isCol;
		}
	}
	return isCol;
}

bool diaWin() {
	bool leftDia = true;
	bool rightDia = true;
	for (int x = 0; x < 5; x ++) {
		cardCellContent* cellLeft = (*(theSpaceP + 6 * x));
		if (!(cellLeft->isChecked)) {
			leftDia = false;
		}
	}

	for (int y = 0; y < 5; y++) {
			cardCellContent* cellRight = (*(theSpaceP + 4*y + 4));
			if (!(cellRight->isChecked)) {
				rightDia = false;
			}
	}
	return (leftDia||rightDia);
}

void printBoard() {
	for (int i = 0; i < 25; i++) {
		if (((cardCellContent*)(*(theSpaceP + i)))->isChecked) {
			printf("%c%c, ", '>', '<'); fflush(stdout);
		}
		else {
			printf("%c%c, ", ((cardCellContent*)(*(theSpaceP + i)))->letter, ((cardCellContent*)(*(theSpaceP + i)))->digit); fflush(stdout);
		}
		if (i % 5 == 4)
		{
			printf("\n"); fflush(stdout);
		}
	}
	printf("\n"); fflush(stdout);
}


