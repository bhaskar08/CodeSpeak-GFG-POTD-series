//User function Template for C++

/*

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};

*/

class Solution{
public:
bool isPrime(int n)
{
    if(n==1)
    {
        return false;
    }
    
    for(int i=2; i<=sqrt(n); i++)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    
    return true;
}
    Node *primeList(Node *head){
        
        Node* temp=head;
        while(temp!=NULL)
        {
            int n=temp->val;
            if(n==1)
            {
                temp->val=2;
                temp=temp->next;
                continue;
            }
            int prev=n;
            int ahead=n;
            while(!isPrime(prev))
            {
                prev--;
            }
            
            while(!isPrime(ahead))
            {
                ahead++;
            }
            
            int dis1=ahead-n;
            int dis2=n-prev;
            if(dis1<dis2)
            {
                temp->val=ahead;
            }
            else if(dis2<dis1)
            {
                temp->val=prev;
            }
            else
            {
                temp->val=prev;
            }
            temp=temp->next;
            
            
        }
        
        return head;
    }
};