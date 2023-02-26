//User function Template for C++

/*
Definition for singly Link List Node
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
*/


class Solution
{
public:
   Node* reverse(Node* head)
   {
       Node* curr=head;
       Node* prev=NULL;
       Node* nxt;
       
       while(curr!=NULL)
       {
           nxt=curr->next;
           curr->next=prev;
           prev=curr;
           curr=nxt;
       }
       
       return prev;
   }
    Node *reverse(Node *head, int k)
    {
        // code here
        Node* temp=head;
        for(int i=0;i<k-1; i++)
        {
            temp=temp->next;
        }
        
        Node* secondHead=reverse(temp->next);
        temp->next=NULL;
        Node* firstHead=reverse(head);
        
        temp=firstHead;
        
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=secondHead;
        
        return firstHead;
    }
};