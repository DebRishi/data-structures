#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <stack>
#include <queue>

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

Node * insert(Node * root,int x) {
    if(root == 0) {
        return new Node(x);
    }
    if(x < root->data) {
        root->left = insert(root->left,x);
    }
    else if(x > root->data) {
        root->right = insert(root->right,x);
    }
    return root;
}
 
Node * arrayUtil(vector <int> v,int start,int end) {
    if(start > end) {
        return 0;
    }
    int mid = (start+end)/2;
    Node * root = new Node(v[mid]);
    root->left = arrayUtil(v,start,mid-1);
    root->right = arrayUtil(v,mid+1,end);
    return root;
}
 
Node * createArray(vector <int> v) {
    sort(v.begin(),v.end());
    Node * root = arrayUtil(v,0,v.size()-1);
    return root;
}
 
Node * preorderUtil(vector <int> preorder,int & index,int min = INT_MIN,int max = INT_MAX) {
    if(index > preorder.size()) {
        return 0;
    }
    Node * root = 0;
    int key = preorder[index];
    if(key < max && key > min) {
        root = new Node(preorder[index++]);
        if(index < preorder.size()) {
            root->left = preorderUtil(preorder,index,min,key);
        }
        if(index < preorder.size()) {
            root->right = preorderUtil(preorder,index,key,max);
        }
    }
    return root;
}
 
Node * createPreorder(vector <int> preorder) {
    int index = 0;
    Node * root = preorderUtil(preorder,index);
    return root;
}
 
Node * postorderUtil(vector <int> postorder,int & index,int min = INT_MIN,int max = INT_MAX) {
    if(index < 0) {
        return 0;
    }
    Node * root = 0;
    int key = postorder[index];
    if(key < max && key > min) {
        root = new Node(postorder[index--]);
        if(index >= 0) {
            root->right = postorderUtil(postorder,index,key,max);
        }
        if(index >= 0) {
            root->left = postorderUtil(postorder,index,min,key);
        }
    }
    return root;
}
 
Node * createPostorder(vector <int> postorder) {
    int index = postorder.size()-1;
    Node * root = postorderUtil(postorder,index);
    return root;
}
 
Node * search(Node * root,int x) {
    if(root == 0) {
        return 0;
    }
    if(x < root->data) {
        return search(root->left,x);
    }
    else if(x > root->data) {
        return search(root->right,x);
    }
    else {
        return root;
    }
}

Node * remove(Node * root,int x) {
    if(root == 0) {
        return 0;
    }
    if(x < root->data) {
        root->left = remove(root->left,x);
    }
    else if(x > root->data) {
        root->right = remove(root->right,x);
    }
    else {
        if(root->left == 0) {
            Node * t = root;
            root = root->right;
            delete(t);
        }
        else if(root->right == 0) {
            Node * t = root;
            root = root->left;
            delete(t);
        }
        else {
            Node * t = root->right;
            while(t->left) {
                t = t->left;
            }
            root->data = t->data;
            root->right = remove(root->right,t->data);
        }
    }
    return root;
}


// LowestCommonAnsestor in BST O(h) = O(log(n))
Node* LCA(Node* root,int key1,int key2) {
    if(!root)
        return 0;
    if(root->data < key1 && root->data < key2)
        return LCA(root->right,key1,key2);
    if(root->data > key1 && root->data > key2)
        return LCA(root->left,key1,key2);
    return root;
}

bool checkBST(Node * root,int min = INT_MIN,int max = INT_MAX) {
    if(root == 0) {
        return true;
    }
    bool left = checkBST(root->left,min,root->data);
    bool right = checkBST(root->right,root->data,max);
    if(root->data < max && root->data > min && left && right) {
        return true;
    }
    else {
        return false;
    }
}

void printPreOrder(Node * root) {
    if(root == 0) {
        cout<<"Tree Doesn't exist"<<endl;
        return;
    }
    stack <Node *> s;
    s.push(root);
    while(!s.empty()) {
        Node * cur = s.top();
        s.pop();
        cout<<cur->data<<" ";
        if(cur->right) {
            s.push(cur->right);
        }
        if(cur->left) {
            s.push(cur->left);
        }
    }
    cout<<endl;
}

void printInOrder(Node * root) {
    if(root == 0) {
        cout<<"Tree Doesn't exist"<<endl;
        return;
    }
    stack <Node *> s;
    Node * cur = root;
    while(cur || !s.empty()) {
        while(cur) {
            s.push(cur);
            cur = cur->left;
        }
        cur = s.top();
        s.pop();
        cout<<cur->data<<" ";
        cur = cur->right;
    }
    cout<<endl;
}

void printPostOrder(Node * root) {
    if(root == 0) {
        cout<<"Tree Doesn't exist"<<endl;
        return;
    }
    stack <Node *> s1,s2;
    s1.push(root);
    while(!s1.empty()) {
        Node * cur = s1.top();
        s1.pop();
        s2.push(cur);
        if(cur->left) {
            s1.push(cur->left);
        }
        if(cur->right) {
            s1.push(cur->right);
        }
    }
    while(!s2.empty()) {
        cout<<s2.top()->data<<" ";
        s2.pop();
    }
    cout<<endl;
}

void printLevelOrder(Node * root) {
    if(root == 0) {
        cout<<"Tree Doesn't exist"<<endl;
        return;
    }
    queue <Node *> q;
    q.push(root);
    while(!q.empty()) {
        int n = q.size();
        for(int i = 0 ; i < n ; i++) {
            Node * cur = q.front();
            q.pop();
            cout<<cur->data<<" ";
            if(cur->left) {
                q.push(cur->left);
            }
            if(cur->right) {
                q.push(cur->right);
            }
        }
    }
    cout<<endl;
}

int main() {
    Node * root = createPostorder({1,7,5,50,40,10});
    printInOrder(root);
}