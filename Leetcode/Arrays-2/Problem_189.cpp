/*189. Rotate Array
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
 

Constraints:

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
0 <= k <= 105
 

Follow up:

Try to come up with as many solutions as you can. There are at least three different ways to solve this problem.
Could you do it in-place with O(1) extra space?
*/
/*
Brute Force Approach:
First store the d elements first in a temporary array
next move the remaining element on the left side 
after moving the elements to the start,push the remaining d elements back in the array
*/

//LEFT ROTATE ARRAY PROGRAM
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void leftRotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        vector<int>temp;
        //put d elements in temp array
        for(int i=0;i<k;i++){//O(d)
            temp.push_back(nums[i]);
        }
        //Push array elements to the front of array
        for(int i=k;i<n;i++){
            nums[i-k]=nums[i];
        }
        //put temp array elements back in original
        for(int i=n-k;i<n;i++){
            nums[i]=temp[i-(n-k)];
        }
    
}

void rightRotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        vector<int>temp;
        //put last d elements in temp array
        for(int i=0;i<k;i++){//O(d)
            temp.push_back(nums[n-k+i]);
        }
        //Push array elements to the back of the array
         for (int i = n - k - 1; i >= 0; i--) {
            nums[i + k] = nums[i];
        }

        // Step 3: put temp elements at front
        for (int i = 0; i < k; i++) {
            nums[i] = temp[i];
        }
    
}

//OPTIMIZED SOLUTION:use reverse the array concept and reverse the array 
void reverse(vector<int>&nums,int start,int end){
        while(start<end){
            swap(nums[start],nums[end]);
            start++;
            end--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        reverse(nums,0,n-1);
        reverse(nums,0,k-1);
        reverse(nums,k,n-1);
        
    }

