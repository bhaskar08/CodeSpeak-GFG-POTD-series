//User function Template for C++
/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution{
public:
Node* targ;
long long int ans=0;
void solve(Node* root, int d)
{
    if(root==NULL)return;
    if(d==0)
    {
        ans+=root->data;
    }
    solve(root->left,d-1);
    solve(root->right,d+1);
}
bool find(Node* root, int target)
{
    if(root==NULL)return false;
    if(root->data>target)
    {
        return find(root->left,target);
    }
    else if(root->data<target)
    {
        return find(root->right,target);
    }
    else
    {
        targ=root;
        return true;
    }
}
    long long int verticallyDownBST(Node *root,int target){
        // Code here
        bool present=find(root, target);
        if(present==false)return -1;
        
        solve(targ,0);
        
        return ans-targ->data;
    }
};