N = int(input())
H = list(map(int,input().split()))

dp = [10**10] * N
dp[0] = 0
for i in range(N):
    if i+1 < N:
        dp[i+1] = min(dp[i+1], dp[i] + abs(H[i] - H[i+1]))
    if i+2 < N:
        dp[i+2] = min(dp[i+2], dp[i] + abs(H[i] - H[i+2]))

print(dp[N-1])


