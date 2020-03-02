#include "linkedlist.h"
#include <iostream>
#include <cstdlib>                          //For NULL definition
using namespace std;

template <class Type> //Assignment/Copy operator overload
const linkedListType<Type>& linkedListType<Type>::operator=
    (const linkedListType<Type>& otherList)
{
    if (this != &otherList)
    {
        copyList(otherList);
    }
    return *this;
}

template <class Type> //Initialisation of current pointer
linkedListIterator<Type>::linkedListIterator()
{
    current = NULL;
}

template <class Type> //Dereference operator overload
linkedListIterator<Type>::
linkedListIterator(nodeType<Type> *ptr)
{
    current = ptr;
}

template <class Type> //Dereference operator overload
Type linkedListIterator<Type>::operator*()
{
    return current->info;
}

template <class Type> //increment operator overload
linkedListIterator<Type> linkedListIterator<Type>::operator++()
{
    current = current->link;
    return *this;
}

template <class Type> //Equivalence operator overload
bool linkedListIterator<Type>::operator==
(const linkedListIterator<Type>& right) const
{
    return (current == right.current);
}

template <class Type>  //Not equal operator overload
bool linkedListIterator<Type>::operator!=
(const linkedListIterator<Type>& right) const
{
    return (current != right.current);
}   

template <class Type>                       //Type this line every time you refer to "this"
void orderdLinkedList::initializeList()
{
    destroyList(); 
    last = NULL;
    cursor = NULL;
    count = 0;
}

template <class Type>
bool orderdLinkedList::isEmptyList()
{
    return (Length() == 0 ? true : false);
}

template <class Type>
void orderdLinkedList::print()
{
    node<Type> *current; //pointer to traverse the list
    current = first; //set current point to the first node
    while (current != NULL) //while more data to print
    {
        cout << current->info << " ";
        current++;
    }
}

template <class Type>
int orderdLinkedList::Length()
{
    return(count);
}

template <class Type>
void destroyList()
{
    node<Type> *temp; 

    while (first != NULL) 
    {
        temp = first;
        first++;
        delete temp;
    }
    first = NULL;
    first = 0;
}

template <class Type>
Type front()
{
    assert(first != NULL);
    return (first->info); 
}

template <class Type>
Type back()
{
    assert(last != NULL);
    return last->info;
}

template <class Type>
void orderdLinkedList::insertFirst(const Type &newItem)
{
    node<Type> *newNode;

    newNode = new node<Type>;
    newNode->info = newItem;
    newNode->link = first;
    first = newNode; 
    count++;
    if (last == NULL)
        last = newNode;
}

template <class Type>
void orderdLinkedList::insertLast(const Type &newItem)
{
    node<Type> *newNode;
 
    newNode = new node<Type>;
    newNode->info = newItem;
    newNode->link = NULL;
    if (first == NULL)
    {
        first = newNode;
        last = newNode;
        count++;
    }
    else 
    {
        last->link = newNode; 
        last = newNode;
        count++;
    }
}
template <class Type>
orderdLinkedList::node<Type> begin()
{
    linkedListIterator<Type> temp(first);
    return (temp);
}

template <class Type>
orderdLinkedList::node<Type> end()
{
    linkedListIterator<Type> temp(NULL);
    return (temp);
}


template <class Type>
void linkedListType<Type>::copyList
(const linkedListType<Type>& otherList)
{
    nodeType<Type> *newNode;
    nodeType<Type> *current;
    if (first != NULL)
    destroyList();
    if (otherList.first == NULL)
    {
        first = NULL;
        last = NULL;
        count = 0;
    }
    else
    {
        current = otherList.first;
        count = otherList.count;
        first = new nodeType<Type>;
        first->info = current->info;
        first->link = NULL; 
        last = first; 
        current = current->link; 
        while (current != NULL)
        {
            newNode = new nodeType<Type>;
            newNode->info = current->info;
            newNode->link = NULL;
            last->link = newNode;
            last = newNode; 
            current = current->link;
        }
    }
}

template <class Type>
orderdLinkedList::orderdLinkedList()
{

}
template <class Type>
orderdLinkedList(const orderdLinkedList<Type> &otherList)
{

}

template <class Type>
orderdLinkedList::~orderdLinkedList()
{
    destroyList();
}

template <class Type>
bool orderedLinkedList<Type>::search(const Type& searchItem) const
{
    bool found = false;
    nodeType<Type> *current;
    current = first;
    while (current != NULL && !found)
        if (current->info >= searchItem)
            found = true;
        else
            current = current->link;
    if (found)
        found = (current->info == searchItem); 
    return (found);
}

template <class Type>
void orderedLinkedList<Type>::insert(const Type& newItem)
{
    nodeType<Type> *current;
    nodeType<Type> *trailCurrent;
    nodeType<Type> *newNode;
    bool found;
    newNode = new nodeType<Type>;
    newNode->info = newItem; 
    newNode->link = NULL; 
    if (first == NULL)
    {
        first = newNode;
        last = newNode;
        count++;
    }
    else
    {
        current = first;
        found = false;
        while (current != NULL && !found) //search the list
            if (current->info >= newItem)
                found = true;
            else
            {
                trailCurrent = current;
                current = current->link;
            }
            if (current == first) //Case 2
            {
                newNode->link = first;
                first = newNode;
                count++;
            }
            else //Case 3
            {
                trailCurrent->link = newNode;
                newNode->link = current;
                if (current == NULL)
                last = newNode;
                count++;
            }
    }
}

template <class Type>
void orderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
    nodeType<Type> *current; //pointer to traverse the list
    nodeType<Type> *trailCurrent; //pointer just before current
    bool found;
    if (first == NULL) //Case 1
        cout << "Cannot delete from an empty list." << endl;
    else
    {
        current = first;
        found = false;
    while (current != NULL && !found) //search the list
        if (current->info >= deleteItem)
            found = true;
        else
        {
            trailCurrent = current;
            current = current->link;
        }
    if (current == NULL) //Case 4
        cout << "The item to be deleted is not in the list." << endl;
    else
        if (current->info == deleteItem) 
        {
            if (first == current) //Case 2
            {
                first = first->link;
                if (first == NULL)
                    last = NULL;
                delete current;
            }
            else //Case 3
            {
                trailCurrent->link = current->link;
                if (current == last)
                    last = trailCurrent;
                delete current;
            }
        count--;
        }
    else //Case 4
        cout << "The item to be deleted is not in the list." << endl;
    }
}

template <class Type>
void orderdLinkedList::mergeLists(i_list<Type> &list1, i_list<Type> &list2)
{

}

int main()
{
    /*
        [ADD NODES]
        node * A;
        A = new node;
        A->info = 2;
        A->link NULL;
    */
    /*
        [CREATE LIST]
        orderdLinkedList myList;
        orderdLinkedList list1;
        orderdLinkedList list2;
        ...
        list1.insertFirst(A);
        list1.insertLast(A);
        list1.insertLast(A);
    */

    return (0);
}