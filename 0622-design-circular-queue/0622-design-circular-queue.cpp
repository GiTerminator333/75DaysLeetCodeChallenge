class MyCircularQueue {
    vector<int> q;
    int f=0, r = 0; //front, rear
    int size = 0;
    int k;
public:
    MyCircularQueue(int k) {
        q.resize(k, -1);
        this->k = k;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        q[r] = value;
        r = (r + 1)%k;
        size++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        q[f] = -1;
        f = (f + 1)%k;
        size--;
        return true;
    }
    
    int Front() {
        return q[f];
    }
    
    int Rear() {
        return q[(k + r - 1)%k];
    }
    
    bool isEmpty() {
        return size == 0; 
    }
    
    bool isFull() {
        return size == k;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */