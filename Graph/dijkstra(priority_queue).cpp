#include<bits/stdc++.h>
using namespace std;

//Time Complexity -> O(V+E(logV))

void addEdge(vector<vector<pair<int,int>>> &adjList, int u, int v, int w) {
    adjList[u].push_back({v,w});
    adjList[v].push_back({u,w});
}

int main() {
    //v -> no of vertices or nodes in a graph
    int v = 3;
    int source = 2; //starting node
    
    //{source, destination, edgeWeight/distance}
    vector<vector<pair<int,int>>> adjList(v,vector<pair<int,int>>());
    
    //node -> {destination, edgeWeight}
    addEdge(adjList, 0, 1, 1);
    addEdge(adjList, 0, 2, 6);
    addEdge(adjList, 1, 2, 3);
    
    //create a vector of distance
    vector<int> dist(v,INT_MAX);//The initial distance to reach each node is infinity.

    //create a min_heap to maintain shortest distances in order
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[source] = 0;//The distance to reach source from source is zero
    pq.push({0,source});//{dist,node}

    while(!pq.empty()) {
        int node = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        for(auto &v : adjList[node]) {
            int adjNode = v.first;
            int weight = v.second;
            if(d + weight < dist[adjNode]) {
                dist[adjNode] = d + weight;
                pq.push({d+weight, adjNode});
            }
        }
    }

    for(int i=0; i<v; i++) {
        cout<<"node:"<<i<<" dist:"<<dist[i]<<endl;
    }

    return 0;
}