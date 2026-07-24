class Solution {
public:
    set<vector<int>> s;

    void getcombinations(vector<int>& arr,int idx ,int tar, vector<vector<int>>& ans,vector<int>& combi){
        //base case
        if(idx == arr.size() || tar < 0){
            return;
        }
        if(tar == 0){
            if(s.find(combi)==s.end()){
                ans.push_back({combi});
                s.insert(combi);
            }
            return;

        }

        combi.push_back(arr[idx]);
        //include
        getcombinations(arr,idx+1,tar-arr[idx],ans,combi);
        //multiple
        getcombinations(arr,idx,tar-arr[idx],ans,combi);
        //backtrack
        combi.pop_back();
        //exclude
        getcombinations(arr,idx+1,tar,ans,combi);


    }
    vector<vector<int>> combinationSum(vector<int>& arr, int tar) {
        vector<vector<int>> ans;
        vector<int> combi;
        getcombinations(arr,0,tar,ans,combi);
        return ans;

    }
};