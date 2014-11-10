//
//  main.cpp
//  KPCB Queue
//
//  Created by Bryan Keller on 10/26/14.
//
//  Test program for my implementation of the bounded queue. It enqueues <queueSize> element, the dequeues them.
//  Out of bounds errors are handles gracefully. Change queueSize to quickly change how many enqueue and dequeue operations are run.

#include "BKQueue.h"

#define queueSize 100000

int main(int argc, const char * argv[])
{
    BKQueue *queue = new BKQueue(queueSize);

    for(int i = 1; i <= queueSize; i++)
    {
        queue->enqueue(i);
    }
    
    for(int i = 0; i < queueSize; i++)
    {
        int element = queue->dequeue();
        printf("\nDequed %i", element);
    }
    
    delete(queue);
    
    return 0;
}
