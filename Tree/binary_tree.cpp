#include <iostream>
#include <climits>
#include <utility>
#include <vector>
#include <stack>
#include <queue>
#include <map>

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

int search(vector <int> inorder,int start,int end,int key) {
    for(int i = start ; i <= end ; i++) {
        if(inorder[i] == key) {
            return i;
        }
    }
    return -1;
}

Node* preBuilder(vector <int> preorder,vector <int> inorder,int & pos,int start,int end) {
    if(start > end) {
        return 0;
    }
    Node * root = new Node(preorder[pos++]);
    int index = search(inorder,start,end,root->data);
    root->left = preBuilder(preorder,inorder,pos,start,index-1);
    root->right = preBuilder(preorder,inorder,pos,index+1,end);
    return root;
}

Node* preTree(vector <int> preorder,vector <int> inorder) {
    int pos = 0;
    int n = inorder.size()-1;
    Node * root = preBuilder(preorder,inorder,pos,0,n);
    return root;
}

Node* postBuilder(vector <int> postorder,vector <int> inorder,int & pos,int start,int end) {
    if(start > end) {
        return 0;
    }
    Node * root = new Node(postorder[pos--]);
    int index = search(inorder,start,end,root->data);
    root->right = postBuilder(postorder,inorder,pos,index+1,end);
    root->left = postBuilder(postorder,inorder,pos,start,index-1);
    return root;
}

Node* postTree(vector <int> postorder,vector <int> inorder) {
    int pos = postorder.size()-1;
    int n = inorder.size()-1;
    Node * root = postBuilder(postorder,inorder,pos,0,n);
    return root;
}

