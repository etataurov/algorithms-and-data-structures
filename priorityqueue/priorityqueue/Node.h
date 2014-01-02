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

struct Node {
    Node(string, int);
    Node();
    string value;
    int priority;
};

#endif /* defined(__priorityqueue__Node__) */
