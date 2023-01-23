//User function template for C++
class Solution{
public:	
	// Converts arr[0..n-1] to reduced form.
	void convert(int arr[], int n) {
	    // code here
	    vector<pair<int,int>>temp;
	    
	    for(int i=0;i<n; i++)
	    {
	        temp.push_back({arr[i],i});
	    }
	    
	    sort(temp.begin(),temp.end());
	    
	    for(int i=0;i<n; i++)
	    {
	        arr[temp[i].second]=i;
	    }
	}

};