//
//  Node.h
//  priorityqueue
//
//  Created by Evgeny Tataurov on 24/12/13.
//  Copyright (c) 2013 Evgeny Tataurov. All rights reserved.
//

#ifndef __priorityqueue__Node__
#define __priorityqueue__Node__

#include <iostream>
using namespace std;

template <typename ValueType>
struct Node {
    Node(ValueType, int);
    Node();
    ValueType value;
    int priority;
};

template <typename ValueType>
Node<ValueType>::Node(ValueType value, int priority){
    this->value = value;
    this->priority = priority;
}

template <typename ValueType>
Node<ValueType>::Node(){
    this->value = NULL;
    this->priority = NULL;
}

#endif /* defined(__priorityqueue__Node__) */
