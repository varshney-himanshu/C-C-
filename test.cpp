#include <iostream>
#include "./header-lib/stack.h"
using namespace std;

int main()
{

    stack *stk = new stack();

    int *data = new int(23);
    stk->push(data);

    int *data2 = new int(54);
    stk->push(data2);

    if (stk->destroyStack())
    {
        cout << "destroyed!!";
    }
    else
    {
        cout << "stack empty!!";
    }

    return 0;
}