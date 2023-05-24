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
    // recursive solution

    // vector<int> answer;
    // void solve(Node* root)
    // {
    //     if(root == NULL)
    //     {
    //         return;
    //     }
    //     for(int i = 0; i < root->children.size(); i++)
    //     {
    //         solve(root->children[i]);
    //     }
    //     answer.push_back(root->val);
    // }
    // vector<int> postorder(Node* root) {
    //     if(root == NULL)
    //     {
    //         return answer;
    //     }
    //     solve(root);
    //     return answer;
    // }

    // recursive solution

    vector<int> postorder(Node* root) {
        vector<int> answer;
        if(root == NULL)
        {
            return answer;
        }
        stack<Node*> s;
        stack<int> temp;
        s.push(root);
        while(!s.empty())
        {
            Node* node = s.top();
            s.pop();
            temp.push(node->val);

            for(int i = 0; i < node->children.size(); i++)
            {
                s.push(node->children[i]);
            }
        }

        while(!temp.empty())
        {
            answer.push_back(temp.top());
            temp.pop();
        }

        return answer;
    }
};