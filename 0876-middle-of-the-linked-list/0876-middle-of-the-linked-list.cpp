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
//method 1 ;
    // ListNode* middleNode(ListNode* head) {
    //     vector<ListNode*>v;
    //     ListNode* temp = head ;
    //     while(temp!=NULL){
    //         v.push_back(temp) ;
    //         temp=temp->next;
    //     }

    //     int n = v.size();
    //     return v[n/2] ;
    // }
//Method 2 ;
    ListNode* middleNode(ListNode* head) {
        int n = 0 ; 
        ListNode* temp=head ;
        while(temp!=NULL){
            n++;
            temp=temp->next ;
        }
        int c=0;
        temp = head ;
        while(c<n/2){
            temp = temp->next ;
            c++;
        }

        return temp ;

    }
};