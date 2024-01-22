/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    // 파스칼 삼각형 크기 numRows 
    // 이차원 배열을 생성한다. 전체크기Row는 numRows만큼 malloc 한다. 

    // i=0 부터 numRows-1까지 반복한다. : 한줄의 파스칼을 완성하기 위함. 
    //     j=0부터 i까지 반복한다. 
    //         i의 크기만큼 배열[i] 내의 크기를 malloc 한다. 
    //         만약 j가 0 또는 i(끝)이면 1을 넣는다. 
    //         아니라면 배열[i][j] = 배열[i-1][j-1] + 배열[i-1][j]를 더한다. 
    *returnSize = numRows;
    *returnColumnSizes = (int*)malloc(numRows * sizeof(int));
    int** pascal; 
    pascal = (int**) malloc(sizeof(int*)*numRows);
    
    for(int i=0; i<numRows;i++) {
            (*returnColumnSizes)[i] = i+1;
            pascal[i] = (int*)malloc(sizeof(int)*(i+1));
        for(int j =0;j<=i;j++) {
            
            if(j==0||j==i) pascal[i][j] = 1;
            else pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
        }
    }
    return pascal;
}