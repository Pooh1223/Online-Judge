fact = [1,1]

for i in range(2,65):
    fact.append(i * fact[i - 1])

t = int(input())

for q in range(t):
    n, k = map(int,(input().strip().split()))

    k -= 1
    ans = []
    num = [int(x) for x in range(1,n + 1)]

    for i in range(n):
        ans.append(num[k // fact[n - i - 1]])
        num.remove(ans[-1])
        k %= fact[n - i - 1]
    
    print('({})'.format(",".join(str(x) for x in ans)))
