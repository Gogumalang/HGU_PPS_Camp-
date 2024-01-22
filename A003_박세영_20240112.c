/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    // 포인터를 활용하여, 동적할당도 하고, 배열 시작점도 자유롭게 할 수 있다. 

    // digit보다 한칸 더 큰 것으로 one을 malloc 한다.(overflow 고려) 
    // one의 LS 에 digit LS+1을 넣는다.  
    // 만약 값이 10이라면 값을 0으로 하고 한칸 뒤로 간다. 
    // 만약 값이 10보다 작다면, 나머지를 다 넣고, MS 를 NULL 처리를 하고, 한칸 앞에를 가르키게 한다. 

    int* p; // 배열 시작 포인터. 
    int* one = (int*)malloc((digitsSize+1)*(sizeof(int))); // 실제 값을 담을 배열: 최대크기 overflow 를 고려한 digitsSize+1

    for(int i =digitsSize;i>0;i--) {
        one[i] = digits[i-1] +1;
        if(one[i]==10) {
            one[i] = 0;
        }
        else {
            for(int j=0;j<i-1;j++) {
                one[j+1] = digits[j];
            }
            one[0] = NULL; // 메모리 공간을 free 한 것
            p = &one[1]; // 배열의 시작점을 옮김 
            *returnSize = digitsSize; 
            return p;
        }
    }
    one[0] = 1;
    *returnSize = digitsSize+1; 
    return one;



    // 일반적인 방식 :
    // 1. 만약 모든게 다 9로 되어있다면, size+1, 100-- 
    // 2. 아니라면 
    //      digitSize만큼 반복 
    //         현재 값 +1
    //         현재 값이 10라면 
    //             현재 인덱스 값 0 전 인덱스로 이동 
    //         아니라면 break; 

    // bool overflow = true; 
    // int i = digitsSize-1;
    // int* one;
    // for(int i=0;i<digitsSize;i++) {
    //     if(digits[i]!=9) {
    //         overflow = false;
    //         break;
    //     }
    // }
    // if (overflow == true) {
    //     *returnSize = digitsSize+1;
    //     one = (int*)malloc((*returnSize)*sizeof(int));
    //     one[0]=1;
    //     for(int i =1;i<(*returnSize);i++) {
    //         one[i] =0;
    //     }
    //     return one;
    // }
    // *returnSize = digitsSize;
    // one = digits;
    // while(1) {
    //     one[i]++;
    //     if(one[i]>9) {
    //         one[i]=0;
    //         i--;
    //     }
    //     else break;
    // }
    // return one;


}