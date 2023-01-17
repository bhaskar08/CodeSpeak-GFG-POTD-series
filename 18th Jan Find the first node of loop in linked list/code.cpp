//User function Template for C++

/*struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/
class Solution
{
    public:
     //Function to find first node if the linked list has a loop.
    int findFirstNode(Node* head)
    {
        // your code here
        Node* slow=head;
        Node* fast=head;
        bool check=false;
        
        while(fast!=NULL and fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                check=true;
                break;
            }
        }
        
        if(check==false)return -1;
        
        fast=head;
        
        // if(slow==head)return head->data;
        
        while(fast!=slow)
        {
            slow=slow->next;
            fast=fast->next;
        }
        
        return fast->data;
    }
};