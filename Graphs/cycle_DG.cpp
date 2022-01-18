#include <iostream>
#include <vector>
using namespace std;
#define vi vector <int>
#define vvi vector <vector <int>>

bool isCycle(int src,vvi & adj,vi & visited,vi & stack) {
    stack[src] = 1;
    visited[src] = 1;
    for(auto i : adj[src]) {
        if(!visited[i] && isCycle(i,adj,visited,stack)) {
            return true;
        }
        if(stack[i]) {
            return true;
        }
    }
    stack[src] = 0;
    return false;
}

int main() {
    int n = 4;
    vvi adj(n);
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(3);
    vi visited(n,0);
    vi stack(n,0);
    bool cycle = false;
    for(int i = 0 ; i < n ; i++) {
        if(!visited[i] && isCycle(i,adj,visited,stack)) {
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