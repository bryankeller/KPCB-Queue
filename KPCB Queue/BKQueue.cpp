//
//  BKQueue.cpp
//  KPCB Queue
//
//  Created by Bryan Keller on 10/25/14.
//
//  Implementation done via a doubly, circularly linked list to algorithmic performance (CPU time).
//  Adding an element is O(1). Removing an element is O(1). Indexing is O(n).
//  Note: My removeElement function requires finding the destination index, so it's technically O(n),
//  but the actual act of removing an element just involves changing a few pointer values in the linked list node.
//

#include "BKQueue.h"
#include <stdlib.h>

BKDoublyLinkedListNode::BKDoublyLinkedListNode(int value)
{
    nodeValue = value;
}

BKDoublyCircularlyLinkedList::BKDoublyCircularlyLinkedList(int size)
{
    listSize = size;
}

BKDoublyLinkedListNode* BKDoublyCircularlyLinkedList::getElementAtIndex(int index)
{
    if(index >= listSize || index < 0)
    {
        printf("Index %i out of bounds. List size is %i", index, listSize);
        return NULL;
    }
    else
    {
        BKDoublyLinkedListNode *targetNode = firstNode;
        for(int i = 0; i < index; i++)
        {
            targetNode = targetNode->nextNode;
        }
        
        return targetNode;
    }
}

void BKDoublyCircularlyLinkedList::addElement(int value)
{
    BKDoublyLinkedListNode *node = new BKDoublyLinkedListNode(value);
    
    if(firstNode == NULL)
    {
        node->nextNode = node;
        node->previousNode = node;
        firstNode = node;
    }
    else
    {
        firstNode->previousNode->nextNode = node;
        
        node->nextNode = firstNode;
        node->previousNode = firstNode->previousNode;
        
        firstNode->previousNode = node;
    }
}

void BKDoublyCircularlyLinkedList::removeElementAtIndex(int index)
{
    if(index >= listSize || index < 0)
    {
        printf("Index %i out of bounds. List size is %i", index, listSize);
    }
    else
    {
        BKDoublyLinkedListNode *nodeToRemove = getElementAtIndex(index);
        
        nodeToRemove->nextNode->previousNode = nodeToRemove->previousNode;
        nodeToRemove->previousNode->nextNode = nodeToRemove->nextNode;
        
        if(index == 0)
        {
            firstNode = nodeToRemove->nextNode;
        }
        
        delete(nodeToRemove);
        nodeToRemove = NULL;
    }
}


BKQueue::BKQueue(int size)
{
    queueSize = size;
    queue = new BKDoublyCircularlyLinkedList(queueSize);
    
    numberOfItemsInQueue = 0;
    
}

void BKQueue::enqueue(int element)
{
    if(numberOfItemsInQueue < queueSize)
    {
        queue->addElement(element);
        numberOfItemsInQueue++;
    }
    else
    {
        printf("Error: Could not enqueue element with value = %i because the queue is full.\n", element);
    }
}

int BKQueue::dequeue()
{
    if(numberOfItemsInQueue > 0)
    {
        int element = queue->getElementAtIndex(0)->nodeValue;
        queue->removeElementAtIndex(0);
        numberOfItemsInQueue--;
        
        return element;
    }
    else
    {
        printf("Error: Could not dequeue element because the queue is empty.\n");
        return NULL;
    }
}