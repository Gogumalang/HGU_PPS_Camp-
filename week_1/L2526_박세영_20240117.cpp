class DataStream {
    int count;
    int d, n;
public:
    DataStream(int value, int k) {
        count =1;
        d= value;
        n =k;
    }
    
    bool consec(int num) {
        if(num!= d) {
            count =1;
            return false;
        }
        else if(count<n){
            count++;
            return false;
        }
        else {
            return true;
        }
    }
};
// num이 
// value 랑 같지만 개수가 작은 경우 
//     false 리턴, queue에 추가 

// 44434343444444444

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */