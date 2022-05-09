#include <iostream>
#include <vector>
using namespace std;

// TC -> O(N);
// SC -> O(N);
vector<int> rearrange(int a[], int n)
{
    vector<int> res;
    for(int i=0; i<n; i++)
    {
        if(a[i] < 0)
        {
            res.push_back(a[i]);
        }
    }
    
    for(int i=0; i<n; i++)
    {
        if(a[i] >= 0)
        {
            res.push_back(a[i]);
        }
    }
    
    return res;
}

// two pointer approach
// TC -> O(N);
// SC -> O(1);
void rearrange2(int arr[], int n)
{
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            if (i != j)
                swap(arr[i], arr[j]);
            j++;
        }
    }
}

int main() {
	
	int n;
	cin>>n;
	int a[n];
	
	for(int i=0; i<n; i++)
	{
	    cin>>a[i];
	}
	
	vector<int> ans = rearrange(a, n);
	
	for(auto i:ans)
	{
	    cout<<i<<" ";
	}
	return 0;
}