//Suyash Deshpande
#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector< vector<ll> > graph;
vector<ll>visited;

bool bfs(ll s,ll n) {
    queue<ll>q;
    q.push(s);
    visited[s]=1;

    while(!(q.empty())) {
            ll node=q.front();
            q.pop();
            for(auto i:graph[node]) {   
                if(visited[i]==-1) {
                    visited[i]=1-visited[node];
                    q.push(i);
                }
               else if(visited[i]==visited[node])     
                        return false;
            }
    }
    return true;
}

int main() {
    ll t;
    cin>>t;
    for(ll j=1;j<=t;j++) {
      
      ll n,e,i;
      cin>>n>>e;
      visited.assign(n+1,-1);
      graph.assign(n+1,vector<ll>());
      while(e--) {
        ll s,d;
        cin>>s>>d;
        graph[s].push_back(d);
        graph[d].push_back(s);
      }

        for(i=1;i<=n;i++)  {
            if(visited[i]==-1) {
                     bool ans=bfs(i,n);
                     if(ans==false)
                         break;
                 } 
         }

        cout<<"Scenario #"<<j<<":"<<endl;
        if(i<=n)
            cout<<"Suspicious bugs found!"<<endl;
        else
            cout<<"No suspicious bugs found!"<<endl;

    }

}
