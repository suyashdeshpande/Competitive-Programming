// Suyash Deshpande

#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> graph;
vector<vector<bool>> visited;
int n,m,ans=0;

bool check(int i,int j)
{
    return ((i>=0 and i<n) and (j>=0 and j<m)) and (visited[i][j]==false);
}


int dfshelper(int i,int j)
{


    visited[i][j]=true;
    int up=0,down=0,right=0,left=0;    
    //up
    if(check(i-1,j))
    {
        up=dfshelper(i-1,j);

    }

    //down
    if(check(i+1,j))
    {
        down=dfshelper(i+1,j);
    }
    //left
    if(check(i,j-1))
    {
            left=dfshelper(i,j-1);
    }
    
    //right
    if(check(i,j+1))
    {
        right=dfshelper(i,j+1);
    }

       
        int l2r=left+right+1;  ans=max(ans,l2r);
        int u2d=up+down+1;     ans=max(ans,u2d);
        int u2l=up+left+1;      ans=max(ans,u2l);
        int u2r=up+right+1;     ans=max(ans,u2r);
        int l2d=left+down+1;    ans=max(ans,l2d);
        int r2d=right+down+1;   ans=max(ans,r2d);
        // cout<<max(right,max(left,max(down,up)))+1<<endl;

    return max(right,max(left,max(down,up)))+1;     

}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        ans=0;
        cin>>m>>n;
        graph.assign(n,vector<char>(m));
        visited.assign(n,vector<bool>(m,false));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>graph[i][j];
                if(graph[i][j]=='#')
                    visited[i][j]=true;
            }

        }

         for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {

                if(visited[i][j]==false)
                {   
                        dfshelper(i,j);
                }
            }

        }  



    cout<<"Maximum rope length is "<<ans-1<<"."<<endl;

    }


return 0;
}
