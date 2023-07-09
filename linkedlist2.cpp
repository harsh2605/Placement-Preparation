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

// Remove duplicate from a sorted linkedlist
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

// Add 1 to a linkedlist
Node *reverse(Node *head)
{
    Node *first = NULL, *sec = NULL, *third = head;
    while (third != NULL)
    {
        first = sec;
        sec = third;
        third = third->next;
        sec->next = first;
    }
    return sec;
}
Node *addOne(Node *head)
{
    // Your Code here
    // return head of list after adding one
    Node *cur = reverse(head), *last = NULL, *final;
    final = cur;
    int carry = 1;
    while (cur != NULL)
    {
        int value = cur->data + carry;
        // cout<<value<<"->";
        if (value > 9)
        {
            cur->data = 0;
            carry = 1;
        }
        else
        {
            cur->data = value;
            carry = 0;
        }
        if (cur->next == NULL)
        {
            last = cur;
        }
        cur = cur->next;
    }
    if (carry != 0)
    {
        Node *new_node = new Node(carry);
        last->next = new_node;
        last = new_node;
    }
    return reverse(final);
}

// Add two number represented by linkedlist
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *dummy = new ListNode(0);
    ListNode *head = dummy;
    int carry = 0;
    while (l1 || l2 || carry != 0)
    {
        int value = 0;
        if (l1)
        {
            value += l1->val;
            l1 = l1->next;
        }
        if (l2)
        {
            value += l2->val;
            l2 = l2->next;
        }
        value += carry;
        ListNode *new_node = new ListNode(value % 10);
        carry = value / 10;
        dummy->next = new_node;
        dummy = new_node;
    }
    return head->next;
}

// Add two numbers represented by linkedlist without reversing the linkedlist
// Just the thing is that it uses extra space as we are using stack here
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *dummy = NULL;
    ListNode *head = dummy;
    stack<int> st1, st2;
    while (l1)
    {
        st1.push(l1->val);
        l1 = l1->next;
    }
    while (l2)
    {
        st2.push(l2->val);
        l2 = l2->next;
    }
    int carry = 0;
    while (!st1.empty() || !st2.empty() || carry != 0)
    {
        int value = 0;
        if (!st1.empty())
        {
            value += st1.top();
            st1.pop();
        }
        if (!st2.empty())
        {
            value += st2.top();
            st2.pop();
        }
        value += carry;
        ListNode *new_node = new ListNode(value % 10);
        carry = value / 10;
        new_node->next = dummy;
        dummy = new_node;
    }
    return dummy;
}

// Intersection of two linkedlist
// Basically you have to find the common elements present in both the linkedlist
//  L1 = 1->2->3->4->6
//  L2 = 2->4->6->8
//  Output: 2 4 6
Node *findIntersection(Node *l1, Node *l2)
{
    // Your Code Here
    Node *head = NULL, *dummy = new Node(0);
    head = dummy;
    while (l1 && l2)
    {
        if (l1->data == l2->data)
        {
            Node *new_node = new Node(l1->data);
            dummy->next = new_node;
            dummy = new_node;
            l1 = l1->next;
            l2 = l2->next;
        }
        else if (l1->data < l2->data)
        {
            l1 = l1->next;
        }
        else
        {
            l2 = l2->next;
        }
    }
    return head->next;
}

// Intersection point of y shaped linkedlist
int intersectPoint(Node *head1, Node *head2)
{
    // Your Code Here
    Node *first = head1, *sec = head2;
    bool flag = 0;
    while (first != sec)
    {
        first = (first == NULL) ? head2 : first->next;
        sec = (sec == NULL) ? head1 : sec->next;
        if (first == NULL && sec == NULL)
        {
            flag = 1; // It will tell that we have entered the following condition or not
            break;
        }
    }
    if (flag)
        return -1;
    return first->data;
}

