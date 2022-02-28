N, M = map(int, input().split())
N *= 2 #実際の人数
A = []
for i in range(N):
    A.append(input())

rank = [] #[勝利数(正負反転), 選手番号(0-indexed)]
for i in range(N):
    rank.append([0, i])

#ジャンケン関数 aの勝ちなら0, bの勝ちなら1, 引き分けなら-1を返す
def janken(a, b):
    if a == b:
        return -1
    if a == 'G' and b == 'C' or a == 'C' and b == 'P' or a == 'P' and b == 'G':
        return 0
    return 1

for j in range(M):
    for i in range(0, N, 2):
        idx1, idx2 = rank[i][1], rank[i+1][1]
        hand1, hand2 = A[idx1][j], A[idx2][j]
        result = janken(hand1, hand2)
        if(result != -1):
            rank[i+result][0] -= 1
    rank.sort()

for win, idx in rank:
    print(idx+1)

