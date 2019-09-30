//Suyash Deshpande
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

long long bfs(int s,vector<vector<int>> &graph, vector<bool>&visited)
{
queue<int> q;
q.push(s);
visited[s]=true;
long long count=0;

while(!(q.empty()))
{
    int temp=q.front();
    q.pop();
    count++;
    for(auto neighbour:graph[temp])
    {
        if(visited[neighbour]==false)
        {
            visited[neighbour]=true;
            q.push(neighbour);

        }

    }

}

return count;
}

    // Complete the journeyToMoon function below.
 long long journeyToMoon(int n, int p, vector<vector<int>> astronaut) {

  vector<vector<int>> graph(n, vector<int>());
  vector<bool> visited(n, false);
  for (int i = 0; i < p; i++) {
    graph[astronaut[i][0]].push_back(astronaut[i][1]);
    graph[astronaut[i][1]].push_back(astronaut[i][0]);

}


vector<long long>arr;
long long sum=0;
for(int i=0;i<n;i++)
{
    if(visited[i]==false)
        {   long long temp=bfs(i,graph,visited);
             arr.push_back(temp);
             sum+=temp;
        }
}
long long ans=0;
for(int i=0;i<arr.size();i++)
{
sum-=arr[i];
ans+=arr[i]*sum;
}

return ans;


}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string np_temp;
    getline(cin, np_temp);

    vector<string> np = split_string(np_temp);

    int n = stoi(np[0]);

    int p = stoi(np[1]);

    vector<vector<int>> astronaut(p);
    for (int i = 0; i < p; i++) {
        astronaut[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> astronaut[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    long long result = journeyToMoon(n, p,astronaut);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
