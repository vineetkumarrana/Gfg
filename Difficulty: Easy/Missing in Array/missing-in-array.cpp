//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    // Note that the size of the array is n-1
//SECOND APPROACH : USING XOR (1^1 = 0 AND 1^0 = 1)
//TC : O(N)
    int missingNumber(int n, vector<int>& arr) {
       
    /*   
       int total_xor=0;
        
      for(int i=0;i<n-1;i++){ // XOR all the array elements
          total_xor^=arr[i];
      }
      
      for(int i=0;i<=n;i++)//// XOR with all numbers from 1 to n
          total_xor^=i;
      
    
    
    return total_xor;
    }
    
    */
//FIRST APPRAOCH : USNG MATHS FORMULA 
//TC=O(N)   and SC=O(1)
    int result=0;
    int sum=0;

    for(int i=0;i<n-1;i++){
        sum=sum+arr[i];
    }
    
    int sum2=n*(n+1)/2;
    result=sum2-sum;
    return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n - 1);
        for (int i = 0; i < n - 1; ++i)
            cin >> arr[i];
        Solution obj;
        cout << obj.missingNumber(n, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends