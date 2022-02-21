/*
 * Card.h
 *
 *  Created on: Jan 27, 2020
 *      Author: Therese
 */

#ifndef CARD_H_
#define CARD_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "BingoCell.h"
#include "theSpaceP.h"
#include "production.h"

void initSpace(int);
bool check(char letter, char digit);
bool isWin();
bool rowWin();
bool colWin();
bool diaWin();
void printBoard();
void set(int row, int col, char letter, char digit);

#endif /* CARD_H_ */
