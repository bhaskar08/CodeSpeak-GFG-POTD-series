//User function Template for C++

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */


class Solution
{
public:
    void maxGCDUtill(Node* root, int &gcd, int &ans)
    {
        if(root==NULL)return;
        
        if(root->left and root->right)
        {
            int curr_gcd=__gcd(root->left->data,root->right->data);
            if(curr_gcd>gcd)
            {
                gcd=curr_gcd;
                ans=root->data;
            }
            else if(curr_gcd==gcd)
            {
                ans=max(ans,root->data);
            }
        }
        maxGCDUtill(root->left,gcd,ans);
        maxGCDUtill(root->right,gcd,ans);
    }
    int maxGCD( Node* root)
    {
        //code here
        int ans=0;
        int gcd=0;
        maxGCDUtill( root, gcd, ans);
        
        return ans;
    }
};

