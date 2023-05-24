class Solution {
public:
    int list_size(ListNode *head)
    {
        int size = 0;
        while(head != NULL)
        {
            size++;
            head = head->next;
        }
        return size;
    }
    
    int getDecimalValue(ListNode* head) {
        
        int size = list_size(head);
        int hp = pow(2,(size-1));
        int decimal_val = 0;
        
        ListNode *temp = head;
        
        while(temp != NULL)
        {
            decimal_val += temp->val * hp;
            hp = hp/2;
            temp = temp->next;
        }
        
        return decimal_val;
        
    }
};