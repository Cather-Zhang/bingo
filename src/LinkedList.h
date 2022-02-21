/*
 * LinkedList.h
 *
 *  Created on: Feb 12, 2021
 *      Author: Cather Zhang
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <stdbool.h>
#include "BingoCell.h"

#define bool _Bool
#define false 0
#define true 1




typedef cardCellContent cellCard;

struct LLNode;
typedef struct
{
	struct LLNode* next;
	struct LLNode* prev;
	cellCard* called;
}LLNode;

typedef struct
{
	cellCard* mp;
	LLNode* newQHead;
}backFromDQFIFO;

LLNode* makeEmptyLinkedList();

LLNode* removeFromList(LLNode* hp, cellCard* pP);
void saveCell(LLNode* lp, cellCard* mp);

bool isEmpty(LLNode* lp);
cellCard* dequeueLIFO(LLNode* lp);
backFromDQFIFO* dequeueFIFO(LLNode* lp);
void printHistory(LLNode* cellP);



#endif /* LINKEDLIST_H_ */
