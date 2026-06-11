// create a linked list ;

class node{
    public :
    int val ;
    node* next ;

    node(int val){
        this->next = NULL ;
        this->val = val ;
    }
};

int main (){
    Node* a = new Node(10) ;
    Node* b = new Node(20) ;
    Node* c = new Node(30) ;

    a->next = b ;
    b->next = c ;

    Node* temp = a ;

    while(temp != NULL{
        cout<<temp->val<<"->" ;
        temp = temp->next ;
    }
    return 0 ;
}