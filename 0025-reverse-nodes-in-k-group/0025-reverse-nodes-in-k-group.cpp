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
    ListNode* reverse(ListNode* head , int k ){
        int c = 0 ;
        ListNode* temp=head ;  
        while(c<k){
            if(temp==NULL){
                return head ; 
            }
            temp=temp->next ;
            c++;
        }
        ListNode* posthead = reverse(temp,k) ;
        ListNode* curr = head  ; 
        ListNode* Next = curr->next ; 
        while(c--){
            curr->next = posthead ; 
            posthead = curr ; 
            curr = Next ; 
            if(Next!=NULL) Next=curr->next ; 
        }
        return posthead ; 
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        return reverse(head , k) ;
    }
};