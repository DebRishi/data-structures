#include<iostream>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<queue>
using namespace std;

struct Edge {
    int node;
    int weight;
    Edge(int n = 0,int w = 0) : node(n),weight(w) {}
};

class Dijkstra {
    public:
    void djikstraArray(vector<vector<Edge>>& graph,int start = 0) {
        int size = graph.size();
        vector<int> visited(size,0);
        vector<int> parent(size,-1);
        vector<int> cost(size,INT_MAX);

        parent[start] = start;
        cost[start] = 0;

        for(int count = 0 ; count < size-1 ; count++) {
            int minNode = -1;
            int minCost = INT_MAX;
            for(int i = 0 ; i < size ; i++) {
                if(!visited[i] && cost[i] < minCost) {
                    minCost = cost[i];
                    minNode = i;
                }
            }
            if(minNode == -1) {
                break;
            }
            visited[minNode] = 1;
            for(auto edge : graph[minNode]) {
                if(!visited[edge.node] && cost[minNode] + edge.weight < cost[edge.node]) {
                    cost[edge.node] = cost[minNode] + edge.weight;
                    parent[edge.node] = minNode;
                }
            }
        }

        printShortestPath(size,parent,cost);
    }

    void djikstra(vector<vector<Edge>>& graph,int start = 0) {
        int size = graph.size();
        vector<int> visited(size,0);
        vector<int> parent(size,-1);
        vector<int> cost(size,INT_MAX);
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> minHeap;

        parent[start] = start;
        cost[start] = 0;
        minHeap.push({cost[start],start});

        while(!minHeap.empty()) {
            int minCost = minHeap.top()[0];
            int minNode = minHeap.top()[1];
            minHeap.pop();
            visited[minNode] = 1;
            for(auto edge : graph[minNode]) {
                if(!visited[edge.node] && cost[minNode] + edge.weight < cost[edge.node]) {
                    cost[edge.node] = cost[minNode] + edge.weight;
                    parent[edge.node] = minNode;
                    minHeap.push({cost[edge.node],edge.node});
                }
            }
        }

        printShortestPath(size,parent,cost);
    }

    void printShortestPath(int size,vector<int>& parent,vector<int>& cost) {
        cout<<"Node"<<setw(10)<<"Parent"<<setw(10)<<"Cost\n\n";
        for(int i = 0 ; i < size ; i++)
            cout<<i<<setw(10)<<parent[i]<<setw(10)<<cost[i]<<endl;
    }

    void addNodes(vector<vector<Edge>>& graph,vector<vector<int>>& edges) {
        for(auto e : edges)
            graph[e[0]].push_back({e[1],e[2]});
    }

    void printGraph(vector<vector<Edge>>& graph) {
        for(int i = 0 ; i < graph.size() ; i++) {
            cout<<i<<" -> ";
            for(auto j : graph[i])
                cout<<j.node<<" ";
            cout<<endl;
        }
        cout<<endl;
    }
};

int main() {
    int size = 9;

    vector<vector<int>> edges = {{0,1,4},{1,0,4},{0,7,8},{7,0,8},{1,2,8},{2,1,8},{1,7,11},{7,1,11},{2,3,7},{3,2,7},{2,5,4},{5,2,4},{2,8,2},{8,2,2},{3,4,9},{4,3,9},{3,5,14},{5,3,14},{4,5,10},{5,4,10},{5,6,2},{6,5,2},{6,7,1},{7,6,1},{6,8,6},{8,6,6},{7,8,7},{8,7,7}};

    vector<vector<Edge>> graph(size);

    Dijkstra d;
    d.addNodes(graph,edges);
    d.printGraph(graph);
    d.djikstraArray(graph);

    return 0;
}