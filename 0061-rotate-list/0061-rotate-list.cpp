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
    ListNode* rotateRight(ListNode* head, int k) {
        int n = 0 ; 
        ListNode* temp=head ; 
        while(temp!=NULL){
            n++;
            temp=temp->next ; 
           
        }

        ListNode* temphead  = head ; 

        if(n!=0) k = k%n ; 

        for(int i = 0 ; i < k && n>k ;i++){
            temp=temphead ; 
            while(temp->next->next!=NULL){
                temp=temp->next ; 
            }
            temp->next->next = head ; 
            head = temp->next ; 
            temp->next = NULL ;
        }
        return head ; 
    }
};