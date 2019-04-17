// Suyash Deshpande

#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll gcd(ll a,ll b) {
        if(b==0)
            return a;
        return gcd(b,a%b);
    }

int main(){  
       while(1){
           ll n,k;
           cin>>n>>k;
           if(n==-1 && k==-1)
                break;
           ll nume,denom;
            denom=(n*(n-1))/2;
            nume=0;
            ll ans = k-2;
            if(ans%2 == 0){
                ll num=ans/2;
                nume=((num+1)*(ans))/2;
            }
            else {
                ll num=(ans-1)/2;
                nume=((num+1)*(ans+1))/2;
            }
            long hcf=gcd(nume,denom);
            if(nume==0)
                cout<<0<<endl;
            else cout<<nume/hcf<<"/"<<denom/hcf<<endl;
       }
     
    return 0;
}
