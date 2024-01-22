class Solution {
public:
    int mySqrt(int x) {
        if(x==0||x==1) return x;
        int i = 1;
        int j = x-1;
        int m = (i+j)/2; 
        do{
            if(x/m < m) j = m;
            else if(x/m > m) i=m;
            else return m;
            m = (i+j)/2; 
        }while((j-i) >1);
        return i;
    }
};