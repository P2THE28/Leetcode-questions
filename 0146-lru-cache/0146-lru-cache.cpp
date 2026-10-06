class Node {
public:
    Node(int Key , int value){
        data = value ;
        key = Key ; 
        next=NULL ; 
        pre=NULL ; 
    }
    int data ;
    int key ; 
    Node* next ; 
    Node* pre ; 
};

class Dlist {
public :
    Node* head ; 
    Node* tail ;

    Dlist(){
        head = NULL ; 
        tail = NULL ; 
    }

    Node* insert(int key , int data){
        Node* newNode= new Node(key,data) ;
        if(head==NULL){
            tail = head = newNode ;
        }else{
            newNode->pre=tail ; 
            tail->next = newNode ; 
            tail=newNode ; 
        }
        return newNode ; 
    }

    void remove(Node* node){
        Node* Pre = node->pre ; 
        Node* Next = node->next ; 
        if(Pre!=NULL) Pre->next = Next ; 
        if(Next!=NULL) Next->pre = Pre ; 
        if(node==head) head = Next ; 
        if(node==tail) tail = Pre ; 
        delete node ; 
    }
};



class LRUCache {
private:
    unordered_map<int,Node*> m ;
    int c ;
    int s = 0 ; 
public:
    LRUCache(int capacity) {
        c = capacity ; 
    }
    Dlist dl ;
    int get(int key) {
        if(m.find(key)==m.end()) return -1 ; 
        int value = m[key]->data ;
        dl.remove(m[key]);
        m[key]=dl.insert(key,value) ; 
        return m[key]->data ; 
    }
    
    void put(int key, int value) {
        
        if(m.find(key)==m.end()){
            if(s==c){
                m.erase(dl.head->key) ;
                dl.remove(dl.head) ;
                s-- ;
            }
            m[key]=dl.insert(key,value) ;
            s++ ;
        }else{
            dl.remove(m[key]) ;
            m[key]=dl.insert(key,value) ;
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */