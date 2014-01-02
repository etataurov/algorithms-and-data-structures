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
#include "Node.h"
#include "Heap.h"

template <typename ValueType>
class PriorityQueue
{
public:
    ~PriorityQueue();
    void clear();
    ValueType dequeue();
    void enqueue(ValueType, int);
    ValueType peek();
    std::string toString();
private:
    Heap<ValueType> heap;
};

template <typename ValueType>
void PriorityQueue<ValueType>::enqueue(ValueType value, int priority){
    heap.insert(new Node<ValueType>(value, priority));
}

template <typename ValueType>
PriorityQueue<ValueType>::~PriorityQueue(){
    clear();
}

template <typename ValueType>
void PriorityQueue<ValueType>::clear(){
    heap.clear();
}

template <typename ValueType>
ValueType PriorityQueue<ValueType>::dequeue(){
    return heap.peek()->value;
}

template <typename ValueType>
ValueType PriorityQueue<ValueType>::peek(){
    return heap.max()->value;
}

template <typename ValueType>
std::string PriorityQueue<ValueType>::toString(){
    return heap.toString();
}

#endif /* defined(__priorityqueue__pqueue__) */
