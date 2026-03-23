class Solution:
    def maximumWealth(self, accounts: List[List[int]]) -> int:
        max_wealth = 0
        for account in accounts:
            wealth = sum(account)
            if wealth >= max_wealth:
                max_wealth = wealth

        return max_wealth
        