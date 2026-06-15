/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */


// Leetcode :- 707
class Node {
public:
    int val;
    Node* next;
    Node* prev;

    Node(int val) {
        this->val = val;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class MyLinkedList {
public:
    Node* head;
    Node* tail;
    int size;

    MyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    int get(int index) {
        if(index < 0 || index >= size) return -1;

        Node* temp;

        if(index < size / 2) {
            temp = head;
            for(int i = 0; i < index; i++) {
                temp = temp->next;
            }
        } else {
            temp = tail;
            for(int i = size - 1; i > index; i--) {
                temp = temp->prev;
            }
        }

        return temp->val;
    }

    void addAtHead(int val) {
        Node* temp = new Node(val);

        if(size == 0) {
            head = tail = temp;
            size++;
            return;
        }

        temp->next = head;
        head->prev = temp;
        head = temp;

        size++;
    }

    void addAtTail(int val) {
        Node* temp = new Node(val);

        if(size == 0) {
            head = tail = temp;
            size++;
            return;
        }

        temp->prev = tail;
        tail->next = temp;
        tail = temp;

        size++;
    }

    void addAtIndex(int index, int val) {

        if(index > size) return;

        if(index <= 0) {
            addAtHead(val);
            return;
        }

        if(index == size) {
            addAtTail(val);
            return;
        }

        Node* temp;

        if(index < size / 2) {
            temp = head;
            for(int i = 0; i < index - 1; i++) {
                temp = temp->next;
            }
        } else {
            temp = tail;
            for(int i = size - 1; i > index - 1; i--) {
                temp = temp->prev;
            }
        }

        Node* newNode = new Node(val);
        Node* nxt = temp->next;

        newNode->next = nxt;
        newNode->prev = temp;

        temp->next = newNode;
        nxt->prev = newNode;

        size++;
    }

    void deleteAtIndex(int index) {

        if(index < 0 || index >= size) return;

        if(size == 1) {
            delete head;
            head = tail = nullptr;
            size = 0;
            return;
        }

        if(index == 0) {
            Node* temp = head;

            head = head->next;
            head->prev = nullptr;

            delete temp;
            size--;
            return;
        }

        if(index == size - 1) {
            Node* temp = tail;

            tail = tail->prev;
            tail->next = nullptr;

            delete temp;
            size--;
            return;
        }

        Node* temp;

        if(index < size / 2) {
            temp = head;
            for(int i = 0; i < index; i++) {
                temp = temp->next;
            }
        } else {
            temp = tail;
            for(int i = size - 1; i > index; i--) {
                temp = temp->prev;
            }
        }

        Node* left = temp->prev;
        Node* right = temp->next;

        left->next = right;
        right->prev = left;

        delete temp;
        size--;
    }
};

