/*
Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

Example 1:
Input: nums = [3,2,3]
Output: 3
Example 2:
Input: nums = [2,2,1,1,1,2,2]
Output: 2
 
Constraints:
n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109
Follow-up: Could you solve the problem in linear time and in O(1) space?*/

//Brute Force approach:
/*Run two loops and in a count variable keep the count of every element,if the element count is
greater than n/2 return the element
T.C:O(N^2)
S.C:O(N)
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int majorityElement(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(nums[i]==nums[j]){
                    count++;
                }
            }
            if(count>n/2) return nums[i];
        }
}

//Better Approach:Hashing
/*In better approach,we are going to use the concept of hashing
Store all the elements in  Hashmap and then iterate through the map and find the element
with count >n/2
T.C:O(NLOGN +N)
S.C:O(N)
*/
int majorityElement(vector<int>& nums) {
        int n = nums.size();
        map<int,int>mp1;
        //nlogn:Iteration in map
        for(int i=0;i<n;i++){
            mp1[nums[i]]++;
        }
        for(auto it:mp1){//n
            if(it.second>n/2){
                return it.first;
            }
        }
}

//Optimal Solution:Moore's Voting Algorithm
int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count=0;
        int ele;
        for(int i=0;i<n;i++){
            if(count==0){
                count=1;
                ele=nums[i];
            }else if(nums[i]==ele){
                count++;
            }else{
                count--;
            }
        }
        return ele;
    }