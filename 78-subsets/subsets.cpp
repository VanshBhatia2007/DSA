class Solution {
public:

    void getallsub(vector<int>& nums ,vector<int>& ans, int i , vector<vector<int>>& allsub){
        //base case
        if(i==nums.size()){
            allsub.push_back({ans});
            return ;
        }

        //include
        ans.push_back(nums[i]);
        getallsub(nums,ans,i+1,allsub);

        //backtrack
        ans.pop_back();

        //exclude
        getallsub(nums,ans,i+1,allsub);
    }
    vector<vector<int>> subsets(vector<int>& nums){
        vector<vector<int>> allsub;
        vector<int> ans;
        getallsub(nums,ans,0,allsub);
        return allsub;
    }
};