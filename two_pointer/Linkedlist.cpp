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

// Linkedlist cycle detection and return the given node where the cycle is detected
// Floyds cycle detection technique using fast and slow pointers
ListNode *detectCycle(ListNode *head)
{
    if (head == NULL)
        return head;
    ListNode *fast = NULL, *slow = NULL;
    slow = head;
    fast = head;
    do
    {
        slow = slow->next;
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
    } while (fast != slow && fast != NULL);
    if (fast == slow && fast && slow)
    {
        slow = head;
        while (fast != slow)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
    return NULL;
}

// Copy List With Random pointers
// With time complexity O(N) && Space complexity as O(N)
// Here we will create a map and map the old node to the new node
// when we again traverse the linkeldist we will point the new node->next to the address of the next new node which is attached to the next old node and in the same fashion we will adjust the random pointer also
Node *copyRandomList(Node *head)
{
    unordered_map<Node *, Node *> mp;
    Node *start = head, *point = NULL;
    while (start != NULL)
    {
        Node *naya = new Node(start->val);
        if (!point)
            point = naya;
        mp[start] = naya;
        start = start->next;
    }
    start = head;
    while (start != NULL)
    {
        mp[start]->next = mp[start->next];
        mp[start]->random = mp[start->random];
        start = start->next;
    }
    return point;
}

// Now solving the same problem with time complexity:O(N) and space complexity:O(1)
Node *copyRandomList(Node *head)
{
    Node *node = head;
    // copying next pointer only, and making ll eg: 1->2->3
    // as 1->(1)->2->(2)->3->(3), bracket objects will be our deep copy list in future
    while (node)
    {
        Node *temp = node->next;
        node->next = new Node(node->val);
        node->next->next = temp;
        node = temp;
    }
    node = head;
    // now copying random pointers, and travelling in our old ll by moving two steps
    // at all times.
    while (node)
    {
        if (node->random)
            node->next->random = node->random->next;
        node = node->next->next;
    }
    Node *dummy = new Node(-1), *helper = dummy, *curr = head;
    // now bifurcating the new ll, and retreiving the original ll,
    while (curr)
    {
        helper->next = curr->next;
        helper = helper->next;
        curr->next = curr->next->next;
        curr = curr->next;
    }
    Node *ans = dummy->next;
    delete dummy; // freeing the space
    return ans;
}

// Swap nodes in pairs
// In this question what we have to do is that we have to swap the numbers in pairs
// suppose the inputed number is [1,2,3,4]
// The output will be [2,1,4,3]
ListNode *swapPairs(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *first = head, *sec = head->next, *start, *prev = NULL;
    start = head->next;
    while (sec != NULL)
    {
        first->next = sec->next;
        sec->next = first;
        if (prev != NULL)
        {
            prev->next = sec;
        }
        prev = first;
        first = first->next;
        if (first != NULL && first->next != NULL)
        {
            sec = first->next;
        }
        else
            break;
    }
    return start;
}

// To find whether the linkelist is a palindrome or not
// What we we do is that we will maintain a slow and fast pointer in this question and we will move the fast till fast->next->next!=NULL;
// Than we will make the half part after slow reverse and take a pointer which will point to the starting of the list and move regularly if we encounter that the slow pointer has reached NULL than the answer is true otherwise false;
// Time complexity:O(N) and space complexity:O(1)
ListNode *reverse(ListNode *node)
{
    ListNode *q = NULL, *r = NULL;
    while (node != NULL)
    {
        r = q;
        q = node;
        node = node->next;
        q->next = r;
    }
    return q;
}
bool isPalindrome(ListNode *head)
{
    ListNode *slow = head, *fast = head, *start = NULL;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    start = head;
    slow = reverse(slow->next);
    while (slow != NULL)
    {
        if (start->val != slow->val)
            return false;
        start = start->next;
        slow = slow->next;
    }
    return true;
}

// Reorder List In this question what we have to do is that we have to order the elements in the list like
// input : 1->2->3->4->5
// Output: 1->5->2->4->3
// Here we will take the fast slow pointer in such a way that the fast will point to NULL at last
ListNode *reverse(ListNode *node)
{
    ListNode *q = NULL, *r = NULL;
    while (node != NULL)
    {
        r = q;
        q = node;
        node = node->next;
        q->next = r;
    }
    return q;
}
void reorderList(ListNode *head)
{
    if (head->next == NULL)
        return;
    ListNode *slow = head, *fast = head, *prev = NULL;
    while (fast != NULL)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;
    }
    prev->next = NULL;
    fast = reverse(slow);
    slow = head;
    while (fast != NULL)
    {
        ListNode *temp1 = slow->next;
        ListNode *temp2 = fast->next;

        slow->next = fast;
        fast->next = temp1;

        slow = temp1;
        fast = temp2;
    }
}