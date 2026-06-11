
void deleteATBegining(node* head){
    if(head == nullptr) return ;

    node* temp = head ;
    temp = temp->next ;

    delete head ;
    head = temp ;
    size-- ;
}

void deleteATend(node* head){
    node* temp = head ;
    while(temp->next->next != nullptr){
        temp = temp->next ;
    }
    temp->next = NULL ;
    size-- ;
}

void deleteAt(int idx , node* head){
    if(size == 0) {
        cout<<"list is empty" ;
        return ;
    } 
    else if(idx <0 && idx>size){
        cout<<"invalid idx " ;
        return ;
    }

    else if(idx == 0) deleteATBegining(head) ;
    else if (idx == size-1) deleteATend(head) ;
    else {
        node* temp = head ;
        for(int i=1 ; i<=idx-1 ; i++){
            temp = temp->next ;
        }
        temp->next = temp->next->next ;
        size-- ;
    }
}