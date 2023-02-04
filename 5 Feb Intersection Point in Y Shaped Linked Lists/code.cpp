/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

class Solution
{
public:
int length(Node* head)
{
    int len=0;
    while(head!=NULL)
    {
        len++;
        head=head->next;
    }
    
    return len;
}
    int intersectPoint(Node* head1, Node* head2)
    {
        // Your Code Here
        int l1=length(head1);
        int l2=length(head2);
        
        Node* ptr1;
        Node* ptr2;
        
        if(l1>l2)
        {
            ptr1=head1;
            ptr2=head2;
        }
        else
        {
            ptr1=head2;
            ptr2=head1;
        }
        
        int d=abs(l1-l2);
        
        while(d)
        {
            ptr1=ptr1->next;
            d--;
        }
        
        while(ptr1!=NULL and ptr2!=NULL)
        {
            if(ptr1==ptr2)
            {
                return ptr1->data;
            }
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        return -1;
        
    }
};