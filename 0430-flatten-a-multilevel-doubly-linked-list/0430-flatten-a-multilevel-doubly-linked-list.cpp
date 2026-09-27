/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* solve(Node* par ){
        Node* curr = par ; 
        while(curr!=NULL){
            if(curr->child!=NULL){ 
                Node* last = solve(curr->child) ;
                last->next = curr->next ; 
                if(curr->next!=NULL) curr->next->prev= last ;
                curr->next=curr->child ; 
                curr->child->prev=curr ;
                curr->child=NULL ;  
            }
            if(curr->next==NULL) break ; 
            curr=curr->next ; 
        }
        return curr ;
    }

    Node* flatten(Node* head) {
        solve(head) ;
        return head ; 
    }
};