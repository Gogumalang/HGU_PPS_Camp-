void swap(vector<int> &a,vector<int> &b) {
    vector<int> temp = a;
    a = b;
    b = temp;
}

void quickSort(vector<vector<int>> &list, int left,int right) {
    int i = left;
    int j = right+1;
    if(left>=right) return ;
    int pivot = list[left][1];

    do{
        do{
            i++;
        }while((i<right) && (pivot > list[i][1]));
        do{
            j--;
        }while(pivot <= list[j][1]);
        if(i<j) swap(list[i],list[j]);
    }while(i<j);

    swap(list[left],list[j]);

    quickSort(list,left,j-1);
    quickSort(list,j+1,right);

}

static bool compare(const vector<int> &v1, const vector<int> &v2) {
    return v1[1]>v2[1];
}

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        //quickSort(boxTypes,0,boxTypes.size()-1);
        sort(boxTypes.begin(),boxTypes.end(),compare);
        int sum_units =0;
        int i =0;
        for(int i =0;i<boxTypes.size();i++){
            if(truckSize - boxTypes[i][0] >0) {
                sum_units += boxTypes[i][0]*boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            }
            else {
                sum_units += truckSize*boxTypes[i][1];
                break;
            }
        }

        return sum_units;
    }
};

