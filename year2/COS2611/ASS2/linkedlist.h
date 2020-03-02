#ifndef LINKEDLIST_H
# define LINKEDLIST_H

template <class Type>
struct  node
{
    Type info;
    node<Type> *link;
};

template <class Type>
class orderdLinkedList
{
    public:
        //linkedListIteratorType
        linkedListIterator();
        linkedListIterator(nodeType<Type> *ptr);
        Type operator*();
        linkedListIterator<Type> operator++();
        bool operator==(const linkedListIterator<Type>& right) const;
        bool operator!=(const linkedListIterator<Type>& right) const;
        
        //linkedListType
        orderdLinkedList<Type> &operator= 
                        (const orderdLinkedList<Type> &otherList);
        void initializeList();                                     
        bool isEmptyList() const;                                  
        void print() const;                                       
        int Length() const;                                        
        void destroyList();                                       
        Type front() const;                                         
        Type back() const;                                          
        void insertFirst(const Type &newItem);                     
        void insertLast(const node<Type> &newItem);                 
        linkedListIterator<Type> begin();                          
        linkedListIterator<Type> end();                            
        orderdLinkedList();                                         
        orderdLinkedList(const orderdLinkedList<Type> &otherList);  
        ~orderdLinkedList());                                   

        //Ordered List
        bool search(const Type& searchItem);
        void insert(const Type& newItem);
        void deleteNode(const Type& deleteItem);
        void mergeLists(node<Type> &list1, node<Type> &list2);

    protected:
        int count;
        node<Type> *first;   
        node<Type> *last;   
    private:
        void copyList(const orderdLinkedList<Type> &otherList);
};

#endif