//
//  Node.cpp
//  priorityqueue
//
//  Created by Evgeny Tataurov on 24/12/13.
//  Copyright (c) 2013 Evgeny Tataurov. All rights reserved.
//

#include "Node.h"
Node::Node(string value, int priority){
    this->value = value;
    this->priority = priority;
}
Node::Node(){
    this->value = "";
    this->priority = NULL;
}