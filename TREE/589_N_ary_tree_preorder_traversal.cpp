// Implemented with both recursion and iteration

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    // vector<int> answer;
    // void solve(Node * root)
    // {
    //     if(root == NULL)
    //     {
    //         return;
    //     }
    //     answer.push_back(root->val);
    //     for(int i = 0; i < root->children.size(); i++)
    //     {
    //         solve(root->children[i]);
    //     }

    // }
    vector<int> preorder(Node* root) {
        // if(root == NULL)
        // {
        //     return answer;
        // }
        // solve(root);
        // return answer;

        vector<int> solution;
        if(root == NULL)
        {
            return solution;
        }
        stack<Node *> s;
        s.push(root);
        while(!s.empty())
        {
            Node * head = s.top();
            s.pop();
            solution.push_back(head->val);
            for(int i = head->children.size() - 1; i >= 0; i--)
            {
                s.push(head->children[i]);
            }
        }
        return solution;
    }

    
};