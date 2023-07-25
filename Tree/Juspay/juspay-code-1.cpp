#include<bits/stdc++.h>
using namespace std;

struct Node {
    bool isLocked;
    int id;
    Node* parent;
    int anc_locked;
    int des_locked;
    vector<Node*> child;
    Node() {
        id = 0;
        isLocked = false;
        parent = nullptr;
        anc_locked = 0;
        des_locked = 0;
    }
};

void change(Node* node,int val) {
    if(!node)
        return;
    node->anc_locked += val;
    for(auto& i : node->child)
        change(i,val);
}

bool lock(Node* node,int id) {
    if(node->isLocked || node->anc_locked > 0 || node->des_locked > 0)
        return false;
    auto parent = node;
    while(parent) {
        parent->des_locked += 1;
        parent = parent->parent;
    }
    change(node,1);
    node->isLocked = true;
    node->id = id;
    return true;
}

bool unlock(Node* node,int id) {
    if(!node->isLocked || node->id != id)
        return false;
    auto parent = node;
    while(parent) {
        parent->des_locked -= 1;
        parent = parent->parent;
    }
    change(node,-1);
    node->isLocked = false;
    node->id = 0;
    return true;
}

bool getAllChilds(Node* node,vector<Node*>& a,int id) {
    if(!node)
        return true;
    if(node->isLocked) {
        if(id != node->id)
            return false;
        else
            a.push_back(node);
    }
    if(node->des_locked == 0)
        return true;
    for(auto& i : node->child) {
        bool ans = getAllChilds(i,a,id);
        if(ans == false)
            return false;
    }
    return true;
}

bool upgrade(Node* node,int id) {
    if(node->isLocked || node->anc_locked > 0 || node->des_locked == 0)
        return false;
    vector<Node*> a;
    bool can = getAllChilds(node,a,id);
    if(!can)
        return false;
    
    change(node,1);
    
    for(auto& i : a)
        unlock(i,id);
    node->isLocked = true;
    node->id = id;
    return true;
}

int main() {
    int n;
    int k;
    int q;
    cin >> n;
    cin >> k;
    cin >> q;
    
    unordered_map<string,Node*> hash;
    vector<string> arr(n);
    for(int i = 0 ; i < n ; i++)
        cin >> arr[i];
    
    Node* root = new Node();
    
    hash[arr[0]] = root;
    
    queue<Node*> queue;
    queue.push(root);
    int index = 1;
    while(!queue.empty() && index < n) {
        int size = queue.size();
        while(size-- > 0) {
            Node* rem = queue.front();
            queue.pop();
            for(int i = 1 ; i <= k && index < n ; i++) {
                Node* newNode = new Node();
                newNode->parent = rem;
                hash[arr[index]] = newNode;
                rem->child.push_back(newNode);
                queue.push(newNode);
                index++;
            }
        }
    }
    
    int val;
    string str;
    int id;
    bool ans;
    
    for(int i = 0 ; i < q ; i++) {
        cin >> val;
        cin >> str;
        cin >> id;
        ans = false;
        if(val == 1)
            ans = lock(hash[str],id);
        else if(val == 2)
            ans = unlock(hash[str],id);
        else if(val == 3)
            ans = upgrade(hash[str],id);
        cout<<ans<<endl;
    }
    
    return 0;
}