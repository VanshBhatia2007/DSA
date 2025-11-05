class Solution {
public:
    vector<vector <int> > ans;
    void solve(vector<int>&a,int i,vector<int> &x,int target){
        int n=a.size();
        //base case
        if(target==0){
            ans.push_back(x);
            return;
        }
        if(i==n){
            return;
        }
        //recursive case
        for(int j=i;j<n;j++){
            if(a[j]<=target){
                x.push_back(a[j]);
                solve(a,j,x,target-a[j]);
                x.pop_back();
            }
        }

    }
    vector<vector<int>> combinationSum(vector<int>& a, int target) {
        vector<int> x;
        solve(a,0,x,target);
        return ans;
    }
};