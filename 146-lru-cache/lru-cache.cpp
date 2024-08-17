class LRUCache {
public:
    class node{
        public:
        int key;
        int val;
        node* next;
        node* prev;
        node(int k, int v){
            key=k;
            val=v;
        }
    };

    int cap;
    unordered_map<int,node*> mp;
    node* head=new node(-1,-1);
    node* tail=new node(-1,-1);

    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    void deleteNode(node* n){
        node* prevNode=n->prev;
        node* nextNode=n->next;
        prevNode->next=nextNode;
        nextNode->prev=prevNode;
    }

    void insertAfterHead(node* n)
    {
        node* curr=head->next;
        head->next=n;
        n->prev=head;
        n->next=curr;
        curr->prev=n;
    }

    int get(int key) {
        if(mp.find(key)==mp.end()) return -1; //key not exist
        node* n=mp[key];   //take node
        //update LRU
        deleteNode(n);
        insertAfterHead(n);
        mp.erase(key);
        mp[key]=head->next;
        //return value
        return n->val;
        
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){ //if already present
            //update value
            node* n=mp[key];
            n->val=value;
            //update LRU
            deleteNode(n);
            insertAfterHead(n);
            mp.erase(key);
            mp[key]=head->next;
        }
        else{//not present
            if(mp.size()==cap){ //size full
                //delete last node
                node* last=tail->prev;
                deleteNode(last); //from LRU
                mp.erase(last->key);  //from map
            } 
            //insert into LRU
            node* newNode = new node(key,value);
            insertAfterHead(newNode); //in LRU
            mp[key]=newNode;// in map
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */