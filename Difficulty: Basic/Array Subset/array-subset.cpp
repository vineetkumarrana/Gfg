//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m) ;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        int a1[n], a2[m];

        for (int i = 0; i < n; i++) {
            cin >> a1[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> a2[i];
        }

        cout << isSubset(a1, a2, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends


string isSubset(int a1[], int a2[], int n, int m) {
 /*
 
 //FRIST APPROACH : TRAVERSE BOTH THE ARRRAYS AND COMPARE THE ELEMENTS
 // TC : O(NM)
   if(m==0)           // Edge case: If a2 is empty, it's always a subset of a1
    return "Yes";
   
    for(int i=0;i<m;i++){    // Traverse each element in a2
        
        bool found=false;
        
        for(int j=0;j<n;j++){  // Traverse each element in a1 to find a2[i]
            
            if(a2[i]==a1[j]) {
                
              found=true;
              a1[j]= -1;  // Optionally, mark the element in a1 as used (if needed):
              break;
              
             }
        }
             
        if(!found)    // If the current element in a2 is not found in a1, return "No"
         return "No";
             
        
    }
    return "Yes";  // If all elements in a2 are found in a1, return "Yes"

*/
    


 // SECOND APPRAOCH : USNG UNORDERED HASHMAP
//TC : O(N) { BECOZ O(n) >O(m) }  and SC : O(N)

unordered_map<int, int> a1_count;
    
    // Populate the map with counts from a1
    for (int i = 0; i < n; ++i) {
        a1_count[a1[i]]++;
    }

    // Check each element in a2 to see if it is in a1 with the required frequency
    for (int j = 0; j < m; ++j) {
        int elem = a2[j];
        
        // If the element is not in a1 or does not have enough occurrences
        if (a1_count[elem] == 0) {
            return "No";
        }

        // Decrement the count in the map as the element is used
        a1_count[elem]--;
    }

    // Optional step: Mark used elements in a1 as -1
    // This is not necessary for the subset check but shows which elements were used
    for (int i = 0; i < n; ++i) {
        if (a1_count[a1[i]] == 0) {
            a1[i] = -1;
        }
    }

    return "Yes";
     
}