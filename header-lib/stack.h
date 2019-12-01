#include <iostream>
using namespace std;

class STACK_NODE
{
public:
    void *dataPtr;
    STACK_NODE *link;
};

class stack
{
private:
    int stackCounter;
    STACK_NODE *top;

public:
    stack()
    {
        STACK_NODE *temp = new STACK_NODE();
        temp->dataPtr = NULL;
        temp->link = NULL;

        this->stackCounter = 0;
        this->top = temp;
    }

    // get stack count
    int getStackCount()
    {
        return this->stackCounter;
    }

    // push data to the stack
    bool push(void *data)
    {
        STACK_NODE *temp = new STACK_NODE();
        if (!temp)
        {
            return false;
        }

        temp->dataPtr = data;
        temp->link = this->top;
        this->top = temp;

        (this->stackCounter)++;
        return true;
    }

    // pop data from the stack
    void *pop()
    {
        if (this->stackCounter == 0)
        {
            return NULL;
        }

        void *data = this->top->dataPtr;

        STACK_NODE *temp = new STACK_NODE();
        temp = this->top;
        this->top = this->top->link;

        free(temp);

        (this->stackCounter)--;
        return data;
    }

    //get Top data
    void *getTop()
    {
        return this->top->dataPtr;
    }

    //destroy stack
    bool destroyStack()
    {

        if (this->stackCounter == 0)
        {
            return false;
        }

        while (this->stackCounter != 0)
        {
            void *data = this->pop();
        }
        return true;
    }

    // verify empty stack
    bool isEmpty()
    {
        return this->stackCounter == 0;
    }

    //destructor
    ~stack()
    {
        this->destroyStack();
    }
};
