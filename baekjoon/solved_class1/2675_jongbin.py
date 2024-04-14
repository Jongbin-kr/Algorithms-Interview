n = int(input())

for _ in range(n):
    i, characters = input().split()
    i = int(i)
    
    output = ''
    for character in characters:
        output += character * i
        
    print(output)