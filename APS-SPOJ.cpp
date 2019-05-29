//Suyash Deshpande

#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define SIEVE_SIZE 10000001

vector<ll>sieve(SIEVE_SIZE, -1);

void buildSieve() {
    for(ll i=2;i<=SIEVE_SIZE;i++) {
        if(sieve[i] == -1) {
            sieve[i] = i;
        for(ll j=i*i;j<=SIEVE_SIZE;j=j+i) {
            if(sieve[j] == -1) {
                sieve[j] = i;
            }
        }
        }
    }
}


int main() {
    int t;
    cin>>t;
    vector<ll>dp(SIEVE_SIZE, -1);
    buildSieve();

    dp[0] = 0;
    dp[1] = 0;
    for(ll i=2;i<SIEVE_SIZE;i++) {
        dp[i] = dp[i-1] + sieve[i];
    }


    while(t--) {
        ll n;
        cin>>n;
        cout<<dp[n]<<endl;
    }
}
