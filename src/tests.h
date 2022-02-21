/*
 * tests.h
 *
 *  Created on: Feb 6, 2021
 *      Author: theresesmith
 */

#ifndef TESTS_H_
#define TESTS_H_

#include <stdbool.h>
#include "production.h"
#include "Caller.h"
#include "Card.h"
#include "BingoCell.h"
#include "theSpaceP.h"
#include "LinkedList.h"

bool tests();

bool testInitSpace();
bool testSet();
bool testSetCorner();
bool testSetMiddle();
bool testSetLast();

bool testCall();
bool testCallOne();
bool testCallTwo();
bool testCallThree();

bool testRow();
bool testRowRepeated();
bool testRowNonRepeatedTrue();
bool testRowNonRepeatedFalse();

bool testCol();
bool testColRepeated();
bool testColNonRepeatedTrue();
bool testColNonRepeatedFalse();

bool testDia();
bool testDiaRepeatedLeft();
bool testDiaRepeatedRight();
bool testDiaNonRepeatedTrueLeft();
bool testDiaNonRepeatedTrueRight();
bool testDiaNonRepeatedFalseLeft();
bool testDiaNonRepeatedFalseRight();

bool testDidNotWin();
bool testSaveCell();
bool testPrintBoard();
bool testReady();

bool testPrintEmptyHistory();
bool testPrintNonEmptyHistory();

#endif /* TESTS_H_ */
