/*
 * tests.c
 *
 *  Created on: Feb 6, 2021
 *      Author: theresesmith
 */

#include "tests.h"

bool tests()
{
	bool ok = true;
	bool ok0 = testInitSpace();
	bool ok1 = testSet();
	bool ok2 = testCall();
	bool ok3 = testRow();
	bool ok4 = testCol();
	bool ok5 = testDia();
	bool ok6 = testDidNotWin();
	bool ok7 = testSaveCell();
	bool ok8 = testPrintBoard();
	bool ok9 = testReady();
	bool ok10 = testPrintEmptyHistory();
	bool ok11 = testPrintNonEmptyHistory();

	ok = ok0 && ok1 && ok2 && ok3 && ok4 && ok5 && ok6 && ok7 && ok8 && ok9 && ok10 && ok11;
	return ok;
}

bool testInitSpace() {
	initSpace(5);
	printBoard();
	puts("testInitSpace passed!");
	return true;
}

bool testSet() {
	bool okSet = true;
	bool ok1 = testSetCorner();
	bool ok2 = testSetMiddle();
	bool ok3 = testSetLast();
	okSet = ok1 && ok2 && ok3;
		return okSet;
}

bool testSetCorner() {
	initSpace(5);
	set(0, 0, 'A', '1');
	bool answer = false;
	cardCellContent* cellP = *theSpaceP;
	if ((cellP->letter == 'A') && (cellP->digit == '1')) {
		answer = true;
		puts("testSetCorner passed!");
	}
	else {
		puts("testSetCorner failed!");
	}
	return answer;
}

bool testSetMiddle() {
	initSpace(5);
	set(2, 3, 'G', '9');
	bool answer = false;
	cardCellContent* cellP = *(theSpaceP + 2 * 5 + 3);
	if ((cellP->letter == 'G') && (cellP->digit == '9')) {
		answer = true;
		puts("testSetMiddle passed!");
	}
	else {
		puts("testSetMiddle failed!");
	}
	return answer;
}

bool testSetLast() {
	initSpace(5);
	set(4, 4, 'R', '5');
	bool answer = false;
	cardCellContent* cellP = *(theSpaceP + 4 * 5 + 4);
	if ((cellP->letter == 'R') && (cellP->digit == '5')) {
		answer = true;
		puts("testSetLast passed!");
	}
	else {
		puts("testSetLast failed!");
	}
	return answer;
}

bool testCall() {
	bool ok = true;
	bool ok1 = testCallOne();
	bool ok2 = testCallTwo();
	bool ok3 = testCallThree();
	ok = ok1 & ok2 & ok3;
	return ok;
}

bool testCallOne() {
	initSpace(5);
	set(2, 3, 'G', '9');
	call('G','9');
	bool answer = false;
		cardCellContent* cellP = *(theSpaceP + 2 * 5 + 3);
		if (cellP->isChecked) {
			answer = true;
			puts("testCallOne passed!");
		}
		else {
			puts("testCallOne failed!");
		}
		return answer;
}

bool testCallTwo() {
	initSpace(5);
	set(1, 2, 'S', '4');
	call('S','4');
	bool answer = false;
		cardCellContent* cellP = *(theSpaceP + 1 * 5 + 2);
		if (cellP->isChecked) {
			answer = true;
			puts("testCallTwo passed!");
		}
		else {
			puts("testCallTwo failed!");
		}
		return answer;
}

bool testCallThree() {
	initSpace(5);
	set(0, 0, 'K', '2');
	call('K','2');
	bool answer = false;
		cardCellContent* cellP = *theSpaceP;
		if (cellP->isChecked) {
			answer = true;
			puts("testCallThree passed!");
		}
		else {
			puts("testCallThree failed!");
		}
		return answer;
}

bool testRow() {
	bool ok = true;
	bool ok1 = testRowRepeated();
	bool ok2 = testRowNonRepeatedTrue();
	bool ok3 = testRowNonRepeatedFalse();
	ok = ok1 & ok2 & ok3;
	return ok;
}

bool testRowRepeated() {
	initSpace(5);
	set(0, 0, 'K', '2');
	set(0, 1, 'K', '2');
	set(0, 2, 'K', '2');
	set(0, 3, 'K', '2');
	set(0, 4, 'K', '2');
	call('K','2');
	bool answer = false;

	if (rowWin()) {
		answer = true;
		puts("testRowRepeated passed!");
	}
	else {
		puts("testRowRepeated failed!");
	}
	return answer;
}

