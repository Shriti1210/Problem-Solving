/*
75. Sort Colors
Medium
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, 
with the colors in the order red, white, and blue
We will use the integers 0, 1, and 2 to represent the color red, white, and blue,
 respectively
You must solve this problem without using the library's sort function.

Example 1:
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:
Input: nums = [2,0,1]
Output: [0,1,2]

Constraints:
n == nums.length
1 <= n <= 300
nums[i] is either 0, 1, or 2.*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*Approach 1:(Better Solution):
Count all the 0s,1s,2s and then run 3 for loops.
First loop will run from 0 to countzeroes
2nd will run from 0s to 1s and similarly 3rd will run
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red=0;
        int white=0;
        int blue=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                red++;
            }else if(nums[i]==1){
                white++;
            }else{
                blue++;
            }
        }
        for(int i=0;i<red;i++){
            nums[i]=0;
        }
        for(int i=red;i<red+white;i++){
            nums[i]=1;
        }
        for(int i=red+white;i<n;i++){
            nums[i]=2;
        }
    }
};

//Approach 2:Dutch National Flag Algorithm
/*
Take three pointers:low,mid and high
It is based on basically 3 rules:
1)[0 ......low-1]---->0
2)[low.......mid-1]----->1
3)[high+1......n-1]------>2

That means that mid to high consists of all the unsorted element of the array.

Keep mid and low pointer at the starting of array
and High pointer at the end of teh array i.e n-1

Now we take 3 cases:1.mid is 0 2.mid is 1 3.mid is 2
1st Case:(mid==0)
swap(arr[low],arr[mid]) mid++ low++

2nd Case:(mid==1)
Do nothing,move mid pointer mid++

3rd Case:(mid==2)
swap(arr[mid],arr[high]) mid++ high--
*/

 void sortColors(vector<int>& nums) {
       int n=nums.size();
       int low=0;
       int mid=0;
       int high=n-1;
       while(mid<=high){
        if(nums[mid]==0){
            swap(nums[low],nums[mid]);
            low++;
            mid++;
        }else if(nums[mid]==1){
            mid++;
        }else{
            swap(nums[mid],nums[high]);
            high--;
            
        }
       }
    }