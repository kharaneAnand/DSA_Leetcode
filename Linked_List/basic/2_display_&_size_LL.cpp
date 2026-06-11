void display(Node* head){
    Node* temp = head ;

    while(temp != NULL){
        cout<<temp->val ;
        temp = temp->next ;
    }
}

int size(Node* head){
    Node* temp = head ;
    int ans = 0 ;
    while(temp != NULL){
        ans++ ;
        temp = temp->next ;
    }
    return ans ;
}

// recursively display 

void display(Node* head){
    if(head == NULL) return ;
    cout<<head->val <<" " ;
    display(head->next) ;
}

