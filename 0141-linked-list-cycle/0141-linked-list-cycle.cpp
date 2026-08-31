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
    bool hasCycle(ListNode *head) {
        ListNode *t1 = head ;
        ListNode *t2 = head ;
        bool found = false ;
        while(t2!=NULL && t2->next!=NULL){
            t1=t1->next ;
            t2=t2->next->next ;
            if(t1==t2){
                return true ;
            }
        }

        return false ;
    }
};