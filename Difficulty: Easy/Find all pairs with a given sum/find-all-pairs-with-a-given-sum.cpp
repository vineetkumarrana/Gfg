//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find all pairs with given sum.
    vector<pair<int, int>> allPairs(int x, vector<int> &arr1, vector<int> &arr2) {
        // Code here
        
        
//first approach usng set  ..put array1 in set thn . if (x-arr2[elements] )present in set..its a pair.
//TC : O(NLOG(N)) AND FOR SORTING and SC : O(N)
     
        unordered_set<int> s;
        vector<pair<int, int>> result;

        // Insert all elements of arr1 into the set
        for (int i = 0; i < arr1.size(); i++) {
            s.insert(arr1[i]);
        }

        // Check for each element in arr2 if x - element exists in the set
        for (int j = 0; j < arr2.size(); j++) {
            if (s.find(x - arr2[j]) != s.end()) {
                result.push_back({x - arr2[j], arr2[j]});
            }
        }

        // Sort the result vector of pairs
        sort(result.begin(), result.end());

        return result;
     
        
//SECOND APPRAOCH USING TWO POINTERS
//TC : O(N/LOG(N) +M/LOG(M))    AND SC : O(N)
//Note: The O(n + m) for the traversal is dominated by the O(n \log n + m \log m) from sorting, so the final time complexity is O(n \log n + m \log m)        
    /*
     vector<pair<int, int>> result;

        // Sort both arrays
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());

        // Initialize two pointers
        int i = 0;                // Pointer for arr1
        int j = arr2.size() - 1;   // Pointer for arr2

        // Traverse the arrays
        while (i < arr1.size() && j >= 0) {
            int sum = arr1[i] + arr2[j];

            if (sum == x) {
                result.push_back({arr1[i], arr2[j]});
                i++;
                j--;
            } else if (sum < x) {
                i++;  // Move the pointer in arr1 to the right
            } else {
                j--;  // Move the pointer in arr2 to the left
            }
        }

        return result;    
        */
        
    }
    
    
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        int x;
        cin >> x;
        cin.ignore();

        vector<int> arr1;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr1.push_back(number);
        }
        vector<int> arr2;
        string input2;
        getline(cin, input2); // Read the entire line for the array elements
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            arr2.push_back(number2);
        }

        Solution ob;
        vector<pair<int, int>> vp = ob.allPairs(x, arr1, arr2);
        int sz = vp.size();
        if (sz == 0)
            cout << -1 << endl;
        else {
            for (int i = 0; i < sz; i++) {
                if (i == 0)
                    cout << vp[i].first << " " << vp[i].second;
                else
                    cout << ", " << vp[i].first << " " << vp[i].second;
            }
            cout << endl;
        }
    }

    return 0;
}
// } Driver Code Ends