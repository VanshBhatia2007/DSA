class Solution {
public:
    void merge(vector<int>& nums,int s,int e,int mid){
        vector<int> temp;
        int i=s,j=mid+1;
        while(i<=mid && j<=e){
            if(nums[i]<=nums[j]){
                temp.push_back(nums[i]);
                i++;
            }else{
                temp.push_back(nums[j]);
                j++;
            }
        }
        while(i<=mid){
            temp.push_back(nums[i]);
            i++;
        }
        while(j<=e){
            temp.push_back(nums[j]);
            j++;
        }
        for(int idx=0;idx<temp.size();idx++){
            nums[idx+s]= temp[idx];
        }

    }

    void mergesort(vector<int>& nums,int s,int e){
        //base case
        if(s<e){
            int mid = s + (e - s) / 2;
            mergesort(nums,s,mid); //left
            mergesort(nums,mid+1,e); //right
            merge(nums,s,e,mid);
        }
    }
    

    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums,0,nums.size()-1);
        return nums;
    }
};