bool testRowNonRepeatedTrue() {
	initSpace(5);
	set(2, 0, 'A', '5');
	set(2, 1, 'D', '3');
	set(2, 2, 'G', '7');
	set(2, 3, 'O', '2');
	set(2, 4, 'Q', '5');

	call('G', '7');
	call('D', '3');
	call('Q', '5');
	call('O', '2');
	call('A', '5');

	bool answer = false;
	if (rowWin()) {
		answer = true;
		puts("testRowNonRepeatedTrue passed!");
	}
	else {
		puts("testRowNonRepeatedTrue failed!");
	}
	return answer;
}

bool testRowNonRepeatedFalse() {
	initSpace(5);
	set(2, 0, 'A', '5');
	set(2, 1, 'D', '3');
	set(2, 2, 'G', '7');
	set(2, 3, 'O', '2');
	set(2, 4, 'Q', '7');

	call('G', '7');
	call('D', '3');
	call('Q', '7');
	call('O', '2');
	call('A', '5');

	bool answer = false;
	if (rowWin()) {
		answer = true;
		puts("testRowNonRepeatedFalse passed!");
	}
	else {
		puts("testRowNonRepeatedFalse failed!");
	}
	return answer;
}

bool testCol() {
	bool ok = true;
	bool ok1 = testColRepeated();
	bool ok2 = testColNonRepeatedTrue();
	bool ok3 = testColNonRepeatedFalse();
	ok = ok1 & ok2 & ok3;
	return ok;
}

bool testColRepeated() {
	initSpace(5);
	set(0, 2, 'K', '2');
	set(1, 2, 'K', '2');
	set(2, 2, 'K', '2');
	set(3, 2, 'K', '2');
	set(4, 2, 'K', '2');
	call('K','2');
	bool answer = false;

	if (colWin()) {
		answer = true;
		puts("testColRepeated passed!");
	}
	else {
		puts("testColRepeated failed!");
	}
	return answer;
}

bool testColNonRepeatedTrue() {
	initSpace(5);
	set(0, 4, 'A', '5');
	set(1, 4, 'D', '3');
	set(2, 4, 'G', '7');
	set(3, 4, 'O', '2');
	set(4, 4, 'Q', '5');

	call('G', '7');
	call('D', '3');
	call('Q', '5');
	call('O', '2');
	call('A', '5');

	bool answer = false;
	if (colWin()) {
		answer = true;
		puts("testColNonRepeatedTrue passed!");
	}
	else {
		puts("testColNonRepeatedTrue failed!");
	}
	return answer;
}

bool testColNonRepeatedFalse() {
	initSpace(5);
	set(0, 0, 'A', '5');
	set(1, 0, 'D', '3');
	set(2, 0, 'G', '7');
	set(3, 0, 'O', '2');
	set(4, 0, 'Q', '7');

	call('G', '7');
	call('D', '3');
	call('Q', '7');
	call('O', '2');
	call('A', '5');

	bool answer = false;
	if (colWin()) {
		answer = true;
		puts("testColNonRepeatedFalse passed!");
	}
	else {
		puts("testColNonRepeatedFalse failed!");
	}
	return answer;
}

bool testDia() {
	bool ok = true;
	bool ok1 = testDiaRepeatedLeft();
	bool ok2 = testDiaRepeatedRight();
	bool ok3 = testDiaNonRepeatedTrueLeft();
	bool ok4 = testDiaNonRepeatedTrueRight();
	bool ok5 = testDiaNonRepeatedFalseLeft();
	bool ok6 = testDiaNonRepeatedFalseRight();
	ok = ok1 & ok2 & ok3 & ok4 & ok5 & ok6;
	return ok;
}

bool testDiaRepeatedLeft() {
	initSpace(5);
	set(0, 0, 'K', '2');
	set(1, 1, 'K', '2');
	set(2, 2, 'K', '2');
	set(3, 3, 'K', '2');
	set(4, 4, 'K', '2');
	call('K','2');
	bool answer = false;

	if (diaWin()) {
		answer = true;
		puts("testDiaRepeatedLeft passed!");
	}
	else {
		puts("testDiaRepeatedLeft failed!");
	}
	return answer;
}

bool testDiaRepeatedRight() {
	initSpace(5);
	set(0, 4, 'K', '2');
	set(1, 3, 'K', '2');
	set(2, 2, 'K', '2');
	set(3, 1, 'K', '2');
	set(4, 0, 'K', '2');
	call('K','2');
	bool answer = false;

	if (diaWin()) {
		answer = true;
		puts("testDiaRepeatedRight passed!");
	}
	else {
		puts("testDiaRepeatedRight failed!");
	}
	return answer;
}

