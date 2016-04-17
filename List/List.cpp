//#include "list.h"
#include <iostream>
using namespace std;
template<class T>
class List
{
public:
    List();
    ~List();

    bool isEmpty();
    const T& operator [](int pos) throw();
    void push_back(const T& Data);
    void push_front(const T& Data);
    void remove(int pos);
    void insert(int pos,const T& Data);
    int _size();
    friend ostream& operator << (ostream& os,const List<T>& list);
private:
    typedef struct node
    {
        T data;
        struct node *next;
    }Node;
    Node *header;
    Node *end;
    int size;
    Node* at(int pos) throw()
    {
        Node* tmp = header;
        try
        {
            if(this->isEmpty())
            {
                throw string("empty list");
            }
            else if(pos > size||pos < 1)
            {
                throw string("out of range");
            }
            else if(pos == 1)
                return header;
            else
            {
                int count = 1;
                //find the position
                while(count <= size)
                {
                    if(pos == count)
                        break;
                    tmp = tmp->next;
                    count++;
                }

            }
        }
        catch(string& e)
        {
            cout << e << endl;
        }
        //return the found node
        return tmp;
    }

};


template<class T>
List<T>::List()
{
    header = end = NULL;
    size = 0;
}

template<class T>
List<T>::~List()
{
    if(header->next==NULL)
    {
        delete header;
    }
    while(header->next!=NULL)
    {
        Node*tmp = header;
        header = header->next;
        delete tmp;
    }
}

template<class T>
bool List<T>::isEmpty()
{
    return size?false:true;
}

template<class T>
const T& List<T>::operator [](int pos) throw()
{
    Node* result = at(pos);
    return result->data;
}

template<class T>
void List<T>::push_back(const T& Data)
{
    //empty list
    if(header == NULL)
    {
        header = new Node;
        header->data = Data;
        header->next = NULL;
        end = header;
        size++;
    }
    else
    {
        //create node
        Node *temp = new Node;
        temp->data = Data;

        //iterate to the last node
        while(end->next!= NULL)
        {
            end = end->next;
        }
        //connect the new node to the list
        end->next = temp;
        temp->next = NULL;
        size++;
    }
}

template<class T>
void List<T>::push_front(const T& Data)
{
    if(header == NULL)
    {
        header = new Node;
        header->data = Data;
        header->next = NULL;
        size++;
    }
    else
    {
        //create new node
        Node *temp = new Node;
        temp->data = Data;

        //link the new node to the very
        //front of the list
        Node *tmp = header;
        temp->next = tmp;
        header = temp;
        size++;
    }
}


template<class T>
void List<T>::remove(int pos)
{
    try
    {
        if(pos > size||pos < 1)
        {
            throw string("out of range");
        }
        if(pos == 1)
        {
            Node* t = header;
            header = header->next;
            delete t;
        }
        if(isEmpty())
        {
            throw string("empty list");
        }
        //two pointers point to the position
        //and one before
        Node *tmp = at(pos);
        Node *tmp2 = at(pos-1);
        //connect the previous pointer to the
        //one after node
        tmp2->next = tmp->next;
        delete tmp;
    }
    catch(string& str)
    {
        cout << str << endl;
    }
}

template<class T>
void List<T>::insert(int pos,const T& Data)
{
    if(pos == 1)
    {
        push_front(Data);
    }
    else if(pos >= size)
    {
        push_back(Data);
    }
    else
    {
        //get the location and one before the location
        Node *tmp = at(pos);
        Node *tmp2 = at(pos-1);
        //create new node
        Node *add = new Node;
        add->data = Data;

        //link the new node between two locations
        tmp2->next = add;
        add->next = tmp;
    }
}

template<class T>
int List<T>::_size()
{
    return size;
}

template<class T>
ostream& operator<< (ostream& os,const List<T>& list)
{
    while((list.header)!=NULL)
    {
        os << (list.header)->data << endl;
        list.header = list.header->next;
    }
    return os;
}
