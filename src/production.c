/*
 * production.c
 *
 *  Created on: Feb 6, 2021
 *      Author: theresesmith
 */

#include "production.h"

cardCellContent** theSpaceP;
LLNode* listOfCalled;

bool production(int argc, char* argv[])
{
	int callTime = 0;
	bool answer = true;

		if(argc <=1) //no interesting information
		{
			puts("Didn't find any arguments.\n");
			fflush(stdout);
			answer = false;
		}
		else //there is interesting information
		{
			printf("Found %d arguments.\n", argc);
			fflush(stdout);
			long aL=-1L;
			int nCalls = -1;

			for(int i = 1; i<argc; i++) //don't want to read argv[0]
			{//argv[i] is a string
				//in this program our arguments are a filename followed by the max of rooms, followed by max of treasure
				switch(i)
				{
				case 1:

					//this is the number of calls

					aL= strtol(argv[i], NULL, 10);
					nCalls = (int) aL;
					if(nCalls <0)
					{
						answer = false;
					}
					printf("Number of calls is %d\n",nCalls);fflush(stdout);

					callTime = nCalls;
					break;

				default:
					puts("Unexpected argument count."); fflush(stdout);
					answer = false;
					break;
				}//end of switch
			}//end of for loop on argument count
			puts("after reading arguments\n"); fflush(stdout);


		}//end of command line arguments

		//obtain space for bingo card

	    initSpace(5); fflush(stdout); // initializes the board to random letter and digit
	    puts("Your original bingo card:");
	    printBoard();

	    if (callTime != 0){
	    ready(callTime);
	    }

		printHistory(listOfCalled);

		puts("\nHere is your final bingo card:");
		printBoard();

	    if (rowWin()) {
	    	puts("Congratulations, you won by row!");
	    }
	    else if (colWin()) {
	    	    	puts("Congratulations, you won by column!");
	    	    }
	    else if (diaWin()) {
	    	    	puts("Congratulations, you won by diagonal!");
	    	    }
	    else{
	    	puts("Sorry, you didn't win :(");
	    }
		return answer;
}


 void call(char letter, char digit) {
	bool isInThere = false;
	cardCellContent* calledCell;
	for (int num = 0; num < 25; num++) {
		calledCell = (*(theSpaceP + num));
		if ((letter == (calledCell->letter)) && (digit == (calledCell->digit))) {
			isInThere = true;            // if the board contains, change value to true
			calledCell->isChecked = true;
			saveCell(listOfCalled,calledCell);
		}
	}
	if (!isInThere) {
		//if the board does not contain called letter and number, create a new cardCellContent and save it to the linked list
		cardCellContent* notCalled = (cardCellContent*) malloc(sizeof(cardCellContent));
				notCalled->col = -1;
				notCalled->row = -1;
				notCalled->digit = digit;
				notCalled->letter = letter;
				notCalled->isChecked = false;
				saveCell(listOfCalled,notCalled);
			}
	}





