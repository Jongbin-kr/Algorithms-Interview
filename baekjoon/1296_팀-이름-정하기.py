"""
문제
연두는 프로그래밍 대회에 나갈 팀 이름을 정하려고 한다. 미신을 믿는 연두는 이환이에게 공식을 하나 받아왔고, 이 공식을 이용해 우승할 확률이 가장 높은 팀 이름을 찾으려고 한다.

이환이가 만든 공식은 사용하려면 먼저 다음 4가지 변수의 값을 계산해야 한다.

L = 연두의 이름과 팀 이름에서 등장하는 L의 개수
O = 연두의 이름과 팀 이름에서 등장하는 O의 개수
V = 연두의 이름과 팀 이름에서 등장하는 V의 개수
E = 연두의 이름과 팀 이름에서 등장하는 E의 개수
그 다음, 위에서 구한 변수를 다음 식에 입력하면 팀 이름의 우승할 확률을 구할 수 있다.

((L+O) × (L+V) × (L+E) × (O+V) × (O+E) × (V+E)) mod 100

연두의 영어 이름과 팀 이름 후보 N개가 주어졌을 때, 우승할 확률이 가장 높은 팀 이름을 구해보자. 확률이 가장 높은 팀이 여러가지인 경우 사전 순으로 가장 앞서는 팀 이름이 우승할 확률이 가장 높은 것이다.

입력
첫째 줄에 연두의 영어 이름이 주어진다. 둘째 줄에는 팀 이름 후보의 개수 N이 주어진다. 셋째 줄부터 N개의 줄에 팀 이름이 한 줄에 하나씩 주어진다.

연두의 영어 이름과 팀 이름은 길이는 1보다 크거나 같고, 20보다 작거나 같으며, 알파벳 대문자로만 이루어져 있다. N은 50보다 작거나 같은 자연수이다.

출력
첫째 줄에 우승할 확률이 가장 높은 팀 이름을 출력한다.

예제 입력 1 
LOVE
3
JACOB
FRANK
DANO
예제 출력 1 
FRANK
"""



import sys, io
from collections import Counter

# tc = """\
# LOVE
# 3
# JACOB
# FRANK
# DANO
# """

# sys.stdin = io.StringIO(tc)

input = lambda: sys.stdin.readline().rstrip()

yd_name = input()

max_prob = 0; winner_team = "Z" * 21
for _ in range(int(input())):
    team_name = input()
    ctr = Counter([ch for ch in yd_name + team_name if ch in "LOVE"])
    prob = ((ctr["L"] + ctr["O"]) * (ctr["L"] + ctr["V"]) * (ctr["L"] + ctr["E"]) * (ctr["O"] + ctr["V"]) * (ctr["V"] + ctr["E"]) * (ctr["O"] + ctr["E"])) % 100
    
    if prob > max_prob:
        max_prob = prob
        winner_team = team_name
    elif prob == max_prob:
        winner_team = min(winner_team, team_name)
    

print(winner_team)
    

"""
이름을 먼저 받아서 sort해둘 수도 있고,
튜플 형태로 정렬할 수도 있다.

파이썬의 튜플은 (요소1, 요소2) 순서대로 비교한다는 점을 이용합니다. 정렬 기준이 여러 개일 때 가장 강력한 방법입니다.

Python
# [방법 3] (확률, 이름) 튜플 활용
# 확률은 클수록 좋으므로 음수(-)를 붙여 '작을수록 좋은' 기준으로 통일
best_info = (1, "")  # (확률_음수, 이름) 초기값

for name in teams:
    prob = calculate(name)
    current_info = (-prob, name) # 확률은 내림차순(점수 높음), 이름은 오름차순(사전 순)
    
    if current_info < best_info: # 튜플끼리 비교하여 최솟값 갱신
        best_info = current_info
        winner = name
"""
    