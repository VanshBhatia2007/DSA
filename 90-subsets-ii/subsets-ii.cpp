class Solution {
public:

    void subsetwithdup(vector<int>& nums,vector<int>& ans, int i,vector<vector<int>>& allsubset){
        //base case
        if(i == nums.size()){
            allsubset.push_back({ans});
            return;
        }

        //include
        ans.push_back(nums[i]);
        subsetwithdup(nums,ans,i+1,allsubset);

        //backtrack
        ans.pop_back();

        //check dup
        int idx = i+1;
        while(idx < nums.size() && nums[idx] == nums[idx-1]) idx++;

        //exclude
        subsetwithdup(nums,ans,idx,allsubset);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums ) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> allsubset;
        vector<int> ans;
        subsetwithdup(nums,ans,0,allsubset);
        return allsubset;
    }
};