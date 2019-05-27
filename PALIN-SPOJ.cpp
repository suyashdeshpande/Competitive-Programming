// Suyash Deshpande

#include<bits/stdc++.h>
using namespace std;
int main() {
	long long int t;
	cin>>t;
	while(t--)
	{
		long long int k=0;
		string s;
		cin>>s;
	    
        int flag=0;
		
		for(long long int i=0;i<(s.length()/2);++i) {
				if(s[s.length()-i-1]>s[i])
				    flag=0;
				else if(s[s.length()-i-1]<s[i])
				    flag=1;
				s[s.length()-i-1]=s[i];
			}

			if(flag==0) {
				long long int x=s.length()/2-1;
				
					if(s.length()%2!=0)
					{
						++x;
						if(s[x]=='9')
						{
							s[x]='0';
							--x;
						}
					}
					while(s[x]=='9' && x>=0)
					{
						s[x]='0';
						s[s.length()-x-1]='0';
						--x;
					}
					if(x>=0)
					{
						s[x]=s[x]+1;
					    s[s.length()-x-1]=s[x];
					}
					else
					{
						
						x=s.length();
						for(long long int i=0;i<x;++i)
						{
							if(i==0)
							s[i]='1';
							else
							s[i]='0';
						}
						s=s+'1';
					}
				
			}
		
			cout<<s<<endl;
		
	}
}
