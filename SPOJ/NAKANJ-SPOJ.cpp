//Suyash Deshpande
#include <bits/stdc++.h>
using namespace std;

bool check(int x,int y)
{
 return (x>=1 and x<=8) and (y>=1 and y<=8) ;
}
   
void bfs(pair<int,int> s,pair<int,int> d)
{

queue<pair<pair<int,int>,int>>q;
q.push(make_pair(s,0));
vector<vector<bool> > visited(9,vector<bool>(9,false));
visited[s.first][s.second]=true;
while(!(q.empty()))
{
    pair<pair<int,int>,int> temp=q.front();
    int move=temp.second,x=temp.first.first,y=temp.first.second;
    q.pop();
    if(x==d.first and y==d.second)
    {
        cout<<move<<endl;
        return;
    }

    if(check(x+1,y+2) and visited[x+1][y+2]==false)
    {
        visited[x+1][y+2]=true;
        q.push(make_pair(make_pair(x+1,y+2),move+1));
    }

    if(check(x+1,y-2)and visited[x+1][y-2]==false)
    {
        visited[x+1][y-2]=true;
        q.push(make_pair(make_pair(x+1,y-2),move+1));
    }
    if(check(x+2,y+1)and visited[x+2][y+1]==false)
    {
        visited[x+2][y+1]=true;
        q.push(make_pair(make_pair(x+2,y+1),move+1));
    }

    if(check(x+2,y-1)and visited[x+2][y-1]==false)
    {
        visited[x+2][y-1]=true;
        q.push(make_pair(make_pair(x+2,y-1),move+1));
    }

    if(check(x-2,y+1)and visited[x-2][y+1]==false)
    {
        visited[x-2][y+1]=true;
        q.push(make_pair(make_pair(x-2,y+1),move+1));
    }

    if(check(x-2,y-1)and visited[x-2][y-1]==false)
    {
        visited[x-2][y-1]=true;
        q.push(make_pair(make_pair(x-2,y-1),move+1));
    }

    if(check(x-1,y+2)and visited[x-1][y+2]==false)
    {
        visited[x-1][y+2]=true;
        q.push(make_pair(make_pair(x-1,y+2),move+1));
    }

    if(check(x-1,y-2)and visited[x-1][y-2]==false)
    {
        visited[x-1][y-2]=true;
        q.push(make_pair(make_pair(x-1,y-2),move+1));
    }
}


}

int main() {
int t;
cin>>t;
while(t--)
{
  string s,d;
  cin>>s>>d;
    pair<int,int> so,des;
    so.first=s[0]-'a'+1; 
    des.first=d[0]-'a'+1;
    so.second=s[1]-'0';
    des.second=d[1]-'0';

    bfs(so,des);
}


return 0;
}
