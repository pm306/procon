import sys
sys.setrecursionlimit(10**6)

N = int(input())
H = list(map(int,input().split()))

memo = [-1] * N
def dp(n):
    if n == 0:
        return 0
    if memo[n] != -1:
        return memo[n]

    ret = 10**10
    ret = min(ret, dp(n-1) + abs(H[n]-H[n-1]))
    if n-2>=0:
        ret = min(ret, dp(n-2) + abs(H[n]-H[n-2]))
    memo[n] = ret
    return ret

print(dp(N-1))
