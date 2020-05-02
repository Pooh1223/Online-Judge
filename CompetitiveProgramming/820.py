import sys

def main():

    while True:
        
        try:
            num = input()
            
            tmp = ''
            
            opcnt = 0
            Sum = 0
            pos = 0

            for i in range(len(num)):
                if num[i] != '+' and num[i] != '*':
                    tmp += num[i]
                else :
                    pos = i
                    break
            
            num += '+'

            for i in range(pos,len(num)):

                if num[i] == '+' or num[i] == '*':
                    opcnt += 1

                    if opcnt == 2:
                        #print(tmp)
                        Sum = eval(tmp)
                        tmp = str(Sum)
                        opcnt = 1

                    tmp += num[i]
                else :
                    tmp += num[i]
            
            print(Sum)
        except:
            break

main()
