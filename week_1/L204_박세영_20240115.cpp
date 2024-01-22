class Solution {
public:
    int countPrimes(int n) {
        if(n==0||n==1) return 0;
        int* sieve = (int*) malloc(sizeof(int)*(n+1));
        for(int i=0;i<=n;i++) sieve[i] = 1;
        int num;
        int count=0;
        for(int i=2;i<n;i++) {
            if(sieve[i]!=0) sieve[i] =1;
            else continue; 
            for(int j=2;i*j<n;j++) {
                sieve[i*j] =0;
            }

        }

        for(int i=2;i<n;i++) {
            if(sieve[i]==1) count++;
        }
        return count;
    }
};