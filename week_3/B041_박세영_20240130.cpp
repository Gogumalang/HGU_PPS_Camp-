class Solution {
public:
    int maximum69Number (int num) {
        int divisor = 1000000000;
        while(1) {
            if(divisor ==0) break;
            if((num/divisor)%10 == 6 ){
                num+=3*divisor;
                break;
            }
            divisor /= 10;
        }
        return num;

    }
};