#include<iostream>
#include<vector>
using namespace std;

class DisjointSet {
    public:
    vector<int> parent;
    vector<int> rank;

    DisjointSet(int n = 0) {
        rank = vector<int>(n,0);
        parent = vector<int>(n);
        for(int i = 0 ; i < n ; i++)
            parent[i] = i;
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

int main() {
    return 0;
}