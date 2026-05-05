/*
383. Ransom Note
Easy
Topics
premium lock icon
Companies
Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

 

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true
 

Constraints:

1 <= ransomNote.length, magazine.length <= 105
ransomNote and magazine consist of lowercase English letters.
*/


// sol 1: brute force
#include <string>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        for (char ch: ransomNote){
            int idx = magazine.find(ch);
            if(idx == string::npos){
                return false;
            }
            else{
                magazine.erase(idx, 1);
            }
        }
        
        return true;
    }
};


// sol2: counter
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> counterMagazine;
        for (auto ch : magazine){
            counterMagazine[ch] += 1;
        }
        
        for (auto ch : ransomNote){
            if (counterMagazine[ch] == 0){
                return false;
            }
            
            else{
                counterMagazine[ch] -= 1;
            }
        }
        
        return true;
    }
};