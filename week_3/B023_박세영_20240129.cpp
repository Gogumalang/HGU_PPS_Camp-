class KthLargest {
public:
    int size;
    priority_queue<int,vector<int>,greater<int>> pq;
    KthLargest(int k, vector<int>& nums) {
        for(auto l:nums) {
            pq.push(l);
        }
        size = k;
        
    }
    
    int add(int val) {
       pq.push(val);

        while(pq.size()>size) {
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

//  heap으로 초기화를 한다. 
//  add -> heap 에 원소를 넣고, k번째 반복했을때 큰 수를 리턴 한다. 

// KthLargest(int k, vector<int>& nums) {
//         h= nums;
//         make_heap(h.begin(),h.end());
//         kth_index = k;
        
//     }
    
//     int add(int val) {
//        int ans;
//        h.push_back(val);
//        push_heap(h.begin(),h.end());
//        for(int i =0;i<kth_index-1;i++) {
//            pop_heap(h.begin(),h.end()-i);
//        }
//         ans = h[0];
//         make_heap(h.begin(),h.end());
//         return ans;
//     }