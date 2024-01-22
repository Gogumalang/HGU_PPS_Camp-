class MyCircularQueue {
private:
    int* q; 
    int front; 
    int rear; 
    int qSize;
public:
    MyCircularQueue(int k) {
        q = (int*) malloc(sizeof(int)*(k+1));
        qSize = k+1;
        front = 0;
        rear = 0;
    }
    
    bool enQueue(int value) {
        if(!isFull()) {
            q[rear] = value;
            rear = (rear+1)%qSize; 
            return true;
        }
        return false;

    }
    
    bool deQueue() {
        if(!isEmpty()) {
            front = (front+1) %qSize;
            return true;
        }
        return false;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return q[front];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return q[(rear+qSize-1)%qSize];
    }
    
    bool isEmpty() {
        if(front == rear) return true;
        return false;
    }
    
    bool isFull() {
        if((rear+1)%qSize == front) return true; 
        return false; 
    }
};

// f r
// 0 0
// 0 1
// 0 2 full 
// 1 0 
// 레어 +1 % size == front ; rare가 한칸 더 이동했을때 

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