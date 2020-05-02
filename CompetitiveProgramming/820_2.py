import sys

def main():

    while True:
        
        try:
            num = input().split('+')

            Sum = 0

            for item in num:
                if '*' not in item:
                    Sum += int(item)
                else :
                    mul = item.split('*')

                    for i in range(len(mul)):
                        if i == 0:
                            Sum += int(mul[i])
                        else :
                            Sum *= int(mul[i])
            
            print(Sum)

        except:
            break
            
main()
