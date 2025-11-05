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
            if(j!=i and a[j]==a[j-1]){
                continue;
            }
            if(a[j]<=target){
                x.push_back(a[j]);
                solve(a,j+1,x,target-a[j]);
                x.pop_back();
            }
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& a, int target) {
        vector<int> x;
        sort(a.begin(),a.end());
        solve(a,0,x,target);
        return ans;
    }
};