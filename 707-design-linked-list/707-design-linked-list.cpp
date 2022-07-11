class Node{
    public:
        int val;
        Node *next;
        Node(int val){
            this->val = val;
            next = NULL;
        }
};
class MyLinkedList {
public:
    int size;
    Node *head;
    MyLinkedList() {
        head = NULL;
        size = 0;
    }
    
    int get(int index) {
        if(index >= size || index < 0) return -1;
        int cnt = 0;
        Node *temp = head;
        while(temp != NULL && cnt < index){
            temp = temp->next;
            cnt++;
        }
        return temp->val;
    }
    
    void addAtHead(int val) {
        Node *temp = new Node(val);
        temp->next = head;
        head = temp;
        size++;
    }
    
    void addAtTail(int val) {
        Node *temp = head;
        if(head == NULL){
            head = new Node (val);
        }
        else{
            while(temp->next){
                temp = temp->next;
            }
            Node *node = new Node(val);
            temp->next = node;
        }
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index > size || index < 0) return;
        Node *temp = head;
        Node *node = new Node(val);
        int cnt = 1;
        if(index == 0){
            node->next = head;
            head = node;
        }
        else{
            while(temp && cnt < index){
                temp = temp->next;
                cnt++;
            }
            node->next = temp->next;
            temp->next = node;
        }
        size++;
    }
    
    void deleteAtIndex(int index) {
        Node *temp = head;
        if(index >= size || index < 0) return;
        if(index == 0){
            Node *temp = head->next;
            delete head;
            head = temp;
        }
        else{
            int cnt = 1;
            while(temp && cnt < index){
                temp = temp->next;
                cnt++;
            }
            Node *p = temp->next;
            temp->next = p->next;
            delete p;
        }
        size--;
    }
    ~MyLinkedList(){
        Node *p = head;
        while(head){
            head = head->next;
            delete p;
            p = head;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */