// User function Template for C++

class Solution{
public:
    vector<long long int> minimumSquares(long long int L, long long int B)
    {
        // code here
        long long int x=__gcd(L,B);
        vector<long long int>ans;
        ans.push_back((L*B)/(x*x));
        ans.push_back(x);
        return ans;
        
    }
};