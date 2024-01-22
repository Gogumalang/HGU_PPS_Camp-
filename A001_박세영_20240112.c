void swap(int *r, int *l) {
    int temp = *r;
    *r = *l;
    *l = temp;
}

void quickSort(int a[],int left, int right) {
    int pivot= a[left];

    int i = left;
    int j=right+1;
    if(left >= right) return;
    do{
        do{
            i++; // pivot 값이 left 에 있어서 무조건 left보다 하나 큰 상태에서 비교해야함 
        }while((i <= right) && (a[i]>pivot));

        do{
            j--; // right 값이 size에 해당이 되어서 무조건 하나 작게 해야함. 
        }while(a[j]<pivot);
        if(i<j) swap(&a[i],&a[j]);

    }while(i<j);

    swap(&a[left],&a[j]);

    quickSort(a,left, j-1);
    quickSort(a,j+1,right);


}

int findContentChildren(int* g, int gSize, int* s, int sSize) {
    // 가장 작은 사이즈를 만족하는 아이 - 쿠키들중 가장 작은 사이즈 쿠키를 연결해야함. 
    // 먼저 가장 작은 사이즈의 아이를 찾는다. -> 정렬을 한다. 
    // 가장 작은 사이즈쿠키를 나열한다 -> 정렬을 한다. 
    // 첫번째 아이부터 가장 작은 사이즈 쿠키를 찾는다. 최소한 같을 때까지. 
    //     찾으면 ouput ++ , 다음 쿠키의 인덱스를 저장한다.
    
    int output=0; 
    if(gSize == 0 || sSize ==0) return output;

    quickSort(g,0,gSize-1);
    quickSort(s,0,sSize-1);
    
    int z=0;
    for(int i=0;i<gSize;i++) {
        for(int j=z;j<sSize;j++) {
            if(g[i]<=s[j]) {
                output ++;
                z= j+1;
                break;
            } 
        }
    }
    return output;
}

