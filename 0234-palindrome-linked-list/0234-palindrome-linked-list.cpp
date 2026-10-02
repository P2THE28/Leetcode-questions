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
    bool isPalindrome(ListNode* head) {
        ListNode* head1 = NULL ; 
        ListNode* temp = head ; 

        while(temp!=NULL){
            ListNode* newNode = new ListNode ;
            newNode->val=temp->val ;
            newNode->next = NULL ;  
            if(head1==NULL){
                head1=newNode ;
            }else{
                newNode->next = head1 ; 
                head1=newNode ; 
            }
            temp=temp->next ; 
        }
        temp=head ; 
        while(temp!=NULL){
            if(temp->val!=head1->val) return false ;
            temp=temp->next ; 
            head1=head1->next ;  
        }
        return true ; 
    }
};