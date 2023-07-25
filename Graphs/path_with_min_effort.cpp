#include<bits/stdc++.h>
using namespace std;

// LEETCODE 1631 - Path With Minimum Effort
class Solution {
public:
    struct Node {
        int i;
        int j;
        int cost;
    };
    
    class compare {
        public:
        bool operator()(Node& a,Node& b) {
            return a.cost > b.cost;
        }
    };
    
    int minimumEffortPath(vector<vector<int>>& graph) {
        int row = graph.size();
        int col = graph[0].size();
        int dir[5] = {0,1,0,-1,0};
        vector<vector<int>> effort(row,vector<int>(col,INT_MAX));
        priority_queue<Node,vector<Node>,compare> heap;
        heap.push({0,0,0});
        while(!heap.empty()) {
            Node top = heap.top();
            heap.pop();
            if(top.i == row-1 && top.j == col-1)
                return top.cost;
            for(int k = 0 ; k < 4 ; k++) {
                int i = top.i + dir[k];
                int j = top.j + dir[k+1];
                if(i < row && i >= 0 && j < col && j >= 0) {
                    int next = graph[i][j];
                    int curr = graph[top.i][top.j];
                    int cost = max(top.cost,abs(next-curr));
                    if(cost < effort[i][j]) {
                        effort[i][j] = cost;
                        heap.push({i,j,cost});
                    }
                }
            }
        }
        return -1;
    }
};

int main() {
    return 0;
}