"""
문제
영식이는 직사각형 모양의 성을 가지고 있다. 성의 1층은 몇 명의 경비원에 의해서 보호되고 있다. 영식이는 모든 행과 모든 열에 한 명 이상의 경비원이 있으면 좋겠다고 생각했다.

성의 크기와 경비원이 어디있는지 주어졌을 때, 몇 명의 경비원을 최소로 추가해야 영식이를 만족시키는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 성의 세로 크기 N과 가로 크기 M이 주어진다. N과 M은 50보다 작거나 같은 자연수이다. 둘째 줄부터 N개의 줄에는 성의 상태가 주어진다. 성의 상태는 .은 빈칸, X는 경비원이 있는 칸이다.

출력
첫째 줄에 추가해야 하는 경비원의 최솟값을 출력한다.

"""


"""
Thoughts
x축 기준으로 감시병이 있는 곳 T/F로 체크하는 리스트.
y축 기준으로도 감시병이 있는 곳 T/F로 체크하는 리스트.
그리고 row 입력받으면서 있는 곳 T로 체크.
그 담에 row별로 순회하면서 False인 곳에 놓고, T로 체크. 


TTFTTTTT
....XXXX T
........ F
XX.X.XX. T
........ F
........ F


"""



import sys, io

# tc = """\
# 3 5
# XX...
# .XX..
# ...XX
# """


# sys.stdin = io.StringIO(tc)
input = lambda: sys.stdin.readline().rstrip()

N, M = map(int, input().split())
N_tf = [False] * N
M_tf = [False] * M
matrix = []
for i in range(N):
    row = []
    for j, char in enumerate(input()):
        if char == "X": N_tf[i] = True; M_tf[j] = True     

print(max(N_tf.count(False), M_tf.count(False)))
        