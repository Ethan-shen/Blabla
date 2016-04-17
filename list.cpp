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
                cout << "empty list" << endl;
                throw;
            }
            else if(pos > size)
            {
                throw std::exception::exception("out of range");
            }
            else if(pos == 1)
                return header;
            else
            {
                int count = 1;
                while(count <= size)
                {
                    if(pos == count)
                        break;
                    tmp = tmp->next;
                    count++;
                }

            }
        }
        catch(exception& e)
        {
            cout << e.what() << endl;
        }
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
    while(header->next!=NULL)
    {
        Node*tmp = header;
        header = header->next;
        delete tmp;
    }
    if(header->next==NULL)
    {
        delete header;
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
        Node *temp = new Node;
        temp->data = Data;

        while(end->next!= NULL)
        {
            end = end->next;
        }
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
        Node *temp = new Node;
        temp->data = Data;

        Node *tmp = header;
        temp->next = tmp;
        header = temp;
        size++;
    }
}


template<class T>
void List<T>::remove(int pos)
{

    if(pos > size||pos < 0)
    {
        cout << "out of range" << endl;
        return;
    }
    if(pos == 1)
    {
        Node* t = header;
        header = header->next;
        delete t;
    }
    if(isEmpty())
    {
        cout << "empty list" <<endl;
        return;
    }
    Node *tmp = at(pos);
    Node *tmp2 = at(pos-1);
    tmp2->next = tmp->next;
    delete tmp;

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
        Node *tmp = at(pos);
        Node *tmp2 = at(pos-1);
        Node *add = new Node;
        add->data = Data;
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
