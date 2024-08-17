//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        // your code here
//FIRST APPROACH USNG TWO LOOPS AND TRAVERSING EACH ELEMENT WITH ALL OTHER ELEMENMTS.
//TC : O(MN)  SC : O(M)OR O(1)

        string ans="";
         if (arr.empty()) return "-1";  // Edge case: if the array is empty, return "-1"
         
        for(int i =0;i<arr[0].length();i++){
            char ch = arr[0][i]; // Store the current character from the first string
            bool match=true;// Flag to track if the character matches in all strings

         // Inner loop: compare the current character with corresponding characters in other strings
   
            for(int j=1;j<arr.size();j++){
                // Check if the current string is shorter than the current index,
                // or if the character does not match
                if(i >= arr[j].size() || ch!=arr[j][i]){
                    match=false;
                    break;
                }
            }
            
            if(match==false)
              break;
            else 
              ans.push_back(ch);
              
        }
        return ans.empty() ? "-1" : ans;
        
        
//SECOND APPROACH BY PLACING FIRST STRING AS PREFIX AND IF IT DOESNOT MATCHES WITH THE REAT PREFIX SHORTEN THE PREFIX BY REMVING ELEMNTS FROM THE LAST.
//TC : O(NM)   SC : O(1)

   /* if(arr.empty()) return"";
      
    string prefix=arr[0];
       
    for(int i=1;i<arr.size();i++){
           
     while(arr[i].find(prefix) != 0){  // While the current string doesn't start with the prefix
               
               prefix=prefix.substr(0,prefix.length()-1); // Reduce the prefix by one character from the end
           }
       }
       return prefix;
        
     */
     
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends