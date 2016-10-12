/* Anna Avanesyan
    Homework 2
      Queue     */

#include <iostream>
#include <string>
#include "list.hpp"

using namespace std;

template <class T>
class Queue{
    private:
        list <T> *m_list;
    public:
        Queue();
        ~Queue();
    
        void enqueue(T element);
        T dequeue();
        bool is_empty();
        T get_front();
        void print();
};

template <class T>
Queue<T>::Queue(){
    
    m_list = new list<T>;
}

template <class T>
void Queue<T>::enqueue(T element){
    
    m_list->set(m_list->get_size(), element);
}

template <class T>
T Queue<T>::dequeue()
{
    m_list->remove(0);
}

template <class T>
T Queue<T>::get_front(){
    
    return m_list->get(0);
}

template <class T>
bool Queue<T>::is_empty(){
    
    if (m_list->get_size() == 0){
        return true;
    } else {
        return false;
    }
}

template <class T>
void Queue<T>::print(){
    
    m_list->print();
}

template <class T>
Queue<T>::~Queue(){
    
    delete m_list;
}
