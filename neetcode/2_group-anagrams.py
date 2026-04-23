"""
Group Anagrams
Medium
Topics
Company Tags
Hints
Given an array of strings strs, group all anagrams together into sublists. You may return the output in any order.

An anagram is a string that contains the exact same characters as another string, but the order of the characters can be different.

Example 1:

Input: strs = ["act","pots","tops","cat","stop","hat"]

Output: [["hat"],["act", "cat"],["stop", "pots", "tops"]]
Example 2:

Input: strs = ["x"]

Output: [["x"]]
Example 3:

Input: strs = [""]

Output: [[""]]
Constraints:

1 <= strs.length <= 1000.
0 <= strs[i].length <= 100
strs[i] is made up of lowercase English letters.
"""


"""
생각

strs의 길이가 1000 (N)이고, str의 길이는 100 (M)이므로 brute-force돌려도 무관.
근데 애너그램인지 아닌지를 어떻게 비교하냐가 문제인데. 
1. set으로 하면 중복이 제거되므로, counter?  --> 이것도 sorted랑 비슷하지않나
2. 혹은 sorted로 정렬해두고 비교해도?  --> N * N * (M log M)?

"""



from collections import Counter, defaultdict

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        
        seen = defaultdict(list)
        
        for st in strs:
            sorted_st = "".join(sorted(st))
            seen[sorted_st].append(st)
    
        return [list_of_st for sorted_st, list_of_st in seen.items()]
            
        
