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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* head = NULL ; 
        ListNode* tail = NULL ; 

        ListNode* temp1 = l1 ; 
        ListNode* temp2 = l2 ; 
        int carry = 0 ; 

        while(temp1!=NULL && temp2 !=NULL){
            int d1 = temp1->val ;
            int d2 = temp2->val ; 
            int sum = d2+d1+carry ; 

            ListNode* newNode = new ListNode ;
            newNode->next = NULL ; 
            newNode->val=sum%10 ; 
            if(head==NULL) {
                head=newNode ; 
                tail=newNode ; 
            }else{
                tail->next = newNode ; 
                tail=newNode ; 
            }
            carry=sum/10 ;

            temp1=temp1->next ; 
            temp2=temp2->next ;
        }

        if(temp2==NULL && temp1!=NULL){
            while(temp1!=NULL){
                int d1 = temp1->val + carry ; 
                temp1->val=d1%10 ; 
                carry=d1/10 ;
                tail->next = temp1 ; 
                tail = temp1 ; 
                temp1=temp1->next ;  
            }
        }

        if(temp1==NULL && temp2!=NULL){
            while(temp2!=NULL){
                int d1 = temp2->val + carry ; 
                temp2->val=d1%10 ; 
                carry=d1/10 ;
                tail->next = temp2 ; 
                tail= temp2 ; 
                temp2=temp2->next ; 
            }
        }

        if(temp1==NULL && temp2==NULL && carry!=0){
            ListNode* newNode = new ListNode ;
            newNode->next = NULL ; 
            newNode->val=carry; 
            tail->next = newNode ; 
            tail=newNode ; 
        }
        return head ; 
    }
};