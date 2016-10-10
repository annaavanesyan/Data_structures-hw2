/* Anna Avanesyan
    Homework 2
     Stack
*/

#include <iostream>
#include <string>
using namespace std;
template <class T>
class Stack
{
private:
    T* m_elements;
    unsigned int m_capacity;
    int m_top;
    
public:
    Stack();
    ~Stack();
    
    void push(T element);
    void pop();
    bool is_empty();
    T get_top();
    void print();
};

template <class T>
Stack<T>::Stack(){          //constructor
    m_top = -1;
    m_capacity= 10;
    m_elements = new T[m_capacity];
};

template <class T>
void Stack<T>::push(T element){
    
    if(m_top != m_capacity){
        m_top++;
        m_elements[m_top] = element;
    }
    else{
        cout << "Stack is full" << endl;
    }
}

template <class T>
void Stack<T>::pop(){
    
    m_elements[m_top] = NULL;
    m_top--;
}

template <class T>
bool Stack<T>::is_empty(){
    if(m_top == -1){
        return true;
    }
    else{
        return false;
    }
}

template <class T>
T Stack<T>::get_top(){
    
    return m_elements[m_top];
}

template <class T>
void Stack<T>::print(){
    if(!is_empty()){
        for(int i= m_top; i >= 0 ; i--){
            cout << m_elements[i] << endl;
        }
    }
    else{
        cout << "Stack is empty" << endl;
    }
}

template <class T>
Stack<T>::~Stack(){         //Destructor
    
    delete m_elements;
}
