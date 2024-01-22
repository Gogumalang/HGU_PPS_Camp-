class Solution {
public:
    int calPoints(vector<string>& operations) {
        int* scores = (int*) malloc(sizeof(int)*operations.size());
        int record = 0;
        for(int i =0;i<operations.size();i++) {
            if(operations[i]=="D") {
                if(record >=1) scores[record] = 2*scores[record-1];
                
            }
            else if(operations[i]=="+") {
                if(record>=2) scores[record] = scores[record-1] + scores[record-2] ;
            }
            else if(operations[i]=="C") {
                record --;
                scores[record]=0;
                record --;
                
            }
            else {
                char* p;
                int val = strtol(operations[i].c_str(),&p,10);
                scores[record]= val;
            }
            record ++;

        }
        int sum = 0;
        for(int i =0;i<record;i++) {
            sum+=scores[i];
        }
        return sum;
    }
};