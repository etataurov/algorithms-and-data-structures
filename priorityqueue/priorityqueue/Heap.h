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

template <typename ValueType>
class Heap
{
public:
    Heap();
    ~Heap();
    void clear();
    void insert(Node<ValueType>*);
    Node<ValueType>* peek();
    Node<ValueType>* max();
    string toString();
private:
    static int parent(int);
    static int left(int);
    static int right(int);
    void heapify(int);
    void reduce(int, Node<ValueType>*);
    void exchange(int, int);
    vector<Node<ValueType>*> m_data;
    int m_heap_size;
    string print_node(int);
};

template <typename ValueType>
Heap<ValueType>::Heap(){
    m_data.resize(10); // 10 should be in const
}

template <typename ValueType>
Heap<ValueType>::~Heap(){
    clear();
}

template <typename ValueType>
void Heap<ValueType>::clear(){
    m_data.clear();
    m_heap_size = 0;
}


template <typename ValueType>
Node<ValueType>* Heap<ValueType>::peek(){
    Node<ValueType>* maximum = max();
    m_data[1] = m_data[m_heap_size];
    m_heap_size--;
    heapify(1);
    return maximum;
}

template <typename ValueType>
Node<ValueType>* Heap<ValueType>::max(){
    return m_data[1];
}

template <typename ValueType>
void Heap<ValueType>::insert(Node<ValueType>* node){
    m_heap_size++;
    cout << m_data.size() << endl;
    reduce(m_heap_size, node);
}

template <typename ValueType>
void Heap<ValueType>::reduce(int i, Node<ValueType>* node){
    m_data[i] = node;
    while (i > 1 && m_data[parent(i)]->priority > m_data[i]->priority){
        exchange(i, parent(i));
        i = parent(i);
    }
}

template <typename ValueType>
int Heap<ValueType>::parent(int i){
    return i/2;
}

template <typename ValueType>
int Heap<ValueType>::left(int i){
    return 2*i;
}

template <typename ValueType>
int Heap<ValueType>::right(int i){
    return 2*i+1;
}

template <typename ValueType>
void Heap<ValueType>::exchange(int i, int j){
    Node<ValueType>* tmp = m_data[j];
    m_data[j] = m_data[i];
    m_data[i] = tmp;
}

template <typename ValueType>
void Heap<ValueType>::heapify(int i){
    int l = left(i);
    int r = right(i);
    int min;
    if (l <= m_heap_size && m_data[l]->priority < m_data[i]->priority){
        min = l;
    }
    else min = i;
    if (r <= m_heap_size && m_data[r]->priority < m_data[min]->priority){
        min = r;
    }
    if (min != i){
        exchange(i, min);
        heapify(min);
    }
}

template <typename ValueType>
string Heap<ValueType>::toString(){
    return print_node(1);
}

template <typename ValueType>
string Heap<ValueType>::print_node(int i){
    string self_data = i <= m_heap_size ? m_data[i]->value : string(""); // bug here: value may not be a string
    if (i <= m_heap_size){
        return "{"+print_node(left(i))+"("+self_data+")"+print_node(right(i))+"}";
    }
    else{
        return "";
    }
    
}

#endif /* defined(__priorityqueue__Heap__) */
