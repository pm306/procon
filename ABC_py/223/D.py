from heapq import heappop, heappush

N, M = map(int, input().split())
G = [[] for _ in range(N)]
#indegree:入次数(有向グラフで、頂点vに向けられた矢印の数)
ind = [0] * N
for i in range(M):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    G[a].append(b)
    ind[b] += 1

#トポロジカルソート
#有向グラフの頂点を、→が左から右に向かうようにソートする
#辞書順最小、との指定があるのでheapqを使う

topo = [] #トポロジカルソートした頂点リスト
que = [] #入次数が0の頂点
for i in range(N):
    if ind[i] == 0:
        que.append(i)

while len(que):
    v = heappop(que)
    topo.append(v)
    for to in G[v]:
        ind[to] -= 1
        if ind[to] == 0:
            heappush(que, to)

#トポソできない＝DAGではない＝閉路が存在する→入次数が0にならい頂点がある
if(len(topo) != N):
    print(-1)
else:
    for v in topo:
        print(v+1, end=" ")
    print()