bool testDiaNonRepeatedTrueLeft() {
	initSpace(5);
	set(0, 0, 'A', '5');
	set(1, 1, 'D', '3');
	set(2, 2, 'G', '7');
	set(3, 3, 'O', '2');
	set(4, 4, 'Q', '5');

	call('G', '7');
	call('D', '3');
	call('Q', '5');
	call('O', '2');
	call('A', '5');

	bool answer = false;
	if (diaWin()) {
		answer = true;
		puts("testDiaNonRepeatedTrueLeft passed!");
	}
	else {
		puts("testDiaNonRepeatedTrueLeft failed!");
	}
	return answer;
}

bool testDiaNonRepeatedTrueRight() {
	initSpace(5);
	set(0, 4, 'A', '5');
	set(1, 3, 'D', '3');
	set(2, 2, 'G', '7');
	set(3, 1, 'O', '2');
	set(4, 0, 'Q', '5');

	call('G', '7');
	call('D', '3');
	call('Q', '5');
	call('O', '2');
	call('A', '5');

	bool answer = false;
	if (diaWin()) {
		answer = true;
		puts("testDiaNonRepeatedTrueRight passed!");
	}
	else {
		puts("testDiaNonRepeatedTrueRight failed!");
	}
	return answer;
}

bool testDiaNonRepeatedFalseLeft() {
	initSpace(5);
	set(0, 0, 'A', '5');
	set(1, 1, 'D', '3');
	set(2, 2, 'G', '7');
	set(3, 3, 'O', '2');
	set(4, 4, 'Q', '7');

	call('G', '7');
	call('D', '3');
	call('Q', '7');
	call('O', '2');
	call('A', '5');

	bool answer = false;
	if (diaWin()) {
		answer = true;
		puts("testDiaNonRepeatedFalseLeft passed!");
	}
	else {
		puts("testDiaNonRepeatedFalseLeft failed!");
	}
	return answer;
}

bool testDiaNonRepeatedFalseRight() {
	initSpace(5);
	set(0, 4, 'A', '5');
	set(1, 3, 'D', '3');
	set(2, 2, 'G', '7');
	set(3, 1, 'O', '2');
	set(4, 0, 'Q', '7');

	call('G', '7');
	call('D', '3');
	call('Q', '7');
	call('O', '2');
	call('A', '5');

	bool answer = false;
	if (diaWin()) {
		answer = true;
		puts("testDiaNonRepeatedFalseRight passed!");
	}
	else {
		puts("testDiaNonRepeatedFalseRight failed!");
	}
	return answer;
}

bool testDidNotWin() {
	initSpace(5);
	bool answer = rowWin() || colWin() || diaWin();
	if (!answer){
		puts("testDidNotWin passed!");
		return true;
	}
	else {
		puts("testDidNotWin failed!");
		return false;
	}
}

bool testSaveCell(){
	cardCellContent* cell1 = (cardCellContent*) malloc(sizeof(cardCellContent));
	cell1->col = 2;
	cell1->row = 3;
	cell1->letter = 'D';
	cell1->digit = '2';
	cell1->isChecked = false;
	LLNode* list = (LLNode*) makeEmptyLinkedList();
	saveCell(list, cell1);
	if ((list->called->letter == 'D') && (list->called->digit == '2')){
		puts("testSaveCell passed!");
		return true;
	}
	else {
		puts("testSaveCell failed!");
		return false;
	}
}

bool testPrintBoard() {
	initSpace(5);
	set(0, 0, 'A', '1');
	printBoard();
	puts("testPrintBoard passed!");
	return true;
}

bool testReady() {
	initSpace(5);
	printBoard();
	ready(1);
	puts("testReady passed!");
	return true;
}

bool testPrintEmptyHistory() {
	LLNode* emptyList = makeEmptyLinkedList();
	printHistory(emptyList);
	puts("testPrintEmptyHistory passed!");
	return true;
}

bool testPrintNonEmptyHistory() {
	LLNode* newList = makeEmptyLinkedList();
	cardCellContent* cell1 = (cardCellContent*) malloc(sizeof(cardCellContent));
		cell1->col = 2;
		cell1->row = 3;
		cell1->letter = 'D';
		cell1->digit = '2';
		cell1->isChecked = false;
	saveCell(newList, cell1);
	printHistory(newList);
	puts("testPrintNonEmptyHistory passed!");
	return true;
}





