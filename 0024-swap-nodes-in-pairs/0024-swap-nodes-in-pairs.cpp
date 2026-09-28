/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        int k = 2 ; 
        ListNode* temp = head ; 
        while(k--){
            if(temp==NULL){
                return head ;
            }
            temp=temp->next ;
        }
        ListNode* postnode = swapPairs(temp) ;
        ListNode* curr = head ; 
        ListNode* Next = curr->next ; 
        k=2 ; 
        while(k--){
            curr->next = postnode ; 
            postnode = curr ; 
            curr=Next ; 
           if(Next != NULL ) Next = curr->next ;  
        }
        return postnode ; 
    }
};