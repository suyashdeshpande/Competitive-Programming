// Suyash Deshpande
#include <bits/stdc++.h>
using namespace std;

void bfs(int n) {
    queue<pair<string, int>> q;
    q.push(make_pair("1", 1));

    while(!q.empty()) {
        int rem;
        pair<string, int> x = q.front();
        q.pop();
        rem = x.second;
        if (x.second % n == 0) {
            cout<<x.first<<endl;
            return;
        }
        q.push(make_pair(x.first + "0", (rem*(10%n))%n));
        q.push(make_pair(x.first + "1", (rem*(10%n) + 1)%n));
        
    }
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        bfs(n);
    }
}
