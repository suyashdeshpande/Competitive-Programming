    #include<bits/stdc++.h>
    using namespace std;
    int main(void)
    {
        int T,N;
        cin>>T;
        set<long long> s;
        s.insert(0);
        long long num = 0;
        vector<long long> tmp; 
        for(int i=1;i<35;i=i+2)
        {
            num = pow(2,i);
            tmp.clear();
            for(auto it1=s.begin();it1!=s.end();it1++)
            {
                if(s.find(num+*it1)==s.end() && (num+*it1)<=1000000000)
                {
                    tmp.push_back(num+*it1);
                }
            }
            for(int j=0;j<tmp.size();j++)
            {
                s.insert(tmp[j]);
            }
        }
        long long sum = 0;
        while(T--)
        {
            cin>>N;
            sum=0;
            long arr[N];
            for(int i=0;i<N;i++)
            {
                cin>>arr[i];
            }
            for(int i=0;i<N;i++)
            {
                if(i==0 && arr[i]==-1)
                {
                    arr[0]=0;
                }
                else if(arr[i]==-1)
                {
                    auto it = s.lower_bound(arr[i-1]);
                    arr[i] = *it;
                }
                sum += arr[i];
            }
            cout<<sum<<endl;
        }
        return 0;
    }