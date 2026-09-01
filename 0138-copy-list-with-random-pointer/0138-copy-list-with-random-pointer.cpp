/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* head1 = NULL ;
        Node* tail = NULL ; 
        Node*temp=head ;
        while(temp!=NULL){
            Node* newNode = new Node(temp->val) ;
            if(head1==NULL){
                head1=newNode ;
                tail =newNode ;
            }else{
                tail->next=newNode ;
                tail = newNode ;
            }
            temp=temp->next ;
        }
        Node* t1 =head ;
        Node* t2 =head1 ;

        while(t1!=NULL){
            Node* temp1=head;
            Node* temp2=head1;
            if(t1->random==NULL){
                t2->random=NULL ;
            }else{
                while(t1->random!=temp1){
                    temp1=temp1->next ;
                    temp2=temp2->next ;
                }
                t2->random=temp2;
            }
            t1=t1->next ;
            t2=t2->next ;
        }
        return head1 ;
    }
};