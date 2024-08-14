//{ Driver Code Starts
// C++ program to remove recurring digits from
// a given number
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(int n, int arr[]) {
        // Code here
        
        /*
//FIRST APPROACH : TRAVERSING EACH ELEMENT WITH ALL THE OTHER ELEMENTS.
//TC : O(N2)    SC : O(N) as we are using extra array to store leaders
        vector<int>answer;  // for storing leaders
        for(int i=0;i<n;i++){
            
          bool isleader=true;   //assume current element is the leader
        
            for(int j=i+1;j<n;j++){
                
                if(arr[j]>arr[i]){
                 isleader=false;
                 break;         //    Exit the loop since arr[i] is not a leader
                }
            }
                if(isleader) 
          answer.push_back(arr[i]);
        }
        return answer;
        */
        
//SECOND APPROACH BY USING BACK TRAVERSAL I.E FROM BACK TO FRONT
    vector<int> answer;
    int maxi=INT_MIN;// keep track of max elements
    // IF WE DONT NEED TO GIVE LEADERS IN SORTED FASHION THN TC : O(N) AND SC : O(N)
    for(int i =n-1;i>=0;i--){
        
        if(maxi<=arr[i]){
          answer.push_back(arr[i]);
          maxi=arr[i];
        }
        
}
        reverse(answer.begin(),answer.end()); //for worst case TC : O(NLOGN)
        return answer;

    }
};

//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t; // testcases
    while (t--) {
        long long n;
        cin >> n; // total size of array

        int arr[n];

        // inserting elements in the array
        for (long long i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution obj;
        // calling leaders() function
        vector<int> v = obj.leaders(n, arr);

        // printing elements of the vector
        for (auto it = v.begin(); it != v.end(); it++) {
            cout << *it << " ";
        }

        cout << endl;
    }
}

// } Driver Code Ends