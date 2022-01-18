#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node * left;
    Node * right;

    Node(int x = 0,Node * l = 0,Node * r = 0) {
        data = x;
        left = l;
        right = r;
    }
};

vector <Node *> possibleBST(int start,int end) {
    vector <Node *> trees;
    if(start > end) {
        trees.push_back(nullptr);
        return trees;
    }

    for(int i = start ; i <= end ; i++) {
        vector <Node *> leftTree = possibleBST(start,i-1);
        vector <Node *> rightTree = possibleBST(i+1,end);

        for(int x = 0 ; x < leftTree.size() ; x++) {
            for(int y = 0 ; y < rightTree.size() ; y++) {
                Node * node = new Node(i);
                node->left = leftTree[x];
                node->right = rightTree[y];
                trees.push_back(node);
            }
        }
    }

    return trees;
}

void printPreorder(Node * root) {
    if(root == 0) {
        return;
    }
    cout<<root->data<<" ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    vector <Node *> trees = possibleBST(1,3);
    
    for(auto i : trees) {
        printPreorder(i);
        cout<<endl;
    }

    return 0;
}