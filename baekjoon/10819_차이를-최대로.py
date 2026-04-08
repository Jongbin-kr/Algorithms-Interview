"""
BOJ 10819
문제
N개의 정수로 이루어진 배열 A가 주어진다. 이때, 배열에 들어있는 정수의 순서를 적절히 바꿔서 다음 식의 최댓값을 구하는 프로그램을 작성하시오.

|A[0] - A[1]| + |A[1] - A[2]| + ... + |A[N-2] - A[N-1]|

입력
첫째 줄에 N (3 ≤ N ≤ 8)이 주어진다. 둘째 줄에는 배열 A에 들어있는 정수가 주어진다. 배열에 들어있는 정수는 -100보다 크거나 같고, 100보다 작거나 같다.

출력
첫째 줄에 배열에 들어있는 수의 순서를 적절히 바꿔서 얻을 수 있는 식의 최댓값을 출력한다.

예제 입력 1 
6
20 1 15 8 4 10
예제 출력 1 
62
"""


"""
생각
9! 정도니까 그냥 브루트하게 돌려도 되고,
아니면 정렬해서 해도 될 듯? 근데 음수가 있으니 그냥 정렬만 하기보다는...
20 15 10 8 4 1 -99 -100 
"""


import sys, io


tc = """\
6
20 1 15 8 4 10
"""
sys.stdin = io.StringIO(tc)



## brute-force
# from itertools import permutations
#
# input = lambda: sys.stdin.readline().rstrip()
# n = int(input())
# nums = map(int, input().split())
# 
# max_res = 0
# for perm in permutations(nums, n):
#     res = 0
#     for i in range(len(perm)-1):
#         res += abs(perm[i] - perm[i+1])
#  
#     max_res = max(res, max_res)
#       
# print(max_res)


## sort using deque
"""
배워갈 점.
굳이 끝에서부터  시작할 필요가 없다. 
4가지 경우의 수를 각각 비교해보는 건 생각보다 비싸지 않겠네.
"""

import sys
from collections import deque

input = lambda: sys.stdin.readline().rstrip()
n = int(input())
nums = map(int, input().split())

left_q = deque(sorted(nums))
res_q = deque([left_q.popleft()])

res = 0
while left_q:
    left_min = abs(left_q[0] - res_q[0])
    left_max = abs(left_q[-1] - res_q[0])
    right_min = abs(left_q[0] - res_q[-1])
    right_max = abs(left_q[-1] - res_q[-1])
    
    max_diff = max(left_min, left_max, right_min, right_max)
    
    if max_diff == left_min: res += left_min; res_q.appendleft(left_q.popleft())
    elif max_diff == left_max: res += left_max; res_q.appendleft(left_q.pop())
    elif max_diff == right_min: res += right_min; res_q.append(left_q.popleft())
    else:                       res += right_max; res_q.append(left_q.pop())

print(res)
    
    
    
"""
lq 4 8 10 15 20
rq 1
1 - 4
4 - 1
1 - 20 V
20 - 1


lq 4 8 10 15
rq 1 20 
4 - 1
15 - 1
20 - 4 V
20 - 15


lq 8 10 15
rq 1 20 4
8 - 1
15 - 1
4 - 8
4 - 15

"""