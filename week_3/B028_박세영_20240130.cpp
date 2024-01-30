class Solution {
public:
    int arrangeCoins(int n) {
        int k = (sqrt(8*(long long)n+1)-1)/2;
        return k;
    }
};

// -----------------// 
// 1. 근의 공식을 씀 -> MAX_INT 일 때 overflow가 발생 -> type 을 변형한다. 
// int k = (sqrt(8*n+1)-1)/2;

// 2. 일반적인 방식 -> O(n)
// int k = 0;
// while(n>k){
//     k++;
//     n -= k; 
// }

// 3. binary search -> 복습 필요 
// O(log n )으로 푸는 방식 이해 
