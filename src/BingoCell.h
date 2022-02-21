/*
 * BingoCell.h
 *
 *  Created on: Feb 10, 2021
 *      Author: Cather Zhang
 */

#ifndef BINGOCELL_H_
#define BINGOCELL_H_
#include <stdbool.h>

typedef struct {
	int row;
	int col;
	char letter;
	char digit;
	bool isChecked; //so that we can detect if a cell has been checked or not
}cardCellContent;



#endif /* BINGOCELL_H_ */
