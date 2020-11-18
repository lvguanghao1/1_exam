#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <time.h>

using namespace std;

// add something just test

/*
void test01() {
    int m = 0, n = 0;
    cin >> m >> n;
    string edge;
    map<int, pair<int, int>> tree;
    for(int i = 0; i < n; ++i)
    {
        int father_id, child_id;
        cin >> father_id >> edge >> child_id;
        if(edge == "left")
        {
            tree[father_id].first = child_id;
            // tree[father_id].second = 0;
        }
        if(edge == "right")
        {
            tree[father_id].second = child_id;
            // tree[father_id].first = 0;
        }
    }
    int count = 0;
    for(auto node : tree)
    {
        int id_left = node.second.first;
        int id_right = node.second.second;
        cout << node.first << " : " << id_left <<  " | " << id_right << endl;;
        if(id_left == 0 || id_right == 0)
            continue;
        if(tree.find(id_left) == tree.end() && tree.find(id_right) == tree.end())
            count++;
    }
    cout << count;
}


int main() {
    int a[5]={4,1,3,3,3};
    test01();
    return 0;
}
*/

class TreeNode {
public:
    int value;
    TreeNode* left,*right;
    TreeNode():value(0),left(NULL),right(NULL) {}
    TreeNode(int a):value(a),left(NULL),right(NULL) {}
};

TreeNode* reverse(TreeNode* head) {
    if(!head)
        return NULL;
    reverse(head->left);
    reverse(head->right);
    TreeNode* node=head->left;
    head->left=head->right;
    head->right=node;
    return head;
}

void coutNode(TreeNode* node) {
    if(!node) {
        cout<<"NULL"<<endl;
        return;
    }
    cout<<node->value<<endl;
    coutNode(node->left);
    coutNode(node->right);
}

void testReverse() {
    vector<TreeNode*> vnode(5);
    for(int i=0;i<5;++i) {
        vnode[i]=new TreeNode(i);
    }
    vnode[0]->left=vnode[1];
    vnode[1]->right=vnode[2];
    vnode[1]->left=vnode[3];
    coutNode(vnode[0]);
    reverse(vnode[0]);
    coutNode(vnode[0]);

}

int getNums(string& str) {
    map<int,int> mp;
    int n=str.size()-1;
    int maxNum=0;

    for(int i=n;i>=0;--i) {
        if(str[i]<'a' || str[i]>'z')
            continue;
        if(!mp.count(str[i]-'a')) {
            mp.insert(make_pair(str[i]-'a',1));
        }
    }
    int tmp=-1,curNum=0;
    for(auto ibegin=mp.begin(),iend=mp.end();ibegin!=iend;++ibegin) {
        if((*ibegin).first==0) {
            curNum=1;
            tmp=(*ibegin).first;
        }
        else if((*ibegin).first==tmp+1){
            ++curNum;
            tmp=(*ibegin).first;
        }
        else {
            curNum=1;
            tmp=(*ibegin).first;
        }
        maxNum=max(maxNum,curNum);
    }
    return maxNum;
}

int getNums02(vector<int>& nums) {
    int n=nums.size();
    if(n<2)
        return 0;
    vector<int> left(n,0),right(n,0);
    int maxHeight=nums[0];
    for(int i=1;i<n;++i) {
        left[i]=maxHeight;
        maxHeight=max(maxHeight,nums[i]);
    }
    maxHeight=nums[n-1];
    for(int i=n-2;i>=0;--i) {
        right[i]=maxHeight;
        maxHeight=max(maxHeight,nums[i]);
    }
    int res=0;
    for(int i=0;i<n;++i) {
        int height=min(left[i],right[i]);
        res+=height>nums[i]?height-nums[i]:0;
    }
    return res;
}



int main() {
    map<int,int> mp;
    if(mp[1])
        cout<<"1:"<<mp.size()<<endl;
    else
        cout<<"0:"<<mp.size()<<endl;
    cout<<"mp[1] is:"<<mp[1]<<endl;
    mp.find(1);
    mp.count(1);
    set<int> s;
    s.find(1);
    s.count(1);
    return 0;
}
