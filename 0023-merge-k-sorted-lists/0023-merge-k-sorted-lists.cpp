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
    ListNode* merge(ListNode* head1 , ListNode* head2){
        ListNode* temp1 = head1 ; 
        ListNode* temp2 = head2 ; 
        ListNode* ans = NULL ; 
        if(head1!=NULL && head2!=NULL){
            if( head1->val < head2->val){
                ans = temp1 ;
                temp1=temp1->next ;  
            }else{
                ans = temp2 ; 
                temp2=temp2->next ; 
            }
        }else if(head1==NULL){
            return head2 ; 
        }else{
            return head1 ; 
        }
        
        ListNode* curr = ans ; 
        while(temp1!=NULL && temp2!=NULL){
            int data1 = temp1->val ; 
            int data2 = temp2->val ; 
            if(data1 < data2){
                curr->next=temp1 ; 
                curr=temp1 ; 
                temp1=temp1->next ; 
            }else{
                curr->next=temp2 ; 
                curr=temp2 ; 
                temp2=temp2->next ; 
            }
        }

        if(temp1==NULL){
            curr->next = temp2 ;
        }else{
            curr->next = temp1 ; 
        }
        return ans ; 
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL ; 
        ListNode* initial = lists[0]  ; 
        for(int i = 1 ; i < lists.size() ;i++){
            initial = merge(initial,lists[i]) ;
        }
        return initial ; 
    }
};