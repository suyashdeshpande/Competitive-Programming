#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> graph;

int dijkstras(int src, int dest, int n) {
    // pair of city index and cost
    unordered_map<int, int> cost;
    // pair consisits of cost and city index
    set<pair<int, int>> s;

    // make all distances infinity
    for(int i=1;i<=n;i++) {
        cost[i] = INT_MAX;
    }
    //cost of src is 0
    cost[src] = 0;

    s.insert(make_pair(0, src));
    while(!s.empty()) {
        // top node of set
        pair<int, int> node = *(s.begin());
        // eraing the top node of set i.e., node with minimum cost
        s.erase(s.begin());

        int curr_src = node.second;
        int curr_cost =  node.first;

        for(auto neighbour: graph[curr_src]) {
            // neighbour index
            int neighbour_index = neighbour.first;
            // neighbour index
            int neighbour_cost = neighbour.second;
             if (curr_cost + neighbour_cost < cost[neighbour_index]) {
                 
                    cost[neighbour_index] = curr_cost + neighbour_cost;

                    // if it already exist eerase it
                    if (s.find(make_pair(cost[neighbour_index], neighbour_index)) != s.end()) {
                        s.erase(s.find(make_pair(cost[neighbour_index], neighbour_index)));
                    }
                        s.insert(make_pair(cost[neighbour_index], neighbour_index));

             }
        }

    }
    
    return cost[dest];

}



int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        graph.assign(n+1, vector<pair<int, int>>());
       
        unordered_map<string, int> city(n+1);
        for(int i=1;i<=n;i++) {

            string city_name;
            cin>>city_name;
            city[city_name] = i;
            int num_neighbours;
            cin>>num_neighbours;

            while(num_neighbours--) {
                int a,cost;
                cin>>a>>cost;
                graph[i].push_back(make_pair(a,cost));
            }
            
        }
        int q;
        cin>>q;
        while(q--) {
            string src, dest;
            cin>>src>>dest;
            cout<<dijkstras(city[src], city[dest], n)<<endl;
        }
       
    }
}
