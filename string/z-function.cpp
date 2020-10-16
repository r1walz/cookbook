/*
 * @author Tanmaya Khandelwal
 *
 * Algorithm to find Z-function of the given string.
 * The Z-function for a string s of size n is an array of length n where the 
 * i-th element is equal to the greatest number of characters  
 * starting from the position i that coincide with the first characters of s.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
 
# include <bits/stdc++.h>
using namespace std;

vector<int> z_function(string s){
    
	int n = s.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int main(){
	string s;
	cin>>s;
	
	vector<int> z = z_function(s);
	for(int i=0;i<z.size();i++) cout<<z[i]<<" ";
}

