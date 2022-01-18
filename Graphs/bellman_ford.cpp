#include<iostream>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<queue>
using namespace std;

struct Edge {
    int src;
    int des;
    int weight;
};

class BellmanFord {
    public:
    void algorithm(int size,vector<Edge>& edges,int start = 0) {
        vector<int> parent(size,-1);
        vector<int> cost(size,1e9);

        parent[start] = start;
        cost[start] = 0;

        for(int count = 0 ; count < size-1 ; count++) {
            for(auto edge : edges) {
                if(cost[edge.src] + edge.weight < cost[edge.des]) {
                    cost[edge.des] = cost[edge.src] + edge.weight;
                    parent[edge.des] = edge.src;
                }
            }
        }

        for(auto edge : edges) {
            if(cost[edge.src] + edge.weight < cost[edge.des]) {
                cout<<"Negetive Cycle Detected"<<endl;
                return;
            }
        }

        printShortestPath(size,parent,cost);
    }

    void printShortestPath(int size,vector<int>& parent,vector<int>& cost) {
        cout<<"Node"<<setw(10)<<"Parent"<<setw(10)<<"Cost\n\n";
        for(int i = 0 ; i < size ; i++)
            cout<<i<<setw(10)<<parent[i]<<setw(10)<<cost[i]<<endl;
    }
};

int main() {
    int size = 9;

    vector<Edge> edges = {{0,1,4},{1,0,4},{0,7,8},{7,0,8},{1,2,8},{2,1,8},{1,7,11},{7,1,11},{2,3,7},{3,2,7},{2,5,4},{5,2,4},{2,8,2},{8,2,2},{3,4,9},{4,3,9},{3,5,14},{5,3,14},{4,5,10},{5,4,10},{5,6,2},{6,5,2},{6,7,1},{7,6,1},{6,8,6},{8,6,6},{7,8,7},{8,7,7}};

    BellmanFord b;
    b.algorithm(size,edges);
    
    return 0;
}