class node{
    int val ;
    node* next ;

    node(int val){
        this->val = val ;
        this->next = NULL ;
     }
};

void insertATBeginning(int val , int idx  , node* head){
   
    node* temp = new node(val) ;
    if(head == nullptr) {
     head = temp ;
    } 
   else{
     temp->next = head ;
     head = temp ;
   }
   size++ ;
}

void insertATEnd(int val , int idx , node* head){
    node* temp = new node(val) ;

    if(size == 0) head = temp ;
    else {
        node* a = head ;
        while(a->next != NULL){
            a = a->next ;
        }
        a->next = temp ;
    }
    size++ ;
}

void insertAT(int val , int idx , node* head){
    if(idx <0 || idx>size) return ;
    else if(idx == 0) insertATBeginning( val ,  idx , head ) ;
    else if (idx == size) insertATEnd(val , idx , head) ;
    else {
        node* temp = new node(val) ;
        node* a = head ;
        
       for(int i=1 ; i<=idx-1 ; i++){
            a = a->next ;
       }
       temp->next = a->next ;
       a->next = temp ;
       size++ ;
    }
}