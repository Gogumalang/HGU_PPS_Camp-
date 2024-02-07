class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t reverse = 0;

        for(int i = 0; i<32; i++) {
            uint32_t mod = n%2;
            n/=2;
            
            reverse *=2;
            reverse +=mod;
        }
        return reverse;
    }
};