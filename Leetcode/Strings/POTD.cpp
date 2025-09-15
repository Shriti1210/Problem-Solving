/*
1935. Maximum Number of Words You Can Type
There is a malfunctioning keyboard where some letter keys do not work. All other keys on the keyboard work properly.

Given a string text of words separated by a single space (no leading or trailing spaces) and a string brokenLetters of all distinct letter keys that are broken, return the number of words in text you can fully type using this keyboard.

Example 1:

Input: text = "hello world", brokenLetters = "ad"
Output: 1
Explanation: We cannot type "world" because the 'd' key is broken.
Example 2:

Input: text = "leet code", brokenLetters = "lt"
Output: 1
Explanation: We cannot type "leet" because the 'l' and 't' keys are broken.
Example 3:

Input: text = "leet code", brokenLetters = "e"
Output: 0
Explanation: We cannot type either word because the 'e' key is broken.
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canBeTypedWords(string text, string broken){
        unordered_set<char> brokenKeys;
        int count = 0;

        for (auto& c : broken){
            brokenKeys.insert(c);
        }

        stringstream ss(text);
        string word;
        vector<string> words;

        while (ss >> word){
            words.push_back(word);
        }

        for (auto w : words)
        {
            for (char c : w)
            {
                if (brokenKeys.find(c) != brokenKeys.end())
                {
                    count++;
                    break;
                }
            }
        }

        return words.size() - count;
    }
};