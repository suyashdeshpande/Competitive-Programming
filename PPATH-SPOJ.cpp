// Suyash Deshpande

#include <bits/stdc++.h>
using namespace std;
vector<bool> seive(10002,true);

void buildSeive()
{       
        for(int i=2;i*i<=10000;i++)
        {
            if(seive[i]==true)
            {
                for(int j=i*i;j<=10000;j+=i)
                    {
                     seive[j]=false; 
                     }

            }
            
        }

}

int arrayToNum(vector<int> &arr)
{       int num=0;
    for(int i=0;i<=3;i++)
    {
        num*=10;
        num+=arr[i];

    }
        return num;
}

void numToArray(vector<int> &num,int temp)
{       
    int i=3;
    while(temp)
        {
                num[i--]=temp%10;
                temp/=10;
        }
}

void bfs(int s,int d)
{
    vector<int> visited(10002,false);
    visited[s]=true;
    queue<pair<int,int>> q; //first->number, second->moves
    q.push(make_pair(s,0));

    while(!(q.empty()))
    {   
        pair<int,int> temp=q.front();
        q.pop();
        vector<int>num(4);
        numToArray(num,temp.first);
        if(temp.first==d)
        {
            cout<<temp.second<<endl;
            return;
        }
        //1st digit
        for(int j=1;j<=9;j++)
        {
                if(j!=num[0])
                {   
                     int first=num[0];
                     num[0]=j;
                     int curr=arrayToNum(num);
                     num[0]=first;   
                    if(seive[curr]==true)
                    {   
                        if(visited[curr]!=true)
                        {
                            q.push(make_pair(curr,temp.second+1));
                            visited[curr]=true;
                        }
                        
                    }

                }

        }
        //2nd digit 
       for(int j=0;j<=9;j++)
        {
                if(j!=num[1])
                {   
                     int first=num[1];
                     num[1]=j;
                     int curr=arrayToNum(num);
                     num[1]=first;   
                    if(seive[curr]==true)
                    {   
                        if(visited[curr]!=true)
                        {
                            q.push(make_pair(curr,temp.second+1));
                            visited[curr]=true;
                        }
                        
                    }

                }

        }
        //3rd digit
        for(int j=0;j<=9;j++)
        {
                if(j!=num[2])
                {   
                     int first=num[2];
                     num[2]=j;
                     int curr=arrayToNum(num);
                     num[2]=first;   
                    if(seive[curr]==true)
                    {   
                        if(visited[curr]!=true)
                        {
                            q.push(make_pair(curr,temp.second+1));
                            visited[curr]=true;
                        }
                        
                    }

                }

        }
        //4th digit
          for(int j=1;j<=9;j+=2)
        {
                if(j!=num[3])
                {   
                     int first=num[3];
                     num[3]=j;
                     int curr=arrayToNum(num);
                     num[3]=first;   
                    if(seive[curr]==true)
                    {   
                        if(visited[curr]!=true)
                        {
                            q.push(make_pair(curr,temp.second+1));
                            visited[curr]=true;
                        }
                        
                    }

                }

        }


        
    }

    cout<<"Impossible"<<endl;

}


int main() {

int t;
cin>>t;
buildSeive();
while(t--)
{
 int s,d;
 cin>>s>>d;
 bfs(s,d);

}


return 0;
}

