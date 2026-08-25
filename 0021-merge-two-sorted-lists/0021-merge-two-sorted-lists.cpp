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
    ListNode* mergeTwoLists(ListNode* h1, ListNode* h2) {
        ListNode* t1 ;
        ListNode* t2 ;
        ListNode* t ;
        ListNode* h ;
        if(h1!=NULL && h2 !=NULL){
            h = ((h1->val) <= (h2->val)) ? h1 : h2 ;
            t1=h1 ;
            t2=h2 ;
            t=NULL;

            while(t1!=NULL && t2!=NULL){
                if((t1->val)<=(t2->val)){
                    if(t==NULL){
                        t=t1;
                    }else{
                        t->next=t1;
                        t=t1;
                    }
                    t1=t1->next;
                }else{
                    if(t==NULL){
                        t=t2;
                    }else{
                        t->next=t2;
                        t=t2;
                    }
                    t2=t2->next ;   
                }
            }
            if(t1==NULL){
                t->next=t2 ;
            }else{
                t->next=t1 ;
            }
        }else if(h1==NULL){
            h=h2;
        }else if(h2==NULL){
            h=h1;
        }
        
        
        return h ;
    }
};