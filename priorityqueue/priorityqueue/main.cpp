//
//  main.cpp
//  priorityqueue
//
//  Created by Evgeny Tataurov on 24/12/13.
//  Copyright (c) 2013 Evgeny Tataurov. All rights reserved.
//

#include <iostream>
#include "pqueue.h"
#include "Node.h"
using namespace std;

int main(int argc, const char * argv[])
{
    PriorityQueue<string>* queue = new PriorityQueue<string>;
    queue->enqueue("Ten", 10);
    queue->enqueue("Two", 2);
    queue->enqueue("Four", 4);
    cout << queue->toString() << endl;
    cout << queue->dequeue() << endl;
    cout << queue->toString() << endl;
    delete queue;
    return 0;
}

