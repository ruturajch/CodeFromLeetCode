class MedianFinder {
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(leftHeap.size() == 0 && rightHeap.size() == 0){
            rightHeap.push(num);
            return;
        }
        if(num < rightHeap.top()){
            if(rightHeap.size() == leftHeap.size()){
                if(num < leftHeap.top()){
                    leftHeap.push(num);
                    rightHeap.push(leftHeap.top());
                    leftHeap.pop();
                }else{
                    rightHeap.push(num);
                }
                
            }else{
                leftHeap.push(num);
            }
            return;
        }else{
            rightHeap.push(num);
            if(rightHeap.size() - leftHeap.size() == 2){
                leftHeap.push(rightHeap.top());
                rightHeap.pop();
            }
            return;
        }
    }
    
    double findMedian() {
        if (leftHeap.size() == rightHeap.size()) {
            return (double)(leftHeap.top() + rightHeap.top()) / 2;
        } else {
            return rightHeap.top();
        }
    }
private:
    priority_queue<int> leftHeap;
    priority_queue<int, vector<int>,greater<int>> rightHeap;

};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */