/*
Question:1. Two Sum
Easy
Given an array of integers nums and an integer target, return indices of the two numbers
 such that they add up to target.You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 
Constraints:
2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
 */

//Approach 1:Brute Force Approach
/*
The first solution that comes up in my mind is the most obvious:use two for loops
For an element ,run through the whole array and check if you find the given target sum*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>p1;
        for(int i=0;i<n-1;i++){
            int more=target-nums[i];
            for(int j=i+1;j<n;j++){
                if(nums[j]==more){
                    p1.push_back(nums[j]);
                    p1.push_back(nums[i]);
                }
            }
        }
        return p1;
 }

//Approach 2(Optimal Solution): Two Pointer Approach
/*

*/
 vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>p1;
        int i = 0;
        int j = i + 1;

    while (i < n - 1) {
        if (nums[i] + nums[j] == target) {
            p1.push_back(i);
            p1.push_back(j);
            break; // stop after finding one pair
        } 
        else if (j == n - 1) { // if reached end for current i
            i++;
            j = i + 1; // reset j for next i
        } 
        else {
            j++;
        }
    }
    return p1;
    
 }