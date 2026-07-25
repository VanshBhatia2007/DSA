class Solution {
public:
    bool ispalindrome(string s){
        string s2= s;
        reverse(s2.begin(),s2.end());
        return s==s2;
    }

    void getpalindrome(string s,vector<string>& partitions,vector<vector<string>>& ans){
        //base case
        if(s.size()==0){
            ans.push_back(partitions);
        }

        for(int i=0;i<s.size();i++){
            string part = s.substr(0,i+1);
            if(ispalindrome(part)){
                partitions.push_back(part);
                getpalindrome(s.substr(i+1),partitions,ans);
                partitions.pop_back();
            }
        }
    }
   
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> partitions;
        getpalindrome(s,partitions,ans);
        return ans;
    }
};