S = input()

A = []
for _ in range(len(S)):
    A.append(S)
    S = S[1:] + S[0]

A.sort()
print(A[0])
print(A[-1])
