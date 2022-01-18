#include<iostream>
#include<vector>
using namespace std;
#define INF INT_MAX

class FloydWarshall {
    public:
    vector<vector<int>> dist;
    vector<vector<int>> next;

    void algorithm(vector<vector<int>>& graph) {
        int n = graph.size();
        dist = graph;
        next = vector<vector<int>>(n,vector<int>(n,-1));
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < n ; j++) {
                if(dist[i][j] != INT_MAX) {
                    next[i][j] = j;
                }
            }
        }

        for(int k = 0 ; k < n ; k++) {
            for(int i = 0 ; i < n ; i++) {
                for(int j = 0 ; j < n ; j++) {
                    if(dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)
                        continue;
                    if(dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        next[i][j] = next[i][k];
                    }
                }
            }
        }
    }

    vector<int> getPath(int u,int v) {
        vector<int> path;
        if(next[u][v] == -1)
            return path;
        path.push_back(u);
        while(u != v) {
            u = next[u][v];
            path.push_back(u);
        }
        return path;
    }
};

int main() {
    vector<vector<int>> dist = {
        {0 , 3 , INF , 7},
        {8 , 0 , 2 , INF},
        {5 , INF , 0 , 1},
        {2 , INF ,INF, 0}
    };
    FloydWarshall f;
    f.algorithm(dist);
    for(auto i : f.getPath(1,3))
        cout<<i<<" ";
}