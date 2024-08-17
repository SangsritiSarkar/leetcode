struct node{
    int key;
    int val;
    int freq;
    node* next;
    node* prev;
    node(int k, int v){
        key=k;
        val=v;
        freq=1; //new node therefore freq=1
    }
};

struct DLL{
    int size;
    node* head;
    node* tail;
    DLL(){
        head=new node(0,0);
        tail=new node(0,0);
        head->next=tail;
        tail->prev=head;
        size=0;
    }

    void insertNode(node* n){
        node* curr=head->next;
        head->next=n;
        n->next=curr;
        curr->prev=n;
        n->prev=head;
        size++;
    }

    void removeNode(node* n){
        node* prevnode=n->prev;
        node* nextnode=n->next;
        prevnode->next=nextnode;
        nextnode->prev=prevnode;
        size--;
    }
};



class LFUCache {
    int tot_cap,curr_cap,min_freq;
    unordered_map<int, node*> keynode;
    unordered_map<int, DLL*> freqlist;

public:
    LFUCache(int capacity) {
        tot_cap=capacity;
        curr_cap=0;
        min_freq=0;
    }

    void updateFreqList(node* n){
        //remove from map
        keynode.erase(n->key);
        //remove from freqlist map
        freqlist[n->freq]->removeNode(n);
        //if freq of n is min and now minFreq list is empty
        if(n->freq==min_freq and freqlist[n->freq]->size==0){
            min_freq++; //update min_freq
        }
        DLL* nextHigherFreqList=new DLL();
        if(freqlist.find(n->freq+1)!=freqlist.end()){ //next higher freqlist exists
            nextHigherFreqList= freqlist[n->freq+1];
        }
        nextHigherFreqList->insertNode(n);
        n->freq++;
        freqlist[n->freq]=nextHigherFreqList;
        keynode[n->key]=n;
    }
    
    int get(int key) {
        if(keynode.find(key)==keynode.end()) return -1;
        node* n=keynode[key];
        int v=n->val;
        updateFreqList(n); //remove from freqList map, keynode map, update freqList
        return v;
    }
    
    void put(int key, int value) {
        if(tot_cap==0) return;
        if(keynode.find(key)!=keynode.end()){ //node exits
            node* n=keynode[key];
            n->val=value;
            updateFreqList(n); //remove from freqList map, keynode map, update freqList
        }
        else{ //new node-->this will have min_freq and inserted after head of freqList=1
            if(curr_cap==tot_cap){ //cache full
                //REMOVE LFU NODE
                DLL* min_list=freqlist[min_freq]; 
                keynode.erase(min_list->tail->prev->key); //remove from keynode map
                freqlist[min_freq]->removeNode(min_list->tail->prev);   //remove from freqlist map
                --curr_cap;
            }
            ++curr_cap; //insert new node
            min_freq=1; //new node
            DLL* newList=new DLL(); //new list for min_freq
            if(freqlist.find(min_freq)!=freqlist.end()){ //1 freq list exists
                newList= freqlist[min_freq]; //newList same as 1 freq list
            }
            node* n=new node(key,value);
            newList->insertNode(n);
            keynode[key]=n;
            freqlist[min_freq]=newList;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */