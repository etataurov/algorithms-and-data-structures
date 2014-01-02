//
//  pqueue.h
//  priorityqueue
//
//  Created by Evgeny Tataurov on 24/12/13.
//  Copyright (c) 2013 Evgeny Tataurov. All rights reserved.
//

#ifndef __priorityqueue__pqueue__
#define __priorityqueue__pqueue__

#include <iostream>
class PriorityQueue
{
public:
    PriorityQueue();
    void clear();
    std::string dequeue();
    void enque(std::string, int);
    std::string peek();
    std::string toString();
private:
    int* tree;
};

#endif /* defined(__priorityqueue__pqueue__) */