int height(Node * root) {
    if(root == 0) {
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    return max(lh,rh)+1;
}

int count(Node * root) {
    if(root == 0) {
        return 0;
    }
    int lc = count(root->left);
    int rc = count(root->right);
    return lc+rc+1;
}

int sum(Node * root) {
    if(root == 0) {
        return 0;
    }
    int ls = sum(root->left);
    int rs = sum(root->right);
    return root->data+ls+rs;
}

int sumReplacement(Node * root) {
    if(root == 0) {
        return 0;
    }
    int lsr = sumReplacement(root->left);
    int rsr = sumReplacement(root->right);
    root->data += lsr + rsr;
    return root->data;
}

int calcDiameter(Node * root) {
    if(root == 0) {
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    int ld = calcDiameter(root->left);
    int rd = calcDiameter(root->right);
    return max(lh+rh+1,max(ld,rd));
}

int calcDiameterOp(Node * root,int & h) {
    if(root == 0) {
        h = 0;
        return 0;
    }
    int lh = 0;
    int rh = 0;
    int ld = calcDiameterOp(root->left,lh);
    int rd = calcDiameterOp(root->right,rh);
    h = max(lh,rh)+1;
    return max(lh+rh+1,max(ld,rd));
}

bool isBalanced(Node * root) {
    if(root == 0) {
        return true;
    }
    if(isBalanced(root->left) == false) {
        return false;
    }
    if(isBalanced(root->right) == false) {
        return false;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    if(std::abs(lh-rh) <= 1) {
        return true;
    }
    else {
        return false;
    }
}

bool isBalancedOp(Node * root,int & h) {
    if(root == 0) {
        h = 0;
        return true;
    }
    int lh = 0;
    int rh = 0;
    if(isBalancedOp(root->left,lh) == false) {
        return false;
    }
    if(isBalancedOp(root->right,rh) == false) {
        return false;
    }
    h = max(lh,rh)+1;
    if(std::abs(lh-rh) <= 1) {
        return true;
    }
    else {
        return false;
    }
}

bool isBST(Node * root,int min = INT_MIN,int max = INT_MAX) {
    if(root == 0) {
        return true;
    }
    bool left = isBST(root->left,min,root->data);
    bool right = isBST(root->right,root->data,max);
    if(root->data < max && root->data > min && left && right) {
        return true;
    }
    else {
        return false;
    }
}

void viewLeft(Node * root) {
    if(root == 0) {
        cout<<"Tree doesn't Exist"<<endl;
        return;
    }
    queue <Node *> q;
    q.push(root);
    while(!q.empty()) {
        int n = q.size();
        cout<<q.front()->data<<" ";
        while(n) {
            Node * cur = q.front();
            q.pop();
            if(cur->left) {
                q.push(cur->left);
            }
            if(cur->right) {
                q.push(cur->right);
            }
            n--;
        }
    }
    cout<<endl;
}

void viewRight(Node * root) {
    if(root == 0) {
        cout<<"Tree doesn't Exist"<<endl;
        return;
    }
    queue <Node *> q;
    q.push(root);
    while(!q.empty()) {
        int n = q.size();
        while(n) {
            Node * cur = q.front();
            q.pop();
            if(cur->left) {
                q.push(cur->left);
            }
            if(cur->right) {
                q.push(cur->right);
            }
            n--;
            if(n == 0) {
                cout<<cur->data<<" ";
            }
        }
    }
    cout<<endl;
}

void topUtil(Node * root,map <int,pair <int,int>> & m,int d = 0,int l = 0) {
    if(root == 0) {
        return;
    }
    if(m.count(d) == 0 || l < m[d].first) {
        m[d] = make_pair(l,root->data);
    }
    topUtil(root->left,m,d-1,l+1);
    topUtil(root->right,m,d+1,l+1);
}

void viewTop(Node * root) {
    map <int,pair <int,int>> m;
    topUtil(root,m);
    for(auto i : m) {
        cout<<i.second.second<<" ";
    }
    cout<<endl;
}

void bottomUtil(Node * root,map <int,pair <int,int>> & m,int d = 0,int l = 0) {
    if(root == 0) {
        return;
    }
    if(m.count(d) == 0 || m[d].first < l) {
        m[d] = make_pair(l,root->data);
    }
    bottomUtil(root->left,m,d-1,l+1);
    bottomUtil(root->right,m,d+1,l+1);
}

void viewBottom(Node * root) {
    map <int,pair <int,int>> m;
    bottomUtil(root,m);
    for(auto i : m) {
        cout<<i.second.second<<" ";
    }
    cout<<endl;
}

Node * lowestCommonAncestor(Node * root,int key1,int key2) {
    if(root == 0) {
        return 0;
    }
    if(root->data == key1 || root->data == key2) {
        return root;
    }
    Node * left = lowestCommonAncestor(root->left,key1,key2);
    Node * right = lowestCommonAncestor(root->right,key1,key2);
    if(left && right) {
        return root;
    }
    else if(left) {
        return left;
    }
    else {
        return right;
    }
}

int getDistance(Node * root,int key,int d = 0) {
    if(root == 0) {
        return -1;
    }
    if(root->data == key) {
        return d;
    }
    int ld = getDistance(root->left,key,d+1);
    int rd = getDistance(root->right,key,d+1);
    if(ld != -1) {
        return ld;
    }
    else {
        return rd;
    }
}

int distBtwNodes(Node * root,int key1,int key2) {
    if(root == 0) {
        return -1;
    }
    Node * lca = lowestCommonAncestor(root,key1,key2);
    int d1 = getDistance(lca,key1);
    int d2 = getDistance(lca,key2);
    return d1+d2;
}

void flattenTree(Node * root) {
    if(root == 0 || root->left == 0 && root->right == 0) {
        return;
    }
    if(root->left) {
        flattenTree(root->left);
        Node * temp = root->right;
        root->right = root->left;
        root->left = 0;
        
        Node * t = root;
        while(t->right) {
            t = t->right;
        }
        t->right = temp;
    }
}

void printSubtreeNodes(Node * root,int d) {
    if(root == 0 || d < 0) {
        return;
    }
    if(d == 0) {
        cout<<root->data<<" ";
        return;
    }
    printSubtreeNodes(root->left,d-1);
    printSubtreeNodes(root->right,d-1);
}

int printNodesAtK(Node * root,int target,int k) {
    if(root == 0) {
        return -1;
    }
    if(root->data == target) {
        printSubtreeNodes(root,k);
        return 0;
    }
    int dl = printNodesAtK(root->left,target,k);
    if(dl != -1) {
        if(dl + 1 == k) {
            cout<<root->data<<" ";
        }
        else {
            printSubtreeNodes(root->right,k-dl-2);
        }
        return dl+1;
    }
    int dr = printNodesAtK(root->right,target,k);
    if(dr != -1) {
        if(dr + 1 == k) {
            cout<<root->data<<" ";
        }
        else {
            printSubtreeNodes(root->left,k-dr-2);
        }
        return dr+1;
    }
    return -1;
}

int maxPathSumUtil(Node * root,int & ans) {
    if(root == 0) {
        return 0;
    }
    int left = maxPathSumUtil(root->left,ans);
    int right = maxPathSumUtil(root->right,ans);
    
    int nodePathSum = max(max(root->data,root->data+left+right),max(root->data+left,root->data+right));
    ans = max(ans,nodePathSum);
    
    int singlePathSum = max(root->data,max(root->data+left,root->data+right));
    return singlePathSum;
}

int maxPathSum(Node * root) {
    int ans = INT_MIN;
    maxPathSumUtil(root,ans);
    return ans;
}

void printPreOrder(Node * root) {
    if(root == 0) {
        cout<<"Tree doesn't Exist"<<endl;
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

void PreOrderRecursive(Node * n) {
    if (n == 0) {
        return;
    }
    cout<<n->data<<" ";
    PreOrderRecursive(n->left);
    PreOrderRecursive(n->right);
}

void printInOrder(Node * root) {
    if(root == 0) {
        cout<<"Tree doesn't Exist"<<endl;
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

void InOrderRecursive(Node * n) {
    if (n == 0) {
        return;
    }
    InOrderRecursive(n->left);
    cout<<n->data<<" ";
    InOrderRecursive(n->right);
}

void printPostOrder(Node * root) {
    if(root == 0) {
        cout<<"Tree doesn't Exist"<<endl;
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

void PostOrderRecursive(Node * n) {
    if (n == 0) {
        return;
    }
    PostOrderRecursive(n->left);
    PostOrderRecursive(n->right);
    cout<<n->data<<" ";
}

void printLevelOrder(Node * root) {
    if(root == 0) {
        cout<<"Tree doesn't Exist"<<endl;
        return;
    }
    queue <Node *> q;
    q.push(root);
    while(!q.empty()) {
        int n = q.size();
        while(n) {
            Node * cur = q.front();
            q.pop();
            cout<<cur->data<<" ";
            if(cur->left) {
                q.push(cur->left);
            }
            if(cur->right) {
                q.push(cur->right);
            }
            n--;
        }
    }
    cout<<endl;
}


void PrintLevel(Node * node,int level) {
    if(node == 0) {
        return;
    }

    if(level == 1) {
        cout<<node->data<<" ";
    }

    else if(level > 1) {
        PrintLevel(node->left,level-1);
        PrintLevel(node->right,level-1);
    }
}

void LevelOrderRecursive(Node * root) {
    for(int i = 1 ; i <= height(root) ; i++) {
        PrintLevel(root,i);
    }
}

void verticalUtil(Node * root,map <int,vector <int>> & m,int d = 0) {
    if(root == 0) {
        return;
    }
    m[d].push_back(root->data);
    verticalUtil(root->left,m,d-1);
    verticalUtil(root->right,m,d+1);
}

void printVerticalOrder(Node * root) {
    map <int,vector <int>> m;
    verticalUtil(root,m);
    for(auto it = m.begin() ; it != m.end() ; it++) {
        cout<<it->first<<" : ";
        for(int i = 0 ; i < it->second.size() ; i++) {
            cout<<it->second[i]<<" ";
        }
        cout<<endl;
    }
}

int main() {
    Node * r = new Node(20);
    r->left = new Node(8);
    r->right = new Node(22);
    r->left->left = new Node(4);
    r->left->right = new Node(12);
    r->left->right->left = new Node(10);
    r->left->right->right = new Node(14);
    printLevelOrder(r);
}