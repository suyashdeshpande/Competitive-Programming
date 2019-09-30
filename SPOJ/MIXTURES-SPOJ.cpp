// Suyash Deshpande

#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll>a(1000);
vector<vector<ll>>dp;

ll sum(int s, int e) {
    ll ans = 0;
    for(int i = s; i <= e; i++) {
        ans += a[i]; 
        ans %= 100;
    }
    return ans;
}

ll solveMixtures(int i, int j) {
    if(i >= j) {
        return 0;
    }
    if(dp[i][j] != -1) {
        return dp[i][j];
    }
    // Break expression at every possible k
    dp[i][j] = INT_MAX;
    for(int k = i; k <= j; k++) {
        dp[i][j] = min(dp[i][j], solveMixtures(i, k) + solveMixtures(k+1, j) + sum(i, k) * sum(k+1, j));
    }
    return dp[i][j];
}

int main() {

    int n;
    while((scanf("%d", &n)) != EOF) {
        for(int i = 0; i < n; i++) {
            cin>>a[i];
        }
    dp.assign(n, vector<ll>(n, -1));
    cout<<solveMixtures(0, n-1)<<endl;
    }

}
