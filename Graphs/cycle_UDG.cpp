#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define vi vector <int>
#define vvi vector <vector <int>>

void addEdge(vvi & adj,int x,int y) {
    adj[x].push_back(y);
    adj[y].push_back(x);
}

bool isCycle(int src,vvi & adj,vi & visited,int parent) {
    visited[src] = 1;
    for(auto i : adj[src]) {
        if(i != parent) {
            if(visited[i]) {
                return true;
            }
            if(!visited[i] && isCycle(i,adj,visited,src)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n = 4;
    vvi adj(n);
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 1);
    vi visited(n,0);
    bool cycle = false;
    for(int i = 0 ; i < n ; i++) {
        if(!visited[i] && isCycle(i,adj,visited,-1)) {
            cycle = true;
        }
    }
    if(cycle) {
        cout<<"There is a cycle";
    }
    else {
        cout<<"There is no cycle";
    }
    return 0;
}