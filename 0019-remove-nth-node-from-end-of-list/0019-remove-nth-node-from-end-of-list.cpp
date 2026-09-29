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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int c = 1 ; 
        ListNode* temp = head ; 
        ListNode* temp9 = head ; 
        int sz = 0 ; 
        while(temp9!=NULL){
            temp9=temp9->next ; 
            sz++ ;
        }
        n=sz-n+1 ;
        
        if(n==1){
            head=head->next ; 
            delete temp ;
        }else{
            while(c!=n-1){
                temp=temp->next ; 
                c++;
            }
            ListNode* temp2 = temp->next ; 
            temp->next = temp2->next ; 
            delete temp2 ;
        }
        
         
        return head ; 
    }
};