/*
 * Caller.c
 *
 *  Created on: Feb 10, 2021
 *      Author: Cather Zhang
 */

#include "Caller.h"


void ready(int times) {
	for (int i = 0; i < times; i++) { // execute the loops however many times we put in the argument
		printf("Round %d:\n", i+1);
		char let = (char)(rand() % 26 + 65);
		char dig = (char)(rand() % 10 + 48);
		printf("%c%c called\n", let, dig);
		call(let, dig); //call the random letter and digit we generated
		printBoard();
	}
}
