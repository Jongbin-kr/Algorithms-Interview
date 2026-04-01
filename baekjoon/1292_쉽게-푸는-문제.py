import sys

input = lambda: sys.stdin.readline().rstrip()

"""
1 2 
2 3 3 3 4 
4 4 4 5 5 5 5 5 6 6 6 6 6 6

#7 = 1*1 + 2*2 + 3*3 + 4*1
#3 = 1*1 + 2*1
"""

a, b = map(int, input().split())

sum_a = 0
cnt_a = 0
for i in range(1, a+1): # 1, 4
    for j in range(i):  # i=1 1, i=2 2 2
        cnt_a += 1
        sum_a += i
        if cnt_a == a: break
    else:
        continue
    
    break
sum_a -= i  # bc a번째 숫자도 포함해야하기 때문에.


sum_b = 0
cnt_b = 0
for i in range(1, b+1):
    for j in range(i):
        cnt_b += 1
        sum_b += i
        if cnt_b == b: break
    else: 
        continue
    
    break

print(sum_b - sum_a)