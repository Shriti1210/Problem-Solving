/*1317. Convert Integer to the Sum of Two No-Zero Integers
No-Zero integer is a positive integer that does not contain any 0 in its decimal representation.

Given an integer n, return a list of two integers [a, b] where:

a and b are No-Zero integers.
a + b = n
The test cases are generated so that there is at least one valid solution. If there are many valid solutions, you can return any of them.

 

Example 1:

Input: n = 2
Output: [1,1]
Explanation: Let a = 1 and b = 1.
Both a and b are no-zero integers, and a + b = 2 = n.
Example 2:

Input: n = 11
Output: [2,9]
Explanation: Let a = 2 and b = 9.
Both a and b are no-zero integers, and a + b = 11 = n.
Note that there are other valid answers as [8, 3] that can be accepted.
 

Constraints:

2 <= n <= 104*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*Approach:
1.Check for each number if it contains a zero or not if it does retun true using a boolean 
function.
2.Take numbers from 1 upto n and find another b=n-a
3.Pass both numbers to the boolean function,if both are false then return the numbers.
*/
class Solution {
public:
    bool hasZero(int num){
        while(num>0){
            if(num%10==0) return true;
            num/=10;
        }
        return false;
    }
    vector<int> getNoZeroIntegers(int n) {
        for(int a=1;a<n;a++){
            int b=n-a;
            if(!hasZero(a) && !hasZero(b)){
                  return{a,b};
            }
        }
        return {};
    }
};