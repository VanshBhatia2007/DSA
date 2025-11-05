class Solution {
public:
    vector<string> x;
    void solve(string ans,int n,int op,int cl){
        //base case
        if(ans.size()==2*n){
            x.push_back(ans);
            return;
        }
        //recursive
        //add (
        if(op<n){
            solve(ans+'(',n,op+1,cl);
        }
        //add )
        if(op>cl){
            solve(ans+')',n,op,cl+1);
        }

    }
    vector<string> generateParenthesis(int n) {
        solve("",n,0,0);
        return x;
    }
};