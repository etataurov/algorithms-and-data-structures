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
#include "Heap.h"
using namespace std;

int main(int argc, const char * argv[])
{
    Heap* heap = new Heap();
    heap->insert(new Node("AKAKA", 10));
    heap->insert(new Node("alog", 2));
    heap->insert(new Node("ALLAA", 4));
    cout << heap->toString() << endl;
    cout << heap->peek()->value << endl;
    cout << heap->toString() << endl;
    cout << "Hello, World!\n";
    return 0;
}

