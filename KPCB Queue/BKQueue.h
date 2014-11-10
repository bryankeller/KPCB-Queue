//
//  BKQueue.h
//  KPCB Queue
//
//  Created by Bryan Keller on 10/25/14.
//

#include <stdio.h>

class BKDoublyLinkedListNode
{
    public:
        BKDoublyLinkedListNode *previousNode, *nextNode;
        int nodeValue;
    
        BKDoublyLinkedListNode(int);
};

class BKDoublyCircularlyLinkedList
{
    BKDoublyLinkedListNode *firstNode;
    int listSize;
    
    public:
        BKDoublyCircularlyLinkedList(int);
    
        BKDoublyLinkedListNode* getElementAtIndex(int);
        void addElement(int);
        void removeElementAtIndex(int);
};


class BKQueue
{
    BKDoublyCircularlyLinkedList *queue;
    int queueSize;
    int numberOfItemsInQueue;
    
    public:
        BKQueue(int);
    
        void enqueue(int);
        int dequeue();
};
