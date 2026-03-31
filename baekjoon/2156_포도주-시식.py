import sys, io

# testcase = """\
# 6
# 6
# 10
# 13
# 9
# 8
# 1
# """

# sys.stdin = io.StringIO(testcase)
input = lambda: sys.stdin.readline().rstrip()

## input
N = int(input())
current_values = [0] * N
dp = [0] * N

for i in range(N):
    current_values[i] = int(input())
    

## algorithm
dp[0] = current_values[0]
if N >= 2: dp[1] = current_values[0] + current_values[1]
if N >= 3: dp[2] = max(dp[1], dp[0] + current_values[2], current_values[1] + current_values[2])

for i in range(3, N):
    dp[i] = max(dp[i-3] + current_values[i-1] + current_values[i], 
                dp[i-2] + current_values[i], 
                dp[i-1])
    
print(dp[-1])