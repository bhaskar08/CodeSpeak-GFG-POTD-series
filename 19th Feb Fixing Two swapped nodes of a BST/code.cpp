// User function Template for C++

/*struct Node
{
    int data;
    struct Node *left, *right;
};*/

class Solution {
  public:
  Node* prev=NULL;
  Node* first=NULL;
  Node* second=NULL;
  
  void inorder(Node* root)
  {
      if(root==NULL)return;
      
      inorder(root->left);
      
      if(prev!=NULL and root->data<prev->data)
      {
          if(first==NULL)
          {
              first=prev;
          }
          second=root;
      }
      prev=root;
      inorder(root->right);
  }
    struct Node *correctBST(struct Node *root) {
        // code here
        inorder(root);
        int a=first->data;
        int b=second->data;
        
        first->data=b;
        second->data=a;
        
        return root;
    }
};