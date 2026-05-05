"""
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
"""


"""
생각

음? 걍 이건가? ransomNote in magazine인가?
아님 for문으로 ransomNote의 캐릭터들을 돌리면서 magazine에서 pop해야나갸아하나

--> 아! 그냥 개수만 세면 되는구나!
----> Counter는 끼리끼리  +/- 할 수 있다.
"""


## sol1: brutely loop
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        
        ransomNote = list(ransomNote)
        for ch in magazine:
            if ch in ransomNote: ransomNote.remove(ch)
            
        return not ransomNote


## sol2: using counter
from collections import Counter

class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        
        ransom_counter = Counter(ransomNote)
        magazine_counter = Counter(magazine)
        
        for key, item in ransom_counter.items():
            if key in magazine_counter and ransom_counter[key] <= magazine_counter[key]:
                continue
            else: 
                return False
            
        else:
            return True
            
            
## sol3: counter operations
from collections import Counter

class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        ransom_counter = Counter(ransomNote)
        magazine_counter = Counter(magazine)
        
        return not(ransom_counter - magazine_counter)