/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head ; 
        ListNode *fast = head ;
        bool found = false ; 
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next ;
            fast=fast->next->next ;
            if(slow==fast){
                slow=head ;
                // method 1 ; 
                // while(slow!=fast){
                //     slow=slow->next ;
                //     fast=fast->next ;
                // }
                // return fast ;
                found = true ; 
                break ;
            }
        }
        if(found == true){ 
            while(slow!=fast){
                slow=slow->next ;
                fast=fast->next ;
            }
            return fast ;
        }
        return NULL ; 
    }
};