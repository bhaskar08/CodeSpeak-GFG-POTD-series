/*

Definition for singly Link List Node
struct Node
{
    char data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
};

You can also use the following for printing the link list.
printList(Node* node);
*/

class Solution {
  public:
    
    bool isAnagram(vector<int> &freq, vector<int> &tempFreq)
    {
        return freq == tempFreq;
    }
    
    void handleAnagram(Node* &ptr1, Node* &ptr2,vector<int> &tempFreq, vector<Node *> &ans, int len)
    {
        ans.push_back(ptr1);
        
        Node *temp = ptr2;
        ptr2 = ptr2->next;
        temp->next = NULL;
        
        ptr1 = ptr2; //window shift
        
        for(int i=0; i<26; i++)
        {
            tempFreq[i] = 0;
        }
        
        
        
        Node *prev = NULL;
        for(int i=0; i<len && ptr2 != NULL; i++)
        {
            tempFreq[ptr2->data - 'a']++;
            prev = ptr2;
            ptr2 = ptr2->next;
        }
        ptr2 = prev;
    }
    vector<Node*> findAnagrams(struct Node* head, string s) {
        // code here
        
        vector<Node*> ans;
        
        Node *ptr1 = head, *ptr2 = head;
        int len = s.size();
        
        
        vector<int> freq(26,0); //freq of characters of string s
        vector<int> tempFreq(26,0); //freq of chars from linked list
        
        for(int i=0; i<len; i++)
        {
            freq[s[i] - 'a']++;
        }
        
        //first n (size of s) chars of linked list
        Node *prev = NULL;
        for(int i=0; i<len && ptr2 != NULL; i++)
        {
            tempFreq[ptr2->data - 'a']++;
            prev = ptr2;
            ptr2 = ptr2->next;
        }
        ptr2 = prev;
        
        while(ptr2 != NULL)
        {
            bool check = isAnagram(freq,tempFreq);
            
            if(check == true) //it is anagram - store ans and window shift
            {
                handleAnagram(ptr1,ptr2,tempFreq,ans,len);
            }
            else
            {
                //not anagram - move pointers
                tempFreq[ptr1->data - 'a']--;
                ptr1 = ptr1->next;
                
                ptr2 = ptr2->next;
                
                if(ptr2 != NULL) tempFreq[ptr2->data - 'a']++;
            }
        }
        
        return ans;
        
    }
};
