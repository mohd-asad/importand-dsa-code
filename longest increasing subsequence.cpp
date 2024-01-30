#include<bits/stdc++.h>
using namespace std;

//binary search
int solve(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> ans;
        
        ans.push_back(nums[0]);
        for(int i=1; i<nums.size(); i++){
            if(nums[i] > ans.back())
              ans.push_back(nums[i]);
            else{
                int id=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                ans[id]=nums[i];
            }  
        }

        return ans.size();
    }
    
// tabulation with space optimization
int solve(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> curr(n+1,0),prev(n+1,0);

        for(int i=n-1; i>=0; i--){
            for(int j=i-1;j>=-1;j--){
               int ans1=0;
               if(j==-1 || nums[i]>nums[j])
                 ans1=1+curr[i+1];
               int ans2=  prev[j+1];

               curr[j+1]=max(ans1,ans2);
            }
            prev=curr;
        }  

        return curr[0];
}


//tabulation
int solve(vector<int>& nums) {
        
    int n=nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,0));

    for(int i=n-1; i>=0; i--){
        for(int j=i-1;j>=-1;j--){
           int ans1=0;
           if(j==-1 || nums[i]>nums[j])
             ans1=1+dp[i+1][i+1];
           int ans2=  dp[i+1][j+1];

           dp[i][j+1]=max(ans1,ans2);
        }
    }  

    return dp[0][0];
}

//memorization
int solve(vector<int> &nums, int cur, int pre, vector<vector<int>> &dp){
    if(cur == nums.size())
      return 0;

    if(dp[cur][pre+1] !=-1)
      return dp[cur][pre+1];  

    int ans1=0;
    if(pre == -1 || nums[cur] > nums[pre])
       ans1=1+solve(nums,cur+1, cur,dp);
    int ans2=solve(nums,cur+1, pre,dp);

    return dp[cur][pre+1]=max(ans1,ans2); 
}

int main(){
    vector<int> nums={10,9,2,5,3,7,101,18};

    cout<<solve(nums)<<endl;
    return 0;
}