#include<bits/stdc++.h>
using namespace std;

void SieveOfEratosthenes(int n)
{
    
    vector<int> prime(n,1);
 
    for (int p = 2; p * p <= n; p++) {
        
        if (prime[p] == true) {
           
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
 
    for (int p = 2; p <= n; p++)
        if (prime[p])
            cout << p << " ";
}

int main(){
    int n;
    cout<<"enter a number \n";
    cin>>n;
   
    SieveOfEratosthenes(n);

    return 0;
}