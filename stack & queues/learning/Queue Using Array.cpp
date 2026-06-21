class myQueue {
    
    int n ;
    int size ;
    vector<int>arr ;
  public:
    myQueue(int n) {
        // Define Data Structures
        this->n = n ;
         size = 0 ;
    }

    bool isEmpty() {
        // check if the queue is empty
        if(size == 0) return true ;
        else return false ;
    }

    bool isFull() {
        // check if the queue is full
        if(size == n) return true ;
        else return false ;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue.
        if(size == n) return ;
        arr.push_back(x) ;
        size++ ;
        return ;
    }

    void dequeue() {
        // Removes the front element of the queue.
        if(size == 0) return ;
       arr.erase(arr.begin()) ;
       size-- ;
        return ;
    }

    int getFront() {
        // Returns the front element of the queue.
        if(size == 0 ) return -1 ;
        return arr[0] ;
    }

    int getRear() {
        // Return the last element of queue
        if(size == 0) return -1 ;
        return arr[size-1] ;
    }
};