// To find whether the given linkedlist is palindrome or not
// Two special conditon that fast->next!=NULL && fast->next->next!=NULL
// Just cut the linkedlist from the middle and reverse the rest part and from the left mode side whether all the values are same or not
Node *reverse(Node *head)
{
    Node *first = NULL, *sec = NULL, *third = head;
    while (third != NULL)
    {
        first = sec;
        sec = third;
        third = third->next;
        sec->next = first;
    }
    return sec;
}
bool isPalindrome(Node *head)
{
    // Your code here
    Node *slow = head, *fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;
    }
    Node *rev_head = reverse(slow->next);
    // cout<<head->data<<" "<<rev_head->data<<endl;
    while (rev_head != NULL)
    {
        if (rev_head->data != head->data)
        {
            return false;
        }
        rev_head = rev_head->next;
        head = head->next;
    }
    return true;
}

// Find length of loop
int countNodesinLoop(struct Node *head)
{
    // Code here
    Node *fast = head, *slow = head;
    do
    {
        slow = slow->next;
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
    } while (fast != NULL && fast != slow);
    if (fast && fast == slow)
    {
        int count = 1;
        slow = slow->next;
        while (fast != slow)
        {
            count++;
            slow = slow->next;
        }
        return count;
    }
    return 0;
}

// DOUBLY LINKEDLIST
// Reverse a doubly linkedlist
Node *reverseDLL(Node *head)
{
    // Your code here
    Node *first = NULL, *sec = NULL, *third = head;
    while (third != NULL)
    {
        first = sec;
        sec = third;
        third = third->next;
        sec->next = first;
        sec->prev = third;
    }
    return sec;
}

// Delete node having greater value on the right
Node *reverse(Node *head)
{
    Node *first = NULL, *sec = NULL, *third = head;
    while (third != NULL)
    {
        first = sec;
        sec = third;
        third = third->next;
        sec->next = first;
    }
    return sec;
}
Node *compute(Node *head)
{
    // your code goes here
    Node *start = reverse(head);
    Node *point = start;
    int maxi = start->data;
    while (start != NULL)
    {
        if (start->next && start->next->data < maxi)
        {
            start->next = start->next->next;
        }
        else if (start->next)
        {
            maxi = start->next->data;
            start = start->next;
        }
        if (start->next == NULL)
        {
            break;
        }
    }
    return reverse(point);
}
// Without reversing the linkedlist
Node *compute(Node *head)
{
    // your code goes here
    if (head == NULL || head->next == NULL)
        return head;
    Node *newnode = compute(head->next);
    if (newnode->data > head->data)
        return newnode;
    head->next = newnode;
    return head;
}

// Merge sort in a linkedlist
ListNode *find_middle(ListNode *head)
{
    ListNode *fast = head->next, *slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
ListNode *mergeSort(ListNode *left, ListNode *right)
{
    if (left == NULL)
        return right;
    if (right == NULL)
        return left;
    ListNode *dummy = new ListNode(0);
    ListNode *ans = dummy;
    while (left != NULL && right != NULL)
    {
        if (left->val < right->val)
        {
            ans->next = left;
            ans = left;
            left = left->next;
        }
        else
        {
            ans->next = right;
            ans = right;
            right = right->next;
        }
    }
    while (left != NULL)
    {
        ans->next = left;
        ans = left;
        left = left->next;
    }
    while (right != NULL)
    {
        ans->next = right;
        ans = right;
        right = right->next;
    }
    return dummy->next;
}
ListNode *sortList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *mid = find_middle(head);
    ListNode *left = head;
    ListNode *right = mid->next;
    mid->next = NULL;
    left = sortList(left);
    right = sortList(right);
    ListNode *ans = mergeSort(left, right);
    return ans;
}

// Flattening a linkedlist
Node *merge_sort(Node *first, Node *sec)
{
    if (first == NULL)
        return sec;
    if (sec == NULL)
        return first;
    Node *dummy = new Node(0);
    Node *temp = dummy;
    while (first != NULL && sec != NULL)
    {
        if (first->data < sec->data)
        {
            temp->bottom = first;
            temp = first;
            first = first->bottom;
        }
        else
        {
            temp->bottom = sec;
            temp = sec;
            sec = sec->bottom;
        }
    }
    if (first != NULL)
    {
        temp->bottom = first;
    }
    if (sec != NULL)
    {
        temp->bottom = sec;
    }
    return dummy->bottom;
}
Node *flatten(Node *root)
{
    // Your code here
    if (root == NULL || root->next == NULL)
    {
        return root;
    }
    root->next = flatten(root->next);
    root = merge_sort(root, root->next);
    return root;
}