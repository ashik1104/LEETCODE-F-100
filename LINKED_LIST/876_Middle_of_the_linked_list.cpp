class Solution {
public:
    
    // int list_size(ListNode *head)
    // {
    //     int size = 0;
    //     while(head != NULL)
    //     {
    //         size++;
    //         head = head->next;
    //     }
    //     return size;
    // }
    ListNode* middleNode(ListNode* head) {
        if(head == NULL)
        {
            return head;
        }
        
        ListNode *temp = head;
        int size = 0;
        while(temp != NULL)
        {
            size++;
            temp = temp->next;
        }
        
        //int sz = list_size(head);
        size = size/2;
        
        ListNode *temp2 = head;
        for(int i = 1; i <= size; i++)
        {
            temp2 = temp2->next;
        }
        return temp2;
    }
};