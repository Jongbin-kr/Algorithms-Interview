inputs = []
while True:
    try:
        a = int(input())
        inputs.append(a)
    except EOFError:
        break
    
    
print(max_input := max(inputs))
print(inputs.index(max_input)+1)
