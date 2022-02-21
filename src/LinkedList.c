/*
 * LinkedList.c
 *
 *  Created on: Feb 12, 2021
 *      Author: Cather Zhang
 */

#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>

bool isEmpty(LLNode* lp)
{
	bool ans = false;
	if(lp->called == (cellCard*)0)
	{
		ans = true;
	}
	return ans;
}

LLNode* makeEmptyLinkedList()
{
	LLNode* lp = (LLNode*) malloc(sizeof(LLNode));
	lp->next = (struct LLNode*)0;
	lp->prev = (struct LLNode*)0;
	lp->called = (cellCard*)0;

	return lp;
}

void saveCell(LLNode* lp, cellCard* mp)
{
	//if the list is empty, then make payP be mp
	//else traverse the list,
	//make a new list element
	//put mp in that
	//attach the new list element to the existing list
	if(isEmpty(lp))
	{
		lp->called = mp;
	}
	else
	{
		LLNode* temp = lp;
		while(temp->next)
		{
			temp=(LLNode*)temp->next;
		}
		//now temp points to the last element

		//make a new element, attach mp to it, wire up the new element
		LLNode* newList = makeEmptyLinkedList();
		newList->called = mp;
		temp->next = (struct LLNode*)newList;

	}
}

void printHistory(LLNode* cellP)
{
    puts("Printing history");
    if(cellP->called ==(cellCard*)0)
    {
         puts("Empty list");
    }
    else
    {
	    //traverse the list, printing as we go

        LLNode* temp = cellP;
        while(temp) //when temp is not null
        {
        	if (temp->called->isChecked) {
            printf("%c%c is called, found on row %d, column %d.\n", temp->called->letter, temp->called->digit, temp->called->row + 1, temp->called->col + 1);
        	}
        	else {
        		printf("%c%c is called, not found.\n", temp->called->letter, temp->called->digit);
        	}
            temp=(LLNode*) (temp->next); // to the next node
        }


    }
}

LLNode* removeFromList(LLNode* hP, cellCard* pP)
{
	LLNode* retHead = hP;//only changes if first element gets removed
	//find the payload
	//use the structure of a list, namely, list is empty or element followed by list
	if(isEmpty(hP))
	{
		//nothing to do
	}
	else
	{
		//puts("list is not empty");fflush(stdout);
		LLNode* altHead = (LLNode*)hP->next;
		//find the item, if it is there
		LLNode* temp = hP;
		bool done = false;
		while((!done) && temp->next)
		{
			//are we there yet?
			if(temp->called == pP)
			{
				done=true;
				//puts("found it 1");fflush(stdout);
			}
			else
			{
				temp=(LLNode*)temp->next;
			}
		}
		//either we are pointing to the correct element, or we are at the end, or both
		if((temp->called) == pP)
		{
			//puts("found it 2");fflush(stdout);
			//found it, remove it
			//are we at the beginning?
			if(temp == hP)
			{  //found it at the first element
				//puts("found it at first element");fflush(stdout);
				//is the list of length 1?
				if(!(temp->next))
				{//if there is no next
					//remove payload, return empty list
					hP->called = (cellCard*)0;
				}
				else //not of length 1
				{ //not freeing the Payload, but freeing the first list element
					//puts("found it at first element of list with length > 1");fflush(stdout);
					//free(hP);
					retHead = altHead;
				}
			}
			else //not found at first location in list
			{
				//puts("found it not at first element");fflush(stdout);
				//save the linkages
				//found element has a next
				//found element has a prev
				//participant before has a next
				//participant after has a prev
				LLNode* prevPart = (LLNode*) temp->prev;//non-zero because not at first element
				LLNode* nextPart = (LLNode*) temp->next;//could be zero, if found at last element
				prevPart->next = (struct LLNode*) nextPart;//RHS is 0 if at end
				//puts("after setting the next of the previous");fflush(stdout);
               // printf("Next is %p, %d\n", nextPart, (bool)nextPart);fflush(stdout);
				if((bool)nextPart)//don't need guarded block if element found at end of list
				{
					//puts("before setting the previous of the next");fflush(stdout);
					nextPart->prev = (struct LLNode*) prevPart;

				}
				//puts("after handling the  previous of the next");fflush(stdout);
			}//end of not found at first location
		}//end of found it
		else
		{
			//didn't find it
			//puts("did not find it");fflush(stdout);
			//nothing to do
		}//end did not find it
	}
	//printf("Returning %p\n", retHead); fflush(stdout);
	return retHead;
}

