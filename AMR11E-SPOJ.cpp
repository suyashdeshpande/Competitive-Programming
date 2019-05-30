// Suyash Deshpande

#include<bits/stdc++.h>
using namespace std;
#define lim 3600
vector<int>prime;
vector<bool>check(lim,false);
vector<int>ans(lim);

void pre()
{
 int i,j;
 for(i=3;i<=55;i+=2)
 {
  if(check[i]==false)
  {
   for(j=i*i;j<=3025;j+=2*i)
   check[j]=true;
  }
 }
 prime.push_back(2);
 for(i=3;i<=2700;i+=2)
 {
  if(check[i]==false)
  prime.push_back(i);
 }
}
void dev()
{
 int i,j,x,count=0;
 for(i=30;i<=2664;i++)
 {
  x=0;
  for(j=0;prime[j]<=i;j++)
  {
   if(i%prime[j]==0)
    x++;
   if(x==3) {
    ans[count++]=i;
    break;}
  }
 }
}
int main()
{
 pre();
 dev();
 int t,i,n;
 cin>>t;
 while(t--)
 {
  cin>>n;
  cout<<ans[n-1]<<endl;
 }
 return 0;
}
