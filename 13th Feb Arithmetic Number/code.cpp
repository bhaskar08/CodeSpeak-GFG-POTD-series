// User function Template for C++

class Solution{
public:
    int inSequence(int A, int B, int C){
        // code here
        int d=B-A;
        if(d==0)return true;
        if(d>0)
        {
            if(C<=0)return false;
            if(d%C==0)return true;
            
            return false;
        }
        else
        {
            if(C>=0)return false;
            
            if(d%C==0)return true;
            
            return false;
        }
        
        return true;
    }
};