#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

class Solution {
    public:
    vector<int> ans;
    vector<bool> visited;

    void dfsVisit(vector<vector<int>>& graph,int node) {
        if(visited[node])
            return;
        visited[node] = true;
        ans.push_back(node);
        for(auto i : graph[node]) {
            if(!visited[i]) 
                dfsVisit(graph,i);
        }
    }

    void dfs(vector<vector<int>>& graph) {
        int size = graph.size();
        ans = vector<int>();
        visited = vector<bool>(size,false);
        for(int i = 0 ; i < size ; i++) {
            if(!visited[i])
                dfsVisit(graph,i);
        }
        cout<<"DFS -> ";
        for(auto i : ans)
            cout<<i<<" ";
        cout<<endl;
    }

    void bfs(vector<vector<int>>& graph) {
        int size = graph.size();
        ans = vector<int>();
        visited = vector<bool>(size,false);

        for(int i = 0 ; i < size ; i++) {
            if(visited[i] == false) {
                // BFS
                queue<int> queue;
                queue.push(i);
                visited[i] = 1;
                while(!queue.empty()) {
                    int node = queue.front();
                    queue.pop();
                    ans.push_back(node);
                    for(auto i : graph[node]) {
                        if(visited[i] == false) {
                            visited[i] = true;
                            queue.push(i);
                        }
                    }
                }
            }
        }
        cout<<"BFS -> ";
        for(auto i : ans)
            cout<<i<<" ";
        cout<<endl;
    }
};

void addNodes(vector<vector<int>>& graph,vector<vector<int>>& edges) {
    for(auto n : edges)
        graph[n[0]].push_back(n[1]);
}

int main() {
    int size = 9;

    vector<vector<int>> edges = {{0, 1},{1, 0},{0, 7},{7, 0},{1, 2},{2, 1},{1, 7},{7, 1},{2, 8},{8, 2},{3, 4},{4, 3},{3, 5},{5, 3},{4, 5},{5, 4},{6, 7},{7, 6},{6, 8},{8, 6},{7, 8},{8, 7}};

    vector<vector<int>> graph(size,vector<int>());
    addNodes(graph,edges);

    for(int i = 0 ; i < size ; i++) {
        cout<<i<<" -> ";
        for(auto j : graph[i])
            cout<<j<<" ";
        cout<<endl;
    }
    cout<<endl;
    
    Solution s;
    s.dfs(graph);
    s.bfs(graph);
    return 0;
}