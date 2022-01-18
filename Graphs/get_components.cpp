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

int getComponents(int src,vvi & adj,vi & visited) {
    if(visited[src]) {
        return 0;
    }
    visited[src] = 1;
    int ans = 1;
    for(auto i : adj[src]) {
        if(!visited[i]) {
            ans += getComponents(i,adj,visited);
            visited[i] = 1;
        }
    }
    return ans;
}

int main() {
    int n = 5;
    vvi adj(n);
    addEdge(adj, 0, 1);
    addEdge(adj, 2, 3);
    addEdge(adj, 0, 4);
    vi visited(n,0);
    vi components;
    for(int i = 0 ; i < n ; i++) {
        if(!visited[i]) {
            components.push_back(getComponents(i,adj,visited));
        }
    }
    for(auto i : components) {
        cout<<i<<" ";
    }
    return 0;
}