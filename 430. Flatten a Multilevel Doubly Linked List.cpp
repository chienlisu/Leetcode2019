/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        
        if (head == NULL)
            return head;

        Node* curr = head;
        
        while (curr != NULL)
        {
            if (curr->child != NULL)
            {
                Node* tail = curr->child;
                while (tail->next != NULL)
                {
                    tail = tail->next;
                }
                
                tail->next = curr->next;
                curr->next = curr->child;
                curr->child = NULL;
                
                // handle prev
                curr->next->prev = curr;
                if (tail->next != NULL)
                {
                    tail->next->prev = tail; 
                }
            }
            
            curr = curr->next;
        }
        return head;
    }
};
