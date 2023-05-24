class Solution {
public:
    ListNode *head = NULL;
    
    void insert_at_tail(int val)
    {
        ListNode *newnode = new ListNode(val);
        if(head == NULL)
        {
            head = newnode;
            return;
        }
        
        ListNode *temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        
        ListNode *a = list1;
        ListNode *b = list2;
        
        
        while(a != NULL && b != NULL)
        {
            if(a->val <= b->val)
            {
                insert_at_tail(a->val);
                a = a->next;
            }
            else
            {
                insert_at_tail(b->val);
                b = b->next;
            }
        }
        while(a != NULL)
        {
            insert_at_tail(a->val);
            a = a->next;
        }
        while(b != NULL)
        {
            insert_at_tail(b->val);
            b = b->next;
        }
        
        return head;
        
    }
};