// Find the middle of the linkedlist
// Time complexity:O(N/2) space complexity:O(1);
// using slow and fast pointer
ListNode *middleNode(ListNode *head)
{
    ListNode *slow = head, *fast = head->next;
    while (fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;
    }
    return slow;
}

// Add two numbers represented by the nodes of linkedlist

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *dummy = new ListNode(0);
    ListNode *temp = dummy;
    int carry = 0;
    while (l1 || l2 || carry)
    {
        int sum = 0;
        if (l1 != NULL)
        {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL)
        {
            sum += l2->val;
            l2 = l2->next;
        }
        sum += carry;
        ListNode *newnode = new ListNode(sum % 10);
        dummy->next = newnode;
        dummy = newnode;
        carry = sum / 10;
    }
    return temp->next;
}

// Add two numbers without reversring the list
// In this case we will use two stack one stack will store the elemets of the first list and other stack store the elements of the second list and then traverse through the stack to get the elements and add the elements and form a newnode and just connect the nodes
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    stack<int> s1, s2, s3;
    ListNode *ans = new ListNode(0);
    ListNode *curr = ans;
    while (l1 != NULL || l2 != NULL)
    {
        if (l1 != NULL)
        {
            s1.push(l1->val);
            l1 = l1->next;
        }
        if (l2 != NULL)
        {
            s2.push(l2->val);
            l2 = l2->next;
        }
    }
    int carry = 0;
    while (!s1.empty() || !s2.empty())
    {
        int sum = carry;
        if (!s1.empty())
        {
            sum = sum + s1.top();
            s1.pop();
        }

        if (!s2.empty())
        {
            sum = sum + s2.top();
            s2.pop();
        }

        s3.push(sum % 10);
        carry = sum / 10;
    }
    if (carry > 0)
    {
        s3.push(carry);
    }
    while (!s3.empty())
    {
        curr->next = new ListNode(s3.top());
        curr = curr->next;
        s3.pop();
    }
    return ans->next;
}

// Remove nth node from the end of a linkedlist
// Here what we will do is manage a window of size n+1 and the starting point of the window wiil be the node which should be removed at the end so we will maintain a previous pointer and at last just write prev->next=curr->next;
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    if (head == NULL)
        return head;
    ListNode *start = head, *point, *prev = NULL;
    point = head;
    while (n != 0)
    {
        start = start->next;
        n--;
    }
    while (start != NULL)
    {
        prev = head;
        head = head->next;
        start = start->next;
    }
    if (prev == NULL)
        point = point->next;
    else
        prev->next = head->next;
    return point;
}

// Intersection of two linkedlist
// The main approach without counting the number of elements in both the lists and than moving the pointer of the node which contain more elements....insted of this approach a better approach is that you take two pointer and move both of them simountanesly when a node approaches to NULL than it is set to the opposite head pointers and the process continues this will help in moving the pointer to the currehnt position and when both the pointers move they will meet at the point where the address of both will be same return that point
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *p = headA, *q = headB;
    if (p == NULL || q == NULL)
        return NULL;
    while (p != q)
    {
        p = p == NULL ? headB : p->next;
        q = q == NULL ? headA : q = q->next;
    }
    return p;
}