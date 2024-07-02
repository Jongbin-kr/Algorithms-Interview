n = int(input())

max_stars = 2 * n - 1


for i in range(1, 2 * n):
    
    if i <= n:
        now_stars = 2 * i - 1
    else: 
        now_stars = (2 * i - 1) - (4 * (i - n))
        
    padding = int((max_stars - now_stars) / 2)
    print(" " * padding + "*" * now_stars)
    

## POINT: When you divide int, it is converted into float!!!
    