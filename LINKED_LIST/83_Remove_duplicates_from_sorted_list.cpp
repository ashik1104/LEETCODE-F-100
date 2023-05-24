class Solution {
public:
    
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)
        {
            return head;
        }
        ListNode *temp = head;
        
        while(temp->next != NULL)
        {
            //bool chk = false;
            if(temp->val == temp->next->val)
            {
                ListNode *del = temp->next;
                temp->next = temp->next->next;
                delete del;
                //chk = true;
            }
            else
            {
                temp = temp->next;
            }
            
        }
        
        
        return head;
        
    }
};