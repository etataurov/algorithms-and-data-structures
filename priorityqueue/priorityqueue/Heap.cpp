//
//  Heap.cpp
//  priorityqueue
//
//  Created by Evgeny Tataurov on 24/12/13.
//  Copyright (c) 2013 Evgeny Tataurov. All rights reserved.
//

#include "Heap.h"
#include "Node.h"
#include <vector>
Heap::Heap(){
    m_data.resize(10);
}
Node* Heap::peek(){
    Node* maximum = max();
    m_data[1] = m_data[m_heap_size];
    m_heap_size--;
    heapify(1);
    return maximum;
}
Node* Heap::max(){
    return m_data[1];
}
void Heap::insert(Node* node){
    m_heap_size++;
    cout << m_data.size() << endl;
    reduce(m_heap_size, node);
}
void Heap::reduce(int i, Node* node){
    m_data[i] = node;
    while (i > 1 && m_data[parent(i)]->priority > m_data[i]->priority){
        exchange(i, parent(i));
        i = parent(i);
    }
}
int Heap::parent(int i){
    return i/2;
}
int Heap::left(int i){
    return 2*i;
}
int Heap::right(int i){
    return 2*i+1;
}
void Heap::exchange(int i, int j){
    Node* tmp = m_data[j];
    m_data[j] = m_data[i];
    m_data[i] = tmp;
}
void Heap::heapify(int i){
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
string Heap::toString(){
    return print_node(1);
}
string Heap::print_node(int i){
    string self_data = i <= m_heap_size ? m_data[i]->value : "";
    if (i <= m_heap_size){
        return "{"+print_node(left(i))+"("+self_data+")"+print_node(right(i))+"}";
    }
    else{
        return "";
    }
    
}