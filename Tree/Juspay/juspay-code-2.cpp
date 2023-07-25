#include<bits/stdc++.h>
using namespace std;

struct Node {
    bool isLocked;
    int id;
    Node* parent;
    int des_locked;
    vector<Node*> child;
    Node() {
        id = 0;
        isLocked = false;
        parent = nullptr;
        des_locked = 0;
    }
};

bool ancestorLocked(Node* node) {
	auto parent = node->parent;
	while(parent) {
		if(parent->isLocked)
			return true;
		parent = parent->parent;
	}
	return false;
}

void change(Node* node,int val) {
    auto parent = node->parent;
    while(parent) {
        parent->des_locked += val;
        parent = parent->parent;
    }
}

bool lock(Node* node,int id) {
    if(node->isLocked || node->des_locked > 0 || ancestorLocked(node))
        return false;
    change(node,1);
    node->isLocked = true;
    node->id = id;
    return true;
}

bool unlock(Node* node,int id) {
    if(!node->isLocked || node->id != id)
        return false;
    change(node,-1);
    node->isLocked = false;
    node->id = 0;
    return true;
}

bool getChildren(Node* node,vector<Node*>& children,int id) {
    if(!node)
        return true;
    if(node->isLocked) {
        if(id != node->id)
            return false;
        else
            children.push_back(node);
    }
    if(node->des_locked == 0)
        return true;
    for(auto& i : node->child) {
        bool ans = getChildren(i,children,id);
        if(ans == false)
            return false;
    }
    return true;
}

bool upgrade(Node* node,int id) {
    if(node->isLocked || node->des_locked == 0 || ancestorLocked(node))
        return false;
    vector<Node*> children;
    bool can = getChildren(node,children,id);
    if(!can)
        return false;
    for(auto& i : children)
        unlock(i,id);
    change(node,1);
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