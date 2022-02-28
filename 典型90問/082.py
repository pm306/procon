L, R = map(int, input().split())
MOD = 10**9 + 7

def souwa(n):
    return n * (n + 1) // 2

#10の累乗
power10 = [0] * 20
power10[0] = 1
for i in range(1, 20):
    power10[i] = power10[i-1] * 10

ans = 0
for i in range(1, 20):
    l = power10[i-1] # 10**(i-1)
    r = min(R, (power10[i] - 1)) #10**i - 1
    if l > r:
        break
    tmp = (souwa(r) - souwa(l-1)) % MOD * i % MOD
    ans = (ans + tmp) % MOD

for i in range(1, 20):
    l = power10[i-1]
    r = min(L-1, (power10[i] - 1))
    if l > r:
        break
    tmp = (souwa(r) - souwa(l-1)) % MOD * i % MOD
    ans = (ans + MOD - tmp) % MOD

print(ans)
