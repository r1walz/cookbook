/*
 * @author Tanmaya Khandelwal
 *
 * Longest Increasing Subsequence is a problem to find largest non-contiguous 
 * elements in the array whose consecutive elements are increasing.
 * It uses dynamic programming for solving the task.
 * Time Complexity: O(n^2)
 * Space Complexity: O(n)
 */
 
# include <bits/stdc++.h>
using namespace std;

int longest_increasing_subsequence(int a[], int n){
	int lis[n],max_len=1;
	lis[0] = 1;
	
	for(int i=1;i<n;i++){
		
		lis[i] = 1;
		
		for(int j=0;j<i;j++){
			if(a[i] > a[j])
				lis[i] = max(lis[i] , 1+lis[j]);
		}
		
		max_len = max(max_len , lis[i]);
	}
	return max_len;
}

int main(){
	int n;
	cin>>n;
	
	int a[n];
	
	for(int i=0;i<n;i++)
		cin>>a[i];
	
	cout<<longest_increasing_subsequence(a, n);  
	
}

