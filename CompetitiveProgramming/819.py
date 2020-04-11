import sys

while True:
    
    try:
        num = [int(x) for x in input().split()]
    
        Sum = 0

        for i in num:
            Sum += i
        
        print(Sum)
    except:
        break
