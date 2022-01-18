#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
	public:
	vector<int> topologicalSort(vector<vector<int>>& graph) {
        int n = graph.size();
	    vector<int> indeg(n,0);
	    for(int i = 0 ; i < n ; i++) {
	        for(int node : graph[i])
	            indeg[node]++;
	    }
	    
	    queue<int> queue;
	    for(int i = 0 ; i < n ; i++) {
	        if(indeg[i] == 0)
	            queue.push(i);
	    }
	    
	    vector<int> ans;
	    while(!queue.empty()) {
	        int node = queue.front();
	        queue.pop();
	        ans.push_back(node);
	        for(int i : graph[node]) {
	            indeg[i]--;
	            if(indeg[i] == 0)
	                queue.push(i);
	        }
	    }
	    return ans;
	}
};

void addNodes(vector<vector<int>>& graph,vector<vector<int>>& edges) {
    for(auto n : edges)
        graph[n[0]].push_back(n[1]);
}

int main() {
    int size = 6;
    vector<vector<int>> edges = {{1,3},{2,3},{4,0},{4,1},{5,0},{5,2}};

    vector<vector<int>> graph(size,vector<int>());
    addNodes(graph,edges);

    Solution s;
    for(int i : s.topologicalSort(graph))
        cout<<i<<" ";
	cout<<endl;

    return 0;
}