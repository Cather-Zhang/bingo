/*
 ============================================================================
 Name        : ReferenceHW2bingo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "tests.h"
#include "production.h"
#include "BaohuiZhang.h"
#include "theSpaceP.h"
#include "BingoCell.h"
#include "LinkedList.h"
#include <time.h>



int main(int argc, char* argv[]) {
	srand((unsigned)time(NULL));
	puts("!!!Hello World, let's do HW2!!!"); /* prints !!!Hello World!!! */
	theSpaceP = (cardCellContent**) malloc(5*5*sizeof(cardCellContent*));  // we reserve space in memory so that tests can use that memory as well
    listOfCalled = (LLNode*) makeEmptyLinkedList(); // we initializes list too for tests
	if(tests())
	{
		puts("The tests all passed."); // YAY!!
		listOfCalled = (LLNode*) makeEmptyLinkedList(); // we reset the list
		production(argc, argv);
	}
	else
	{
		puts("Not all tests passed; better luck next time"); //that would suck :(
	}
	return EXIT_SUCCESS;
}
