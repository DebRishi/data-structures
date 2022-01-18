#include<iostream>
#include<algorithm>
#include<iomanip>
#include<vector>
using namespace std;

struct Node {
    int src;
    int des;
    int weight;
};

class Kruskal {
    public:
    class DisjointSet {
        public:
        vector<int> parent;
        vector<int> rank;

        DisjointSet(int size = 0) {
            rank = vector<int>(size,0);
            parent = vector<int>(size);
            for(int i = 0 ; i < size ; i++) {
                parent[i] = i;
            }
        }

        int findParent(int node) {
            if(node == parent[node]) {
                return node;
            }
            return parent[node] = findParent(parent[node]);
        }

        void unionSets(int x,int y) {
            int parX = findParent(x);
            int parY = findParent(y);
            if(rank[parX] < rank[parY]) {
                parent[parX] = parY;
            }
            else if(rank[parX] > rank[parY]) {
                parent[parY] = parX;
            }
            else {
                parent[parY] = parX;
                rank[parX]++;
            }
        }
    };

    static bool compare(Node& a,Node& b) {
        if(a.weight != b.weight)
            return a.weight < b.weight;
        if(a.src != b.src)
            return a.src < b.src;
        return a.des < b.src;
    }

    void algorithm(int size,vector<Node>& edges) {
        sort(edges.begin(),edges.end(),compare);
        DisjointSet ds(size);
        vector<Node> mst;
        
        for(auto edge : edges) {
            if(ds.findParent(edge.src) != ds.findParent(edge.des)) {
                mst.push_back(edge);
                ds.unionSets(edge.src,edge.des);
            }
        }

        int totalCost = 0;
        cout<<"\nSource"<<setw(15)<<"Destination"<<setw(10)<<"Cost\n\n";
        for(auto edge : mst) {
            cout<<edge.src<<setw(15)<<edge.des<<setw(10)<<edge.weight<<endl;
            totalCost += edge.weight;
        }
        cout<<"\nTotal Cost : "<<totalCost<<"\n\n";
    }
};

int main() {
    int size = 9;

    vector<Node> edges = {{7,6,1} ,{8,2,2} ,{6,5,2} ,{0,1,4} ,{2,5,4} ,{8,6,6} ,{2,3,7} ,{7,8,7} ,{0,7,8} ,{1,2,8} ,{3,4,9} ,{5,4,10},{1,7,11},{3,5,14}};

    Kruskal k;
    k.algorithm(size,edges);

    return 0;
}