#include<bits/stdc++.h>
using namespace std;

int KMP(string &s,string &t){
    
    int n=t.size();
    vector<int> pi(n,0);
    int j=0,i=1;

    while(i<n){
        if(t[i]==t[j]){
            j++;
            pi[i]=j;
            i++;
        }
        else {
            if(j!=0){
                j=pi[j-1];
            }
            else{
                pi[i]==0;
                i++;
            }
        }
        
    }

    // for(int i=0;i<n;i++){
    //     cout<<pi[i]<<" ";
    // }

    int ans=0;
    i=0,j=0;
    while(i<s.size()){
        if(s[i]==t[j]){
            j++;
            i++;
        }
        
        else {
            if(j!=0){
                j=pi[j-1];
            }
            else i++;
        }

        if(j==n){
           ans++;
           j=pi[j-1];
        }
    }
    return ans;

}

int main(){

    string s="ABABDABACDABABCABAB";
    string t="ABABCABAB";

    cout<<KMP(s,t)<<endl;

    return 0;
}