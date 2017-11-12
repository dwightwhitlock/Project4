#include <iostream>
#include <string>

class FullQueue {};  

class EmptyQueue {}; 

template <class ItemType>
struct QueueNode
{
    ItemType info;
    int priority;
    QueueNode<ItemType> * next;
};

template <class ItemType>
class PriorityQue
{
public: 
    PriorityQue();
    // Class constructor.
    
   ~PriorityQue();
    // Class destructor.

    void Enqueue(ItemType newItem, int priority);
    // Function: Adds newItem to the rear of the queue.
    // Post: If (queue is full) FullQueue exception is thrown
    //       else newItem is at rear of queue.

    void Dequeue(ItemType& item);
    // Function: Removes front item from the queue and returns it   
    //in item.
    // Post: If (queue is empty) EmptyQueue exception is thrown
    //       and item is undefined
    //       else front element has been removed from queue and
    //       item is a copy of removed element.

    ItemType Peek();
    // Returns the value of the most urgent item in the queue without removing it 
    // from the queue. Calling peek on an empty queue throws an exception

    int PeekPriority();
    // Returns the priority of the most urgent item in the queue without removing it from
    // the queue. Calling peek on an empty queue throws an exception.

    void MakeEmpty();
    // Function: Initializes the queue to an empty state.
    // Post: Queue is empty.

    int GetLength();
    // Returns the number of elements currently in the queue

    void PrintQueue(std::ofstream& out);
    // Returns the number of elements currently in the queue
   
    bool IsEmpty() const;
    // Function: Determines whether the queue is empty.
    // Post: Function value = (queue is empty)
   
    bool IsFull() const;
    // Function: Determines whether the queue is full.
    // Post: Function value = (queue is full

private:
    QueueNode<ItemType>* ListData;
    int Length = -1;
};