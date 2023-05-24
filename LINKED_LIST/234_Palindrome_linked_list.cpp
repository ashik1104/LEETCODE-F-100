class Solution {
public:
    bool isPalindrome(ListNode* head) {
        
        stack<int> s;
        queue<int> q;
        
        ListNode *temp1 = head;
        while(temp1 != NULL)
        {
            s.push(temp1->val);
            q.push(temp1->val);
            temp1 = temp1->next;
            
        }
        
        while(!s.empty())
        {
            int val1 = s.top();
            int val2 = q.front();
            if(val1 != val2)
            {
                return false;
            }
            s.pop();
            q.pop();
        }
        
        return true;
    }
};