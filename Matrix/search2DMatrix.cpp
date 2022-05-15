#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // linear search 
        // TC O(N*M)
         int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(matrix[i][j] == target)
                {
                    return true;
                }
            }
        }
        
        return false;
    }
};

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // binarySearch cause each row is sorted
        // TC O(LOG(N*M))
        int n = matrix.size();
        int m = matrix[0].size();
        
        int s = 0;
        int e = n*m-1;
        
        int mid = s + (e-s)/2;
        
        while(s<=e)
        {
            int element = matrix[mid/m][mid%m];
            if(element == target)
            {
                return true;
            }
            if(element>target)
            {
                e = mid-1;
            }
            else{
                s = mid+1;
            }
            mid = s+(e-s)/2;
        }
        return false;
    }
};

int main(){



    return 0;
}