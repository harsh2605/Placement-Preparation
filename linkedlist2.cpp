// Creation of linkedlist and adding nodes into the linkedlist
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int val;
    Node *next;
    Node(int data)
    {
        val = data;
        next = NULL;
    }
};
void add_Node(Node *&root, int data)
{
    if (root == NULL)
    {
        Node *create_node = new Node(data);
        root = create_node;
    }
    else
    {
        Node *cur = root;
        while (cur->next != NULL)
        {
            cur = cur->next;
        }
        Node *create_node = new Node(data);
        cur->next = create_node;
    }
}
int main()
{
    Node *root = NULL;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    add_Node(root, a);
    add_Node(root, b);
    add_Node(root, c);
    add_Node(root, d);
    while (root != NULL)
    {
        cout << root->val;
        root = root->next;
    }
}

// 1.Finding length of a linkedlist both iteratively and recursively(tc:O(N))

// 2.Finding middle of the linkedlist
// Solution{One approach is to count the number of nodes and than find the middle of the linkedlist this time complexity:O(N)}
// Next approach will be haier and the tortoise approach where we will be using fast and slow pointers
// Time complexity:O(N/2);
ListNode *middleNode(ListNode *head)
{
    ListNode *fast = head, *slow = head;
    while (fast && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
    }
    return slow;
}

// 3.Reverse a linkedlist
// Solution:The first approach will be you have to traverse the whole linkedlist and store the values of  the linkedlist in a vector and after that we have to traverse through the back of the vector and store its value in the linkedlist from the starting
// Time complexity:O(N)
// Space complexity:O(N)

// Another approach is to use three pointer and reverse the linkedlist in one pass
// Recursive approach
ListNode *reverseList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *newhead = reverseList(head->next);
    ListNode *head_next = head->next;
    head_next->next = head;
    head->next = NULL;
    return newhead;
}

// Iterative approach
ListNode *reverseList(ListNode *head)
{
    ListNode *first, *sec, *third;
    first = NULL;
    sec = NULL;
    third = head;
    while (third != NULL)
    {
        first = sec;
        sec = third;
        third = third->next;
        sec->next = first;
    }
    return sec;
}

// Detecting loop in a linkedlist (floyds cycle detection algorithm haier and tortoise approach)
// Time complexity:O(N) space complexity:O(1)
bool hasCycle(ListNode *head)
{
    if (head == NULL)
        return false;
    ListNode *fast = head, *slow = head;
    do
    {
        slow = slow->next;
        fast = fast->next;
        if (fast)
            fast = fast->next;
    } while (fast && slow && fast != slow);
    if (fast && fast == slow)
        return true;
    return false;
}

// Detecting the point where the loop points
// Time complexity:O(N) space complexity:O(1)
ListNode *detectCycle(ListNode *head)
{
    if (head == NULL)
        return NULL;
    ListNode *fast = head, *slow = head;
    do
    {
        slow = slow->next;
        fast = fast->next;
        if (fast)
            fast = fast->next;
    } while (fast && slow && fast != slow);
    if (fast && fast == slow)
    {
        slow = head;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
    return NULL;
}

// Move last element to the first of linkedlist
ListNode *move(ListNode *root)
{
    ListNode *prev = NULL, *start = root;
    while (start->next != NULL)
    {
        prev = start;
        start = start->next;
    }
    if (prev != NULL)
    {
        prev->next = NULL;
        start->next = root;
        root = start;
    }
    return root;
}

// Remove nth node from the end of the linkedlist
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *dummy = new ListNode();
    dummy->next = head;
    ListNode *fast = dummy, *slow = dummy;
    for (int i = 0; i < n; i++)
    {
        fast = fast->next;
    }
    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;
    return dummy->next;
}

// Rotate list leetcode question
// Input: head = [1,2,3,4,5], k = 2
// Output: [4,5,1,2,3]
// Bascially three steps to solve this question:
// 1.find the length of the linkedlist .2.Than point the last pointer to the head node and make them a circular linkedlist 3.Move the starting pointer to rotate varialble number of times and than mark its next to NULL;
ListNode *rotateRight(ListNode *head, int k)
{
    if (head == NULL)
        return NULL;
    int num_node = 0;
    ListNode *start = head, *last = NULL;
    while (start != NULL)
    {
        num_node++;
        if (start->next == NULL)
            last = start;
        start = start->next;
    }
    last->next = head;
    start = head;
    int rotate = num_node - (k % num_node);
    for (int i = 1; i < rotate; i++)
    {
        head = head->next;
    }
    start = head->next;
    head->next = NULL;
    return start;
}

// Remove duplcate from a sorted linkedlist
ListNode *deleteDuplicates(ListNode *head)
{
    ListNode *cur = head;
    while (cur != NULL)
    {
        if (cur->next != NULL && cur->val == cur->next->val)
        {
            cur->next = cur->next->next;
        }
        else
        {
            cur = cur->next;
        }
    }
    return head;
}