N = int(input())
A = []
B = []
for i in range(N):
    a, b = map(int, input().split())
    A.append(a)
    B.append(b)

#2つの火がぶつかる時間を求める
col_time = 0
for i in range(N):
    col_time += A[i] / B[i]
col_time /= 2

#衝突する区間まで左端から導火線を進める
ans = 0 #左端の火が進んだ距離
left_time = 0 #左端の火が進んだ時間
for i in range(N):
    next_time = left_time + A[i] / B[i] #次の区間まで進む場合の経過時間
    #next_timeが衝突する時間を過ぎていれば、次に進む区間のどこかで衝突する
    if next_time >= col_time:
        ans += (col_time - left_time) * B[i]
        print(ans)
        break
    ans += A[i]
    left_time += A[i] / B[i]
