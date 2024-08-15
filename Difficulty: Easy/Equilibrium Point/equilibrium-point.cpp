//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find equilibrium point in the array.
    // arr: input array
    int equilibriumPoint(vector<long long> &arr) {
        // Your code here
        
        //TC : O(2N) = O(N)  AND SC: O(1) [AT WORST CASE IT WILL BE O(N)]
        int n=arr.size();
        if (n == 1) return 1; // If there's only one element, it's the equilibrium point.
         long long total = 0, leftsum = 0;
        
        for(int i=0;i<n;i++)
            total=total+arr[i];
            
        
        for(int i=0;i<n;i++) {
            total=total-arr[i];  // now total is the right sum for index i

            
            if (leftsum==total) 
               return i+1;
             
          leftsum += arr[i];     
        }
        return -1;   // If no equilibrium point is found
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<long long> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.equilibriumPoint(arr) << endl;
    }
}
// } Driver Code Ends