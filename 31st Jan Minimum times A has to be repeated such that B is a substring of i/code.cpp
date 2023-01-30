//User function Template for C++

class Solution {
  public:
    int minRepeats(string A, string B) {
        // code here
        string temp=A;
        int moves=1;
        while(A.size()<B.size())
        {
            A+=temp;
            moves++;
        }
        if(A.find(B)!=-1)return moves;
        
        A+=temp;
        moves++;
        if(A.find(B)!=-1)return moves;
        
        return -1;
    }
};