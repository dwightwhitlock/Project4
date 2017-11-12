#include "PriorityQueue.h"
#include <iostream>
#include <string>

using namespace std;

template <class ItemType>
PriorityQue<ItemType>::PriorityQue() 
// Initalizes the list with default max length 500
{
 	ListData = NULL;
 	Length=0;
}

template <class ItemType>
PriorityQue<ItemType>::~PriorityQue()
// Deletes the array
{
   Length=0;
}

template <class ItemType>
void PriorityQue<ItemType>::Enqueue(ItemType newItem, int priority)
// Function: Adds newItem to the rear of the queue.
// Pre: If (queue is full) FullQueue exception is thrown
//       else newItem is at rear of queue.
{
	if(IsFull()) {throw FullQueue();} //Catch fulllist

	QueueNode<ItemType>* newNode = new QueueNode<ItemType>;
	newNode->info = newItem;
	newNode->priority = priority;

	if(Length == 0) //If list is empty
	{  
		ListData = newNode;
		newNode->next = NULL;
		Length++;
	}
	else if(priority < ListData->priority)
	{
		QueueNode<ItemType>* second;
	    second = ListData;
	    ListData = newNode;
	   	ListData->next = second;
	    Length++;
	}
	else 
	{
		QueueNode<ItemType>* tempPntr = ListData;
		while(tempPntr->next != NULL){
			if(priority >= tempPntr->next->priority)
				tempPntr = tempPntr->next;
			else
				break; 
		}
		
		if(tempPntr->next == NULL)
		{
    		tempPntr->next = newNode;
    		newNode->next = NULL;
    		Length++;
		}
		else
		{
			QueueNode<ItemType>* cur;
    		QueueNode<ItemType>* nxtNode;
    		nxtNode = tempPntr->next;
    		cur = tempPntr;
    		tempPntr = newNode;
    		tempPntr->next = nxtNode;
    		cur->next = tempPntr;
    		Length++;
		}	
	}	

}

template <class ItemType>
void PriorityQue<ItemType>::Dequeue(ItemType& item)
// Function: Removes front item from the queue and returns it in item.
// Post: If (queue is empty) EmptyQueue exception is thrown and
//       item is undefined else front element has been removed
//       from queue and item is a copy of removed element.
{
	if(IsEmpty()) {throw EmptyQueue();}
	QueueNode<ItemType>* nxtPntr = ListData->next;

	if(Length == 1)
	{
		item = ListData->info;
		delete ListData;
		Length--;
	}
	else
	{
		item = ListData->info;
		delete ListData;
		ListData = nxtPntr;
		Length--;
	}
}

template <class ItemType>
ItemType PriorityQue<ItemType>::Peek()
// Returns the value of the most urgent item in the queue
// Calling peek on an empty queue throws an exception
{
	return ListData->info;
}

template <class ItemType>
int PriorityQue<ItemType>::PeekPriority()
// Returns the priority of the most urgent item in the queue
// Calling peek on an empty queue throws an exception.
{
	return ListData->priority;
}

template <class ItemType>
void PriorityQue<ItemType>::MakeEmpty()
// Function: Initializes the queue to an empty state.
// Post: Queue is empty.
{
	QueueNode<ItemType>* ptr = ListData;
 	while(ptr != NULL)
 	{	
 		QueueNode<ItemType>* old = ptr;
 		ptr = ptr->next;
 		delete old;
 	}
 	Length = 0;
}

template <class ItemType>
int PriorityQue<ItemType>::GetLength()
// Returns the number of elements currently in the queue
{
	return Length;
}

template <class ItemType>
void PriorityQue<ItemType>::PrintQueue(std::ofstream& out)
// Returns the number of elements currently in the queue
{
	if(Length == 0) {
		return;
	}

	QueueNode<ItemType>* cur = ListData; 
	out << "Queue: ";

	while(cur->next != NULL)
	{
		out << cur->info << " ";
		cur = cur->next;
	}
	out << cur->info << " ";
	out << endl;
}

template <class ItemType>
bool PriorityQue<ItemType>::IsEmpty() const
// Function: Determines whether the queue is empty.
// Post: Function value = (queue is empty)
{
	if(Length == -1 || Length == 0) {return true;}
	else{return false;}
}

template <class ItemType>
bool PriorityQue<ItemType>::IsFull() const
// Function: Determines whether the queue is full.
// Post: Function value = (queue is full)
{
	bool IsFull = false;
	try {
		QueueNode<ItemType>* testNode = new QueueNode<ItemType>;
		delete testNode;
	}
	catch(const std::bad_alloc& e) {
		IsFull = true;
	}
	return IsFull;
}
