import sys, io

testcase = """\
6
6
10
13
9
8
1
"""

sys.stdin = io.StringIO(testcase)
input = lambda: sys.stdin.readline().rstrip()

## input
N = int(input())
current_values = [0] * N
max_values = [0] * N
streaks = [0] * N

for i in range(N):
    current_values[i] = int(input())
    
max_values[0], streaks[0] = current_values[0], 1
max_values[1], streaks[1] = current_values[1], 2
max_values[2] = max(0 + current_values[1] + current_values[2], max_values[0] + current_values[2])
streaks[2] = 2 if max_values[2] == 0 + current_values[1] + current_values[2] else 1

for i in range(3, N):
    i_3 = max_values[i-3] + current_values[i-2] + current_values[i]
    i_2 = max_values[i-2] + 0 + current_values[i]
    i_1 = max_values[i-1] + current_values[i] if streaks[i-1] < 2 else 0
    
    max_value = max(i_3, i_2, i_1)
    if max_value == i_3: max_values[i], streaks[i] = i_3, 2
    elif max_value == i_2: max_values[i], streaks[i] = i_2, 1
    else: max_values[i], streaks[i] = i_1, 2
    
print(max(max_values))


"""
이거 약간 DP 느낌인데 어떻게 해야할지 모르겠네...

6 10 13 9 8 1
6 10    9 8   = 33
  10 13   8 1 = 32

문제점:
1. i번째 잔을 안마시는 경우를 고려하지 않음
2. max_value에서 스트릭은 고려하지 않고, i_2, i_1을 모두 동등하게 취급해버림.

""" 