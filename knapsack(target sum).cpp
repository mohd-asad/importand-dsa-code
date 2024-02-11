#include<bits/stdc++.h>
using namespace std;

/*int solve(int weight[], int value[], int id, int wm){

     if(id == 0){
        if(weight[0] <= wm) return value[0];
        else return 0;
     }

    int in=0,ex=0;
    if(weight[id] <= wm){
       in=value[id]+solve(weight, value, id-1, wm-weight[id]);
    } 
    ex=solve(weight, value, id-1, wm);

    int ans= max(in,ex);

    return ans;
}*/

/*int solve(int weight[], int value[], int id, int wm, vector<vector<int>> dp){

     if(id == 0){
        if(weight[0] <= wm) return value[0];
        else return 0;
     }

     if(dp[id][wm] != -1)
       return dp[id][wm];

    int in=0,ex=0;
    if(weight[id] <= wm){
       in=value[id]+solve(weight, value, id-1, wm-weight[id],dp);
    } 
    ex=solve(weight, value, id-1, wm,dp);

    dp[id][wm]=max(in,ex);

    return dp[id][wm];
}*/

/*int solve(int weight[], int value[], int n, int wm){

   vector<vector<int>> dp(n,vector<int> (wm+1,0));

    for(int i=0; i<wm+1; i++){
      if(weight[0]<=wm)
        dp[0][i]=value[0];
      else 
        dp[0][i]=0;  
    } 

    for(int id=1; id<n; id++){
      for(int w=0; w<=wm; w++){
          int in=0,ex=0;
          if(weight[id]<=w){
            in=value[id]+dp[id-1][w-weight[id]];
          }
          ex=dp[id-1][w];

         dp[id][w]=max(in,ex); 
      }
    }

    return dp[n-1][wm];
}*/

/*int solve(int weight[], int value[], int n, int wm){

   vector<int> prev(wm+1);
   vector<int> curr(wm+1);

    for(int i=0; i<wm+1; i++){
      if(weight[0]<=wm)
        prev[i]=value[0];
      else 
        prev[i]=0;  
    } 

    for(int id=1; id<n; id++){
      for(int w=0; w<=wm; w++){
          int in=0,ex=0;
          if(weight[id]<=w){
            in=value[id]+prev[w-weight[id]];
          }
          ex=prev[w];

         curr[w]=max(in,ex); 
      }

      prev=curr;
    }

    return prev[wm];
}
*/
int solve(int weight[], int value[], int n, int wm){

   vector<int> curr(wm+1);

    for(int i=weight[0]; i<wm+1; i++){
      if(weight[0]<=wm)
        curr[i]=value[0];
      else 
        curr[i]=0;  
    } 

    for(int id=1; id<n; id++){
      for(int w=wm; w>=0; w--){
          int in=0,ex=0;
          if(weight[id]<=w){
            in=value[id]+curr[w-weight[id]];
          }
          ex=curr[w];

         curr[w]=max(in,ex); 
      }

    }

    return curr[wm];
}

int main(){

    int weight[]={1,2,3,4,5};
    int value[]={4,3,5,8,6};
    int mw=5;
    int n=5;

    int ans=solve(weight,value, n,mw);

    cout<<ans;

    return 0;

}