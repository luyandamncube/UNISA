#ifndef STACK_H
# define STACK_H

template <class Type>
class stackType: public stackADT<Type>
{
    public:
        //StackADT
        virtual void initializeStack() = 0;
        virtual bool isEmptyStack() const = 0;
        virtual bool isFullStack() const = 0;
        virtual void push(const Type& newItem) = 0;
        virtual Type top() const = 0;
        virtual void pop() = 0;

        //StackType
        const stackType<Type>& operator=(const stackType<Type>&);
        void initializeStack();
        bool isEmptyStack() const;
        bool isFullStack() const;
        void push(const Type& newItem);
        Type top() const;
        void pop();
        stackType(int stackSize = 100);
        stackType(const stackType<Type>& otherStack);
        ~stackType();
    private:
        int maxStackSize;
        int stackTop; 
        Type *list; 
        void copyStack(const stackType<Type>& otherStack);
};

#endif

