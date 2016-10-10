#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

template <class T>
struct node{
    public:
        T data;
        node* next;
};


template <class P>
class list{
private:
    node <P> * m_head;
    unsigned int m_size;
    node<P>* get_node(int);
public:
    list();
    ~list();
    
    void push_front(P value);
    void push_back(P value);
    void insert(int place, P value);
    void remove(int place);
    void set(int place , P value);
    P get(int place);
    int get_size();
    bool is_empty();
    void clear();
    void print();
};

template <class P>
list<P>::list(){    //constructor
    m_head = new node<P>;
    m_size = 0;
}

template <class P>
void list<P>::push_front(P value){
    
    node<P> *first_element = new node<P>();
    first_element->data = value;
    first_element-> next = m_head;
    m_head =  first_element;
}

template <class P>
void list<P>::push_back(P value){
    
    node<P> *inserted_value = new node<P>();
    node<P> *temp = new node<P>();
    inserted_value->data = value;
    
    temp->next = m_head;

    while(temp->next != NULL){
        temp->next = temp->next;
    }
    
    temp->next = inserted_value;
    inserted_value->next = NULL;
}

template <class P>
node<P> *list<P>::get_node(int place)
{
    if (place > m_size || place < -1){
        cout << "There is nor such element " << endl;
    }
    else {
        node<P>* temp = m_head;
        int i = -1;
        while (i != place) {
            temp = temp->next;
            i++;
        }
        return temp;
    }
}

template <class P>
void list<P>::set(int place, P element)
{
    if (place > m_size || place < 0){
        cout << "There is no such position" << endl;
    }
    else {
        get_node(place)->data = element;
    }
}

template <class P>
P list<P>::get(int place)
{
    if (place > m_size || place < 0){
        cout << "There is no such position " << endl;
    }
    else{
        return get_node(place)->data;
    }
}

template <class P>
void list<P>::remove(int place)
{
    if (place > m_size || place < 0){
        cout << "There is no such position in the list" << endl;
    }
    else{
        node<P>* temp = get_node(place-1);
        node<P>* object = temp->next;
        temp->next = temp->next->next;
        delete object;
        m_size--;
    }
}

template <class P>
int list<P>::get_size()
{
    return m_size;
}

template <class P>
bool list<P>::is_empty()
{
    if (m_head == NULL){
        return true;
    }
    else{
        return false;
    }
}

template <class P>
void list<P>::clear()
{
    node<P>* temp = new node<P>();
    temp->next = m_head;
    while (temp->next != NULL){
        temp->next = temp->next;
        delete temp;
    }
    m_head = NULL;
}

template <class P>
void list<P>::print(){
    node<P> *temp =  new node<P>();
    temp->next = m_head;
    
    while(temp->next!= NULL){
    temp = temp->next;
    cout << temp->data << endl;
    }
}

template <class P>  //destructor
list<P>::~list()
{
    clear();
}
