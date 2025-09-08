/*Question :Given an integer n, return any array containing 
n unique integers such that they add up to 0.
Example 1:

Input: n = 5
Output: [-7,-1,1,3,4]
Explanation: These arrays also are accepted [-5,-1,1,2,3] , [-3,-1,2,-2,4].
Example 2:

Input: n = 3
Output: [-1,0,1]
Example 3:

Input: n = 1
Output: [0] */

//Approach 1:Using 2 pointers i and j
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 vector<int> sumZero(int n) {
        vector<int>result;
        int start=1;
        int i=0;
        int j=n-1;
        while(i<j){
            result[i]=start;
            result[j]=-start;
            i++;
            j--;
            start++;
        }if(i==j){
            result[i]=0;
        }
    }

//Approach 2: Calculate sum of number from 1 to n-1 then add a negative number of total sum
//the numbers.
 vector<int> sumZero(int n) {
        vector<int>result;
        for(int i=1;i<=n/2;i++){
            result.push_back(i);
            result.push_back(-i);
        }
        if(n%2==1){
            result.push_back(0);
        }
        return result;
    }