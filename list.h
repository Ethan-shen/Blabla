#ifndef _LIST_H_
#define _LIST_H_
#include <iostream>

template<class T>
class List
{
public:
    List();
    ~List()
    {

    }

    bool isEmpty();
    const T& operator [](int pos) throw();
    void push_back(const T& Data);
    void push_front(const T& Data);
  //  void remove(int pos);
 //   void insert(int pos,const T& Data);
 //   int size();
    friend ostream& operator <<(ostream& os,const List& list);
private:
    typedef struct node
    {
        T data;
        struct node *next;
    }Node;
    Node *header;
    int size;
};


#endif // _LIST_H_
