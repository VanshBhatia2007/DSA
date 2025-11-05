class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>&x,int n,int k,int s){
        //base case
        if(k==0){
            ans.push_back(x);
            return;
        }
        //recursive case
        for(int i=s;i<=n;i++){
            x.push_back(i);
            solve(x,n,k-1,i+1);
            x.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> x;
        solve(x,n,k,1);
        return ans;
    }
};