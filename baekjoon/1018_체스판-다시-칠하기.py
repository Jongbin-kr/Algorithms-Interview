import sys
h, w = map(int, input().split())
lines = []
for _ in range(h):
    lines.append(sys.stdin.readline().strip())

bw = lines[0][0]
err_num = 0
for i in range(h):
    for j in range(w):
        if bw != lines[i][j]:
            err_num += 1
        
        bw = "B" if bw == "W" else "W"

print(err_num)