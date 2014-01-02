//
//  Heap.h
//  priorityqueue
//
//  Created by Evgeny Tataurov on 24/12/13.
//  Copyright (c) 2013 Evgeny Tataurov. All rights reserved.
//

#ifndef __priorityqueue__Heap__
#define __priorityqueue__Heap__

#include <iostream>
#include <vector>
#include "Node.h"

class Heap
{
public:
    Heap();
    void insert(Node*);
    Node* peek();
    Node* max();
    string toString();
private:
    static int parent(int);
    static int left(int);
    static int right(int);
    void heapify(int);
    void reduce(int, Node*);
    void exchange(int, int);
    vector<Node*> m_data;
    int m_size;
    int m_heap_size;
    string print_node(int);
};

#endif /* defined(__priorityqueue__Heap__) */
