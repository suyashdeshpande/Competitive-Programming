// Suyash Deshpande

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<bool>prime(10000002);
    vector<int>count(10000002);

	for(int i=1; i<10000002; i+=2)
        prime[i]=true;
	for(int i=0; i<10000002; i+=2)
        prime[i]=false;
	prime[0] = prime[1] = false;
    prime[2]=true;
	int s=sqrt(10000002);
	for(int i=3; i<=s; i+=2){
		if(prime[i])
		    for(int j=i*i; j<10000002; j+=(i<<1))
			    prime[j]=false;
	}

	count[10000001] = prime[10000001] ? 1 : 0 ;
	for(int i=10000000; i>=0; i--)
		count[i] = prime[i] ? count[i+1]+1 : count[i+1];		
	int t, n;
	cin>>t;
	while(t--){
		cin>>n;
        cout<<count[(n+2)>>1]-count[n+1]<<endl;
	}		
	return 0;
}
