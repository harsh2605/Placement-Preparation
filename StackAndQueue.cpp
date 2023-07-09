// find the middle of the stack in O(1) time complexity and perform all the opeartion like push,pop and delete middle node in O(1) time complexity
#include <bits/stdc++.h>
using namespace std;

class myStack
{
    struct Node
    {
        int num;
        Node *next;
        Node *prev;

        Node(int num) { this->num = num; }
    };

    // Members of stack
    Node *head = NULL;
    Node *mid = NULL;
    int size = 0;

public:
    void push(int data)
    {
        Node *temp = new Node(data);
        if (size == 0)
        {
            head = temp;
            mid = temp;
            size++;
            return;
        }

        head->next = temp;
        temp->prev = head;

        // update the pointers
        head = head->next;
        if (size % 2 == 1)
        {
            mid = mid->next;
        }
        size++;
    }

    int pop()
    {
        int data = -1;
        if (size != 0)
        {
            Node *toPop = head;
            data = toPop->num;
            if (size == 1)
            {
                head = NULL;
                mid = NULL;
            }
            else
            {
                head = head->prev;
                head->next = NULL;
                if (size % 2 == 0)
                {
                    mid = mid->prev;
                }
            }
            delete toPop;
            size--;
        }
        return data;
    }

    int findMiddle()
    {
        if (size == 0)
        {
            return -1;
        }
        return mid->num;
    }

    void deleteMiddle()
    {
        if (size != 0)
        {
            Node *toDelete = mid;
            if (size == 1)
            {
                head = NULL;
                mid = NULL;
            }
            else if (size == 2)
            {
                head = head->prev;
                mid = mid->prev;
                head->next = NULL;
            }
            else
            {
                mid->next->prev = mid->prev;
                mid->prev->next = mid->next;
                if (size % 2 == 0)
                {
                    mid = mid->prev;
                }
                else
                {
                    mid = mid->next;
                }
            }
            delete toDelete;
            size--;
        }
    }
};

// Implement Stack using queue
// First approach will be using 2 queue to implement stack
// Here 1.first push the element in 2nd queue;
// 2.Than one by one take the element from the queue 1 and put it inside the queue 2
// 3.Take all the elements from queue 2 and copy them inside queue 1

// Second approach will be using a single queue
// In this you first push the element in the queue and than run a loop till queue size-1 and push the elements from the front to the back
void push(int x)
{
    q.push(x);
    for (int i = 0; i < q.size() - 1; i++)
    {
        q.push(q.front());
        q.pop();
    }
}

// Implement queue using stack
// First approach is using 2 stack
// 1.Transfer all the elements from stack 1 to stack 2
// 2.Push the element to stack 1
// 3.Transfer all the elements from stack2 to stack1

// Second approach is also using 2 stack
// using input and output stack
// 1.push opeartion push the element in the stack 1
// 2.pop operation : if the output stack is empty than push all the elements from the input stack into output stack and return the top element
// 3.top operation : if the output stack is empty than push all the elements from the input stack into output stack and return the top element