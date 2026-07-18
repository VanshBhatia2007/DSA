class Solution {
public:
    int bs(vector<int>& arr, int tar , int st , int end){
        int mid = (st+end)/2;
        
        //base case
        if(st > end) return -1;

        //recursive case
        if(arr[mid]==tar) return mid;
        else if(arr[mid]<=tar) return bs(arr,tar,mid+1,end);
        else return bs(arr,tar,st,mid-1);
    }
    int search(vector<int>& arr, int tar) {
        return bs(arr,tar,0,arr.size()-1);
    }
};