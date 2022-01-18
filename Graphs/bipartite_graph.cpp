#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
    public:
    bool bipartiteGraph(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        queue<int> queue;
        
        for(int i = 0 ; i < n ; i++) {
            if(color[i] == -1) {
                queue.push(i);
                color[i] = 1;
                while(!queue.empty()) {
                    int n = queue.size();
                    while(n-- > 0) {
                        int curr = queue.front();
                        queue.pop();

                        for(int node : graph[curr]) {
                            if(color[node] == -1) {
                                color[node] = !color[curr];
                                queue.push(node);
                            }
                            else {
                                if(color[node] == color[curr])
                                    return false;
                            }
                        }
                    }
                }
            }
        }
        return true;
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
    cout<<s.bipartiteGraph(graph);

    return 0;
}